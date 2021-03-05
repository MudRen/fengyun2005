
inherit ITEM;

void create()
{
    set_name("桌子", ({ "desk" , "桌子"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "张");
        set("long", "一张很破烂的红木桌子。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


