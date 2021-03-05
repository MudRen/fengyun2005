#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(BLU"武当录"NOR, ({ "wudanglu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "本");
            set("material", "paper");
            set("long", "长勤武当录。\n");
          }

    ::init_item();
}
