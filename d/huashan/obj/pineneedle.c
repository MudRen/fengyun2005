inherit ITEM;

void create()
{
	set_name("松针", ({ "pineneedle", "松针", "songzhen" }) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","in");
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "片");
	    set("long", "地上铺了一层厚厚的松针。\n");
	    set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }

