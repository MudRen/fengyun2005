// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "火牢");
        set("long", @LONG
这是青龙会这个死亡地狱中的一个火牢，凡是被青龙会捉拿的侠士官差，大半
都会送到这里严加烤问一凡，而几乎没有人能承受的住这炼狱一般的审讯，从来没
有，除了一个人，那人就是刚被『七月十五』舵主西门玉提去的青龙会叛徒高立。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"twt",
//  "south" : __DIR__"tbzl",
]));
        set("objects", ([
        __DIR__"npc/guard1": 1,
                        ]) );
        set("indoors", "cave");
	set("coor/x",-5);
	set("coor/y",5);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
