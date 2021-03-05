inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "白云山庄偏厅");
        set("long", @LONG
偏厅里摆着一百二十张八仙桌，每张桌旁都坐满了客人，只是，每个客人都板着
脸，紧张得神经兮兮的样子。似乎发生了什么意外之事。几个满头珠翠的妇人，手里
捧着碗茶，在和旁边的女伴窃窃私语。
LONG       );
        set("exits", ([ 
		"west": __DIR__"yuanvillage2",
	]));
        set("objects", ([
			__DIR__"npc/guest1":	2,
			__DIR__"npc/guest2":	2,
	]) );
	set("coor/x",-45);
        set("coor/y",30);
        set("coor/z",10);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
