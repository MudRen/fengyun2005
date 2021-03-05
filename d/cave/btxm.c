// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "北天西门");
        set("long", @LONG
这里的地势比西北角低多了，路面上的裂缝中都是一条条小水流在急急地向南
流着。水流中有着缕缕的青苔，使整个路面湿滑无比。一不小心就会滑一跤。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"sbj",
  "south" : __DIR__"btxl",
]));
        set("objects", ([
        __DIR__"obj/lichen": 1,
                        ]) );
        set("indoors", "cave");
	set("coor/x",-20);
	set("coor/y",0);
	set("coor/z",0);
	setup();

}
