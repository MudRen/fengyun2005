
inherit ITEM;

void create()
{
    set_name("青苔", ({ "lichen" , "青苔"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "堆");
        set("long", "漂浮在暗河水面上的一堆青苔。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


