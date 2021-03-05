// mimicat@fy4
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "松谷庵");
        set("long", @LONG
粉墙青瓦的小院落坐落在竹林之中，一道小溪从竹林穿出，从小院后面绕过。
大门微敞，门上题字“松谷庵”，字体娟秀，显然出自女子之手，宁静的木鱼声不时
从庵内传出，透过门缝可以看见院内种植的花草。
LONG
        );
	set("exits", ([ 
    	"south" : __DIR__"yard",  
		"north" : __DIR__"sroad",
	]));
     set("objects", ([
            "/obj/specials/ding/ding_hs" : 1,

        ]) );
    set("outdoors", "huangshan");
	set("coor/x",-140);
	set("coor/y",-35);
	set("coor/z",30);
	setup();
}



