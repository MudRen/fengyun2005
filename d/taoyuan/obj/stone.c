#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("大山石", ({ "stone" , "大山石"}) );
	set_weight(50000);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep", "behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "山石不知道有多大，露出地面的约有两三人高。石头的表面爬满石苔，依稀\n" +
		"可辨 “桃源村” 三个大字。仔细看下面还有几行小字。\n\n"
		YEL"  桃源乃祖先传下远避兵灾之地。此中人们安居乐业，崇尚和平。\n"NOR
		YEL"  世间的江湖恩怨一入此地，尽应全部抛弃。所有恩仇务必于桃源\n"NOR
		YEL"  以外解决。桃源历经百年，并无纷争风雨。人们爱护固然是原因，\n"NOR
		YEL"  更有高人侠士相与维护，匡助和平。\n\n"NOR
		YEL"  在桃源行凶者将被侠客追杀，莫谓言之不豫。\n\n"NOR
		);
		set("long_night", "山石不知道有多大，露出地面的约有两三人高。石头的表面爬满石苔，依稀\n" +
		"可辨 “桃源村” 三个大字。\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }
