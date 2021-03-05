
inherit ITEM;

void create()
{
	set_name("垃圾", ({ "trash" , "垃圾"}) );
	set_weight(500);
	set_max_encumbrance(8000000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "堆");
		set("long", "又臭又脏的垃圾堆的满街都是。\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


