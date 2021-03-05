inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "恰克卜里山");
        set("long", @LONG
石砌城垣横亘于布达拉宫与恰克卜里山之间，山头上布满着楼阁、禅房、寺院、
碑碣，在山顶远远可以望见布达拉宫，那高耸在岩石上的巨大城堡，连绵的雉谍，
发光的窗瞩，看来依旧是那么瑰丽，那么调和。
LONG
        );
        set("exits", ([ 
		"northeast":  __DIR__"garden",
		"south":  	__DIR__"smallroad4",
	]));
        set("objects", ([
        	
	]) );
	set("outdoors", "guanwai");
        set("coor/x",40);
        set("coor/y",-20);
        set("coor/z",10);
	setup();

}
