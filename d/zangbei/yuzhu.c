inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "玉龙峰");
        set("long", @LONG
终于来到玉龙峰下，巨大的山影，沉重地压在过往的车马上。风在呼号，却也
吹不开那阴森凄迷的云雾。山麓阴影中，有几个客商正在歇息。向西，一条大道黄
土飞扬，通向[33m边城[32m。向北则是通向[33m玉龙峰顶[32m的山路，崎岖而蜿蜒向上。
LONG
        );
        set("exits", ([ 
		"southeast" : __DIR__"kunlun3",
		"northup" :   AREA_EREN"road0",
		"west":		__DIR__"wild1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "eren");
        set("coor/x",-1100);
        set("coor/y",700);
        set("coor/z",0);
	set("map","zbeast");
	setup();
	replace_program(ROOM);
}
