// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","达摩堂");
  set("long",@LONG
菩提[33m达摩[32m为中国禅宗的始祖，于嵩山少林寺创壁观婆罗门，六祖慧能为禅道之
祖，百丈禅师建丛林成其形。这里供奉的正是这三位开山尊宿。
LONG
  );
  set("exits",([
         "west":__DIR__"tianwang.c"
               ]));
        set("objects", ([
                BOOKS"iron-cloth_20" : 1,
       ]) );
	set("coor/x",10);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
