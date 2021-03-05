#include <ansi.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "云龙武馆");
        set("long", @LONG
test
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"ecloud2",
]));


    set("indoors", "fengyun");
	set("coor/x",0);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

