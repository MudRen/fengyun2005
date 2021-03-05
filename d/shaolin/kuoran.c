// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "廓然堂");
        set("long", @LONG
进门，抬头一块匾额“静中静”，这里四周无人，一般僧众绝不敢进入，便是
一般大和尚，也无权擅入，这里居住的都是寺外来拜会方丈的绝世高人。屋中除了
一桌一床，只有一红泥小火炉。
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"fang",
]));
        set("objects", ([
                __DIR__"npc/baixiaoshen" : 1,
       ]) );
	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",-10);
	setup();
}


void init()
{
    call_out("close_path", 5);
}

void opengate()
{
	set("exits/east", __DIR__"tongren");
//    call_out("close_path", 5);
}

void close_path()
{
        if( !query("exits/east") ) return;
        message("vision","石灰砖瓦纷纷落下，堵住了墙上的洞口。\n",this_object() );
                delete("exits/east");
}


int passing()
{
	object room;
	room = find_object(__DIR__"tongren");
	if (!room)
		room=load_object(__DIR__"tongren");
	return room->usr_in();
}

int valid_leave(object me, string dir)
{
	if (dir == "east" & passing())
	// 一个一个来，一个一个去
       	return notify_fail("你看看洞口，踌躇了一会儿，还是提不起勇气进去。\n");

//  	if( dir == "west" && !me->query("annie/demon_gao"))
//       	return notify_fail("你看看洞口，踌躇了一会儿，还是提不起勇气进去。\n");
	return 1;
}

