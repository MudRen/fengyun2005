// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "玉屏峰下");
        set("long", @LONG
背靠玉屏峰有一座两层楼的建筑坐落在树林之中，灰色的瓦顶上生满了野草，
一道小石阶向上直通小楼，石阶上布满了落叶，整个建筑充斥着一种苍凉的气息，
跟四周的美景节节不入。
LONG
        );
    set("exits", ([ 
  		"northeast"  : __DIR__"yingke",
		"west" : __DIR__"lianhua",
 		"up" : __DIR__"yuping2",
 		"southeast" : __DIR__"lianrui",
	]));
    set("objects", ([
        __DIR__"npc/wang" : 1,
        __DIR__"npc/monkey1" : 1,
    ]) );

        set("outdoors", "huangshan");
	set("coor/x",-70);
	set("coor/y",-10);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}
