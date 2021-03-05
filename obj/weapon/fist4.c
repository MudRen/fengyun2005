//  An example non-weapon type of weapon
// fist,fist1,fist2....数字越高，dmg越高

#include <weapon.h>
#include <ansi.h>
inherit FIST;
void create()
{
    set_name(HIY"金纹"NOR+HIW"银爪"NOR, ({ "gold claw","claw" }) );
    set_weight(3000);
    if( clonep() )
	set_default_object(__FILE__);
    else {
	set("unit", "对");
	set("long", "这是一对雕着金色花纹的白银爪，做工细致精巧，显然主人不是寻常人等。\n");
	set("value", 1);
	set("material", "steel");
    }
    init_fist(10);

    set("wield_msg", "$N从怀中摸出一对$n带在手上。\n");
    set("unwield_msg", "$N将手上的$n拿下来藏入怀中。\n");


}
