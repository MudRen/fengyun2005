inherit ITEM;
#include <ansi.h>

void create()
{
    set_name("红丝囊", ({ "small bag","bag"}) );
    set_weight(2000);
	set_max_encumbrance(40000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
        set("long", "一个小小的行囊，走江湖的人常用。\n");
		set("value", 2000);
	}
	::init_item();
}

int is_container() { return 1; }


