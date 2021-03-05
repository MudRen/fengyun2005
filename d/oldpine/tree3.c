// Room: /d/oldpine/tree3.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "大松树顶");
        set("long", @LONG
你终於爬上这株松树的树顶了，一阵阵凉风从四面八方吹来，使你觉得心旷神
怡，虽然你的经验告诉你在这种地方往下看是十分不智的，但是你还是忍不住看了
一眼，这里离地面至少也有十五、六丈高，一阵晕眩警告你最好在跌下去以前离开
这个地方。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tree2",
]));
        set("outdoors", "oldpine");

	set("coor/x",-20);
	set("coor/y",30);
	set("coor/z",60);
	setup();
        
}