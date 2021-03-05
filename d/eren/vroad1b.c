inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "菜田");
        set("long", @LONG
田野经过夜来的雨洗，庄稼饱润地举起头来，颜色又浓又绿。大麻长得高过人
头，张开巴掌大的叶子，把满地棉花一比，就显得更是肥润。金黄的菜花，碧绿的
豌豆，嫩红的西红柿，酱紫的茄子，在灿烂的阳光照耀下闪着光。
LONG
        );
        set("exits", ([ 
		"south" : __DIR__"vroad1",
	]));
        set("objects", ([

	]) );
	set("outdoors", "eren");
        set("coor/x",40);
        set("coor/y",70);
        set("coor/z",0);
	set("map","eren");
	setup();
}
