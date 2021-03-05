
inherit ROOM;
#include <room.h>

void create()
{
    set("short", "养生舍");
    set("long", @LONG
养生舍四壁皆空，唯墙上书道：不有中有，不无中无。不色中色，不空中空。
非有为有，非无为无。色非为色，非空为空。空即是色，色即是色。色无定色，色
即是空。空无定空，空即是色。知空不空，知色不色。
LONG
    );
    set("exits", ([
	"south" : __DIR__"pusheng",
      ]));
    set("objects", ([
	__DIR__"npc/huofe" : 1,
      ]) );

    set("coor/x",-20);
    set("coor/y",-220);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);

}
