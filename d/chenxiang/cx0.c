// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "沉香城北门");
        set("long", @LONG
城门很大，而且很新，一看就是今几年才建起来的。门前的广场种了一棵棵小
树，特别的可爱。暗青色的石砖埔出一条相当宽的马路，连石砖的棱角还没有磨损。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"chenxiang3",
  "southeast" : __DIR__"cx1",
]));
        set("objects", ([
        __DIR__"npc/cg": 2,
                        ]) );
        set("outdoors", "chenxiang");
	set("coor/x",-20);
	set("coor/y",50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
