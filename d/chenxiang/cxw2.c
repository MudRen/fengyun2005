// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "西巷");
        set("long", @LONG
这里的道路已经不如其他的地方宽了，坑坑洼洼的，有些砖已经松动，踩上去
晃晃荡荡，在雨天就会发出“呼呲”的声音。如果刮风的话，则黄风飞扬，使每个
路人都灰头土脸的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"beix",
  "south" : __DIR__"nanx",
  "west" : __DIR__"cxw3",
  "east" : __DIR__"cxw1",
]));
        set("outdoors", "chenxiang");
	set("coor/x",-20);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
