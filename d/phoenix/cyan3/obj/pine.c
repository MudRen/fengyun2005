
inherit ITEM;

void create()
{
	set_name("松树", ({"tree"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("prep","behind");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "一棵高大的松树立在沉香海上，松树上有个漆黑的树洞，洞里仿佛有什么在窥探着你。\n");
		set("value", 1);
	}
    ::init_item();
}

int is_container() { return 1; }


void 	init()
{
	add_action("do_climb","climb");
}	

int do_climb(string arg){

	object me,room;
	me=this_player();
	if (!arg || (arg!="tree" && arg!="树")) 
		return notify_fail("你想爬什么？\n");;
	message_vision("$N抓着树干往上爬了半天，一松手又跌了下来。\n",me);
	tell_object(me,"说你不行，你就不行，行也不行，不服不行。\n");
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
