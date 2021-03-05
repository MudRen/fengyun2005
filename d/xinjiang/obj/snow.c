//oh apstone, inc.
inherit ITEM;
void create()
{
	set_name("积雪", ({ "snow" , "积雪"}) );
	set_weight(50000);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "白色的积雪，又厚又重\n");
		set("value", 1);
	}
	::init_item();
}

int is_container() { return 1; }


