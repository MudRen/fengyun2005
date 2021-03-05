
inherit ROOM;
#include <room.h>

void create()
{
        set("short", "浸龙浴池");
        set("long", @LONG
一入门，热气扑面，白白的水气立刻包围了你。你依稀看到一个巨大的檀木水池,
水呈碧绿，散发着一种奇特的药香，水面上还漂着一片片红红的花瓣儿，你真想一下
子跳（ｊｕｍｐ）进去，闭上眼睛好好的放松一下。
LONG
        );
        set("exits", ([
                "east" : __DIR__"jlonglang3",
        ]));
        set("objects", ([
                __DIR__"npc/": 2,
        ]) );
        set("coor/x",-40);
        set("coor/y",40);
        set("coor/z",-300);
        setup();
        create_door("east", "檀木门", "west", DOOR_CLOSED);

}


