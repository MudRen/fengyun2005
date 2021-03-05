// annie 07.2003
// dancing_faery@hotmail.com
//萧青湘
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("石牌", ({ "石牌" , "牌", "峰上","山岩"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
//		set("long", "石牌上凿的是：\n[34m山高摩世界\n水深流古今\n公候将相今何在\n百年唯有山水存\n若离开酒色财气\n便堪为当世神仙\n\n[32m");
		set("long", "石牌上凿的是：\n\n"MAG"　　　　水　　山\n　　　　连　　接\n　　　　青　　远\n　　　　峰　　天\n　　　　一　　无\n　　　　脉　　穷\n　　　　幽　　碧\n\n"NOR);
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

