// icy_girth.c

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
    set_name(HIW"白布头"NOR, ({ "whitetowel" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
        set("long", "一条浸渍满血迹的白布头。\n");
		set("value", 700);
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
    ::init_head();
}
