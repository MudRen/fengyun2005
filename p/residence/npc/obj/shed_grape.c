#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("葡萄藤棚架", ({ "grape shed"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set_max_encumbrance(10000);
	set("prep","on");
	set("unit", "个");
	set("desc", "一个木棚子，架上爬满了翠绿色的葡萄藤，试着摘摘看（pick grape）\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","j");
//	set("outdoors",1);
	set("size",1);
set("tax",10);
set("score_tax",2);
	set("value", 1000000);
	seteuid(getuid());
}

int is_container(){	return 1;}

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
	
	write("请保持环境清洁，不要将垃圾望"+name()+"里乱丢。\n");
	return 1;
}


int reset_item_list(object dest)
{
	return 1;
}


int do_pick(string arg)
{
 	object me = this_player(),env=environment(me),ob=this_object(),herb,*inv;

	if (!env->is_owner(me->query("id")))
		return notify_fail("屋子里的物件只有主人才能使用。\n");
	if (!arg)
		return 0;
	if (arg != "grape" && arg!="葡萄")
		return 0;
	if (query("pick_time") + 3600 > time())
		return notify_fail("架上只有葡萄藤了．．．\n");

	inv = all_inventory(ob);
	if (sizeof(inv))
		return notify_fail( "葡萄藤棚架上已经有些碎玉葡萄被摘下来了。\n");

	message_vision(CYN"\n$N从葡萄藤棚架上摘下了一些青碧如玉的碎玉葡萄。\n"NOR, me);
	set("pick_time",time());
	herb = new(__DIR__"grape.c");
	herb->set_amount(1);
	herb->move(ob);
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
