#include <room.h>
inherit DOOR_ROOM;

void create()
{
        set("short", "卧室");
        set("long", @LONG
这是淳于堡主起居的地方。东面的楼梯向下通向黑松阁东厅，西面的楼梯向下
通向黑松阁西厅。北面是一个小小的阳台。南面则是堡主的膳房。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
	  "north" : __DIR__"yiantai",
	  "south" : __DIR__"kitchen",
	  "westdown" : __DIR__"west_blackge",
	  "eastdown" : __DIR__"east_blackge",
	]));
        create_door("south", "door","玉帘门", "north", DOOR_CLOSED);


	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",30);
	setup();
}

