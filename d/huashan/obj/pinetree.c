inherit ITEM;

void create()
{
	set_name("松树", ({ "松", "tree", "松树" }) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","behind");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "棵");
	    set("long", "一棵巨大的松树，树似乎被火焚烧过，然而在焦黑的树干上又长出嫩绿的新芽。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

