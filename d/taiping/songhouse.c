// seaside.c
inherit ROOM;
void create()
{
        set("short", "黑屋");
        set("long", @LONG
墙漆成死黑，地面亦是死黑的一片，门窗的后面牵着黑布，就连桌椅床褥都是
漆黑，整个地方仿佛就裹在死亡的暗影中。对门的墙壁之前，有一个祭坛，低悬着
漆黑的神幔，也不知坛上供着的是什么。坛前是一方祭桌，上面放着两个黑鼎，一
个黑盆。黑盆在两鼎之间，堆着乌黑的一大堆圆饼。
LONG
        );
        set("exits", ([ 
		"south": __DIR__"songhouse2",
		"up": __DIR__"songhouse3",
	]));
        set("objects", ([
        	__DIR__"npc/song": 1,
        	__DIR__"obj/altar": 1,
        	__DIR__"obj/altar2": 1,
        ]));
        set("item_desc", ([
	
	 ]));
	set("coor/x",-60);
	set("coor/y",-60);
	set("coor/z",0);
	set("map","taiping");
	setup();
}

void init()
{
        if(query("exits/north")) {
	        set("item_desc", ([
	                "door": "黑色的木板门，门是开着的。\n",
	                "门": "黑色的木板门，门是开着的。\n",
	        ]) );
	}
	else {
	        set("item_desc", ([
	                "door": "黑色的木板门紧紧地关着，你可以拉(pull)门。\n",
	                "门": "黑色的木板门紧紧地关着，你可以拉(pull)门。\n",
	        ]) );
	}
	add_action("do_pull", "pull");
}

int do_pull(string arg)
{
        object room, me;
        if( arg=="door" || arg == "门" || arg == "黑门") {
                me = this_player();
                if(query("exits/north")) {
                        write("黑门是开着的！\n");
		}
		else {
	                set("exits/north", __DIR__"sroad1");
		        set("item_desc", ([
		       	         "door": "黑色的木板门，门是开着的。\n",
		                "门": "黑色的木板门，门是开着的。\n",
	       		 ]) );
                	message_vision("$N用力拉开黑门。\n", me);
                	if( room = find_object(__DIR__"sroad1") ) {
	                        message("vision", "黑门从里面打了开来。\n", room);
		                room->set("exits/south", __DIR__"songhouse");
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
	message("vision", "黑门又被关上了。\n", room);
	message("vision", "黑门又被关上了。\n", this_object());
        set("item_desc", ([
                "door": "黑色的木板门紧紧地关着，你可以拉(pull)门。\n",
	        "门": "黑色的木板门紧紧地关着，你可以拉(pull)门。\n",
        ]) );
	room->delete("exits/south");
	delete("exits/north");
}

int valid_leave(object me,string dir)
{
	object ob;
	if(userp(me) && dir == "up" && ob=present("mother song",this_object()))
	{
		if (me->query("family/master_id")!="master yin"){
			message_vision(ob->name()+"说：老太婆的楼上乱得很，客人还是止步吧。\n",me);
			return notify_fail("");
		}
		else {
			message_vision(ob->name()+"说：老太婆的楼上乱得很，不过，官爷执意要检查就请上吧。\n",me);
			return 1;
		}
	}
	return 1;
}

void reset()
{
	object *inv;
        object item1,table;
        int i,needle;
        
        ::reset();
        table = present("jizhuo", this_object());
        if (table) {
	        inv = all_inventory(table);
	        for (i=0;i<sizeof(inv);i++) {
	        	if (inv[i]->query("name")=="黑色的圆饼") needle=1;
	        }
	        if (!needle) {
	        	item1 = new(__DIR__"obj/blackpie");
	        	item1->move(table);
	        	}
	}
}