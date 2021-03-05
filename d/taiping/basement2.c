#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "石牢");
        set("long", @LONG
抬头望去。上面也是一片黑暗，黑暗中却有尺许的一片迷朦的亮光。那一片亮
光黑暗中透着蓝色，还有几点昏黄的亮光在闪烁。是星光。上面是天空。星光碧绿
而暗淡，照不到下面，那个洞口周围却照得非常清楚。每一面石壁都四丈过外，四
面石壁合成了这一个两丈多的石牢。
LONG
        );
        set("exits", ([ 
		"west":  __DIR__"basement",
		"north": __DIR__"basement3",
		"up": 	__DIR__"yuanzi",
	]));
	set("objects", ([
        	__DIR__"npc/daniang2": 1,       	
    	]) );
        set("no_fly",1);
        set("item_desc", ([
	
	 ]));
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object me,string dir) {
        object evil;
	
	if( userp(me) && dir == "up" ) {
		evil=present("li daniang",this_object());
		if (evil) {
			message_vision(evil->name()+"挡住了你上跃的去势。\n",me);
			return notify_fail("");
		}
	}
	return 1;
}