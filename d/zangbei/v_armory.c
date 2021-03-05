inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "武器库");
        set("long", @LONG
强盗们也有兵器库，而且种类还很全，但见室中壁上、桌上、架上、柜中。几
间，尽皆列满兵刃，式样繁多，虽不是名刀名剑，却也是保养得锋锐如新。引人注
目的是靠墙放着一溜长弓，龙虎寨的强盗们个个擅长弓箭之术，其中更有数十个佼
佼者号称能百步穿杨，这些强弓便是他们的兵器。
LONG
        );
        set("exits", ([ 
		"west":	__DIR__"village",
	]));
        set("objects", ([
	]) );
        set("coor/x",-1520);
        set("coor/y",560);
        set("coor/z",0);
	set("map","zbwest");
	setup();
}

