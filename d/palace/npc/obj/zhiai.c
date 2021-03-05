// icy_band.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIW"白虎之铠"NOR, ({ "white tiger", "ribbon" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("value", 4000);
		set("material", "cloth");
        set("armor_prop/armor", 10);
	}
	::init_head();
}
