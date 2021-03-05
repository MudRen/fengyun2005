#include <armor.h>
inherit CLOTH;

void create()
{
    set_name("白罗袍", ({"silk cloth", "cloth"}));
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else 
    {
        set("long","一件白色的丝袍，质地精良，裁剪精细，看起来别有风姿。\n");
        set("material", "cloth");
        set("unit", "件");
        set("value", 4);
        set("armor_prop/armor", 5);
    }
    ::init_cloth();
}
