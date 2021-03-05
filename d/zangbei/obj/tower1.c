inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("嵩岳寺塔", ({ "嵩岳寺塔", "tower"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "座");
		set("long", "单层密檐式砖塔，由基台、塔身、密檐和塔刹几部分构成。
塔高数十尺，轻功好的也许可以攀登（climb）上去。\n");
		set("value", 1);
		set("prep","in");
	}
	::init_item();
}

int is_container() { return 1; }


