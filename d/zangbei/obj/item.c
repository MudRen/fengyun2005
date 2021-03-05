inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("待定物品", ({ "item"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "桑堆河水流平缓，深不见底，偶尔会有鱼儿跃出水面。\n");
		set("value", 1);
		set("prep","in");
	}
	::init_item();
}




