
inherit ITEM;

void create()
{
	set_name("焦黄茅草", ({ "grass" , "茅草", "焦黄茅草"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "丛");
		set("long", "半人高的焦黄茅草。\n");
		set("value", 1);
	}
}

int is_container() { return 1; }

