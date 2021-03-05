#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"极乐丹"NOR, ({ "jiledan" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "丸");
            set("material", "stone");
            set("long", "一丸极乐丹。\n");
          }

    ::init_item();
}
