inherit ITEM;
#include <ansi.h>
void create()
{
        set_name("野草", ({ "野草" , "grass"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "路边的野草，生命力极为顽强。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


