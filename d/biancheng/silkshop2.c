inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "后房");
        set("long", @LONG
这里是陈大倌绸缎庄的后房，门口垂着半透明的珠帘，靠着左壁摆着三张木椅，
两条茶几。两只大藤椅向外蹲着、相距三尺许，中间并没茶几，却放着一口白铜的
火盆，青色的火焰正在盆沿跳舞。陈大倌喜欢吹着水烟泡，坐在藤椅上看着店里的
生意。
LONG
        );
        set("exits", ([ 
		"south": __DIR__"silkshop",
	]));
        set("objects", ([
        	__DIR__"npc/bosschen":	1,
	]) );
	set("coor/x",-20);
        set("coor/y",15);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	
}

void reset(){
	if (present("caihua feng",this_object()))	return;
	::reset();
}	