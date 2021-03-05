#include <ansi.h>
#include <weapon.h>
inherit FIST;

void create() {
	set_name("锋锐指甲", ({ "nail" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "对");
		set("long", "一对做工粗糙的青铜指甲。\n");
		set("material", "bronze");
		set("female_only",1);
		set("annie/for_kaleidostrike",1);
	}
	::init_fist(15);	// 最好的指甲.
}

int init()
{
	set("weapon_wielded","指尖套");
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
