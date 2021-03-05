#include <ansi.h>
inherit __DIR__"quicksand.c";

void create()
{
	object san, sna;
	set("short", "大漠风沙");
	set("long", @LONG
你现在处在酷热如烘炉的沙漠中，热的令人连气都透不出。除了满耳呼呼的风
声，你什么也听不见；除了满眼滚滚的飞沙，你什么也看不见；天地间仿佛只剩下
你一个人。你脚下缓缓而动的流沙给你如履薄冰的感觉。
LONG
	);
	set("exits", ([ 
  "west" : __DIR__"desert4",
  "north" : __DIR__"desert5",
  "south" : __DIR__"desert6",
  "east"  : __DIR__"desert0",
  "down"  : __DIR__"quicksand3",
]));
        set("objects", ([
                __DIR__"obj/sand" : 1,
                __DIR__"npc/snake" : 2,
                "/obj/money/coin": 1,
                "/obj/money/silver": 1,
        ]) );

        set("outdoors", "quicksand");

	set("coor/x",-1030);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        	san = present("sand", this_object());
        	sna = new(__DIR__"npc/obj/jade1");
        	sna->move(san);
        	sna = present("coin", this_object());
        	sna->move(san);
        	sna = present("silver", this_object());
        	sna->move(san);
}
