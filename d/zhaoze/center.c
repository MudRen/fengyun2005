// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
#include <room.h>
inherit ROOM;


void create()
{
        set("short", "火沼中心");
        set("long", @LONG
一潭黑水不停地冒着气泡，枯枝烂叶连同发黄的白骨足有尺厚。几块暗红色的
狰狞巨石堆在黑水中央，上面布满了各种尸骸。潭水中漂浮着段段枯木，有些还散
发着袅袅黑烟。
LONG
        );
        set("exits", ([ 
 		 "west" : __DIR__"zhaoze4",
	]));
        set("objects", ([
                __DIR__"npc/dragon" : 1,
       	]) );
        set("outdoors", "zhaoze");
        set("no_fly",1);
//	set("no_curse",1);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void init()
{	object ob,room;
	if( interactive( ob = this_player())) {
    		if(ob->query_skill("force",1) < 150) {
			if (!room=find_object(__DIR__"edge.c"))
				room = load_object(__DIR__"edge.c");
			ob->move(room);
			message_vision(HIR"$N被丛林里的灼热气焰冲了回来。\n\n"NOR, ob);
		}else if (userp(ob) || userp(ob->query("possessed")))
				ob->apply_condition("zhaoze",10);			
	}
}