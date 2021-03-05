inherit ROOM;

void create()
{
        set("short", "东花园");
        set("long", @LONG
你站在黑松城堡的东花园里。花园里长满了各式各样奇花异草。东侧高耸的城
墙上长满了青色的蔓藤。蔓藤从墙顶一直垂到你的脚下。再往西则是雄伟的黑松阁。
LONG
        );
        set("exits", ([
                "west" : __DIR__"east_blackge",
        ]));
	        set("objects", ([
                __DIR__"npc/wolfdog" : 3,
        ]) );
        set("item_desc", ([
                "wall": "城墙虽陡，但长满了蔓藤。你似乎可以试着爬(climb)上去。\n",
		"城墙": "城墙虽陡，但长满了蔓藤。你似乎可以试着爬(climb)上去。\n",
		"蔓藤": "蔓藤长满了城墙，你似乎可以试着爬(climb)上去。\n"	
        ]) );
       set("outdoors", "chuenyu");
	set("coor/x",10);
	set("coor/y",40);
	set("coor/z",20);
	setup();
}

void init()
{
	add_action("climbing", "climb");
}

int climbing(string arg)
{
//	object obj;
	object me;
	if(!arg || arg=="")
	{
		write("你要爬什么？\n");
		return 1;
	}
	if( arg == "wall" || arg == "蔓藤" || arg == "城墙")
	{
		me = this_player();
        	if (me->query_temp("climbdown"))
			{
				write("你已经在爬了。\n");
				return 1;
			}
	        message_vision("$N抓着蔓藤，慢慢的顺着城墙爬了下去。\n", me);
		me->start_busy(3);
		call_out("fliping",4,me);
//		me->stop_busy();
		me->set_temp("climbdown",1);
		return 1;
	}
	else
	{
		write("你不可以爬"+arg+"。\n");
		return 1;
	}
}

int fliping(object me)
{
	if(!me->is_ghost()){
	        me->move(__DIR__"east_castle.c");
	        message_vision("$N松开蔓藤，从城墙离地三尺处一跃而下。\n", me);
	}
	me->delete_temp("climbdown",1);
	return 1;
}