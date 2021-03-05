
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("太极五行袍", ({ "cloth" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 15);
	}
  ::init_cloth();
}
