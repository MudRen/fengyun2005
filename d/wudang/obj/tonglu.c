inherit ITEM;

void create()
{
	set_name("铜炉", ({ "tong lu", "铜炉"}) );
	set_weight(5000);
	set_max_encumbrance(800);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	set("prep", "on");
	    set("unit", "只");
	    set("long", "青铜铸成的供炉。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

