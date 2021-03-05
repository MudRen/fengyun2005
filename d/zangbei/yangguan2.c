inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "大漠");
        set("long", @LONG
茫茫一片雪白，什么也没有，连一个皱折也找不到。没有边，没有际。天边渐
渐飘出几缕烟迹，并不动，却在加深，疑惑半晌，才发现，那是刚刚化雪的山脊。
偶尔地平线上会有几峰驼影，那是跋涉的商旅。
LONG
        );
        set("exits", ([ 
		"northwest" : __DIR__"kunlun1",
		"southeast" : __DIR__"yangguan1",
		"south" : __DIR__"yangguan1a",
		"east" : __DIR__"yangguan1b",
	]));
        set("objects", ([
        	        __DIR__"npc/traveler" : 2,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-300);
        set("coor/y",300);
        set("coor/z",0);
	set("map","zbeast");
	setup();
}
