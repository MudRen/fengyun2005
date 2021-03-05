// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "老北街");
        set("long", @LONG
暗青色的石砖，四轮马车宽的街道，你似乎还可以看到当年小镇的影子。除了
一切都变得陈旧以外，别的什么都没有变。西面的中药店已经今非昔比，生意好的
不得了。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"cx2",
  "southeast" : __DIR__"cx4",
  "west" : __DIR__"yao",
]));
        set("outdoors", "chenxiang");
	set("coor/x",-10);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
