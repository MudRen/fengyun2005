inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "村居");
        set("long", @LONG
屋子的主人显是以打鱼为生的，门口一个大水缸里几条大白鲤悠闲地游来游去，
旁边的水桶里是红色的鱼虫。屋檐下面晒着一个很大的网兜和两张渔网，晃晃悠悠
挂着的，是一串晒干了的红辣椒和几个蒜头。
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"groad3b",
	]));
        set("objects", ([
        	__DIR__"npc/fishman":1,
	]) );
        set("coor/x",70);
        set("coor/y",100);
        set("coor/z",0);
	set("map","eren");
	setup();
}
