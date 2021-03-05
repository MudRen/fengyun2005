// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "青石中路");
        set("long", @LONG
北高南低，整个洞地就象是倾斜的木板。从这里可以彻底地体会到这洞有多大。
由于坡度太大，每块条石高度相差甚多，就和台阶一样。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"tnzl",
  "east" : __DIR__"dnm",
  "west" : __DIR__"xnm",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//	__DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("indoors", "cave");
	set("coor/x",4);
	set("coor/y",-14);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
