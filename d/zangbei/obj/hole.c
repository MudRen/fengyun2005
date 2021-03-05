inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("坑", ({ "坑" , "ken", "hole"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个三尺宽，五尺深，七尺长的坑，恰好可以躺下一个人。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


