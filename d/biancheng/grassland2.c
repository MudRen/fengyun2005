inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "大道");
        set("long", @LONG
前面一片灯火，万马堂的迎宾处，显然就在灯火辉煌处。风中已隐隐有马嘶之
声，自四面八方传了过来。纵目四顾，只觉得苍穹宽广，大地辽阔，绝不是局促城
市中的人所能想象。远远望过去，一面白色的大旗正在风沙中飞卷。
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"grassland1a",
		"north" : __DIR__"gate",
		"northeast": __DIR__"grassland3",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-10);
        set("coor/y",70);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
