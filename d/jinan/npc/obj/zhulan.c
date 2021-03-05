inherit ITEM;

#include <ansi.h>
void create()
{
        set_name(GRN"翠竹篮"NOR, ({ "bamboo basket","basket"}) );
        set_weight(100);
        set_max_encumbrance(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "一个由嫩绿的翠竹编制的饭篮。\n");
                set("value", 150);
        }
}

int is_container() { return 1; }

