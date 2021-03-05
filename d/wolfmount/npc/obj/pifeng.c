#include <armor.h>

inherit SURCOAT;

void create()
{
    set_name("狼皮披风", ({"wolf pifeng", "pifeng"}));
	set_weight(2500);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "一件用野狼皮缝制而成的披风。\n");
		set("material", "leather");
		set("unit", "件");
		set("value", 700);
		set("armor_prop/armor", 10);
	}
	::init_surcoat();
}
