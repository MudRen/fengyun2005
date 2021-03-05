// knife.c

#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("碧玉刀", ({ "knife" }) );
        set_weight(6500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把当年张家老祖宗退隐时皇上赐的宝刀\n");
                set("value", 200);
                set("material", "crimsonsteel");
        set("wield_msg", "$N从腰间抽出一把亮闪闪的$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n别在腰间。\n");
        }

        ::init_dagger(15);


}

