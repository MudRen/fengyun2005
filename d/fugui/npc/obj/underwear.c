
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("小短裤", ({ "short trousers","trousers" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("value", 100);
                set("armor_prop/armor", 1);
        }
        ::init_cloth();
}

