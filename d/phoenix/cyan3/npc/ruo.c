#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
    set_name("苏若", ({ "su ruo","su","suruo" }) );
	set("gender", "女性" );
	set("age", 16);
	set("price_modifier",500);
	set("per",32);
	set("score",-32);

	set("no_fly",1);
	set("no_arrest",1);

	set("nickname",HIR"向羽纱"NOR);
	set("title","西方魔教 "MAG"夜魔坛弟子"NOR);

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


