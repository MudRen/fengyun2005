inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "一百零八塔");
        set("long", @LONG
一百零八塔位于河西岸一处陡峭的山坡上。这里原是规模宏大的寺庙建筑群，
如今，绝大部分已经毁灭湮没，仅塔林独存。这一百零八塔自上而下排成十二列，
整体布局上尖下阔，像一个金字塔形，别具一格，带给人们许多遐想。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"songyue",
		"southeast" : __DIR__"qingtongxia",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-550);
        set("coor/y",600);
        set("coor/z",0);
	set("map","zbeast");
	setup();
	replace_program(ROOM);
}
