// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "石峰入口");
        set("long", @LONG
再往前走，但见前面一座高插入云的怪石奇峰，正如蹲伏的恶兽挡在前面。但
石峰中竟有条小路，蜿蜒曲折，如羊肠盘旋，恰到自然地通向石峰群中。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"road3",
  "west" : __DIR__"road1",
]));

        set("outdoors", "fengyun");
	set("coor/x",20);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
