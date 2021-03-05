inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "快活林");
        set("long", @LONG
三千里内再也找不出第二个如此美丽的庭园，同时更不会找到比这里更迷人的
地方。各种不同的人，从各种不同的地方到这里来就像是苍蝇见到了肉上的血，就
算在这里花光了最后一分银子，也不会觉得冤枉。因为这里是高老大的“快活林”。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"bridge",
		"northup":  __DIR__"mount3",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1680);
        set("coor/y",610);
        set("coor/z",10);
	set("map","zbwest");
	setup();

}
