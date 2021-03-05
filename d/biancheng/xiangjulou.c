inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "相聚楼");
        set("long", @LONG
这地方根本没有名字，但却是附近几百里之内最有名的地方。大厅中摆着十八
张桌子，无论你选择哪一张桌子坐下来，都可以享受到最好的酒菜，你若还要享受
别的，就得推门。大厅四面有十八扇门。无论你推哪扇门走进去，都绝不会后悔，
也不会失望。大厅的后面还有道很高的楼梯。没有人知道楼上是什么地方，也没有
人上楼去过。困为你根本不必上楼，无论你想要的是什么，楼下都有。
LONG
        );
        set("exits", ([ 
	"south" : __DIR__"road5",
	"up": __DIR__"xiangjulou2",
	]));
        set("objects", ([
        	__DIR__"npc/bieli": 1,
        	__DIR__"npc/dinglinglin":	1,
        	__DIR__"npc/dinglingzhong":	1,
        	__DIR__"npc/dinglingjia":	1,
        	__DIR__"npc/dingyunhe":		1,
	]) );
        set("coor/x",-40);
        set("coor/y",10);
        set("coor/z",0);
	set("map","zbwest");
	setup();
	replace_program(ROOM);
}
