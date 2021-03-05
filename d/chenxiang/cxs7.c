// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "沉香城南门");
        set("long", @LONG
城门有几丈高，厚而且结实，上面还镶满了铜钉。一个原木钉成的吊桥跨架在
护城河上。城墙滑不留手，上面还有一个个的箭楼。箭楼之间还有水桶粗细的火炮。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs6",
  "south" : __DIR__"cxs8",
]));
        set("objects", ([
        __DIR__"npc/cg": 2,
                        ]) );
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-80);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
