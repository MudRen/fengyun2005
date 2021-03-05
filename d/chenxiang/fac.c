// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "法场");
        set("long", @LONG
这里的黄土已经不是黄色了，这里唯一的一根木桩也看不出本来的颜色了。在
这里流过的血已经足够把这里洗刷几遍的。尤其是木桩周围的泥土，都已经被血染
成暗褐色。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"cxs4",
]));
        set("objects", ([
        __DIR__"npc/poorghost": 1,
                        ]) );
        set("outdoors", "chenxiang");
	set("coor/x",10);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
