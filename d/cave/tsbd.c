// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "天西北道");
        set("long", @LONG
紧靠洞边，洞壁笔直，根本无法攀爬。一个个火把忽明忽暗。洞壁上有很多的
裂缝，不是地渗出一滴滴的水珠，把整条路弄得湿湿的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"twt",
  "west" : __DIR__"sbm",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("indoors", "cave");
	set("coor/x",-10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
