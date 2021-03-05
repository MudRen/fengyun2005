inherit ITEM;

void create()
{
    set_name("大竹筐", ({ "big basket","basket"}) );
	set_weight(1000);
    set_max_encumbrance(20000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "个");
        set("long", "一个手工编制的大竹筐。\n");
        set("value", 500);
	}
	::init_item();
}

int is_container() { return 1; }

