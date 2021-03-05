// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","洞天福地");
  set("long",@LONG
峰回路转，有一石坊立于道上，上书四个金字：洞天福地。向北一座寺庙隐约
可见，山风吹来，清新凉爽，令人精神一振。向西山道遮没在绿树之中，仅可见一
线天光。
LONG
  );
  set("exits",([
         "westdown":__DIR__"qiyan.c",
         "northup" :__DIR__"chansi.c"
               ]));
        set("objects", ([
                __DIR__"npc/laoshi" : 1,
       ]) );
        set("outdoors", "qianfo");
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",-10);
	setup();
  replace_program(ROOM);
}
