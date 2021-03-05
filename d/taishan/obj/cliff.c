
inherit ITEM;

void create()
{
	set_name("东壁", ({ "cliff" , "东壁"}) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "座");
		set("long", "山势陡峭，东壁立千尺，宛如刀削。\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }
