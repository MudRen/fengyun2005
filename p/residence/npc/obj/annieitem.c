#include <ansi.h>
inherit ITEM;
inherit F_ANNIE;

int do_put(object me, object obj, object dest);
int do_get(object me, object ob, object env);	

void init()
{
	if (environment() == this_player())
	   	add_action("do_install","install");
	else 
	{
		add_action("do_putitem","put");
		add_action("do_getitem","get");
		add_action("do_pick","pick");
	}

   	add_action("do_look","look");
   	add_action("do_dismantle","dismantle");
}

int is_container()
{
	return 0;
}

int do_pick(string arg)
{
	return 0;
}

int is_closed()
{
	if (!environment()) return 1;	
	return userp(environment());
}

int restore_item()
{
	object item;
	mapping item_list,mitem;
	string *lists,str;
	int i,idx;

	item_list = environment()->query("stock_"+query("item_type"));
	if( !mapp(item_list) || !sizeof(item_list) )
			return 1;
	// 没有任何东西。
	lists = keys(item_list);
	for(i=0; i<sizeof(lists); i++)
	{
       if (!sscanf(lists[i],"%d",idx)) continue;
		mitem = environment()->query("stock_"+query("item_type")+"/"+lists[i]);
		item = new(mitem["item_basename"]);
		annie_itemmimic(item,mitem["data"],mitem["temp_data"]);
		item->set_name(mitem["item_name"],mitem["item_id"]);
		item->set_amount(mitem["amount"]);
		item->move(this_object());
	}
	return 1;
}


int reset_item_list(object dest)
{
	object room = environment(),obj,*inv;
	mapping item_list,item;
	mapping list,tlist;
	int i,j;
	if (!is_container())
		return 1;

	inv = all_inventory(dest);
	i = sizeof(inv);
	room->delete("stock_"+query("item_type"));
	for (j=0;j<i ;j++ )
	{
		obj = inv[j];
		list = (mapping)obj->query_entire_dbase();
		tlist = (mapping)obj->query_entire_temp_dbase();

			item =
			([
				"item_basename": base_name(obj),
				"data":list,
				"temp_data":tlist,
				"item_name": obj->query("name"),
				"item_id": obj->parse_command_id_list(),
				"amount": obj->query_amount(),
			]);
		room->set(("stock_"+query("item_type"))+"/"+(j+1),item);
	}
	room->save();
	return 1;
}

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
		return notify_fail("你没有合适的工具进行拆除，需要毁灭石像。\n");
	item_list = env->query("item_list");
	if( !mapp(item_list) || !sizeof(item_list) )
		return notify_fail("错误#13108。\n");	// 天知道是什么意思...ppl report的时候当search index
	message_vision(CYN"$N一提气，扬起毁灭石像向"+name()+NOR+CYN"上砸去，不两下就把"+name()+NOR+CYN"砸得稀烂。\n\n"NOR,me);
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
	
	// 这里需要说明一点,凡是使用此参数的annieitem必须是“lore”类型，否则会冲突。
	env->delete("stock_"+query("item_type")+"/text");
	env->delete("stock_"+query("item_type")+"/text2");
	env->delete("stock_"+query("item_type")+"/text3");
	
	
	env->add("item/"+query("item_type"),-1);
	env->add("free_space",query("size"));

	env->add("tax",-query("tax")*7);
	env->add("score_tax",-query("score_tax")*100);

	if (env->query("tax")<0)
		env->set("tax",0);	// 防bug
	if (env->query("score_tax")<0)
		env->set("score_tax",0);	// 防bug
	
	if (query("item_type") == "k")
	{
		// 水源
		env->set("resource/water",0);
	    env->delete("liquid");
	}

	env->save();

	destruct(present("dismantle statue",me));
	destruct(ob);
	return 1;	
}

int do_look(string arg)
{
	if (!arg)
		return 0;
	if (present(arg,environment()) != this_object())
		return 0;
	set("long",query("desc"));
//	if (wizardp(this_player()))
//		set("long",query("desc")+"仔细看去，隐约可见几个小字：江门铸造。\n");
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
//	if (env->query("outdoors") && !query("outdoors") )
//		return notify_fail(name()+"只能被放置在室内。\n");
//	if (!env->query("outdoors") && query("outdoors") )
//		return notify_fail(name()+"只能被放置在室外。\n");
	if (query("lore_item") && env->query("item/"+query("item_type")))
		return notify_fail("这类东西每间屋子里只能放一个。\n");
	move(env);
	env->add("item_index",1);
	env->add("item/"+query("item_type"),1);
	env->add("free_space",-query("size"));

	env->add("tax",query("tax")*7);
	env->add("score_tax",query("score_tax")*100);

	env->set("item_list/"+env->query("item_index"),base_name(ob));

	if (query("item_type") == "k")
	{
		// 水源
		env->set("resource/water",1);
	    env->set("liquid",query("liq"));
	}

	env->save();
	write("物品安装完毕。\n");
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

	if (!is_container())
		return notify_fail("这不是容器。\n");

	if (sizeof(all_inventory(me))>=26)
		return notify_fail("你已经带著太多东西了！\n");


	
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
	
		for(i=0; i<sizeof(inv); i++) {
			
			if( (inv[i]->is_character() && !inv[i]->query("yes_carry")) 
				|| inv[i]->query("no_get") || inv[i]->query("lore")) continue;
			
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

		if (sizeof(all_inventory(me))>=26)
		return notify_fail("你已经带著太多东西了！\n");


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
	
	if (!is_container())
		return notify_fail("这不是容器。\n");

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
			{
//				write("1"+inv[i]->query("name"));
				do_put(me, inv[i], dest);
			}
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

	container_size = query("max_item");

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
	// 钱不能存放。
	// TASK不能存放。
	// 有CALL OUT的东西不能存放。
	if (obj->query("no_stack"))
	{
		tell_object(me,"这样东西无法存放。\n");
		return 1;
	}
	if (obj->query("money_id"))
	{
		tell_object(me,"这样东西无法存放。\n");
		return 1;
	}
	if (obj->query("dynamic_quest"))
	{
		tell_object(me,"这样东西无法存放。\n");
		return 1;
	}
	if (sizeof(info))	
	{
		tell_object(me,"这样东西无法存放。\n");
		return 1;
	}


	if( obj->query("generate_item") )
		return notify_fail("这种东西只能存放在黑色的大箱子中。\n");

//	Now we just use 大箱子 to save all temperary items

/*	if (!obj->query("armor_prop") && query("item_type") == "c")				// 衣橱
	{
		tell_object(me,name()+"里只能存放衣物。\n");
		return 1;
	}

	if (!obj->query("weapon_prop") && query("item_type") == "b")			// 兵器架
	{
		tell_object(me,name()+"里只能存放武器。\n");
		return 1;
	}

	if (!obj->query("skill/max_skill") && query("item_type") == "d")		// 书橱
	{
		tell_object(me,name()+"里只能存放书籍。\n");
		return 1;
	}

	if (!obj->query("food_supply") && !obj->query("liquid") && query("item_type") == "e")		// 食橱
	{
		tell_object(me,name()+"里只能存放食水。\n");
		return 1;
	}

	if ((obj->query("food_supply") || obj->query("liquid") || obj->query("weapon_prop") 		// others in 大木箱
		 || obj->query("armor_prop")  || obj->query("skill/max_skill")) &&  query("item_type") == "f")
	{
		tell_object(me,obj->name()+"更适合放到专用的地方，不要与杂物丢在一起。\n");
		return 1;
	}*/

	// -------------------------------------------------------------->
	
	switch((string)dest->query("prep")) {
		case "on" :
			prep = "放在" + dest->name() + "上";
			break;
		case "under" :
			prep = "放在" + dest->name() + "下";
			break;
		case "behind" :
			prep = "放在" + dest->name() + "后面";
			break;
		case "insdie" :
			prep = "放进" + dest->name() + "里面";
			break;
		default :
			prep = "放进" + dest->name() + "里面";
			break;
	}
	if( obj->move(dest) ) {
		message_vision( sprintf("$N将一%s%s%s。\n",
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
