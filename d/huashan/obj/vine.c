inherit ITEM;

void create()
{
	set_name("青萝", ({ "vine", "青萝" }) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","inside");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "片");
	    set("long", "松枝上长满了厚厚的青萝。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

