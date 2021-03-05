#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("烤家兔肉", ({ "fried rabbit meat","meat"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "一块烤制好的香喷喷的家兔肉。\n");
                set("value", 1000);
        }
        ::init_item();
}
