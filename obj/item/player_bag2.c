inherit ITEM;
#include <ansi.h>

void create()
{
    set_name("百宝囊", ({ "medium box","box"}) );
    set_weight(2000);
	set_max_encumbrance(80000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
        set("long", "一个小小的行囊，可以防水，走江湖的人常用。\n");
		set("value", 20000);
		set("waterproof",1);
	}
	::init_item();
}

int is_container() { return 1; }


