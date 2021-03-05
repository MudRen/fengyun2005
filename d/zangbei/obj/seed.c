#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("棉籽", ({ "seed" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "袋");
            set("material", "cotton");
            set("long", "一袋上好的棉籽。\n");
          }

    ::init_item();
}
