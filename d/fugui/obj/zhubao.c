inherit ITEM;

#include <ansi.h>

void create()
{
	set_name( "珠宝", ({ "zhubao"}) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一大堆珠宝。\n");
		set("unit", "堆");
		set("value", 100);
		set("thief_obj",1);
	}
	::init_item();
}