#include <weapon.h>
inherit FIST;
void create()
{
    set_name("如意追魂手", ({ "ironfist" }) );
    set_weight(1000);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "对");
//	set("long", "这是一对精铁打造的指套,武林中人常用。\n");
	set("value", 400000);
		set("level_required",50);
	set("weapon_prop/attack",15);
	set("material", "steel");
    }
    init_fist(30);

    set("wield_msg", "$N从怀中摸出一对$n带在手上。\n");
    set("unwield_msg", "$N将手上的$n拿下来藏入怀中。\n");


}
