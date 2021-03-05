inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山沟");
        set("long", @LONG
环绕雪山的小路因为朝圣者的脚印变得宽阔，夕阳中朝圣者拉长的身影真实而
又缥缈。傍晚，疲劳一天的马在细细地吃草，疲劳一天的马夫也在雪峰下的密林深
处燃起袅袅炊烟。再过一会儿，酒足饭饱，朝圣者和马夫的歌声便在潮润的空气中
氤氲开来。
LONG
        );
        set("exits", ([ 
		"northeast" : __DIR__"echu",
		"southwest":  __DIR__"valley2",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-2040);
        set("coor/y",600);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}
