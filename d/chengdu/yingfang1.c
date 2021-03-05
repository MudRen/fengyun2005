// hippo 01.2010

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "营房");
        set("long", @LONG
火器营众多营房是由八块大小、尺寸完全相同的梯形块所组成。这样
的划分，加上统一的建筑施工，在不规则的地形上，使得火器营的房屋分
配、使用、附属设施极为合理，各营的房屋数目完全相等。
LONG
        );
	set("exits",([
  		"east" : __DIR__"caochang1",
	]) );
		
	set("outdoors", "chengdu");

	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}