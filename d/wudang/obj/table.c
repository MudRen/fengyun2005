inherit ITEM;

void create()
{
	set_name("木桌", ({ "table", "木桌", "桌"}) );
	set_weight(5000);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	set("prep", "on");
	    set("unit", "张");
	    set("long", "一张木制的桌子。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

