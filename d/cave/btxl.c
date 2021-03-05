// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "北天西路");
        set("long", @LONG
路边的暗河已经可以看见了，由于北高南低，这里居然形成一个小小的瀑布，
瀑布的流水很急，发出哗哗的声音。瀑布过后，暗河又隐入地面不见了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"btxm",
  "south" : __DIR__"tzdx",
]));
        set("indoors", "cave");
	set("coor/x",-20);
	set("coor/y",-10);
	set("coor/z",0);
	setup();

}
