#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(RED"碎布"NOR, ({ "cloth" }) );
        set("long", "一片碎布，色泽鲜红，似乎是从什么衣服上撕下来的。\n");
        set("unit", "片" );
        set("libie_evidence",1);
        ::init_item();
}
