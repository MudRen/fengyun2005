// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "天南中路");
        set("long", @LONG
路面向南越来越低了，从这儿可以看到南边的洞顶，似乎和脚面一边齐。南边
的房屋全部在脚下，房屋中的点点灯火点缀着一片黑暗，就象是夜里的萤火虫。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"tnzm",
  "south" : __DIR__"zl",
]));
        set("objects", ([
          __DIR__"npc/maozhan": 1,
                        ]) );
        set("indoors", "cave");
	set("coor/x",4);
	set("coor/y",-8);
	set("coor/z",0);
	setup();
}


int valid_leave(object obj, string dir){
	object ma;
	if(dir == "north"){
		if(!obj->query("vendetta/authority") && present("mao zhan", this_object())){
			ma = present("mao zhan", this_object());
			return notify_fail(ma->name()+"闪身挡住了你的路。\n");
		}
	}	
	return 1;
}
