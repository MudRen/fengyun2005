inherit ROOM;
void create()
{
        set("short", "怡红小院");
        set("long", @LONG
红门内是一个小院，几个花枝招展的女子坐在院墙下向你招手，脂粉的香味薰
的人昏昏沉沉，骨子里有一种禁不住的冲动。。迎面一幢二层小楼，描金匾额上鹦
鹉阁三个大字龙飞凤舞。门里传出箫鼓丝竹，夹着猜拳唱曲、呼幺喝六之音，好不
热闹。右手一扇月牙形拱门上写着惬意园，门后几杆翠竹探出头来。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"corridor1",
		"west": __DIR__"redhouse",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        
	]));
	set("coor/x",-70);
	set("coor/y",-50);
	set("coor/z",0);
	set("map","taiping");
	setup();
}

void init()
{
     	add_action("do_pull", "pull");
        if(query("exits/east")) {
	        set("item_desc", ([
	                "door": "铜钉的大门，门是开着的。\n",
	                "门": "铜钉的大门，门是开着的。\n",
	        ]) );
	}
	else {
	        set("item_desc", ([
	                "door": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
	                "门": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
	        ]) );
	}
}

int do_pull(string arg)
{
        object room, me;
        if( arg=="door" || arg == "门" || arg == "红门") {
                me = this_player();
                if(query("exits/east")) {
                        write("门是开着的！\n");
		}
		else {
	                set("exits/east", __DIR__"sroad1");
		        set("item_desc", ([
	       	         "door": "铜钉的大门，门是开着的。\n",
	       	         "门": "铜钉的大门，门是开着的。\n",
	       		 ]) );
                	message_vision("$N打开红门。\n", me);
                	if( room = find_object(__DIR__"sroad1") ) {
	                        message("vision", "红门从里面打了开来。\n", room);
		                room->set("exits/west", __FILE__);
				call_out("closedoor", 5, room);
                	}
		}
	}
	else {
                 write("你要开什么？\n");
	}
	return 1;
}


int closedoor(object room)
{
	message("vision", "红门又被关上了。\n", room);
	message("vision", "红门又被关上了。\n", this_object());
        set("item_desc", ([
                "door": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
                "门": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
        ]) );
	room->delete("exits/west");
	delete("exits/east");
}