inherit ROOM;

void create()
{
        set("short", "绝崖");
        set("long", @LONG
这座绝崖上光秃秃的，除了一块块的巨石什么也没有。这里的天色似乎也特别
暗淡，暗淡得使人感到人生的灰暗。向下则是一望无底，雾气蒙蒙的死谷。
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"mroad2",
]));
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/poslave" : 2,
        ]) );
        set("item_desc", ([
                "死谷": "谷壁并不很光滑，你似乎有一线希望可以爬(climb)下去。\n"
        ]) );


	set("coor/x",-1130);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
}
void init()
{
        add_action("climbing", "climb");
}

int climbing(string arg)
{
//      object obj;
        object me;
        if(!arg || arg=="")
        {
                write("你要爬什么？\n");
                return 1;
        }
        if( arg == "valley" || arg == "down" || arg == "死谷")
        {
	        me = this_player();
	        if (me->query_temp("climbing")) {
	        	write("你已经在爬了。\n");
	        	return 1;
	        	}
	        
	        message_vision("$N抓着突出的石角，慢慢的顺着谷壁爬了下去。\n", me);
	        me->start_busy(4);
	        call_out("fliping",7,me);
		me->set_temp("climbing",1);
	//      me->stop_busy();
	        return 1;
        }
        else
        {
                write("你不可以爬"+arg+"\n");
                return 1;
        }
}
void fliping(object me)
{
	object room;
	if( !me->is_ghost()) {
		room = find_object(__DIR__"valley");
		if(!objectp(room)) room= load_object(__DIR__"valley");
		me->move(room);      
		message_vision("$N顺着谷壁爬了下来。\n", me); 
	}
	me->delete_temp("climbing");
        return;
}
