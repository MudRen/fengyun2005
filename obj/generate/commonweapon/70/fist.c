#include <ansi.h>
#include <weapon.h>
inherit FIST;
void create()
{
    set_name(HIY"黄沙鹰扬"NOR, ({ "claw" }) );
    set_weight(1000);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "对");
//	set("long", "这是一对精铁打造的指套,武林中人常用。\n");
	set("value", 500000);
		set("level_required",70);
	set("weapon_prop/attack",17);
	set("material", "steel");
    }
    init_fist(35);

    set("wield_msg", "$N从怀中摸出一对$n带在手上。\n");
    set("unwield_msg", "$N将手上的$n拿下来藏入怀中。\n");


}
