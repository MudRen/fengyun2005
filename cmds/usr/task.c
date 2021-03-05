// task.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
#include <ansi.h>
int main(object me, string str)
{
	string output;
	
	if (me->query_temp("timer/big_cmd")+5 > time())
		return notify_fail("此类命令比较耗费系统资源，每五秒才能执行一次。\n");
	else
		me->set_temp("timer/big_cmd",time());
		
        me->add("sen",-5);
	output =  HIY"┌───────────────┐"NOR + HIR"　风云2005使命榜　"NOR + HIY"┌───────────────┐\n"NOR;
	output += HIY"└───────────────┘"NOR + HIR"～～～～～～～～"NOR + HIY"└───────────────┘\n"NOR;
	output += TASK_D->dyn_quest_list();
	output += HIY"┌───────────────┐"NOR + HIR"　　　　　　　　"NOR + HIY"┌───────────────┐\n"NOR;
	output += HIY"└───────────────┘"NOR + HIR"～～～～～～～～"NOR + HIY"└───────────────┘\n"NOR;

	me->start_more("", output, 0);
	return 1;
}

int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	task[0m
[0;1;37m────────────────────────────────[0m   

这个指令是用来得知目前的所有使命，由于比较耗费系统资源，
每五秒才能使用一次。

[0;1;37m────────────────────────────────[0m   
HELP
	);
	return 1;
}
