inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山道");
        set("long", @LONG
地势越发平坦，再往前走便是一片松林。阳光照在松林中，一络一络的阳光，
好像到了树枝遇到了弹性似的，反照下来，洒在人的身上，仿若细雨一般舒畅。枝
头鸟鸣，松鼠在忙碌地准备过冬的食物，一个个吃的身子倍儿圆。
LONG
        );
        set("exits", ([ 
	"southup" : __DIR__"road3",
	"northdown" : __DIR__"road5",
	]));
        set("objects", ([
                	__DIR__"npc/songshu": 1,
	]) );
	set("outdoors", "eren");
        set("coor/x",0);
        set("coor/y",40);
        set("coor/z",20);
	set("map","eren");
	setup();
	replace_program(ROOM);
}
