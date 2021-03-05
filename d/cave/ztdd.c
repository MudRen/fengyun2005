// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit __DIR__"cave_mine";
#include <ansi.h>

void create()
{
        set("short", "天中道东");
        set("long", @LONG
这里是个十字路口，西面的叉口以前可以直接通到天外天的中心，现在却被一
堵高墙挡住了。可是白天在这里依旧可以看到中心的园坛洞顶，从圆洞直射下来的
天光形成的圆柱。
LONG
        );
   	set("exits", ([ /* sizeof() == 4 */
  		"north" : __DIR__"btdl",
  		"south" : __DIR__"ntdl",
  		"west" : __DIR__"zddm",
		"southeast" : __DIR__"ztddn",
	]));
        set("indoors", "cave");
	set("coor/x",10);
	set("coor/y",-5);
	set("coor/z",0);
	setup();
}


