inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "一品香");
        set("long", @LONG
一品香是个很大的茶馆，茶馆里通常都有各式各样的人，越大的茶馆里人越多。
现在正是茶馆生意上市的时候，里面的客人却不很多，两个下棋的，一个剥花生的，
一个和尚，一个麻子，一个卖唱的老头，还有一个是伏在桌上打磕睡的大胖子。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"nstreet2",
		"up" : __DIR__"tas",
	]));
        set("objects", ([
        	__DIR__"npc/fatman": 1,
	]) );
        set("coor/x",-20);
        set("coor/y",20);
        set("coor/z",0);
	set("map","zbwest");
	setup();
}
