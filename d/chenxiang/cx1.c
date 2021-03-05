// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "沉香城旧街");
        set("long", @LONG
这里是当年沉香镇北街，街道由暗青色的石砖铺成，已经相当的破旧。街道虽
然已经加宽，但还是只能让一辆四轮马车通过。在这里你可以隐隐约约闻到刚刚出
锅的面饼的香味。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"cx0",
  "southeast" : __DIR__"cx2",
  "west" : __DIR__"mian",
]));
        set("objects", ([
        __DIR__"npc/moo": 1,
        __DIR__"npc/ditou" : 2,
//        __DIR__"npc/linshouou" : 1,
                        ]) );
        set("outdoors", "chenxiang");
	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
