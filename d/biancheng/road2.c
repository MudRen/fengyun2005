inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "街心");
        set("long", @LONG
世界上有无数个这样的小城，每一个都是这样子，简陋的房屋，廉价的货物，
善良的人家。小城街道不长，也不宽，站在街心就可以望到南北两端的尽头。风吹
过，街旁的木字招牌哗哗作响。小城仿佛就是一粒粘满了世俗尘灰的明珠，镶嵌在
无边无际的原野里。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"road1",
		"west" : __DIR__"road3",
		"north": __DIR__"nstreet1",
		"south": __DIR__"sstreet1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-10);
        set("coor/y",0);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
