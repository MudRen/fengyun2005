// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit DOOR_ROOM;
void create()
{
        set("short", "塔院");
        set("long", @LONG
这里是少林常住院的塔院，内有两塔，东西并立，为西边佛塔和下生弥勒佛塔，
供奉的都是弥勒佛。弥勒双足踏于莲花，仪容坦然，姿态端庄。西边的小门通向
甘露台，是僧人们汲水的地方。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"lixue",
  "westup" : __DIR__"ganlu",
]));
        set("outdoors", "shaolin");
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	create_door("westup","door", "木门", "eastdown", DOOR_CLOSED);
}
