inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("塑像", ({ "塑像", "statue"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "座");
		set("long", "花教创始人薛迦班智达的塑像。\n");
		set("value", 1);
		set("prep","on");
	}
	::init_item();
}

int is_container() { return 1; }


