// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "沉香城西街");
        set("long", @LONG
路边稀稀疏疏地种着几棵椰子树，在风中晃呀晃地，似乎在和路人不停地打招
呼。东面的沉香台热闹非凡，找不到摊位卖东西的小贩都扩散到这里来了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"farmershop",
  "west" : __DIR__"cxw2",
  "east" : __DIR__"cxcenter1",
]));
        set("outdoors", "chenxiang");
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
