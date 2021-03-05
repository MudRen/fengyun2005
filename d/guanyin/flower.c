// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "花香中");
        set("long", @LONG
走了也不知多久，风中突然传来一阵阵甜蜜的花香。这花香不是牡丹，不是玫
瑰，也不是梅，不是菊......这花香甜蜜得竟非世间所有，而似来自天上。
LONG
        );
        set("exits", ([ 
 		 "south" : __DIR__"sand",
  		  "north" : __DIR__"valley",
	]));
	set("no_force",1);
	set("no_fly",1);
        set("outdoors", "guanyin");
	set("coor/x",0);
	set("coor/y",-30);
	set("coor/z",0);
	setup();

}



int valid_leave(object who, string dir){
	if (dir=="north"){
		if (userp(who))
			who->apply_condition("no_force",10);
	}
	return 1;
}