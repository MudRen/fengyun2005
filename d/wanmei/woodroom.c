inherit ROOM;
// Copyright (C) 2002, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "小柴房");
        set("long", @LONG
一间小而简陋的木屋，但并不漏雨。墙角整齐地堆着一捆捆干柴。墙上钉着一
个木架，架上挂着一些砍柴用的工具。一条长凳放在屋子中央。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"frontyard",
	]));
    set("objects", ([
        __DIR__"obj/chair": 1,
		__DIR__"obj/rope" : 1,
		__DIR__"obj/drywoods" : 4,
    ]) );

	set("coor/x",-30);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}

void reset(){
	object obj;
	int i;

	::reset();
	if(!present("rope", this_object())){
		obj = new(__DIR__"obj/rope");
		if(objectp(obj)){
			obj->move(this_object());
		}
	}
	if(!present("chair", this_object())){
		obj = new(__DIR__"obj/chair");
		if(objectp(obj)){
			obj->move(this_object());
		}
	}
	if(!present("woods", this_object())){
		for(i=0; i < 5; i++){
			obj = new(__DIR__"obj/drywoods");
			if(objectp(obj)){
				obj->move(this_object());
			}
		}
	}
	return;
}