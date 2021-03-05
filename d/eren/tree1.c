inherit ROOM;
#include <ansi.h>


void create()

{
        set("short", "大槐树上");
        set("long", @LONG
这棵槐树已经有八百年了，每到五月天的时候，就会满树的密密地开些个白色
的小花儿。花儿开得沉掂掂的、香喷喷的，槐花儿飘香的时候，满树下的孩子跳着
笑着，欢闹着，叫嚷着爬上树来摘花儿。
LONG
        );
        set("exits", ([ 
		"down" : __DIR__"road1e",
	]));
        set("objects", ([
		__DIR__"npc/bird": 	1,
	]) );
	set("outdoors", "eren");
        set("coor/x",-50);
        set("coor/y",10);
        set("coor/z",20);
	set("map","eren");
	setup();
}
