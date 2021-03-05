inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("冰川", ({ "冰川" , "ice"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "大大小小、形形色色的冰川，冰塔，冰峰。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


