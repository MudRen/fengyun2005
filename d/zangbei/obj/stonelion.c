inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("狮子", ({ "狮子" , "石狮", "stoneline","stone","lion" }) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "汉白玉雕成十六个狮子，有立有卧，正侧各异，造型雄健。\n");
		set("value", 1);
		set("prep","on");
	}
	::init_item();
}

int is_container() { return 1; }


