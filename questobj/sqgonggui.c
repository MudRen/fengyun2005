#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIC"三清宫规"NOR, ({ "sqgonggui" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "stone");
            set("long", "一本三清宫的宫规\n");
          }

    ::init_item();
}
