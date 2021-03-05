inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "海子山");
        set("long", @LONG
海子指的是高山上的湖泊，在这高原的山上竟然有几百个湖泊，如天空不经意
滴下的眼泪，散落于嶙嶙乱石间。湖畔铺天盖地、千奇百怪却又形神兼备的天然石
雕令人震颤又令人恐惧，不由想起陈子昂的诗，“前不见石人，后不见来者，念天
地之悠悠，独怆然而涕下”。
LONG
        );
        set("exits", ([ 
		"northdown" : __DIR__"valley2",
		"southeast":  __DIR__"lake1",
		"eastdown":  __DIR__"hanmei",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-2060);
        set("coor/y",560);
        set("coor/z",40);
	set("map","zbwest");
	setup();

}
