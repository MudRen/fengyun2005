
inherit ITEM;

void create()
{
	set_name("松树", ({"pine","松树"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown",1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "一棵长势良好的松树，树洞里似乎有什么正看着你。\n");
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
