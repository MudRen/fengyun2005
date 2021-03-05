// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "旗杆顶");
        set("long", @LONG
整个沉香城尽收眼底，满眼的绿竹，棕榈树，和椰子树。青色的城墙和金黄色
的琉璃屋顶处处可见。展望远处，一片黑压压的森林被一团团烟雾笼罩着，就好象
有妖怪似的。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "down" : __DIR__"cxs4",
]));
        set("outdoors", "chenxiang");
        set("objects", ([
        __DIR__"npc/sb": 1,
                        ]) );
	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}
