#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(RED"饮血平寇大会请柬"NOR, ({ "letter" }) );
	set_weight(500);
	set("lore",1);
	set("unit","封");
	set("long","一封假造得十分逼真的大会请柬，上面书著浓草的几个大字＂清平门下　沐昭光＂。");
	set("desc_ext","参加大会");
    ::init_item();
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
