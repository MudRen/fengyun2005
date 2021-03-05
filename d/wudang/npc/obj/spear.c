#include <weapon.h>
inherit SPEAR;

void create()
{
	set_name("长枪", ({ "spear" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把看起相当普通的长枪，份量大约有十来斤左右。\n");
		set("value", 1000);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入地下。\n");
	}
	::init_spear(20);
}
