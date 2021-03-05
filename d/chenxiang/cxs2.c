// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "沉香城南路");
        set("long", @LONG
这里离沉香台很近，还可以看到竹林的影子。四周都是崭新的，一看就是刚刚
开发出来的地方。往北是老城区，往南则是新建起来不久的地带。路旁的城隍庙是
唯一带着原来气息的建筑，和对面新开张的菜根香小店形成鲜明对照。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxcenter1",
  "west" : __DIR__"ch",
  "east" : __DIR__"cag",
  "south" : __DIR__"cxs3",
]));
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
