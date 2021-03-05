// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "灌木丛");
        set("long", @LONG
这里的灌木低而杂乱且生有倒刺儿。山风吹来，阴冷而又腥臭，使人不寒而颤，
不再带有后山坡草坪的清香。再往前走则是峭壁如削的万丈悬崖，令人望而生畏，止
步不前。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"lake",
  "south" : __DIR__"upriver",
]));
	set("outdoors","wanmei");
        set("objects", ([
                __DIR__"npc/bihu" :1,
                        ]) );
	set("coor/x",20);
	set("coor/y",110);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
