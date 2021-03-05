//  An example non-weapon type of weapon

#include <weapon.h>
inherit FIST;

void create()
{
	set_name("铁掌", ({ "ironfist" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "这是一对精铁打造的铁掌。\n");
		set("value", 50);
		set("material", "steel");
		set("level_required",25);
	}
	init_fist(40);
	set("wield_msg", "$N从怀中摸出一对$n带在手上。\n");
	set("unwield_msg", "$N将手上的$n拿下来藏入怀中。\n");


}
