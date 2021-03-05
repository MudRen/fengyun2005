#include <room.h>
inherit DOOR_ROOM;

void create()
{
        set("short", "膳房");
        set("long", @LONG
这是淳于堡主的用膳房。整个房间飘荡着上等竹叶青的酒香和令人垂滟欲滴的
烤山猪的香气。你似乎听到你的肚子在“咕咕咕”的叫了起来。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"bedroom",
]));
        set("objects", ([
                __DIR__"obj/pigmeat" : 3,
		__DIR__"obj/qiwine" : 3,
		__DIR__"npc/cook" : 1,
        ]) );


        create_door("north", "door","玉帘门", "south", DOOR_CLOSED);

	set("coor/x",-10);
	set("coor/y",30);
	set("coor/z",30);
	setup();
}

