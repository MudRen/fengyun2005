inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "大沙漠");
        set("long", @LONG
虽然是同一个太阳，但这太阳到了沙漠上，就忽然变得又狠又毒，像是要将整
个沙漠都晒得燃烧起来似的。没有风，一丝风都没有，也没有丝毫声音，在烈日下，
沙漠上所有的生命，都已进入了一种晕死状态，热气从沙漠里蒸发出来，热得令人
恨不得把身上衣裳都脱光。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"yangguan1d",
		"south" : __DIR__"yangguan1d",
		"east" : __DIR__"yangguan1d",
		"north" : __DIR__"yangguan1d",
	]));
        set("objects", ([

	]) );
	set("outdoors", "zangbei");
        set("coor/x",-90);
        set("coor/y",300);
        set("coor/z",0);
        set("map","zbeast");
	setup();
}

int valid_leave(object obj, string dir){
	object room;
	
	switch (random(5)) {
		case 0: room = find_object(__DIR__"desert_cabin");
			tell_object(obj,YEL"走啊走，前面似乎有了几户人家！\n"NOR);
			if (!room) room = load_object(__DIR__"desert_cabin");
			obj->move(__DIR__"desert_cabin");
			return notify_fail("");
		case 1: room = find_object(__DIR__"desert_ambush");
			tell_object(obj,YEL"走啊走，前面是个小土丘，土丘后隐约传来求救声！\n"NOR);
			if (!room) room = load_object(__DIR__"desert_ambush");
			obj->move(__DIR__"desert_ambush");
			return notify_fail("");
		case 2: room = find_object(__DIR__"yangguan1d");
			tell_object(obj,YEL"走啊走，你在沙漠里越走越深！\n"NOR);
			if (!room) room = load_object(__DIR__"yangguan1d");
			obj->move(__DIR__"yangguan1d");
			return notify_fail("");	
		default: room = find_object(__DIR__"yangguan1c");
			tell_object(obj,YEL"走啊走，前面沙地上有脚印。。。原来你又回到了原地！\n"NOR);
			if (!room) room = load_object(__DIR__"yangguan1c");
			obj->move(__FILE__);
			return notify_fail("");	
	}	
	
	return 1;
}

void init() {
	add_action("do_go","go");
}

int do_go (string arg)
{
   	object obj, room;
   	obj = this_player();
	
	if (arg != "west" && arg != "south" && arg !="north" && arg!="east")	return 0;
		
	switch (random(5)) {
		case 0: room = find_object(__DIR__"desert_cabin");
			tell_object(obj,YEL"走啊走，前面似乎有了几户人家！\n"NOR);
			if (!room) room = load_object(__DIR__"desert_cabin");
			obj->move(__DIR__"desert_cabin");
			break;
		case 1: room = find_object(__DIR__"desert_ambush");
			tell_object(obj,YEL"走啊走，前面是个小土丘，土丘后隐约传来求救声！\n"NOR);
			if (!room) room = load_object(__DIR__"desert_ambush");
			obj->move(__DIR__"desert_ambush");
			break;
		case 2: room = find_object(__DIR__"yangguan1d");
			tell_object(obj,YEL"走啊走，你在沙漠里越走越深！\n"NOR);
			if (!room) room = load_object(__DIR__"yangguan1d");
			obj->move(__DIR__"yangguan1d");
			break;	
		default: room = find_object(__DIR__"yangguan1c");
			tell_object(obj,YEL"走啊走，前面沙地上有脚印。。。原来你又回到了原地！\n"NOR);
			if (!room) room = load_object(__DIR__"yangguan1c");
			obj->move(__FILE__);
			break;	
	}	
	
	return 1; 	
}
