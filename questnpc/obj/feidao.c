// throwing_knife.c

#include <weapon.h>

inherit THROWING;

void create()
{
        set_name("飞刀", ({ "throwing knife", "knife" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "些");
                set("base_unit", "把");
                set("base_weight", 200);
                set("base_value", 40);
                set("material", "iron");
                set("long",     "一把薄薄的刀片，长四寸二分，重六两九钱。\n");
                set("volumn",50);
        }
        set_amount(50);
        init_throwing(25);
        setup();
}
