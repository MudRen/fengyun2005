#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
	set_name("北星挂坠", ({ "amulet" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "stone");
		set("unit", "条");
		set("long", "一条美丽的挂坠。\n");
		set("armor_prop/intelligence",3);
		set("armor_prop/karma",3);
		set("value",10000);
	}
	::init_neck();
}

