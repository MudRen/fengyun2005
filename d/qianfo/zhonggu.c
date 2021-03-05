// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","钟鼓楼");
  set("long",@LONG
这里是安置佛钟，佛鼓的地方，禅宗晨鸣钟，暮击鼓，钟声嘹亮，鼓声清脆，
以提示寺中修行的僧众。
LONG
  );
  set("exits",([
            "eastdown":__DIR__"weituo.c"
               ]));
          set("objects", ([
                __DIR__"npc/bonze6" : 1,
       ]) );
	set("coor/x",-10);
	set("coor/y",-30);
	set("coor/z",10);
	setup();
  replace_program(ROOM);
}
