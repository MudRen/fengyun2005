inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "枯梅堂");
        set("long", @LONG
堂中洁净如洗，檀香飘渺。此堂虽以枯梅命名，却实为上好檀香木打造。房顶
很高，上挂八盏油灯，灯芯闪烁散发出袅袅白烟。阳光映射白烟，留下条条光痕。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"frontyard",
  "east" : __DIR__"yard",
]));
        set("objects", ([
        __DIR__"npc/oldman": 1,
                        ]) );

	set("coor/x",-20);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
