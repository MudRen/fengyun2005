#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"黄山风景图"NOR, ({ "hstu" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "张");
            set("material", "paper");
            set("long", "一张黄山风景的简介图\n");
          }
	::init_item();
}
