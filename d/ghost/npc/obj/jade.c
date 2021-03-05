#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"血玉髓"NOR, ({ "bloody ruby","ruby"}) );
        set_weight(3450);
        set("unit", "块");
        set("long", "一块鲜红如血的长条玉石。\n");
        ::init_item();
}

