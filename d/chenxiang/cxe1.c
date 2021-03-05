// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "东街");
        set("long", @LONG
这里的街道显得比较荒芜。一条小溪顺着街北静静地流淌，每当太阳落山，一
阵阵的浓雾便从东面的莽林渗来，渐渐地将整个沉香城吞没在烟雾迷漫之中。直到
第二天太阳高照，浓雾才渐渐散去。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cxe2",
  "west" : __DIR__"cxcenter",
]));
        set("outdoors", "chenxiang");
	set("coor/x",10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
