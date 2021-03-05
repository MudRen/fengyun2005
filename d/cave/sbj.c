// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "西北角");
        set("long", @LONG
天外天呈长方形，这里是西北角。有一个大洞在角落里，一看就是用来丢垃圾
的。洞很深，而且有水流的声音。丢下去的垃圾全部被暗河冲走了。
LONG
        );
	set("exits", ([ /* sizeof() == 4 */
		"east" : __DIR__"sbm",
  		"south" : __DIR__"btxm",
	]));
    set("objects", ([
        __DIR__"npc/mabian": 1,
    ]) );
        set("indoors", "cave");
	set("coor/x",-20);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

int valid_leave(object obj, string dir){
	object ma;
	if(dir == "east"){
		if(!obj->query("vendetta/authority") && present("ma bian", this_object())){
			ma = present("ma bian", this_object());
			return notify_fail(ma->name()+"闪身挡住了你的路。\n");
		}
	}	
	return 1;
}
