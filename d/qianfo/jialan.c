// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","伽蓝殿");
  set("long",@LONG
伽蓝殿内供奉的是守护伽蓝土地的神像，最左为施造祗园精舍的给孤独长者，
居中为祗陀太子，其父波斯匿王在右。
LONG
  );
  set("exits",([
         "east":__DIR__"tianwang.c"
               ]));
        set("objects", ([
                __DIR__"npc/bonze1":1,
       ]) );

	set("coor/x",-10);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
