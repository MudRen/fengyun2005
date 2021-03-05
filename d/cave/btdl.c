// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit __DIR__"cave_mine";
#include <ansi.h>

void create()

{
        set("short", "北天东路");
        set("long", @LONG
石碑成群，有的破碎，有的躺倒，还有的被泥土淹没了一半。由于地下潮湿，
石碑都已经被青苔腐蚀了，上面刻的什么已经看不清楚。一不小心就可能别石碑绊
倒。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"btdm",
  "south" : __DIR__"ztdd",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("indoors", "cave");
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}
