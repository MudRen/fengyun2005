#include <weapon.h>
inherit FIST;
void create()
{
    set_name("精钢爪", ({ "claw" }) );
    set_weight(1000);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "对");
//	set("long", "这是一对精铁打造的指套,武林中人常用。\n");
	set("value", 20000);
		set("level_required",20);
	set("weapon_prop/attack",7);
	set("material", "steel");
    }
    init_fist(15);

    set("wield_msg", "$N从怀中摸出一对$n带在手上。\n");
    set("unwield_msg", "$N将手上的$n拿下来藏入怀中。\n");


}
