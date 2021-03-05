#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", HIC"轻舟"NOR);
        set("long", @LONG
            .
            |\
            | \
            |  \
            |   \
            |    \
            |     \
            |      \
            |       \       ____O
            |        \     .' ./
            |   _.,-~"\  .',/~'
            <-~"   _.,-~" ~ |
^"~-,._.,-~"^"~-,._\       /,._.,-~"^"~-,._.,-~"^"~-,._
~"^"~-,._.,-~"^"~-,._.,-~"^"~-,._.,-~"^"~-,._.,-~"^"~-,._
^"~-,._.,-~"^"~-,._.,-~"^"~-,._.,-~"^"~-,._.,-~"^"~-,._
~-,._.,-~"^"~-,._.,-~"^"~-,._.,-~"^"~-,._.,-~"^"~-,._

LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  			"east" : __DIR__"renjiandao2",
		]));
        set("outdoors", "bat");
        set("objects", ([
        	__DIR__"npc/baiyiren2": 1,
        ]) );
		set("no_fly",1);
		set("coor/x",-40);
		set("coor/y",10);
		set("coor/z",70);
		setup();
}


