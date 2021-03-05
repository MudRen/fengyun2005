//  An example non-weapon type of weapon
// fist,fist1,fist2....数字越高，dmg越高

#include <weapon.h>
inherit FIST;
void create()
{
    set_name("梅花扣", ({ "meihua fist","fist" }) );
    set_weight(1500);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "对");
	set("long", "这是一对打造精致的梅花扣，指孔处被打磨的十分光滑，一看就知道出自名家之手\n");
	set("value", 1);
	set("material", "steel");
    }
    init_fist(10);

    set("wield_msg", "$N从怀中摸出一对$n带在手上。\n");
    set("unwield_msg", "$N将手上的$n拿下来藏入怀中。\n");


}
