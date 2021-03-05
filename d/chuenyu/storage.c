#include <room.h>
inherit DOOR_ROOM;

void create()
{
        set("short", "储藏室");
        set("long", @LONG
一个小小的储藏室。四壁上布满了灰尘。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"west_blackge",
]));
        set("objects", ([
                "/obj/weapon/sword" : 5,
        ]) );

        create_door("north", "door","木门", "south", DOOR_CLOSED);
	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",20);
	setup();
}

