inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "客房");
        set("long", @LONG
老伯的客人很多，这儿就是客人住的屋子之一。老伯从不托词推诿，也绝不空
口许诺，只要他答应了你，天大的事你都可以放在一边，因为他绝不令你失望。你
不必给他任何报酬甚至于不必是他的老朋友。无论你多么孤苦穷困，他都会将你的
问题放在心上，想办法为你解决。
LONG
        );
        set("exits", ([ 
		"south" :   	__DIR__"garden2",

	]));
        set("objects", ([
        	__DIR__"npc/lumantian":		1,
	]) );
        set("coor/x",-1320);
        set("coor/y",980);
        set("coor/z",-50);
	set("map","zbeast");
	setup();
}
