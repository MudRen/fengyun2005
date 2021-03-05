
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("断树枝", ({ "shu zhi" }) );
	set_weight(10);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "一根两尺长的树枝，切口十分工整。\n");
		set("value", 200);
		set("material", "steel");
		set("rigidity", 200);
		set("wield_msg", "$N从腰间拔出一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插在腰间。\n");
	}
	::init_sword(2);
}
