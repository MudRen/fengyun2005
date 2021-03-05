// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "紫竹林");
        set("long", @LONG
道路的两旁有片小小的竹林，竹林中有一个小小的竹亭，竹亭的顶棚上长着一
丛紫色的细竹。据说这竹亭是当年皇上南游时歇过脚的地方，而这紫竹也是皇上亲
自种下的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs5",
  "west" : __DIR__"jing",
  "east" : __DIR__"wol",
  "south" : __DIR__"cxs7",
]));
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
