inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "小木屋顶");
        set("long", @LONG
一个扁平的乌木箱几乎占据了整个屋顶。乌木箱制作精细，滴水不漏，箱中灌
满泉水。每当夏日骄阳直射，箱中泉水就被晒热，再由竹管流下，供人沐浴。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"woodhouse",
]));
        set("outdoors", "wanmei");
        set("objects", ([
        __DIR__"npc/dodo": 1,
                        ]) );
	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
