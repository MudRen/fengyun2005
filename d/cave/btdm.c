// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "北天东门");
        set("long", @LONG
这里的洞顶突然降低许多，就好象一个天然的屋顶。屋顶被一排密密的钟乳石
支撑着，形成一面墙。而墙的中间又有一丈多宽的空隙，刚好让条石横着铺过。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"dbj",
  "south" : __DIR__"btdl",
]));
        set("indoors", "cave");
	set("coor/x",10);
	set("coor/y",5);
	set("coor/z",0);
        setup();

}
