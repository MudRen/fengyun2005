inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "马房");
        set("long", @LONG
英雄都爱良驹。老伯却是例外，他从不将马看成玩物，马只不过是他的工具。
他很少来马房，但马房里的人并不敢因此而疏忽，所以每匹马都被养得很健，顶头
的两匹马上终日备着马鞍，随时可以出发。
LONG
        );
        set("exits", ([ 
		"east" :   __DIR__"garden3",
	]));
        set("objects", ([
        	__DIR__"npc/fenghao":	1,
	]) );
        set("coor/x",-1360);
        set("coor/y",950);
        set("coor/z",-50);
	set("map","zbeast");
	setup();
}
