// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "西南角");
        set("long", @LONG
乱石嶙峋，杂藓丛生。到处是垃圾和积水，散发着令人作呕的臭气。如果仔细
看的话，可以看到在垃圾和臭水中蠕动的各种令人恶心的长虫。而垃圾堆里竟都是
腐烂的尸体。。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
//  		"north" : __DIR__"ntxm",
  		"east" : __DIR__"txnd",
	]));
    set("objects", ([
        __DIR__"npc/xiaowu": 1,
        __DIR__"obj/trash": 1,
    ]) );
        set("indoors", "cave");
	set("coor/x",1);
	set("coor/y",-14);
	set("coor/z",0);
	setup();
}

/*
int valid_leave(object obj, string dir){
	object ma;
	if(dir == "east"){
		if(!obj->query("vendetta/authority") && present("ding gan", this_object())){
			ma = present("ding gan", this_object());
			return notify_fail(ma->name()+"闪身挡住了你的路。\n");
		}
	}	
	return 1;
}
*/
