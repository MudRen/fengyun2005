// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "老石桥");
        set("long", @LONG
这里充分地显示着江南小镇那种独特仅有的风格，园拱形的小桥横跨一条弯弯
的小河流。桥下的流水被浮萍染成爱人的翠绿。偶尔一两只轻舟划过，带动着河边
的莲藕。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"cx3",
  "south" : __DIR__"cxcenter",
]));
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
