// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "玄武门西");
        set("long", @LONG
方砖，绿草。和东边没有什么两样。十丈方圆的地方显得特别的协调，不大也
不小。从这里可以清楚地望到不远处的旗杆和旗杆顶部的观望亭。只是这儿行人更
少，却时常有手执兵刃的官兵巡逻而过。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
          "east" : __DIR__"cxs3",
          "west" : AREA_WOLFMOUNT"yinroad1",
]));
        set("outdoors", "chenxiang");
	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
