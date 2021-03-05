
inherit ROOM;

void create()
{
	set("short", "大厅");
	set("long", @LONG
山谷的要害处竟然有一座大屋，不大不小正堵住了去路。铁锅摆在火炉上，火
炉摆在高台前，高台就在大厅里。大厅高四丈，石台高七尺，铁锅也有三尺多高。
炉火正旺，锅里煮着气腾腾的一锅肉，香得简直可以把十里之内的人和狗都引来。
LONG
	);
	set("exits", ([
                "west" : __DIR__"groad3",
                "east" : __DIR__"groad4",
	]));
	set("objects", ([
                __DIR__"npc/jiangjun" : 1,
                __DIR__"obj/meat" : 1,
	]));
	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
        object ob;
        int i;
		
		if (dir == "east") {
			if( (ob=present("jiang jun", this_object())) && present("stewed meat", this_object())) {
				return notify_fail(ob->name()+"向你喝道：没吃完肉，就想走？\n");
	        }
	        if( (ob=present("jiang jun", this_object())) && present("stewed meat", me)) {
	                return notify_fail(ob->name()+"向你喝道：没吃完肉，就想走？\n");
	        }
        }
        return 1;
}

void reset()
{
        object          item, meat;

        ::reset();
        item = present("big pot", this_object());
	if(objectp(item)) {
		destruct(item);
		meat = new(__DIR__"obj/meat"); 
		meat->move(this_object());
	}
}
