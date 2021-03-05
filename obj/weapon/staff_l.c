// staff.c : Gun zi

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("熟铜棍", ({ "staff" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是一根沙场军兵用的熟铜棍。\n");
                set("value", 1);
                set("material", "copper");
        }
        init_staff(2);
}
