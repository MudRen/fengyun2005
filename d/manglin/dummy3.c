inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "莽林之中");
        set("long", @LONG
四周古树参天，荆棘密布。浓密宽厚的树叶遮蔽了日月星辰，使人分不出昼夜。
四下如死一般的寂静，只有风吹过树梢的沙沙之声。偶尔一两声虎啸狼嚎随着腥风
飘至耳际。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"groupn3",
  "south" : __DIR__"groups3",
  "east" : __DIR__"groupe3",
  "west" : __DIR__"groupw3",
]));
        set("outdoors", "manglin");
	set("coor/x",110);
	set("coor/y",-10);
	set("coor/z",-40);
	setup();
        replace_program(ROOM);
}
