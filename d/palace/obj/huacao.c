
inherit ITEM;

void create()
{
	set_name("花草", ({ "huacao" , "花草", "flower"}) );
	set_weight(500);
	set_max_encumbrance(800);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "行");
		set("long", "修剪整齐的花草。\n");
		set("value", 1);
	}
}

int is_container() { return 1; }


