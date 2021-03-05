inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "草场");
        set("long", @LONG
辽阔的大草原上，舒缓起伏的草地，神秘而宁静地铺到天之尽头，草地上弯弯
曲曲的河流，河岸边炊烟袅袅的藏式帐篷共同组成一幅如诗如梦的画面。每当清晨，
洁白的浓雾慢慢在地面流淌，远远近近的帐篷如同雾海中的小岛。再往北是一片连
绵起伏的山坡。
LONG
        );
        set("exits", ([ 
		"south":		__DIR__"grassland5",
		"northup":		__DIR__"hill",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",110);
        set("coor/y",100);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
