inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "高原");
        set("long", @LONG
越过昆仑山区，地势逐渐平坦。干燥的土地，秋风卷起满天黄沙，在无边无际
的高原上咆哮而过。极目远眺，天地无止无境，景象壮观，憾人心魄。此地民风淳
朴，走累了可以到路边的帐篷里歇息，热情的牧民会拿出羊奶酒款待你。
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"wild1",
		"northwest" : __DIR__"wild3",
		"southwest":  __DIR__"tent1",
	]));
        set("objects", ([
	]) );
	set("outdoors", "biancheng");
        set("coor/x",-1500);
        set("coor/y",700);
        set("coor/z",0);
	set("map","zbeast");
	setup();
}
