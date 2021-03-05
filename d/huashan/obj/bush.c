inherit ITEM;

void create()
{
	set_name("灌木", ({ "bush", "灌木", "guanmu" }) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","in");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "丛");
	    set("long", "一丛茂密的灌木。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

