
inherit ITEM;

void create()
{
	set_name("王母池", ({ "王母池" , "lake"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "王母池是深潭之佼佼者，潭水清冽，可见人影。\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }
