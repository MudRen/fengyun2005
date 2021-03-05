inherit ROOM;
// Copyright (C) 2002, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "小木屋");
        set("long", @LONG
木屋只有半边顶，一棵老梅树盖住了那半边。墙上挂着几条浴巾，阳光透过树
枝照在浴巾上。一条竹管从房顶垂下，竹管的尽头塞着一个[37m木塞子[32m，偶尔还有水珠
滴下。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"frontyard",
]));
        set("objects", ([
        __DIR__"obj/towel": 1,
                        ]) );
        set("item_desc", ([
                "木塞子": "你似乎可以把它拔（ｐｕｌｌ）下来！\n",

        ]) );
	set("coor/x",-30);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
void init()
{
	add_action("do_pull","pull");
	add_action("do_climb","climb");
}


int do_pull(string arg)
{
	object me;
	if (arg == "木塞子" || arg == "木塞" || arg == "cork" ) {
		if(query("resource/water"))
			return notify_fail("木塞子已经被拔下来了。\n");
		me = this_player();
		message_vision("$N＂噗＂的一声将木塞子拔了下来，冒着热气的水马上流了下来。\n",me);
		set("resource/water",1);
		set("liquid/name","热水");
		call_out("remove_water",50);
		return 1;
	}
	return notify_fail("你要拔什么？\n");
}

int remove_water()
{
	tell_object(this_object(),"热水滴了几滴，就流光了。\n");
	delete("resource/water");
        delete("liquid/name");
	return 1;
}

int do_climb(string arg)
{
	object me,room;
	me = this_player();
	if (arg == "tree" || arg == "老梅树" || arg == "梅树") {
		message_vision("$N＂嗖＂的一声，顺着老梅树窜上屋顶。\n",me);
		room = find_object(__DIR__"roof");
		if (!room)
			room = load_object(__DIR__"roof");
		me->move(room);
		return 1;	
	}
	return notify_fail("你想爬什么？\n");
}

void reset(){
	object obj;
	::reset();
	if(!present("towel", this_object())){
		obj = new(__DIR__"obj/towel");
		if(objectp(obj)){
			obj->move(this_object());
		}
	}
	return;
}