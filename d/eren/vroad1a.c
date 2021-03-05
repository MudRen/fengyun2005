inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "菜田");
        set("long", @LONG
道路旁种满了蔬菜，金黄的菜花，碧绿的豌豆，嫩红的西红柿，酱紫的茄子，
一派丰收景象。几个农夫忙着在地里除虫，田埂上，三五个孩子甩着光脚丫子嬉戏
追打，后面一条大黑狗汪汪地跟着跑。
LONG
        );
        set("exits", ([ 
		"north" : __DIR__"vroad1",
	]));
        set("objects", ([
		__DIR__"npc/sadkid": 1,
	]) );
	set("outdoors", "eren");
        set("coor/x",40);
        set("coor/y",50);
        set("coor/z",0);
	set("map","eren");
	setup();
}
