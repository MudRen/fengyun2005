inherit DOOR_ROOM;
#include <room.h>

void create()
{
        set("short", "海滩");
        set("long", @LONG
这里似乎已经到了海滩的尽头，原先也许还是渔村，但却似突然遇着个重大的
变故，是以此时早已荒废，只见海滩上尽是已将腐朽的破船，仅剩的十余间木屋也
是东倒西歪，不成模样。西边一间最大的木屋，木屋破破烂烂，在海风里呜呜地响，
随时都可能倒塌。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"house",
		"north" : __DIR__"village3",
		"east" : __DIR__"village",
	]));
        set("outdoors", "tieflag");
	set("item_desc", ([
	 ]));
	set("coor/x",900);
	set("coor/y",20);
	set("coor/z",0);
	setup();
	create_door("west","door","木门","east",DOOR_CLOSED);
}

