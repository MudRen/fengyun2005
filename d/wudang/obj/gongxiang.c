inherit ITEM;

void create()
{
	set_name("供香", ({ "gong xiang", "供香"}) );
	set_weight(10);
	if( clonep() )
	    set_default_object(__FILE__);
	else {
	    set("unit", "支");
	    set("long", "一支燃着的供香。\n");
	    set("value", 10);
	}
	::init_item();
}

