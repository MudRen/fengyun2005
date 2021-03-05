inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "小镇中心");
        set("long", @LONG
所有来往的客商都会聚集到这里，可奇怪的是这儿并不热闹，尤其是白天。北
面是一幢二层的小楼，没有招牌，没有锦旗，南首的窄门外只有到傍晚时才会挂一
盏红灯笼。来往的都是这两处的常客，进去时个个匆匆忙忙低着头，走出来个个红
光满面，像是很满足的样子。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"road4",
		"west": __DIR__"road6",
		"southwest" : __DIR__"smallroad1",
		"north": __DIR__"xiangjulou",
		"south": __DIR__"xiaojinku",
	]));
        set("objects", ([
        	__DIR__"npc/huamantian": 1,
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-40);
        set("coor/y",0);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
