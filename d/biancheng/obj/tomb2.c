inherit ITEM;
#include <ansi.h>


void create()
{
        set_name("坟冢", ({ "tomb","坟冢" }) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("value", 1);
		set("long","从坟地的规模来看，这里埋的应该是一方富绅。\n");
		set("prep","on");
	}
	
	::init_item();
}


int is_container() { return 1; }

