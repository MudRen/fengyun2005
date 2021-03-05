//mac's xibei.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","西碑廊");
  set("long",@LONG
此为历代皇帝举行封禅大典时的碑刻，最引人注目的是秦二世泰山刻石，为公
元前二零九年秦二世胡亥东封泰山时，令丞相李斯书刻的，可惜仅存十个残字：臣
斯去疾昧死臣请矣臣。
LONG
  );
  	set("exits",([
         	"east":__DIR__"zhengyuan",
         	"west": __DIR__"w_bei",
               ]));
   
	set("coor/x",-10);
	set("coor/y",-20);
	set("coor/z",0);
	setup();
  	replace_program(ROOM);
}
