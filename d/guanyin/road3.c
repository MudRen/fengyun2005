// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "小路");
        set("long", @LONG
石峰中竟有一条小路，蜿蜒曲折，如羊肠盘旋，就算再多走几次也无法辨出方
向的......普天之下无论谁到了这里，也休想轻易出去。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"road2",
  "west" : __DIR__"road4",
  "northwest" : __DIR__"deep",
]));

        set("outdoors", "fengyun");
        set("objects", ([
        __DIR__"npc/jiao1" : 1,
        __DIR__"npc/jiao2" : 1,
                        ]) );
        
        
	set("coor/x",20);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
