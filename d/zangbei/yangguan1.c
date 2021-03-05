inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "大漠");
        set("long", @LONG
再往前走，沙漠无边无际，除了茫茫一片雪白什么也没有，连一个皱折也找不
到。远处是西北的群山，都积着雪，层层叠叠，直伸天际。在这样的天地中独个儿
行走，侏儒也变成了巨人，在这样的天地中独个儿行走，巨人也变成了侏儒。
LONG
        );
        set("exits", ([ 
		"northwest" : __DIR__"yangguan2",
		"southeast" : __DIR__"yangguan",
		"west" : __DIR__"yangguan1a",
		"north" : __DIR__"yangguan1b",
	]));
        set("objects", ([
        	
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-100);
        set("coor/y",100);
        set("coor/z",0);
	set("map","zbeast");
	setup();
}
