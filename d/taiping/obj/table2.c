inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("石桌", ({ "table","desk","石桌",}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "一张用整块的大青石凿成的石桌。\n");
		set("value", 1);
		set("prep", "on");
	}
	::init_item();
}

int is_container() { return 1; }


