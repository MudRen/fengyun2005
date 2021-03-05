// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "石峰群");
        set("long", @LONG
这里是一片岩石，大大小小，各色各样，千奇百怪的岩石。大的如石峰排云，
高入云霄，直插入穹苍中；小的也高有数十丈，如太古洪荒时的恶龙怪兽，静静地
蹲踞在那里，等着将全人类俱都吞噬。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"entrance",
  		"east" : __DIR__"road2",
	]));

        set("outdoors", "fengyun");
	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
