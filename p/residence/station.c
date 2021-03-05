#include <ansi.h>


inherit ROOM;
void create ()
{
  set ("short", CYN"上天梯"NOR);
  set ("long", @LONG

LONG);
        set("exits", ([ 
  "up" : __DIR__"enterance",
  "down" : "/d/fy/station",
]));
  	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",-10);
	setup();
}
