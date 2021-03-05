#include <room.h>
inherit DOOR_ROOM;

void create()
{
        set("short", "花园");
        set("long", @LONG
这是一座极大的花园，四面群山围绕，园中万花竞艳。牡丹芍药，黄菊红玫，
四季香花，在这地竟同时开放，抬眼望去，宛如置身一片香涛花海之中。白石小径，
青竹篱笆间，零乱地站了十余个红衣少女，正在剪草灌花。西边一扇铜门。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"garden3",
  "north" : __DIR__"garden1",
  "south" : __DIR__"garden2",
  "west" : __DIR__"secretpath2",
]));
        set("objects", ([
        __DIR__"npc/dagu" : 1,
                        ]) );

	set("outdoors","palace");
    
	set("coor/x",10);
	set("coor/y",50);
	set("coor/z",0);
	setup();
    create_door("west", "door","铜门", "east", DOOR_CLOSED);
}

