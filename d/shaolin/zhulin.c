// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "竹林");
        set("long", @LONG
一片竹林，伴随阵阵山风，竹叶的婆娑之声恰似丝竹之音，沁人心脾，阳光虽
烈，这里却清幽异常，一眼望去，竟然看不见尽头。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"diyuan",
  "west" : __DIR__"yinshi",
]));
    set("outdoors", "shaolin");
	set("coor/x",-30);
	set("coor/y",120);
	set("coor/z",20);
	set("objects", ([
                __DIR__"npc/yan13" : 1,
       ]) );
	setup();
//    replace_program(ROOM);
}

int invalid_leave(object me)
{
	me->delete_temp("yan13ask");
	return 0;
}


