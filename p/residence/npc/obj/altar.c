#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("神坛", ({ "myth altar"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set("unit", "个");
	set("desc", "一个不知道供着什么的神坛，坛上燃着几炷香，整间屋檀香袅袅（kneel）\n");
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
	   	add_action("do_kneel","kneel");
}



int do_kneel(string arg)
{
	object me = this_player(),env=environment(me),ob=this_object();
	if (!env->is_owner(me->query("id")))
		return notify_fail("屋子里的物件只有主人才能使用。\n");
	if (!arg)
		return 0;
	if (present(arg,env) != ob)
		return 0;
	if (me->is_fighting() || me->is_busy()) return 1;
	me->remove_all_killer();
	message_vision("$N跪倒在地，决定忘记以前所有的仇家．\n",me);
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
