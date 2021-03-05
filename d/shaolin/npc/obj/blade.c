// sword.c : an example weapon

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("长刀", ({ "blade" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看起相当普通的长刀，份量大约有十来斤左右。\n");
		set("value", 400);
		set("material", "steel");
	}
	init_blade(25);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一声抽出一把$n握在手中。\n");
	set("unwield_msg", "$N将手中的$n插入腰间的刀鞘。\n");


}
