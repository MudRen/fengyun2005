#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "渔人居");
        set("long", @LONG
门口晒着一张网，屋檐下吊着几条咸鱼。主人王大路是个懒人，“三天打鱼，
两天晒网”这句话用在他身上时再确切不过。然而王大路的本事就是，每次他出门
总能满载而归，让周围的邻居眼红不已。太平镇周围是沼泽地，用王大路的话说，
每捕一次鱼就得养上一个礼拜才行。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"mroad6",
	]));
        set("outdoors", "taiping");
	set("item_desc", ([
	        
	]));
	set("objects", ([
	        __DIR__"npc/fishman": 1,
	]));
	set("coor/x",-30);
	set("coor/y",-60);
	set("coor/z",0);
	set("map","taiping");
	setup();
}
