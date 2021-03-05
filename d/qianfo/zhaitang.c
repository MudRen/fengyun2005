// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","斋堂");
  set("long",@LONG
斋堂为寺内僧众吃饭的地方，安宾头庐尊者像，传说晋僧道安常注经论，夜里
梦见梵僧宾头庐劝他设  斋堂，于是大悟之下设斋堂以供之。
LONG
  );
  set("exits",([
//            "north":__DIR__"changlang3.c",
            "east" :__DIR__"guanyin.c",
            "west" :__DIR__"zt2.c",
               ]));
          set("objects", ([
                __DIR__"npc/monk" : 1,
       ]) );
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
  replace_program(ROOM);
}
