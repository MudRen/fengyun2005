#include <ansi.h>
inherit ITEM;

#define MAX_ITEM 130

int do_put(object me, object obj, object dest);
int do_get(object me, object ob, object env);	

void create()
{
	set_name("垃圾堆", ({ "stack field"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set_max_encumbrance(8000000);
	set("unit", "个");
	set("prep","in");
	set("desc", "一个用来堆垃圾的垃圾堆。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("outdoors",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","a");
	set("size",3);
	set("lore_item",1);
	set("value", 250000);
	seteuid(getuid());
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



int is_container() {return 1;}
int is_closed(){	return userp(environment());}

void init()
{
	if (environment() == this_player())
	   	add_action("do_install","install");
	else 
	{
	add_action("do_putitem","put");
	add_action("do_getitem","get");
	}
   	add_action("do_look","look");
   	add_action("do_dismantle","dismantle");
}

int reset_item_list(object dest);

int do_dismantle(string arg)
{
	object me = this_player(),env=environment(me),ob=this_object();
	object *inv;
	object box,item;
	mapping item_list;
	string *lists,mitem;
	int i,idx;
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
	if (!env)
		return notify_fail("错误#13106。\n");	// 天知道是什么意思...ppl report的时候当search index
	if (!env->is_owner(me->query("id")))
		return notify_fail("家庭用品只能由屋子的主人拆除。\n");
	if (!present("dismantle statue",me))
		return notify_fail("你没有合适的工具以进行拆除。\n");
	item_list = env->query("item_list");
	if( !mapp(item_list) || !sizeof(item_list) )
		return notify_fail("错误#13108。\n");	// 天知道是什么意思...ppl report的时候当search index
	message_vision(CYN"$N一提气，扬起毁灭石像向"+name()+"上砸去，不两下就把"+name()+"砸得稀烂。\n\n"NOR,me);
//	env->add("item_index",-1);	
	inv = all_inventory(ob);
	while (sizeof(inv))
	{
		inv = all_inventory(ob);
		destruct(inv[0]);
	}
	ob->reset_item_list(ob);

	lists = keys(item_list);
	for(i=0; i<sizeof(lists); i++)
	{
		if (!sscanf(lists[i],"%d",idx))	continue;
		mitem = env->query("item_list/"+lists[i]);
		if (mitem == base_name(ob))
			env->delete("item_list/"+lists[i]);
	}
	env->add("item/"+query("item_type"),-1);
	env->add("free_space",query("size"));
	env->save();
	destruct(present("dismantle statue",me));
	destruct(ob);
	return 1;	
}

int do_look(string arg)
{

	mixed *inv;
	string *apply, msg, prep;
	mapping prop;
	int i;
    object obj;
              
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
	set("long",query("desc"));
	if (wizardp(this_player()))
		set("long",query("desc")+"仔细看去，隐约可见几个小字：江门铸造。\n");


        obj = this_object();  
        write(obj->long());
        
        inv = all_inventory(obj);
                switch((string)obj->query("prep")) {
                        case "on":
                                prep = "上";
                                break;
                        case "under":
                                prep = "下";
                                break;
                        case "behind":
                                prep = "后";
                                break;
                        case "inside":
                                prep = "里";
                                break;
                        default:
                                prep = "里";
                                break;
                        }

		write("这里面有：\n");
		for (i=0; i<sizeof(inv); i++)
			write(inv[i]->short()+"\n");
		

		return 1;
}


int do_install(string arg)
{
	object me = this_player(),env=environment(me),ob=this_object();
	if (!arg)
		return notify_fail("你要安装什么东西？\n");
	if (present(arg,me) != ob)
		return 0;
	if (!env)
		return notify_fail("错误#13107。\n");	// 天知道是什么意思...ppl report的时候当search index
	if (!env->is_owner(me->query("id")))
		return notify_fail("家庭用品只能由屋子的主人放置。\n");
	if (env->query("free_space") - query("size") < 0)
		return notify_fail("屋子里没有足够的空间可以放置"+name()+"。\n");
	if (env->query("outdoors") && !query("outdoors") )
		return notify_fail(name()+"只能被放置在室内。\n");
	if (!env->query("outdoors") && query("outdoors") )
		return notify_fail(name()+"只能被放置在室外。\n");
	if (query("lore_item") && env->query("item/"+query("item_type")))
		return notify_fail("这类东西每间屋子里只能放一个。\n");
	move(env);
	env->add("item_index",1);
	env->add("item/"+query("item_type"),1);
	env->add("free_space",-query("size"));
	env->set("item_list/"+env->query("item_index"),base_name(ob));
	env->save();
	write("Ok.\n");
	return 1;	
}

int reset_item_list(object dest)
{
	return 1;
}

int do_getitem(string arg)
{
	object me = this_player(),env=this_object();
	string from, item;
	object obj, *inv,  obj2;
	object *my_inv, my_item;
	int i, j, amount, num;
	string arg1, from1;

	if( !arg ) return notify_fail("你要捡起什麽东西？\n");
	if( me->is_busy() )
		return notify_fail("你上一个动作还没有完成！\n");

// prevent people using get xyz from wall 0 
// prevent people using get xyz from wall 1
	if ( sscanf(arg, "%s from %s %d", arg1, from1, num)==3) {
		if (num==0 || num ==1)
			return notify_fail("不必或不能使用get xxx from xxx 0/1。\n");
	}

	if( sscanf(arg, "%s from %s", arg, from)!=2 )
		return 0;
		// 丢给正常get指令处理
	if (present(from,environment(me)) != env)
		return 0;

	if (!environment()->is_owner(me->query("id")))
	{
		tell_object(me,"屋子里的物件只有主人才能使用。\n");
		return 1;
	}

	
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
			return do_get(me, obj, env);	
		} else {
			obj->set_amount( (int)obj->query_amount() - amount );
			obj2 = new(base_name(obj));
			obj2->set_amount(amount);
			obj2->move(me);		
			// Counting precise amount costs more time.
			if( me->is_fighting() ) me->start_busy(3);
			return do_get(me, obj2, env);	
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
			if (env->query("death_time")+15 > time()) {
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
			do_get(me, inv[i], env);	
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
	
	return do_get(me, obj, env);	
}


int do_get(object me, object obj,object env)	
{
	object old_env, *enemy;
	int equipped;
	object target;
	string	prep;

	target = me;
	if( !obj ) return 0;
	old_env = env;	
	if( obj->is_character()  && !obj->is_corpse()) {
		return notify_fail("你不能背负活物。\n");
		// If we try to save someone from combat, take the risk :P
	} else {
		if( obj->query("no_get") ) return 0;
	}

	if( obj->query("equipped") ) equipped = 1;
	if( obj->query("yes_carry")) target = environment(me);
	if( obj->move(target) ) {
		if((int)obj->query("no_transfer")){
			obj->set("no_get",1); 
			obj->set("no_drop",1);
		}

		reset_item_list(this_object());

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
					prep = "在" + old_env->name() + "中翻找半天，淘出";
					break;
				default:
					prep = "在" + old_env->name() + "中翻找半天，淘出";
					break;
			};
			message_vision( sprintf("$N%s一%s$n。\n", prep,
				obj->query("unit")), me, obj );
		}
		return 1;
	}
	else return 0;
}


int do_putitem(string arg)
{
	object me = this_player(),dest=this_object();
	string target, item;
	object obj, *inv, obj2;
	int i, amount;

	if(!arg) return notify_fail("你要将什麽东西放进哪里？\n");

	if( sscanf(arg, "%s in %s", item, target)!=2 )
		return notify_fail("你要给谁什麽东西？\n");

	if (present(target,environment(me)) != dest)
		return 0;
	


	if(sscanf(item, "%d %s", amount, item)==2) {
		if( !objectp(obj = present(item, me)) )
			return notify_fail("你身上没有这样东西。\n");
		if( !obj->query_amount() )
			return notify_fail( obj->name() + "不能被分开。\n");
		if( amount < 1 )
			return notify_fail("东西的数量至少是一个。\n");
		if( amount > obj->query_amount() )
			return notify_fail("你没有那麽多的" + obj->name() + "。\n");
		else if( amount == (int)obj->query_amount() )
			return do_put(me, obj, dest);
		else {
				obj2 = new(base_name(obj));
				obj2->set_amount(amount);
				if (do_put(me, obj2, dest))
				{
					obj->set_amount( (int)obj->query_amount() - amount );
					return 1;
				}		
				if (obj2) destruct(obj2);
				return 0;
		}
	}

	if(item=="all")
	{
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if( inv[i] != dest  && !inv[i]->query("no_drop")) 
			do_put(me, inv[i], dest);
		write("Ok.\n");
		return 1;
	}

	if(!objectp(obj = present(item, me)))
		return notify_fail("你身上没有这样东西。\n");
	return do_put(me, obj, dest);
}


int do_put(object me, object obj, object dest)
{
	string prep;
	int container_size;
	mixed *info;
	info = filter_array(call_out_info(), (: $1[0]==$2 :), obj);
	
    if((int) obj->query("no_drop") ||(int) obj->query("no_get")||obj->query("lore"))
                return notify_fail("你不可以这么做。\n");
	if (obj->is_container())
		return notify_fail("你不能把容器放在另一个容器里。\n");	

	if( obj == dest)
			return notify_fail("你不可以这么做。\n");
	
	if(dest->is_closed())
		return notify_fail("你要先把" + dest->name() + "打开。\n");

	container_size = MAX_ITEM;

	// 这里有别于普通put指令，因此不能return notify_fail。 annie 08.2003
	// <--------------------------------------------------------------
	if (!environment()->is_owner(me->query("id")))
	{
		tell_object(me,"屋子里的物件只有主人才能使用。\n");
		return 1;
	}
	if(sizeof(all_inventory(dest)) >= container_size)
	{
		tell_object(me,dest->name() + "里面最多只能放" + chinese_number(container_size) +
				"件物品。\n");
		return 1;
	}
/*	if (obj->query("value") < 4)	// 无法典当的东西被认为是unique item。
	{
		tell_object(me,"这样东西并不值多少钱，没有小心保存的必要。\n");
		return 1;
	}*/
	// NO STOCK物品不能存放。
	if (obj->query("no_stack"))
	{
		tell_object(me,"这样东西无法存放。\n");
		return 1;
	}
	// -------------------------------------------------------------->
	
	switch((string)dest->query("prep")) {
		case "on" :
			prep = "扔进" + dest->name() + "上";
			break;
		case "under" :
			prep = "扔进" + dest->name() + "下";
			break;
		case "behind" :
			prep = "扔进" + dest->name() + "后面";
			break;
		case "insdie" :
			prep = "扔进" + dest->name() + "里";
			break;
		default :
			prep = "扔进" + dest->name() + "里";
			break;
	}
	if( obj->move(dest) ) {
		message_vision( sprintf("$N把一%s%s%s。\n",
			obj->query("unit"), obj->name(), prep),
			me );
		if(obj->query("no_drop") || obj->query("no_get")|| obj->query("lore"))
			dest->add("no_give",1);


		reset_item_list(dest);
		return 1;
	}
	else return 0;
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
