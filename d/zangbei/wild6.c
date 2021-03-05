inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "草原");
        set("long", @LONG
烈日下走着一队队晒得黝黑的赶马人，云影下的帐篷白得透明，阳光里的人群
和牛群黑得耀眼，数百头牦牛像黑色的云阵涌向地平线处，长毛被风吹得飘扬起来。
每过数里就能看到寺庙，和风尘仆仆的朝圣者。
LONG
        );
        set("long_night",@LONG
草原的夜是寂寞的，辽远清冷的高空，挂起无数的星点，在下面，夜行人的灯
笼摇摇摆摆，象是沼地中的鬼火跳舞，在道路两旁，全是黑沉沉的红杉树林，在前
面，无边的草原在风中瑟瑟作响，呜咽似地呻吟，令赶路的人毛骨悚然。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"wild5",
		"west" : __DIR__"wild7",
		"north" : __DIR__"temple5",
	]));
        set("objects", ([
        	__DIR__"npc/bull":	2,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1900);
        set("coor/y",710);
        set("coor/z",0);
	set("map","zbwest");
	setup();
}
