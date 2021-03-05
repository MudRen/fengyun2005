
inherit ITEM;

void create()
{
	set_name("野花", ({ "flower" , "野花"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "些");
		set("long", "这是一些不知名的野花，花开的正热闹。\n");
		set("value", 1);
	}
}

int is_container() { return 1; }

