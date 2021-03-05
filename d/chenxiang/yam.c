// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "衙门");
        set("long", @LONG
门前两个张牙舞爪的石狮，两门黝黑发亮的火炮，一扇看不透的乌门，再加上
墙上的一幅幅画像，将整个衙门笼罩在强烈的杀气中。就是再凶顽的匪徒到了这里
也要胆寒。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cxs4",
]));
        set("objects", ([
        __DIR__"npc/governor": 1,
        __DIR__"npc/yayi0": 1,
        __DIR__"npc/yayi": 2,
                        ]) );

	set("coor/x",-10);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
