
inherit ITEM;

void create()
{
	set_name("木桩", ({ "wood" , "木桩"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "一根中空的木桩\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }
