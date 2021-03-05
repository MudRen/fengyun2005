// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "天外天");
        set("long", @LONG
一个巨大的岩洞展现在眼前，岩洞的顶极其的高，几乎一眼望不到顶。上面垂
下来的钟乳石也有几丈长，如果不仔细看，真的不敢相信这是在地下。在昏暗的灯
光中，钟乳石的影子晃来晃去，就象一棵棵小树。一阵阵的阴风不知道从什么地方
吹来。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"td",
  "south" : __DIR__"qszl",
  "east"  : __DIR__"tdbd",
  "west"  : __DIR__"tsbd",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("indoors", "cave");
	set("coor/x",-5);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}
