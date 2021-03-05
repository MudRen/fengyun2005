#include <armor.h>

inherit CLOTH;

void create()
{
    set_name("浅红绸衫", ({ "pink cloth", "cloth" }) );
    set_weight(1000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long","这件粉红色的绸衫上面绣着几只黄鹊，闻起来还有一股淡香。\n");
        set("unit", "件");
        set("value", 0);
        set("material", "cloth");
        set("armor_prop/armor", 1);
        set("female_only", 1);
    }
    ::init_cloth();
}

