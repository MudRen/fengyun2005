
inherit ITEM;
#include <ansi.h>

void create()
{
    set_name("超级大箱子", ({ "bottomless box","box"}) );
    set_weight(20000);
	set_max_encumbrance(4000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
        set("long", "一个极大极大的箱子。\n");
		set("value", 100);
	}
	::init_item();
}

int is_container() { return 1; }


