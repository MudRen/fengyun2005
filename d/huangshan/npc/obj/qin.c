#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("古木琴", ({ "muqin" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把外表古色古香，但是内包精铁的六弦琴。（琴质40）\n");
                set("value", 10);
                set("material", "iron");
                set("wield_msg","$N从怀里取出一张$n，信手一划，泉水般的琴声从指尖流泻而出。\n");
		set("unwield_msg","$N将$n收起在身后。\n");
		set("timbre",40);
        }

        ::init_hammer(20);
}
