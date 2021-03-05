inherit ITEM;

void create()
{
	set_name("竹筐", ({ "basket"}) );
	set_weight(1000);
	set_max_encumbrance(8000);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "个");
	    set("long", "一个竹编的筐。\n");
	    set("value", 150);
	}
	::init_item();
}

int is_container() { return 1; }

