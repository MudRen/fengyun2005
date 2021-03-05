// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit "/d/phoenix/ann_room.c";
string look_stone();

void create()
{
	set("short", "老树顶");
    set("long", @LONG
爬上老树顶，你在心头嘀嘀咕咕：什么嘛，为什么到处的秘密都会在路边
的一棵树上？想归想，你还是仔细四望，只见繁茂的绿叶与盘曲的枝条覆满了
整片天穹，周围昏沉沉的，什么也看不清。
LONG
NOR
        );
	set("objects", ([
	]));
	set("item_desc", ([


	]) );
	set("exits",([
  		"down" : "peak6",
	]) );

	set("outdoors", "cyan");
	set("area","cyan");

	set("coor/x",-60);
	set("coor/y",50);
	set("coor/z",100);
	setup();
}


void init()
{
	::init();
	add_action("do_search", ({"search"}));
}

int do_search(string arg)
{
	object me = this_player(),he;
	if (me->is_busy() || me->is_fighting())
	{
		write("你现在正忙。\n");
		return 1;
	}

	tell_object(me,"你在树叶枝条中四处摸索。\n");
	message_vision("一阵悉悉索索的声音传来，不知道$N在拨弄什么。\n",me);
	he=present("hidden shadow",this_object());
	if (he || query("get"))
		tell_object(me,"然而你什么都没有找到。\n");
	else
	{
		set("get",1);
		he = new(__DIR__"obj/jade");
		tell_object(me,"你摸到了一块触手冰凉生硬的东西，");
		if (he->move(me))
		{
			tell_object(me,"连忙揣进怀里。\n");
		}
		else
		{
			tell_object(me,"可是一不小心，它就从你手中滑落下去。\n");
			destruct(he);
		}
	}

	me->perform_busy(4);
	return 1;
}


void reset()
{
	object river,stone,*inv;
	
	::reset();

	if (query("get"))
		set("get",0);

	return;
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


