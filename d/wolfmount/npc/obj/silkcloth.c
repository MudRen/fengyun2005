#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("丝绸长袍", ({"silk cloth", "cloth"}));
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long","一件丝绸长袍，质地和裁剪都不错。\n");
        set("material", "cloth");
        set("unit", "件");
        set("value", 6);
        set("armor_prop/armor", 10);
    }
    ::init_cloth();
}
