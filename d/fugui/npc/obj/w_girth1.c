// cloth.c
//

#include <armor.h>

inherit WAIST;
#include <ansi.h>
void create()
{
    	set_name(HIC"镂银宫绦"NOR , ({ "silvergirth" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");

		set("long","缠在身上，顿时腰若约素，婀娜多姿。\n");
		set("material", "cloth");
		set("value", 1000);
		set("female_only", 1);
	}
	::init_waist();
}
