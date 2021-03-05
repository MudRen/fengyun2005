// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "玄武门东");
        set("long", @LONG
一块块一尺见方的青砖，砖缝里长满了绿油油的嫩草。草特别的齐，一看就是
有人在精心地打理。阳光洒在地上，就象是个巨大的围棋盘。几只小鸟叽叽喳喳地
在地上寻食，偶尔人过，便扑腾腾地飞起。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"cxs3",
  "east" : __DIR__"fydao1",
]));
        set("objects", ([
        __DIR__"npc/yj": 1,
        __DIR__"npc/taijian": 1,
                        ]) );

        set("outdoors", "chenxiang");
	set("coor/x",10);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
