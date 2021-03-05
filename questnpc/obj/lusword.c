#include <weapon.h>
#include <ansi.h>
inherit SWORD;


void create()
{
        set_name(HIW"无鞘剑"NOR, ({ "sword" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一柄很薄的剑，但没有剑鞘。\n");
                set("value", 4000);
                set("material", "steel");
        }
        ::init_sword(70);

}
