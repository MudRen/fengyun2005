// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "山谷口");
        set("long", @LONG
气温越来越暧，简直近于酷热，这整个山谷，竟似已变得一股洪炉，要炼出人
们的灵魂。但在前面，山谷中豁然开朗，群峰合抱间，竟是一片花海。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"south" : __DIR__"flower",
  		"north" : __DIR__"flower2",
	]));
	set("no_force",1);
	set("no_fly",1);
        set("outdoors", "fengyun");
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
