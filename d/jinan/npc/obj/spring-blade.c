#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name("融雪刀", ({ "spring blade","blade" }) );
        set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "一柄流动着水色光芒的长刀。\n");
                set("value", 0);
				set("no_stack",1);
				set("no_drop",1);
                set("material", "steel");
        }
        ::init_blade(73);
}
