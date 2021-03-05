#include <ansi.h>
inherit __DIR__"annieitem";

void create()
{
	set_name("小塔", ({ "mini pagoda"}) );	// 让这个id有别于其他东西。不使用单字id!
	set_weight(30000);
	set("unit", "个");
	set("desc", "一个小小的石砌宝塔，塔中供的是东岳大帝的塑像。\n");
	set("no_get",1);
	set("no_sell",1);
	set("no_drop",1);
	set("no_stack",1);
	set("no_reset",1);
	set("item_type","n");
	set("size",1);
set("tax",10);
set("score_tax",1);
	set("value", 100000);
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
	if(me->query("sen") <=20)
		return notify_fail("你的神不够。\n");
	message_vision("$N对着小塔膜拜了一下。\n" ,me);
	if( me->query("bellicosity") > 0)
	   me->set("bellicosity",0 );
	message_vision("$N身上的杀孽之气似乎一瞬间消弭无形。\n" , me);
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
