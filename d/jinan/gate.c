// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","济南城口");
  set("long",@LONG
这里就是济南城的入口，进了济南城，扑面而来尽是孔学之风，你立刻被一种
浓浓的齐鲁风情所吸引。济南城的大道当地人称之为孔道，加上孔庙、孔府、孔林，
无处不让你对博大精深的孔家风范所感染。附近便是丐帮和朱砂帮的堂口了。
LONG
  );
  set("exits",([
         "north"  :__DIR__"tanghuai.c",
		 "south" : __DIR__"street1",
               ]));
    set("outdoors", "jinan");
	set("coor/x",0);
	set("coor/y",120);
	set("coor/z",0);
	setup();
    replace_program(ROOM);

}

