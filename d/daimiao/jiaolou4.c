// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//mac's jiaolou4.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","哏角楼");
  set("long",@LONG
这是岱庙围墙四隅的角楼，分别以四卦为名，以求避凶趋吉，楼中有一面大碑，
碑上书一大字：
[33m
				哏
[32m
LONG
  );
  	set("exits",([
         	"south":__DIR__"jiaolou2",
         	"west" :__DIR__"wangyue",
        ]));
        set("objects", ([
                	__DIR__"npc/gang4" : 1,
       	]) );
	set("coor/x",30);
	set("coor/y",20);
	set("coor/z",10);
	setup();
  	replace_program(ROOM);
}
