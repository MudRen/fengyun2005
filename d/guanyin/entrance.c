// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "石峰边缘");
        set("long", @LONG
这里不但像是已到了沙漠的尽头，简直像是到了天地的尽头。再往前走，便要
跌入百韧不复的深渊中。前面俱是石峰，无边无际，再也难往前走。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : AREA_QUICKSAND"desert2",
  "north" : __DIR__"road1",
]));

        set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
