inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("石板", ({ "石板" , "shiban","stone"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块石板，上面有几个深深的马蹄印。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


