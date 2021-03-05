inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("铁雪信笺", ({ "letter"}) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "封");
		set("long", "一封铁少写给李玉涵的信件。\n");
		set("value", 1000);
	}
}



