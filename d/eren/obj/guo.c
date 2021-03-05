inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("大锅", ({ "大锅","锅","guo"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个很大的铁锅，咕噜噜地翻着气泡。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


