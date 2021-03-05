inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "山沟");
        set("long", @LONG
从俄初山到海子山，沿山沟走约一个半时辰路程。沟里有偌大的草坪，象撒开
的辫子弯弯曲曲地从山的这一端流到另一端之后收敛成溪。转过山角，西面不远处
有一座白砖红瓦的庄园，据说是一位武林人物厌倦了江湖生涯，在此隐居。
LONG
        );
        set("exits", ([ 
		"northeast" : __DIR__"valley1",
		"southup":  __DIR__"haizi",
		"west": 	__DIR__"xuevillage",
	]));
        set("objects", ([
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-2060);
        set("coor/y",580);
        set("coor/z",20);
	set("map","zbwest");
	setup();

}
