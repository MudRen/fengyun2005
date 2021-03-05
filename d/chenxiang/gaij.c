// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "丐帮分舵");
        set("long", @LONG
只有丐帮才会在这里开分舵，才能够忍受这里的脏和臭。除非是和丐帮有不戴
共天的大仇家才会到这里来。这里就象个大垃圾场，而这里的人就象是在垃圾里蠕
动的蛆。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"cxw3",
]));
        set("objects", ([
        __DIR__"npc/gm": 1,
        __DIR__"npc/gaibang3": 1,
        __DIR__"npc/gaibang2": 1,
        __DIR__"npc/gaibang1": 1,            
                        ]) );
	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
