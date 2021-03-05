inherit ITEM;

void create()
{
	set_name("木板", ({ "wood","木板"}) );
	set_weight(270);
	set_max_encumbrance(800);
	set("no_shown", 1);
	set("prep","under");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
		set("long", "一块木板。\n");
		set("value", 0);
		set("lore",1);
	}
    ::init_item();
}

int init()
{
	set_max_encumbrance(800*(!userp(environment())));
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
