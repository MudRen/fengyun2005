inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "    ");
        set("long", @LONG[1;33m
　　　　　　　　　　　　　　　　　　　　　　☆
　　　　　　　　　　　　　☆
　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
　　　　　　　　　　☆　　　　　　　　　☆
　　　　　　　　　　　　　　　　　　　　　　　　　　　　　☆
　　　☆
　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　
　　　　　　　　　　　　　☆
　　　　　　　　　　　　　　　　　　　　　　　　　　　☆

		☆
				           ☆
		      ☆	


			              [0;37m为你  摘下  满天星[32m
	
LONG
        );
        set("exits", ([ 
		"down": __DIR__"star_room1",
	]));
        set("objects", ([
        	
	]) );
        set("coor/x",-1690);
        set("coor/y",640);
        set("coor/z",10);
        set("no_fly",1);
	set("map","zbwest");
	setup();

}
