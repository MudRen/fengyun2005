#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(CYN"指环儿"NOR, ({ "zhihuan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "stone");
            set("long", "一个小巧的指环儿\n");
          }

    ::init_item();
}
