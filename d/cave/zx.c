// Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;

void create()
{
	string where;
        set("short", "西中道");
        set("long", @LONG
左右都是用石头和泥土搭起来的房子，因为地下潮湿，为了透气，每栋房子的
顶都相当的高。这条道路就象是被两道悬崖夹着的谷底，十分的阴森可怕。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
  		"west" : __DIR__"zdxm",
 // 		"east" : __DIR__"tt",
		"south" : __DIR__"weaponshop",
		"north" : __DIR__"cavehotel",
	]));
    set("objects", ([
        __DIR__"npc/mafeng": 1,
    ]) );
        set("indoors", "cave");
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",0);
	setup();

}

int valid_leave(object obj, string dir){
	object ma;
	if(dir == "west"){
		if(!obj->query("vendetta/authority") && present("ma feng", this_object())){
			ma = present("ma feng", this_object());
			return notify_fail(ma->name()+"闪身挡住了你的路。\n");
		}
	}	
	return 1;
}
