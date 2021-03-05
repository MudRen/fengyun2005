inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIR"鹦鹉楼"NOR);
        set("long", @LONG
穿过回廊，走过花径，来到一座精致的小楼，这里是血奴的住处，楼檐下挂着
十七八个鸟笼，只有鸟笼没有鸟。鸟笼里本来养的都是些什么鸟？是不是鹦鹉？鸟
笼空了，鹦鹉呢？这些问题也许只有主人才能回答。楼下是个花厅，一张琴桌上点
着两柱香烟，厅里洋溢着一种奇怪的甜甜的味道。
LONG
        );
        set("exits", ([ 
		"west" : __DIR__"corridor5",
		"up": __DIR__"birdhouse2",
	]));
	set("item_desc", ([
	        
	]));
	set("coor/x",-70);
	set("coor/y",-60);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
