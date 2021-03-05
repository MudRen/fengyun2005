#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"金牙箍"NOR, ({ "jygu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "个");
            set("material", "gold");
            set("long", "一个发黄的金牙箍。\n");
          }

    ::init_item();
}
