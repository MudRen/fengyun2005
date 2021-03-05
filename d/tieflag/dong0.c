// Room: dong0
inherit ROOM;
#include <room.h>

void create()
{
        set("short", "山隙中");
        set("long", @LONG
这是山壁间一条一尺多宽的山隙，被附生在壁上的蔓草藤萝遮掩，不加仔细探
查很难发现。
LONG
        );

       set("exits", ([ /* sizeof() == 2 */
  		"east" : AREA_EASTCOAST"troad3",
  		"westdown" : __DIR__"dong1",
 
]));
         
	set("coor/x",70);
	set("coor/y",-10);
	set("coor/z",50);
	setup();
	replace_program(ROOM);

}

