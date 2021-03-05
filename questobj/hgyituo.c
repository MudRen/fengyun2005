#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(RED"鸿孤遗托" NOR, ({ "hgyituo" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "stone");
            set("long", "一张鸿孤遗托。\n");
          }
    ::init_item();
}
