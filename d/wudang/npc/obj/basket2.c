inherit ITEM;

void create()
{
	set_name("饭篮", ({ "basket"}) );
	set_weight(300);
	set_max_encumbrance(1000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "个");
	    set("long", "一个竹编的饭篮。\n");
	    set("value", 150);
	}
	::init_item();
}

int is_container() { return 1; }

