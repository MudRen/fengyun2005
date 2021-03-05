// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "外南路");
        set("long", @LONG
离开沉香城的中心已经有一段距离了，虽然还可以听到远处的喧哗声，但每当
微风拂过，椰子树和棕榈树发出的沙沙声就将整个小城淹没。再往南就是一片小竹
林。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs4",
  "west" : __DIR__"mudan",
  "east" : __DIR__"suren",
  "south" : __DIR__"cxs6",
]));
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
