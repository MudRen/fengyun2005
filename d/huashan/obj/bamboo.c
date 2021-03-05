inherit ITEM;

void create()
{
	set_name("翠竹", ({ "翠竹", "bamboo", "竹" }) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","in");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "丛");
	    set("long", "一丛翠绿的竹子。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

