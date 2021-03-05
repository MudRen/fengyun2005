inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "厨房");
        set("long", @LONG
厨房很大，油烟气也很浓，浓烈的菜香，化做一团团蒸气，弥漫了屋子，有如
迷雾一般。几个厨子围着灶台正忙得不可开交。墙角有个大水缸，几尾鲜鱼在里面
扑腾，屋梁上悬着几块腊肉。
LONG
        );
        set("exits", ([ 
	"west" : __DIR__"hahalou1",
	]));
	set("resource/water", 1);
    	set("liquid/container", "水缸");  
        set("objects", ([
        	__DIR__"npc/cooker": 1,
        	__DIR__"obj/counter": 1,
	]) );
	set("coor/x",55);
        set("coor/y",50);
        set("coor/z",0);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
