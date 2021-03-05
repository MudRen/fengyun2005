inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "前院");
        set("long", @LONG
一片大的空场，两边是农场的房屋，后面是庄主的宅子，宅子的两翼连接着一
面高高的园墙，墙后是一排一排的繁茂的白杉。中间是一条宽的直路，顺着这条路
走过去，便可以进入万马堂的正厅。向远处望，便是无边无际的草场。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"yard2",
		"out" : __DIR__"gate",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-10);
        set("coor/y",90);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
