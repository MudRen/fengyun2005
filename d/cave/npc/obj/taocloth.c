
#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
    set_name(HIB"蓝色道袍"NOR, ({ "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
        set("armor_prop/armor", 10);
        set("value", 3);
	}
	::init_cloth();
}
