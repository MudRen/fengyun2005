#include <room.h>
inherit ROOM;

void create()
{
        set("short", "花园");
        set("long", @LONG
这是一座极大的花园，四面群山围绕，园中万花竞艳。牡丹芍药，黄菊红玫，
四季香花，在这地竞同时开放，抬眼望去，宛如置身一片香涛花海之中。白石小径，
青竹篱笆间，零乱地站了十余个红衣少女，正在剪草灌花。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"garden",
]));
        set("objects", ([
        __DIR__"npc/girls" : 5,
                        ]) );

	set("outdoors","palace");
	set("coor/x",10);
	set("coor/y",60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}

