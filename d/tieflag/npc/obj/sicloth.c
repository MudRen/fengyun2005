// cloth.c

#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("丝衣", ({"cloth"}) );
    set("long","柔丝所制轻柔华丽的花衫。\n");
    set_weight(500);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "件");
        set("material", "cloth");
        set("armor_prop/armor", 5);
    set("value",20);
    }
    ::init_cloth();
}
