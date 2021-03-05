
inherit ITEM;

void create()
{
	set_name("五大夫松", ({ "tree" , "五大夫松"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", "传五大夫松乃始皇避雨的所在。\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }
