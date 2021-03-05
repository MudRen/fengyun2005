// Copyright (C) 2002, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "小茅厕");
        set("long", @LONG
茅厕通风良好，干净清爽。几个带盖的白玉小马桶整齐地排列在墙边。每个马
桶上还有一个挂钩，好象是可以挂在扁担上的。墙上挂着一个马鬃木刷还正在滴着
水。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
  		"north" : __DIR__"backyard",
	]));
    set("objects", ([
		__DIR__"obj/matong":2,
		__DIR__"obj/brush" : 1,
    ]) );

	set("coor/x",10);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

void reset(){
	object obj;
	::reset();
	if(!present("matong", this_object())){
		obj = new(__DIR__"obj/matong");
		if(objectp(obj)){
			obj->move(this_object());
		}
		obj = new(__DIR__"obj/matong");
		if(objectp(obj)){
			obj->move(this_object());
		}
	}
	if(!present("brush", this_object())){
		obj = new(__DIR__"obj/brush");
		if(objectp(obj)){
			obj->move(this_object());
		}
	}
	return;
}