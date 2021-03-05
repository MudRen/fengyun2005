inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("石碑", ({ "石碑" , "碑","bei","shibei"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "\n葡萄美酒夜光杯，欲引琵琶马上催，劝君更尽一杯酒，西出阳关无故人。
			王翰	*凉州词*	\n\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


