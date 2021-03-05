#include <armor.h>

inherit CLOTH;
#include <ansi.h>

void create()
{
    set_name(HIY"虎皮大氅"NOR, ({"tiger cloak", "cloak"}));
    set_weight(20000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("long","一件由虎皮缝制的大氅，看上去着实威风凛凛。\n");
        set("material", "cloth");
        set("unit", "件");
        set("value", 100);
        set("armor_prop/armor", 10);
        set("male_only", 1);
    }
    ::init_cloth();
}
