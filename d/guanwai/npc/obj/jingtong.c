// hammer.c

#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("转经筒", ({ "jingtong","tong" }) );
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个小小的圆筒，上面密密麻麻地刻着经文。\n");
                set("value", 60000);
                set("material", "iron");
                set("wield_msg", "$N拿出一个$n握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        ::init_hammer(1);
}
