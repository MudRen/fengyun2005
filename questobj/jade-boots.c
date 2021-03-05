// icy_boot.c

#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name( HIC "觇玉软靴" NOR, ({ "jade-boots", "boots" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 8000);
        set("reward", 1);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("armor_prop/dodge", 5);
	}
	::init_boots();
}
