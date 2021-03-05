// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "乡间小路");
        set("long", @LONG
往北是沉香城南门，往南是沼泽边缘，很多英雄好汉从这里再往南走就再也没
有回来了。除非你武艺高强，最好不要再往南走了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs7",
  "south" : AREA_ZHAOZE"edge",
]));
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-90);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
