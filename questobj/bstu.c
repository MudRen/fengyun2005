#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( WHT "巴山图" NOR, ({ "bstu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("long", "一张详细的巴山地图，左下角写了一行小字：
风云城东十里，左三右四，子午双时．．\n");
          }
    ::init_item();
}
