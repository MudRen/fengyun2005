
inherit ITEM;

void create()
{
    set_name("杂草", ({ "grass" , "杂草"}) );
	set_weight(5000);
	set_max_encumbrance(800);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit", "片");
		set("prep", "under");
        set("long", "一片顽强地生长在岩石上的杂草..\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }


