
#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
	set_name(HIC"开山斧"NOR, ({ "huge axe", "axe" }) );
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "一把车轮大小的板斧。\n");
		set("value", 60);
		set("material", "iron");
		set("wield_msg", "$N拿出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n抗在肩上。\n");
	}

	::init_axe(15);
}
