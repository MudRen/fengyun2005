
#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("圆月弯刀", ({ "moonblade" }) );
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把弯如月牙儿蕃刀");
                set("value", 200);
                set("material", "steel");

        set("wield_msg", "$N从腰间抽出一把亮闪闪的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n别在腰间。\n");
        }
        ::init_blade(10);
}

