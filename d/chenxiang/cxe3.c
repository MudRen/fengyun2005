// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "镇东首");
        set("long", @LONG
这里已经是沉香城的最东边。从镇里延伸出来的道路在这里渐渐趋于无影无踪。
茅草越来越厚，景色越来越荒凉。再往东就是漫无边际的莽林。据老一辈的人讲，
莽林中既有杀机四伏的陷阱，也隐有武功盖世的奇侠。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : AREA_MANGLIN"edge1",
  "west" : __DIR__"cxe2",
  "south" : __DIR__"dangpu",
]));
        set("objects", ([
        __DIR__"npc/girl": 2,
                        ]) );
        set("outdoors", "chenxiang");
	set("coor/x",30);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
