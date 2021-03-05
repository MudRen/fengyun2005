// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "北城厢");
        set("long", @LONG
窗户发出“吱吱”的声音，上面的窗纸已经七零八落了。窗户框上面的油漆也
都剥落，而且被木虫蛀满了孔。土坯的墙已经被风化得不能再薄了，土坯里面的稻
草都似乎被风吹断了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"cxw2",
]));
        set("objects", ([
        __DIR__"npc/wang": 1,
                        ]) );
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
