// hammer.c

#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("狼牙棒", ({ "mace" }) );
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把沉甸甸的狼牙棒,犬牙交错,霸道异常.。\n");
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N双手使力，举起一柄狼牙棒，竟有万夫莫挡之势．\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        ::init_staff(20);
}
