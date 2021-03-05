// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "内院");
        set("long", @LONG
一个空旷的黄土院子，院子很大，北面一道小土坡上是一道小小的木门。
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"jialan",
  "south" : __DIR__"neiyuan2",
]));
        set("outdoors", "shaolin");
	set("coor/x",0);
	set("coor/y",60);
	set("coor/z",10);
	setup();

}
