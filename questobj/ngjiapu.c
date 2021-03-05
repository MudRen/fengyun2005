#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(CYN"南宫家谱"NOR, ({ "ngjiapu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("long", "一张南宫家谱。\n");
          }

    ::init_item();
}
