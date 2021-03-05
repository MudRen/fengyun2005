//mac's tiankuang.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <room.h>
inherit ROOM;
void create()
{
  set("short","天贶殿");
  set("long",@LONG
天贶殿为正殿，正面为高大的东岳大帝彩塑像，周围摆放着历代皇帝举行祭典
时用的祭器和乐器，殿壁东北南三面为大型壁画，展示泰山神出巡时的浩大场面。
LONG
  );
  	set("exits",([
        	 "north":__DIR__"houqing",
         	 "south":__DIR__"zhengyuan",
         	 "east": __DIR__"dongci",
        ]));
        set("objects", ([
                __DIR__"npc/master_semi" : 1,
        ]) );
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
  
}

int valid_leave(object me, string dir)
{
	if (userp(me))
		REWARD_D->riddle_done(me,"智入岱庙",10,1);
	if (QUESTS_D->verify_quest(me,"智入岱庙"))
		QUESTS_D->special_reward(me,"智入岱庙");  
	return 1;
}
