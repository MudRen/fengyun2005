// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "僧兵院");
        set("long", @LONG
这是少林僧兵居所，到这里的都是少林精英，屋中陈设远胜和尚院，上等竹席，
青丝绸被，屋内张贴字画，每床前更有红木桌一张，屋中更有几位少年僧人专职打
扫。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"luohan",
  "west" : __DIR__"wuku",
]));
	set("coor/x",-10);
	set("coor/y",80);
	set("coor/z",20);
	setup();

}
