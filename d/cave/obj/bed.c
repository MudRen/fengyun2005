
inherit ITEM;

void create()
{
    set_name("小床", ({ "bed" , "小床"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "堆");
        set("long", "一张摇摇晃晃的小床，堆满了杂物。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


