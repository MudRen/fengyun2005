#include <ansi.h>
inherit __DIR__"quicksand.c";

void create()
{
	set("short", "大漠风沙");
	set("long", @LONG
你现在处在酷热如烘炉的沙漠中，热的令人连气都透不出。除了满耳呼呼的风
声，你什么也听不见；除了满眼滚滚的飞沙，你什么也看不见；天地间仿佛只剩下
你一个人。你脚下缓缓而动的流沙给你如履薄冰的感觉。
LONG
	);
	set("exits", ([ 
  "west" : __DIR__"greenland",
  "north" : __DIR__"desert4",
  "south" : __DIR__"desert7",
  "east"  : __DIR__"desert6",
  "down"  : __DIR__"quicksand8",
]));
        set("objects", ([
                __DIR__"obj/sand" : 1,
		__DIR__"npc/snake" : 2,
        ]) );

	set("outdoors", "quicksand");

	set("coor/x",-1070);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
