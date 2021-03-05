#include <armor.h>

inherit CLOTH;
#include <ansi.h>

void create()
{
        set_name(HIB"蓝色长裙"NOR, ({ "blue skirt", "skirt" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","这件蓝色的百折长裙上面绣着几朵杏花，闻起来还有一股淡香。\n");
                set("unit", "件");
                set("value", 0);
                set("material", "cloth");
                set("armor_prop/armor", 1);
                set("female_only", 1);
        }
        ::init_cloth();
}

