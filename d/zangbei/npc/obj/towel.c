#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name("头巾", ({ "towel" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
        set("long", "一条缠在头上的白毛巾。\n");
		set("value", 200);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
    ::init_head();
}
