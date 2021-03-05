inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山村西首");
        set("long", @LONG
道路两旁，已有房舍，每一栋屋，建造得极精巧。行人也多了起来，赶早的农
夫，摆摊的小贩，偶尔还能见到几个小孩在互相追逐，伴着几声汪汪的犬吠。一条
打扫得干干净净的青石小路通向山村中心。
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"valley1",
	"east" : __DIR__"vroad2",
	"south" : __DIR__"vroad1a",
	"north" : __DIR__"vroad1b",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",40);
        set("coor/y",60);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
