inherit ITEM;

void create()
{
	set_name("纸折小船", ({ "paper boat","boat" }) );
	set_weight(1300);
	set_max_encumbrance(100);
	set("prep","inside");
	if( clonep() )
			set_default_object(__FILE__);
	else {
			set("unit", "个");
			set("long", "一个纸折的小船，屋棱檐帐仔细分明，手工极其精致。\n");
			set("value", 1000);
			set("real", 1);
	}
	::init_item();
}

int query_autoload() { return 1; }

int is_container()
{
	return 1;
}

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

