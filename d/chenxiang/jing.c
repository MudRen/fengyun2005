// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "净水阁");
        set("long", @LONG
两三级台阶，朱红大门一扇，崭新的窗户纸，连门槛都丝毫没有磨损。从这里
一眼就可以看到东边的紫竹林，如果再仔细一点的话，还可以看到竹林中的小亭。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cxs6",
]));
        set("objects", ([
        __DIR__"npc/jadeowner": 1,
                        ]) );
	set("coor/x",-10);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
