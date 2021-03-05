#include <weapon.h>
inherit HAMMER;
void create()
{
        set_name("巨钟", ({ "giant bell" }) );
        set_weight(1000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long", "铸于金章宗太和年间，口沿八唇，上铸八卦，重一万一千斤\n");
                set("value", 3);
                set("material", "iron");
        }
        init_hammer(200);
}
