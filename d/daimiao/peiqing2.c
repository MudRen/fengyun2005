//mac's peiqing1.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","配寝殿");
  set("long",@LONG
此为泰山神的神妃的住所，神龛内有一张大型紫檀透花雕刻的龙榻，榻上的绣
龙花缎被下有东岳神的睡像，睡像为檀木雕刻，榻旁有神妃着衣端坐。
LONG
  );
  set("exits",([
         "east":__DIR__"houqing.c",
               ]));
        set("objects", ([
        __DIR__"obj/huabei" : 1,
	BOOKS"skill/incar_90" : 1,
	__DIR__"npc/xintu2" : 1,
                        ]) );
	set("coor/x",-10);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

void reset()
{
        object *inv;
        object con, item;
        ::reset();
        con = present("huabei", this_object());
        inv = all_inventory(con);
        if(!sizeof(inv)) {
        item = new(__DIR__"obj/xiang");
        item->move(con);
        }
}

