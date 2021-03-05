
inherit ROOM;

void create()
{
        set("short", "黑松城堡的西侧");
        set("long", @LONG
你站在黑松山顶，黑松城堡的西侧。高耸的城墙上长满了青色的蔓藤。蔓藤从
墙顶一直垂到你的脚下。再往西是刀削般的万丈悬崖。往东则是城堡的正门。
LONG
        );
        set("exits", ([
                "east" : __DIR__"gate_castle",
        ]));
        set("item_desc", ([
                "wall": "城墙虽陡，但长满了蔓藤。你似乎可以试着爬(climb)上去。\n",
		"城墙": "城墙虽陡，但长满了蔓藤。你似乎可以试着爬(climb)上去。\n",
		"蔓藤": "蔓藤长满了城墙，你似乎可以试着爬(climb)上去。\n"	
        ]) );
       set("outdoors", "chuenyu");

	set("coor/x",-10);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
}

void init()
{
	add_action("climbing", "climb");
}

int climbing(string arg)
{
	object obj;
	object me;
	if(!arg || arg=="")
	{
		write("你要爬什么？\n");
		return 1;
	}
	if( arg == "wall" || arg == "蔓藤" || arg == "城墙")
	{
		me = this_player();
		if (me->query_temp("climbup"))
			{
				write("你已经在爬了。\n");
				return 1;
			}	
	        message_vision("$N抓着蔓藤，慢慢的顺着城墙爬了上去。\n", me);
		me->start_busy(3);
		call_out("fliping",3,me);
		me->set_temp("climbup",1);
//		me->stop_busy();
		return 1;
	}
	else
	{
		write("你不可以爬"+arg+"\n");
		return 1;
	}
}

int fliping(object me)
{
	if(!me->is_ghost()){
	        me->move(__DIR__"west_garden.c");
	        message_vision("$N用手一撑墙头儿，轻巧的跳了过来。\n", me);
	}
	me->delete_temp("climbup");
	return 1;
}
