inherit ITEM;
#include <ansi.h>

void create()
{
    	set_name("老僧的尸体", ({ "corpse"}) );
    	set_weight(800000);
    	set_max_encumbrance(400000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "具");
        set("long", "一具少林和尚的尸体，好像刚死了不久。。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }
