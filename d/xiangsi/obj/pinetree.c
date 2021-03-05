
inherit ITEM;

void create()
{
	set_name("青松", ({ "pine" , "青松"}) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	set("prep","under");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "株");
		set("long", "一株半挂在悬崖之外的青松，松下似乎长着几朵小草小花。\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }

/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/
