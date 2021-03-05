
inherit ITEM;

void create()
{
	set_name("千年银杏", ({ "tree" , "银杏", "千年银杏"}) );
	set_weight(50000);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", "一株千年银杏，绿叶如荫，树冠若盖。\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }


