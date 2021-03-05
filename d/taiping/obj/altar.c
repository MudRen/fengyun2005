inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("祭坛", ({ "altar","jitan","祭坛"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个祭坛，低悬着漆黑的神幔。\n");
		set("prep","up");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


