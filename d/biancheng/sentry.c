inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "了望台");
        set("long", @LONG
草场边有一个小土丘，小丘上还有一座土岗，土岗上有一座木架茅顶的了望台，
是古时候若遇上动乱，士兵点燃烽火的地方。登高一望，远处一面白色的大旗正在
风沙中飞卷，像是一个离别的情人在向你挥着丝巾，那上面鲜红的字，却像情人的
血和泪。旗下就是万马堂的迎宾处。
LONG
        );
        set("exits", ([ 
		"north":	__DIR__"grassland4",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",110);
        set("coor/y",70);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
