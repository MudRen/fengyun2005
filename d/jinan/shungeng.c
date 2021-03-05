// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","舜耕山庄");
  set("long",@LONG
这便是赫赫有名的舜耕山庄，舜耕山又称历山，传说是舜—虞重华的出身地。
是真是假已不得而知，但这里的房子确实千金难求。能在此有一处房产是许多人一
生的梦。而丐帮褴褛衣衫之下，其实是富甲天下，好大喜功的现任帮主南宫灵一掷
千金在此建立了奢华的丐帮总堂。
LONG
  );
  	set("exits",([
         "east":__DIR__"street2",
         "north":__DIR__"gb1",
         "west":__DIR__"gb5",
               ]));
        set("valid_startroom", 1);
	set("coor/x",-20);
	set("coor/y",80);
	set("coor/z",0);
	setup();
        
}
