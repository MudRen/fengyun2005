#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "镇龙塔");
        set("long", @LONG
此塔位于红山山顶，塔身高过十丈，塔顶铺满青蓝色瓦片，在阳光下十分耀眼。
塔的周围是红砖地，已经很旧了，布满了裂痕。这里很静，除了一些武林中人在这
里较武过招之外，似乎没有其他人来了。
LONG
        );
        set("exits", ([ 
  "down" : __DIR__"hongshan",
]));

        set("objects", ([
        __DIR__"npc/xiechangqing" : 1,
	]) );

        set("outdoors", "xinjiang");
	set("coor/x",0);
	set("coor/y",50);
	set("coor/z",20);
	setup();
}

