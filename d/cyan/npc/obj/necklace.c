#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
	set_name("石佛珠", ({ "necklace" }) );
	set_weight(100000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "stone");
		set("unit", "条");
		set("long", "一条由庞大的石佛珠连成的挂串。\n");
		set("value",1);
	}
	::init_neck();
}

