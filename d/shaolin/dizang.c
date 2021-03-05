// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "地藏殿");
        set("long", @LONG
殿内昏暗，因为供奉的是幽冥教主，殿中一座铜铸地藏像，左右两侍者，座下
是谛听神兽。四周墙上壁画难以辨认，似乎是经脉图，但是边上歪曲的文字弄不明
白。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"qianfe",
]));
/*        set("objects", ([
                __DIR__"obj/herb" : 1,
       ]) ); */
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",20);
	setup();

}
