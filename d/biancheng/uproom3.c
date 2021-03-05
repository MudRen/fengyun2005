inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "卧房");
        set("long", @LONG
很难想象这就是拥有万贯家财的万马堂主人的卧室，床只是简简单单的木板铺
成，除了一张靠椅，屋子里就没有其他的家具。创业易，守业难，马空群认为要成
就大事，就不能贪图眼前的安逸，就得时时刻刻保持豹一般的警觉和敏锐。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"uproom2",
	]));
        set("objects", ([
	]) );
        set("coor/x",-5);
        set("coor/y",130);
        set("coor/z",10);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
