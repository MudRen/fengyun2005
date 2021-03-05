#include <weapon.h>
inherit BLADE;

void create() {
        set_name("细长的竹叶", ({ "zhuye" }) );
        set_weight(400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 10);
                set("material", "bamboo");
                set("long", "这是一条细长的竹叶，叶缘锋锐如刀。\n");
                set("wield_msg", "$N将$n交到右手。\n");
                set("unequip_msg", "$N将$n移到左手。\n");
        }
        ::init_blade(25);
}


int init()
{
        set("weapon_wielded","持");
}

