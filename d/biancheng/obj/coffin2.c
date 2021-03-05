inherit ITEM;
#include <ansi.h>


void create()
{
        set_name("棺材", ({ "coffin","棺材" }) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "具");
		set("value", 1);
		set("long","一口崭新的棺材，盖子打开着。\n");
		set("prep","on");
	}
	
	::init_item();
}


int is_container() { return 1; }

