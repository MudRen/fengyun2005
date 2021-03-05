#include <ansi.h>
#include <room.h>

inherit DOOR_ROOM;

void create()
{
    set("short", HIG"东地巷"NOR);
    set("long", @LONG
道路两旁乱哄哄的，远不似风云广场的繁华，偶尔有几声小贩的叫卖，空气里
夹杂着一种说不出的怪味。唯有远眺可以看到东城门外的起伏山峦，山色似乎也浓
得象墨一样，时不时也会吹来几分清新，来往的旅人不时会被远方的云霞的美景所
吸引伫足。红尘滚滚，谁说又没有化外高人。
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"east" : __DIR__"ecloud5",
	"west" : __DIR__"ecloud31",
	"north" : __DIR__"yulong3",
	"south" : __DIR__"backdoor",
      ]));
    set("objects", ([
	__DIR__"npc/drugseller" : 1,
      ]) );

    set("outdoors", "fengyun");
    set("coor/x",240);
    set("coor/y",0);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    create_door("south", "door","后门", "north", DOOR_CLOSED);
}


int valid_leave(object me, string arg) {
    if (arg == "south") {
	return notify_fail("门里有人吆喝着：有事儿走正门。。。你被请了出来。\n");
    }
    return ::valid_leave(me, arg);
}
