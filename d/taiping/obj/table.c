inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("檀木几", ({ "table","desk","檀木茶几","檀木几",}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long", "一张上好的檀木茶几，还散发着淡淡的香味。\n");
		set("value", 1);
		set("prep", "on");
	}
	::init_item();
}

int is_container() { return 1; }


