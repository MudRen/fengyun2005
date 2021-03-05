// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
#include <room.h>
void create()
{
	object con, item; 
  set("short","丐帮私房");
  set("long",@LONG
这是所丐帮的私房，东面墙上挂的是一个姓齐的画家画的虾米，西面则是一幅
奔马图，据称都属孤品。仅此就已经价值连城。更不用说这房间的摆设了。
LONG
  );
  set("exits",([
         "south":__DIR__"gb4",
               ]));
	set("objects", ([
	    __DIR__"npc/master5" : 1,
	]) );
	set("have_staff", 1);
	set("coor/x",-20);
	set("coor/y",90);
	set("coor/z",0);
	setup();

}
