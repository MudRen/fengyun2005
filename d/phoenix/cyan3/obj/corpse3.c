#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("倭刀", ({ "katana"}) );
	set("no_get", 1);
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一柄上好的倭刀，正牢牢地钉在离地数丈的树干上。\n\n");
		set("unit", "个");
		set("value", 0);
	}
	::init_item();
}


