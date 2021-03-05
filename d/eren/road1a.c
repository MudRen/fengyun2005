inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山腰");
        set("long", @LONG
走至半山，有一块小平地，两棵大树下几张青石凳，是给登山者歇脚之处。向
上望，玉龙峰顶还在白云环绕之处，向西看，一条曲曲弯弯的小路在乱石丛中时断
时续。远处树丛中青砖碧瓦，似乎是几座庄园。
LONG
        );
        set("exits", ([ 
		"eastdown" : __DIR__"road1",
		"westdown": __DIR__"road1b",
	]));
        set("objects", ([
        	__DIR__"npc/swordman1": 1,
        	__DIR__"npc/swordman2": 1,
        	__DIR__"obj/stonestool": 1,
	]) );
	set("outdoors", "eren");
        set("coor/x",-10);
        set("coor/y",10);
        set("coor/z",40);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
