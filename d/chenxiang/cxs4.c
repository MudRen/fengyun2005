// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "旗场");
        set("long", @LONG
一杆几丈高的木旗杆牢牢地埋在路当中，旗杆的顶端有一个小小的了望台。近
年来沉香镇的规模蒸蒸日上，却也吸引了许多蠢蠢欲动的匪人，狼山的悍匪更是官
府的心头大患。瞭望台就是为此而建，每当匪徒来袭扰的时候，这里守望的官兵便
会鸣钟告警。
示警。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"cxs3",
  "west" : __DIR__"yam",
  "east" : __DIR__"fac",
  "south" : __DIR__"cxs5",
  "up" : __DIR__"gding",
]));
        set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
	object room;
	room = find_object(__DIR__"gding");
	if(objectp(room))
	tell_object(room,me->name()+"离开了旗场。\n");
                return 1;
}

int valid_enter(object me, string dir)
{
        object room;
        room = find_object(__DIR__"gding");
        if(objectp(room))
        tell_object(room,me->name()+"来到了旗场。\n");
	return 1;
}

