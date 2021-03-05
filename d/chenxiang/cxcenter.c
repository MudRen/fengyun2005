// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit ROOM;

void midnight_event();
void sunrise_event();

void create() {
	set("short",HIR"老城广场"NOR);
	set("long", @long
沉香镇的中心广场的北面是一条小河流，河流的旁边有一块大青石，就当做船
夫的上岸的小码头，来来往往的驳船都在这里卸货，日久就成了个热闹的小市场。
广场中心有一平台，登高一望，西南群山起伏，有著名的[33m黄山[32m和[33m狼山[32m，东南数十里
外是连绵的[33m莽林[32m和[33m沼泽[32m，北面行商之路一直通向[33m塞外[32m。
long);
	set("exits", ([
			"north" : __DIR__"cx4",
			"south" : __DIR__"cxs1",
			"east" : __DIR__"cxe1",
			"west" : __DIR__"nanbank",
			]));
	set("objects", ([
			__DIR__"npc/fishseller": 1,
			__DIR__"npc/fishbuyer": 1,
			]) );
	set("outdoors", "chenxiang");
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
	NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :)); 
}


void midnight_event() {
	object badguy;
	object room = this_object();
	int i, bandit_no = 2 + random(5);
	
	if(!random(20)) {
		for(i=0; i<bandit_no; i++) {
			if(objectp(badguy = new("/obj/npc/bandit"))) {
				badguy->setup_bandit("蒙面土匪", "/obj/armor/cloth", "/obj/weapon/blade_guitou", "cx");
				badguy->move(room);
				badguy->ccommand("chat 月黑杀人，风高放火！");
			}
		}
		NATURE_D->add_day_event(3, 1, this_object(), (: sunrise_event :));
	} else {
		NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
	}
}

void sunrise_event() {
	object *ob_list;
	int i;
	
	ob_list = children("/obj/npc/bandit");
	for(i=0; i<sizeof(ob_list); i++) {
		if(ob_list[i]->query("area_mark") == "cx") {
			if(environment(ob_list[i])) {
				message_vision("$N叫道：天晓也，扯乎！\n",ob_list[i]);
			}
			destruct(ob_list[i]);
		}
	}
	NATURE_D->add_day_event(0, 2, this_object(), (: midnight_event :));
}
