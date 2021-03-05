#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("小树叶", ({ "leaf"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "片");
                set("long", "一片小小树叶。\n");
                set("value", 1100);
				set("annie_leaf",1);
        }
        ::init_item();
}
