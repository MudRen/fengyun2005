inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "大漠");
        set("long", @LONG
再往前走，沙漠无边无际，除了茫茫一片雪白什么也没有，连一个皱折也找不
到。远处是西北的群山，都积着雪，层层叠叠，直伸天际。在这样的天地中独个儿
行走，侏儒也变成了巨人，在这样的天地中独个儿行走，巨人也变成了侏儒。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"yangguan2",
		"south" : __DIR__"yangguan1",
		"east":	__FILE__,
		"north": __FILE__,
			
	]));
        set("objects", ([

	]) );
	set("outdoors", "zangbei");
    set("coor/x",-100);
    set("coor/y",300);
    set("coor/z",0);
	set("map","zbeast");
	setup();
}


void init() {
	add_action("do_south","go");
}

int do_south (string arg)
{
   	object me, room;
   	me = this_player();
	
	if (arg != "west" && arg != "south" && arg !="north" && arg!="east")	return 0;
		
	if (random(3) || arg ==" west" )	return 0;
   	
   		tell_object(me,YEL"走着走着，你惊恐地发现。。。你已经迷路了！！！\n"NOR);
      	room = find_object(__DIR__"yangguan1c");
		if (!room) room = load_object(__DIR__"yangguan1c");
		me->move(room);
      	return 1; 	
}
