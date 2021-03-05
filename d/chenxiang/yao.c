// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "华佗药店");
        set("long", @LONG
朱红的大门，闪闪发光的金匾，还有病愈的百姓送来的贡品，把这里衬托的比
香火鼎盛的庙宇还要红火。这间药店五十多年来还没有换过主人，听说有数不清的
江湖好汉在这里落过脚。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cx3",
  "west" : __DIR__"yao2",
]));
        set("objects", ([
        __DIR__"npc/huoji": 1,
                        ]) );
	set("coor/x",-20);
	set("coor/y",20);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
