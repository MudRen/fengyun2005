
inherit ITEM;

void create()
{
	set_name("黑龙潭", ({ "黑龙潭" , "lake"}) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个诺大的黑龙潭。\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }
