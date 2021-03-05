// get.c
//	fix the bug that can not get 1 piece from xxx
//		modified by justdoit at 11.1 2001
// 	added various check and 15 sec corpse-protection delay
//		by Silencer at 3/6/2003
/*
	东西的Mark
	(1). no_drop: Can pawn only
	(2). no_get: 大部分用在静物上
	(3). no_transfer: 在第一次ｇｅｔ后自动转为no_drop，不能sell, 可以pawn, redeem后转为no_drop
	(4). no_stack: 不能放在自己屋子里
	(5). lore: 只能拥有一个，且不能放在容器里．

	老的ｍａｒｋ
	(1). no_give.. so you just drop it to transfer?
	(2). no_pawn... why? just set value to 1
	(3). no_sell.. why? just set value to 1


	i need revise put/give/get/drop/sell/pawn container lore etc later...

	// added modification posted by siso at JUN 6, 2005 
	-- Silencer
*/



#include <ansi.h>

inherit F_CLEAN_UP;

int do_get(object me, object ob, object env);	//modified
object present(mixed str, object env); 
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string from, item;
	object obj, *inv, env, obj2;
	object *my_inv, my_item;
	int i, j, amount, num, freeze;
	string arg1, from1;

	if( !arg ) return notify_fail("你要捡起什麽东西？\n");
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

	if (sizeof(all_inventory(me))>=26)
		return notify_fail("你已经带著太多东西了！\n");

// prevent people using get xyz from wall 0 
// prevent people using get xyz from wall 1
	if ( sscanf(arg, "%s from %s %d", arg1, from1, num)==3) {
		if (num==0 || num ==1)
			return notify_fail("不必或不能使用get xxx from xxx 0/1。\n");
	}

	// Check if a container is specified.
	if( sscanf(arg, "%s from %s", arg, from)==2 ) {
		env = present(from, me);
		if(!env) env = present(from, environment(me));
		if(!env) return notify_fail("你找不到 " + from + " 这样东西。\n");
		if( !env->is_corpse() && env->is_character() && (wiz_level(me) <= wiz_level(env)))
			return notify_fail("你的管理等级必须比对方高，才能搜身。\n");
		if( !env->is_corpse() && env->is_character() && !userp(env) && wiz_level(me) <= 3 )
			return notify_fail("你的管理等级不够。\n");	
	} else 
		env = environment(me);
	
	// check if this thing is locked or whatsoever any tricks invovled
	if( (int) env->is_closed())
		return notify_fail( "你要先把" + env->name() + "打开。\n");
	
	// Check if a certain amount is specified.
	if(sscanf(arg, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, env)) )
			return notify_fail("这里没有这样东西。\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开拿走。\n");
		if( amount < 1 )
			return notify_fail("东西的个数至少是一个。\n");
		if( amount > obj->query_amount() ) {
			return notify_fail("这里没有那麽多的" + obj->name() + "。\n");
		} else if(amount == (int)obj->query_amount()) {
			return do_get(me, obj, env);	//modified
		} else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
						obj2->set_name(obj->query("name"),obj->parse_command_id_list());
			obj2->set("long",obj->query("long"));
			obj2->set("unit",obj->query("unit"));

			obj2->move(me);		//modified
			// Counting precise amount costs more time.
			if( me->is_fighting() ) me->start_busy(3);
			return do_get(me, obj2, env);	//modified
		}
	}

	// Check if we are making a quick get.
	if(arg=="all") {
		if( me->is_fighting() )	
			return notify_fail("你还在战斗中！只能一次拿一样。\n");
		if( !env->query_max_encumbrance() )	return notify_fail("那不是容器。\n");

		inv = all_inventory(env);
		if( !sizeof(inv) )
			return notify_fail("那里面没有任何东西。\n");
		
	//	15 sec corpse loot protection. Only killer/self can loot the corpse.	
		if (env->query("allow_to_loot")) {
			if (env->query("freeze")) freeze = 180;
				else freeze = 15;
			if (env->query("death_time")+ freeze > time()) {
				if ( member_array( me,env->query("allow_to_loot")) == -1
					&& env->query("victim_name")!= me->query("name"))
						return notify_fail("你现在还不能拿起这件东西。\n");
			}
		}
	
		for(i=0; i<sizeof(inv); i++) {
			
			if( (inv[i]->is_character() && !inv[i]->query("yes_carry")) 
				|| inv[i]->query("no_get") || inv[i]->query("lore")) continue;
			
			if (inv[i]->query("allow_to_loot")) {
			if (inv[i]->query("death_time")+15 > time()) {
				if ( member_array( me,inv[i]->query("allow_to_loot")) == -1
					&& inv[i]->query("victim_name")!= me->query("name"))
						return notify_fail("你现在还不能拿起这件东西。\n");
				}
			}
			do_get(me, inv[i], env);	//modified
		}
		write("Ok。\n");
		return 1;
	}

	if( !objectp(obj = present(arg, env)) || (living(obj) && !(int)obj->query("yes_carry")))
		return notify_fail("你附近没有这样东西。\n");

	if( obj->query("no_get") )
		return notify_fail("这个东西拿不起来。\n");

// 	lore item, you can only own one in your inventory at a time
	if ( obj->query("lore")) {
		my_inv = all_inventory(me);
		for(j=0;j<sizeof(my_inv);j++){
			my_item = my_inv[j];
			if(obj->query("name")==my_item->query("name")
				&& my_item->query("lore"))
			return notify_fail("这样东西你最多只能有一件。\n");
			}
	}

//	15 sec corpse loot protection. Only killer/self can loot the corpse.	
	
	if (env->query("allow_to_loot")) {
		if (env->query("death_time")+15 > time()) {
			if ( member_array( me,env->query("allow_to_loot")) == -1
				&& env->query("victim_name")!= me->query("name"))
				return notify_fail("你现在还不能拿起这件东西。\n");
		}
	}
	if (obj->query("allow_to_loot")) {
		if (obj->query("death_time")+15 > time()) {
			if ( member_array( me,obj->query("allow_to_loot")) == -1
				&& obj->query("victim_name")!= me->query("name"))
				return notify_fail("你现在还不能拿起这件东西。\n");
		}
	}
	
	return do_get(me, obj, env);	//modified
}
	
int do_get(object me, object obj,object env)	//modified
{
	object old_env/*, *enemy*/;
	int equipped;
	object target;
	string	prep;

	target = me;
	if( !obj ) return 0;
	old_env = env;	//modified
	if( obj->is_character()  && !obj->is_corpse()) {
		return notify_fail("你不能背负活物。\n");
		// If we try to save someone from combat, take the risk :P
	} else {
		if( obj->query("no_get") ) return 0;
	}

	
	if (sizeof(all_inventory(me))>=26)
		return notify_fail("你已经带著太多东西了！\n");

	if( obj->query("equipped") ) equipped = 1;
	if( obj->query("yes_carry")) target = environment(me);
	if( obj->move(target) ) {
		if (!obj->query("got_time"))
		{
			obj->set("got_time",time());			
		}
		
		if (obj->query("value")>= 1000
			&& !obj->query("money_id")
			&&  obj->query("material")!="herb")
				log_file("money_item", sprintf("%s worth %d.\n",base_name(obj) ,obj->query("value")));
				
		if((int)obj->query("no_transfer")){
			obj->set("no_get",1); 
			obj->set("no_drop",1);
		}
		if(me->is_fighting()) 
			me->start_busy(1);
		if( obj->is_character()  && !obj->query("yes_carry"))
			message_vision( "$N将$n扶了起来背在背上。\n", me, obj );
		else {
			if(old_env==environment(me)) prep =  "捡起";
			else if(old_env->is_character()) prep =  "从" + old_env->name() + "身上" + (equipped? "除下" : "搜出");
			else switch( old_env->query("prep") ) {
				case "on":
					prep = "从" + old_env->name() + "上拿起";
					break;
				case "under":
					prep = "从" + old_env->name() + "下拿出";
					break;
				case "behind":
					prep = "从" + old_env->name() + "后拿出";
					break;
				case "inside":
					prep = "从" + old_env->name() + "中拿出";
					break;
				default:
					prep = "从" + old_env->name() + "中拿出";
					break;
			};
			message_vision( sprintf("$N%s一%s$n。\n", prep,
				obj->query("unit")), me, obj );
		}
		return 1;
	}
	else return 0;
}


// 覆盖present()这个efun,加入对"name"的比较 by siso_20050606 
object present(mixed str, object env) 
{ 
   object *inv; 
   int n; 

   if( !env->query_max_encumbrance() ) 
       return 0; 
   inv = all_inventory(env); 
   if( !sizeof(inv) ) 
       return 0; 
   if( str ) { 
       str = replace_string(str, "$BLK$", BLK); 
       str = replace_string(str, "$RED$", RED); 
       str = replace_string(str, "$GRN$", GRN); 
       str = replace_string(str, "$YEL$", YEL); 
       str = replace_string(str, "$BLU$", BLU); 
       str = replace_string(str, "$MAG$", MAG); 
       str = replace_string(str, "$CYN$", CYN); 
       str = replace_string(str, "$WHT$", WHT); 
       str = replace_string(str, "$HIR$", HIR); 
       str = replace_string(str, "$HIG$", HIG); 
       str = replace_string(str, "$HIY$", HIY); 
       str = replace_string(str, "$HIB$", HIB); 
       str = replace_string(str, "$HIM$", HIM); 
       str = replace_string(str, "$HIC$", HIC); 
       str = replace_string(str, "$HIW$", HIW); 
       str = replace_string(str, "$NOR$", NOR); 
   } 
   for(n=0; n<sizeof(inv); n++) { 
       if ( str ==  inv[n]->name() || str == (inv[n]->query("id")) ) 
           return  inv[n]; 
   } 
   return efun::present(str, env); 
} 


int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	get <物品名称> [from <容器名>][0m
[0;1;37m────────────────────────────────[0m   
指令格式 : get <物品名称> [from <容器名>]

这个指令可以让你捡起地上或容器内的某样物品. 
物品和容器都既可以使用英文ID也可以使用中文名字。 
如果物品或容器有颜色，请参照以下规则： 

get <颜色代码><物品名称>$NOR$ from <容器> 

<颜色代码> 
$BLK$ - 黑色            $NOR$ - 恢复正常颜色 
$RED$ - 红色            $HIR$ - 亮红色 
$GRN$ - 绿色            $HIG$ - 亮绿色 
$YEL$ - 土黄色          $HIY$ - 黄色 
$BLU$ - 深蓝色          $HIB$ - 蓝色 
$MAG$ - 浅紫色          $HIM$ - 粉红色 
$CYN$ - 蓝绿色          $HIC$ - 天青色 
$WHT$ - 浅灰色          $HIW$ - 白色 
 
相关指令：drop
 
HELP
    );
    return 1;
}
 

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
