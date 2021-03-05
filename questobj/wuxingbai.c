#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(BLK"太极五行牌"NOR, ({ "wuxingpai" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "块");
            set("material", "stone");
            set("long", "武当的镇山之宝：太极五行牌\n");
          }

    ::init_item();
}
