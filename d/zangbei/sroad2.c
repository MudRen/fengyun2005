inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "小径");
        set("long", @LONG
一条小路穿过花丛，穿过小桥，通向菊花园的西侧。花园里很静，没有人，没
有声音。老伯的花园一向都是这样子的，但你只要一走进去，每个角落里都可能有
人忽然出现，每个人都可能要你的命。
LONG
        );
        set("exits", ([ 
		"east" :  	__DIR__"sroad1",
		"west" : 	__DIR__"sroad3",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1380);
        set("coor/y",970);
        set("coor/z",-50);
	set("map","zbeast");
	setup();
}
