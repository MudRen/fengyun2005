inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "镜湖");
        set("long", @LONG
镜湖，又叫木格措，方圆数里，走到这儿，湖光山色，仿佛置身于瑶池仙境。
湖景一日多变：清晨，坦荡无垠的湖面静如镜面，倒映着雪峰和群山；午后波涛滚
滚，涛声如雷震撼山谷；傍晚夕阳西斜，湖面金光灿烂夺目，动静交替。
LONG
        );
        set("exits", ([ 
		"southwest" : __DIR__"mount3",
		"northeast":  __DIR__"spring",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1670);
        set("coor/y",630);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}

