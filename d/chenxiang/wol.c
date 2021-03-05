// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "卧龙馆");
        set("long", @LONG
房顶相当地高，比两层楼都高，一盏铜灯用胳膊粗细的铁链从房顶直垂下来，
上面有六株巨烛，巨烛的颜色各不相同，每当点燃的时候，就连火苗的颜色也不一
样。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"cxs6",
  "east" : __DIR__"wol2",
]));
        set("objects", ([
        __DIR__"npc/ywai": 1,
                        ]) );
	set("coor/x",10);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
        object ob;
        if( dir == "east" &&  !me->query_temp("marks/cured_jia") 
	&& ob=present("jia", this_object())) 
                return notify_fail("这个方向的路被"+ob->name()+"挡住了 。\n");
	else
                return 1;
}

