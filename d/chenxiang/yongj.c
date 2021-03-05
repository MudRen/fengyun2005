// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "田记杂货");
        set("long", @LONG
店面小而且杂乱，谁也不清楚这里卖什么不卖什么，什么可以买，什么不可以
买。外面的臭气时而不时地飘进来，令人作呕。杂货店的墙上划满了各种各样的记
号，给这里罩上了神秘的气氛。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxw3",
]));
        set("objects", ([
        __DIR__"npc/tianpeng": 1,
                        ]) );
	set("coor/x",-30);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
