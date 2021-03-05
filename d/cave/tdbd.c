// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "天东北道");
        set("long", @LONG
路很湿，墙也很湿，但并没有积水。在这里可以听到流水的声音，但并看不到
河流。天外天的暗河很多而且纵横交错，水流湍急而且杂乱无章。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"twt",
  "east" : __DIR__"dbm",
]));
        set("indoors", "cave");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
	setup();

}
