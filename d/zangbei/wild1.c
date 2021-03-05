inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "昆仑山西");
        set("long", @LONG
昆仑山的西麓，山峦起伏，风景秀丽，向北有著名的[33m二郎山[32m，神仙阁。据说山
里还住着一个人，这个人爱花，他住的地方就是座花海，一片花城。在不同的季节
中，那里总有不同的花盛开，他总是住在花开得最盛的那个地方。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"yuzhu",
		"west" : __DIR__"wild2",
		"north": __DIR__"erlang",
		"south": __DIR__"mroom",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1300);
        set("coor/y",700);
        set("coor/z",0);
	set("map","zbeast");
	setup();
	
}
