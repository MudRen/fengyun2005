inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "小厨房");
        set("long", @LONG
推开另一扇门，竟是间小小的厨房。自从数月前律香川的夫人林秀死后，律香
川每天都会在半夜起来，弄点东西吃。他喜欢自己动手，也许只有在厨房里的时候，
他才会觉得真正轻松。他最喜欢的拿手菜是蛋炒饭，风鸡和香肠。
LONG
        );
        set("exits", ([ 
		"east": 	__DIR__"groom3",

	]));
        set("objects", ([
               	
	]) );
        set("coor/x",-1290);
        set("coor/y",980);
        set("coor/z",-50);
	set("map","zbeast");
	setup();
}
