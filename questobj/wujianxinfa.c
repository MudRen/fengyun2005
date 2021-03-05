#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIW"无剑心法"NOR, ({ "wujianxinfa" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "stone");
            set("long", "一本破旧，字迹模糊的书。\n");
          }

    ::init_item();
}
