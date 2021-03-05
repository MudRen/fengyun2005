// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <ansi.h>
#include <room.h>

inherit __DIR__"bush_base.c";

void create()
{
	set("short", "火沼深处");
	set("long", @LONG
天色越发昏暗，到处弥漫着暗红色的蒸气。这里气温极高，所有的植物都呈现
出一种焦黄的颜色。地下的泥土更见松软，每一步都有陷下去的危险。
LONG
	);
	set("exits", ([ 
  "north" : __DIR__"zhaoze5",
]));

        set("item_desc", ([
                "bush": "这里荆棘(bush)密布，但你似乎可以砍开(chop)它们。\n",
                "荆棘": "这里荆棘(bush)密布，但你似乎可以砍开(chop)它们。\n"

        ]) );
        set("outdoors", "zhaoze");
        set("no_fly",1);
	set("route","south");
        set("route_room",__DIR__"zhaoze7");
	set("coor/x",10);
	set("coor/y",10);
	set("coor/z",0);
	setup();
}