// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "背阴西路");
        set("long", @LONG
两边的建筑高大而且肮脏，遮住了大部分的天空和所有的阳光。就是再好的天
这里也有一股发霉的味道。路边的坑洼积满了恶臭的脏水，一不小心就会溅一身。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"gaij",
  "south" : __DIR__"yongj",
  "west" : __DIR__"cxw4",
  "east" : __DIR__"cxw2",
]));
        set("outdoors", "chenxiang");
	set("coor/x",-30);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
