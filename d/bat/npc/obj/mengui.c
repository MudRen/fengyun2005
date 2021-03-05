#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( "鹰爪门门规", ({ "mengui" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("long", "一张详细的鹰爪门门规。\n");
          }
	::init_item();
}


