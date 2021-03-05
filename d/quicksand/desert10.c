#include <ansi.h>
#include <room.h>

inherit ROOM;

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
  "west" : __DIR__"mfoot",
  "east"  : __DIR__"desert9",
]));
        set("item_desc", ([
  "sand" : "缓缓流动的流沙就象一头待人而噬的巨兽，匍匐在你脚下。\n",
  "流沙" : "缓缓流动的流沙就象一头待人而噬的巨兽，匍匐在你脚下。\n",
]));

	set("outdoors", "quicksand");

	set("coor/x",-1100);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}
