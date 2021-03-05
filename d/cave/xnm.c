// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "西南门");
        set("long", @LONG
铺路用的石头在这里散乱地堆放着，还有一些零散的工具。向南的地方有个大
洞，一看就是刚刚刨出来的。似乎是这里的主人嫌这里不够大，想从此再向南扩张。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"txnd",
  "east" : __DIR__"zl",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("indoors", "cave");
	set("coor/x",3);
	set("coor/y",-14);
	set("coor/z",0);
	setup();

}
