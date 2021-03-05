inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "马家驿");
        set("long", @LONG
马家驿在二郎山下，本是个驿站，距离菊花园只有七八十里路，自从驿差改道，
驿站被废置，这地方就日渐荒凉。但无论多荒凉的地方都有人住的。现在这地方只
剩下十六七户人家，其中有个叫马方中的人．就住在昔日驿站的官衙里。
LONG
        );
        set("exits", ([ 
		"north":	__DIR__"wild1",
		"east":		__DIR__"mgarden",
	]));
        set("objects", ([
        	__DIR__"npc/mayueyun":	1,
        	__DIR__"npc/ma1":	1,
        	__DIR__"npc/ma2":	1,
	]) );
	
        set("coor/x",-1300);
        set("coor/y",680);
        set("coor/z",0);
        set("ma_room1",1);
	set("map","zbeast");
	setup();
}
