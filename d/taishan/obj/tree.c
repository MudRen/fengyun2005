
inherit ITEM;

void create()
{
	set_name("一品大夫松", ({ "tree" , "一品大夫松"}) );
	set_weight(50000);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", "一株比普照寺历史更加久远的松树\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }
