//  An example non-weapon type of weapon
// fist,fist1,fist2....数字越高，dmg越高

#include <weapon.h>
inherit FIST;
void create()
{
    set_name("精钢爪", ({ "claw" }) );
    set_weight(1500);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "对");
	set("long", "这是一对精钢打造的钢爪,看得出锻造的人花费了些心思。\n");
	set("value", 1);
	set("material", "steel");
    }
    init_fist(10);

    set("wield_msg", "$N从怀中摸出一对$n带在手上。\n");
    set("unwield_msg", "$N将手上的$n拿下来藏入怀中。\n");


}
