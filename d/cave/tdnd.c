// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "天东南道");
        set("long", @LONG
几辆小土车随便地放在路边，有的还装满了湿湿的泥土，似乎要被运送到别的
地方。还有一些不知道名字的工具都堆放在这里，似乎全部是用来开山的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"dnm",
  "east" : __DIR__"dnj",
]));
        set("objects", ([
        __DIR__"obj/dolly": 2,
                        ]) );
        set("indoors", "cave");
	set("coor/x",8);
	set("coor/y",-14);
	set("coor/z",0);
	setup();

}

