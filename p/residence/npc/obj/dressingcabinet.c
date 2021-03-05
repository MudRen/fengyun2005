#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("明镜妆台", ({ "dressing table"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set("unit", "座");
	set("desc", "一座放着盈盈明镜的妆台。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","n");
	set("size",1);
	set("value", 100000);
set("tax",10);
set("score_tax",1);
	seteuid(getuid());
}

void init()
{
	::init();
	if (environment() != this_player())
	   	add_action("do_makeup","makeup");
}



int do_makeup(string arg)
{
	object me = this_player(),env=environment(me),ob=this_object();
	if (!env->is_owner(me->query("id")))
		return notify_fail("屋子里的物件只有主人才能使用。\n");
	if (me->is_fighting() || me->is_busy()) return 1;
	if (me->query("gender") != "女性")
		return notify_fail("大男人扭扭捏捏的妆扮甚么？\n");
	message_vision(CYN"$N坐到妆台前，对着明镜仔细地打扮着自己。\n"NOR, me);
	// 画眉?
	if (!me->query_temp("annie/prup"))
		me->add_temp("apply/personality",1);
	me->set_temp("annie/prup",1);
	me->perform_busy(1);
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
