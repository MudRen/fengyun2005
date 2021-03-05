inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("天梯石栈", ({ "tianti" , "shizhan","天梯石栈","天梯","石栈"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "古代工匠在绝壁上开凿出来的道路。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


