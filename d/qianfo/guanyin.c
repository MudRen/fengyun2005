// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","观音殿");
  set("long",@LONG
观音殿供奉的是观世音菩萨，手持杨枝水瓶，乘狮立于普陀洛伽山海之间，左
右两菩萨协伺，乘象者为普贤菩萨，乘狮为文殊菩萨，其四围为“华岩经”善财五
十三参。
LONG
  );
  set("exits",([
            "south":__DIR__"weituo.c",
            "north":__DIR__"luohan.c",
            "west" :__DIR__"zhaitang.c",
            "east" :__DIR__"xiangji.c"
               ]));
          set("objects", ([
                __DIR__"npc/bonze8" : 1,
       ]) );
	set("NONPC",1);   
	set("coor/x",0);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
