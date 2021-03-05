#include <room.h>
inherit DOOR_ROOM;

void create()
{
        set("short", "黑松阁西厅");
        set("long", @LONG
这是黑松堡主淳于怀太迎宾的西厅。整个大厅布置的雍荣典雅。向东是黑松阁
的正厅，向西和向北都是精心修剪过的花园。楼上则是淳于巨大的睡房。南面是一
个小小的储藏室。
LONG
        );
        set("exits", ([ /* sizeof() == 5 */
  "eastup" : __DIR__"bedroom",
  "east" : __DIR__"center",
  "west" : __DIR__"west_garden",
  "south" : __DIR__"storage",
  "north" : __DIR__"north_garden",
]));
        set("objects", ([
                __DIR__"npc/guard" : 2,
        ]) );

        create_door("south", "door","木门", "north", DOOR_CLOSED);

	set("coor/x",-20);
	set("coor/y",40);
	set("coor/z",20);
	setup();
}

