// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "石峰狭道");
        set("long", @LONG
风，卷起黄沙，迷漫在狭谷间，更平添了一种凄秘诡谲之意，两山夹立，天仅
一线。人行在狭谷间，但见黄沙，却连天也瞧不见了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"sand",
  "south" : __DIR__"deep2",
  "east" : __DIR__"deep",
]));

	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
