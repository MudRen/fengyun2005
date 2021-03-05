// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "白梅阁");
        set("long", @LONG
此阁甚大，且由少而珍贵的白梅木精雕细琢而成。白梅木纹理清晰，木质洁白
并坚硬如大理石，且散发出一股淡淡的清香，经年不衰。厅中四凳一桌，亦白梅木
打造。整个伟阁白晰高雅，再以木纹加以点缀，别具一格。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"yard",
  "east" : __DIR__"backyard",
]));
        set("objects", ([
		__DIR__"npc/master" :1,
                        ]) );

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
