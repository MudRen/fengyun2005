// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "木牢");
        set("long", @LONG
这里微微向南转，中心的天光已然不见，路也越行越狭窄，很快就到了青龙地
城五行大牢的木牢，四处石壁上每隔一段便有个插在石壁上的火炬，火光不停的跳
动，一切都笼罩在昏暗的红色光芒之下。牢中放满了藤条，木棍，木蒺藜。。各种
扭曲的刑具上似乎在吸食着活人的鲜血，闪耀着灰暗的血色。
LONG
        );
   	set("exits", ([ /* sizeof() == 4 */
  		"northwest" : __DIR__"ztdd",
	]));
        set("indoors", "cave");
	set("coor/x",12);
	set("coor/y",-8);
	set("coor/z",0);
        set("objects", ([
        __DIR__"npc/guard4": 1,
                        ]) );
	setup();
}


