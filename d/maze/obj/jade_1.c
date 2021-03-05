#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"碧血石"NOR, ({ "stone"}) );
        set_weight(500); 
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "一颗小小的宝石，似乎可以镶嵌在什么上。\n");
                set("value", 2000);
                set("ring-imbue","red");
        }
	::init_item();
}

