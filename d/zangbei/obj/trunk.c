inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("树干", ({ "trunk", "树干"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "一棵大树的树干，表面很平坦，象是经常有人坐在上面。\n");
		set("value", 1);
		set("prep", "on");
	}
	::init_item();
}

int is_container() { return 1; }


