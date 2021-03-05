
inherit ITEM;

void create()
{
	set_name("水草", ({ "watergrass" , "水草"}) );
	set_weight(500);
	set_max_encumbrance(800000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "团");
		set("prep", "under");
		set("long", "一大团带著烂泥的水草\n");
		set("value", 1);
	}
}

int is_container() { return 1; }


