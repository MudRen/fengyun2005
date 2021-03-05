// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "东中道");
        set("long", @LONG
北高南低，整个路面都是倾斜的。虽然洞里光线不好，这里的火烛比别的地方
都多。路边堆放着一大排木桶，有大有小，里面装满了水，似乎是在紧急时救火用
的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tt",
//  "east" : __DIR__"zddm",
]));
        set("objects", ([
          __DIR__"obj/woodbarrel": 3,
                        ]) );
        set("indoors", "cave");
	set("coor/x",6);
	set("coor/y",-4);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

/*
int valid_leave(object obj, string dir){
	object ma;
	if(dir == "west"){
		if(!obj->query("vendetta/authority") && present("mao zhan", this_object())){
			ma = present("mao zhan", this_object());
			return notify_fail(ma->name()+"闪身挡住了你的路。\n");
		}
	}	
	return 1;
}
*/
