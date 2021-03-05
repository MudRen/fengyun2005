inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("角落", ({ "corner" , "角落"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "驿站马房的角落,打扫得干干净净,堆着饲料。\n");
		set("prep","in");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


