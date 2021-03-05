inherit ROOM;
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

void create()
{
        set("short", "万梅山庄");
        set("long", @LONG
在你面前是枝桠交叉的梅林，每当白雪皑皑之冬，遍山梅花竟相开放。北风之
中，雪花与红梅相映成辉，美不胜收。梅枝掩映之中，风铃叮咚，忽隐忽现。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"road2",
  "east" : __DIR__"gate",
]));
        set("outdoors", "wanmei");
	set("coor/x",-50);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
