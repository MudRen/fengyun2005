// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "菜根香");
        set("long", @LONG
这是一个排场不大的饭店，与其说是个饭店，还不如说是个在街边的大排挡。
几把长凳零散地放在几张方桌前，桌上有竹子做的筷筒，里面插满了筷子。一个
小二勤快的跑来跑去招呼客人。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"west" : __DIR__"cxs2",
]));
        set("objects", ([
        __DIR__"npc/cx_waiter": 1,
                        ]) );
		set("coor/x",10);
		set("coor/y",-30);
		set("coor/z",0);
		setup();
        
}
