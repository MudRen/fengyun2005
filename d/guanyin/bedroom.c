// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "精致卧房");
        set("long", @LONG
没有妆台，没有绣被，没有锦帐流苏，也没有任何华贵的阵设，糜奢的珍玩，
眩目的珠宝。这屋子的精致，正如天生丽质，若搽脂粉，反而污了颜色。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  		"southdown" : __DIR__"mirror",
	]));
        set("objects", ([
                __DIR__"npc/master" : 1,
       	]) );
	set("no_force",1);
	set("no_fly",1);
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
	setup();
        
}