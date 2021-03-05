
#include <ansi.h>
#include <armor.h>

inherit BOOTS;

void create()
{
	set_name(HIR"魅影神靴"NOR, ({ "ghosty boots", "boots" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("value", 8000);
		set("material", "cloth");
        	set("armor_prop/armor", 5);
	}
	::init_boots();
}
