inherit ITEM;
#include <ansi.h>


void create()
{
        set_name("枯树", ({ "tree","枯树" }) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("value", 1);
		set("long","一棵死了多年的老槐树，没有一丝生机。\n");
		set("prep","on");
	}
	
	::init_item();
}


int is_container() { return 1; }

