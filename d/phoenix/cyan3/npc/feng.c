#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
    set_name("凤铭心", ({ "feng minxin","feng","minxin" }) );
	set("gender", "女性" );
	set("age", 16);
	set("price_modifier",500);
	set("per",32);
	set("score",-32);

	set("no_fly",1);
	set("no_arrest",1);

	set("nickname",WHT"烟花故人"NOR);
	set("title","西方魔教 "MAG"空魔坛坛主"NOR);

	set("combat_exp", 2000000);
	set("attitude", "friendly");
	
		setup();

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


