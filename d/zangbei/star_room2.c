inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "星星小院");
        set("long", @LONG
一栋小小的屋子，红色墙暗灰色的屋顶，建造得很精致。屋子外有个小小的花
圃，有几朵花正盛开，却看不出是茶花还是菊花。一条小溪静静地从屋前淌过，听
不见声音，也看不见人，窗子里仿佛有盏孤灯还未熄灭。	
LONG
    );
        set("exits", ([ 
		"enter": __DIR__"star_room1",
		"east":  __DIR__"river",
	]));
        set("objects", ([
        	
	]) );
        set("coor/x",-1680);
        set("coor/y",640);
        set("coor/z",0);
        set("no_fly",1);
		set("map","zbwest");
	setup();

}
