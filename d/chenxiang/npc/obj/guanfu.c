// cloth.c
//

#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("知县青蟒官服", ({ "guanfu" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("long", "这是沉香知县官服。\n");
                set("value", 1000);
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        ::init_cloth();
}

