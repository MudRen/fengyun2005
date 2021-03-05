// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "东南门");
        set("long", @LONG
几垛刚刚烧好的砖坯堆放在这里，还有新鲜的沙石和泥土，似乎正要进行一个
大规模的工程。路边被凿了个大洞，直通下面的地下河，洞上有个架子，上面有个
木桶，似乎是用来吊水的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zl",
  "east" : __DIR__"tdnd",
]));
        set("indoors", "cave");
	set("coor/x",6);
	set("coor/y",-14);
	set("coor/z",0);
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
	setup();
}
