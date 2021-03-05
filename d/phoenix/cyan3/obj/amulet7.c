#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
	set_name("黝黑的项链", ({ "necklace" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("material", "stone");
		set("unit", "条");
		set("long", "一条落满尘土的黝黑的项链，不知道已在陶罐里躺了多少年。\n");
		set("armor_prop/perception",8);
		set("value",0);
	}
	::init_neck();
}

