
#include <weapon.h>
#include <ansi.h>
inherit SPEAR;

void create()
{
	set_name(HIW"银白色的长枪"NOR, ({ "silver spear" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把银光闪闪的长枪，份量大约有十来斤左右。\n");
		set("value", 400);
		set("material", "steel");
		set("wield_msg", "$N「唰」地一声把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入地下。\n");
	}
	::init_spear(15);
}
