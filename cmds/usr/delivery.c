// flower_delivery.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// created by suu on Oct/31/01
	
#include <ansi.h>
inherit F_CLEAN_UP;
int time_period(int timep, object me);

int main(object ob, string arg) {
	int nowtime = time();
	object me;
	if(!arg || !wizardp(ob)) 
	{
		me = this_player();
		if(!me->query("delivery")) 
		{
			if((me->query("next_delivery_time")) > time()) 
			{
				return notify_fail(HIW"你要过" 
                + QUESTS_D->wait_period(me->query("next_delivery_time") - time()) 
                + "之后才可继续送花。\n"NOR);
			}else 
			return notify_fail("你现在没有任何送花任务！\n");            
		}
		if(mapp(me->query("delivery")))
		{
			mapping delivery;
			delivery =  me->query("delivery");
            write(WHT"你现在的任务是替"  + delivery["sender"] + "送花给住在"
+delivery["area"]+"的"+delivery["receiver"]->name()+"。\n"NOR);
		} else 
		{
			return notify_fail("你现在没有任何送花任务！\n");            
		}
		nowtime = (int)time() - me->query("delivery_time");
		if(nowtime  < 600) 
		{
			time_period(nowtime, me);
		} else 
		{
            return notify_fail("你已经没有足够的时间来完成它了。\n");
			if (nowtime < 1200)
			{
				return notify_fail(HIW"你要过" 
				+  QUESTS_D->wait_period(1200-nowtime) 
				+ "之后才可继续送花。\n"NOR);
			}
		}
	} else 
	{
		if(!(ob = present(arg, environment(ob))) && !(ob =  find_player(arg))) 
		{
			return notify_fail("你要察看谁的送花任务？\n");
		}
		if(!ob->query("delivery")) 
		{
			if((ob->query("next_delivery_time")) > time()) 
			{
				return notify_fail(HIW+ob->name()+"要过" 
                + QUESTS_D->wait_period(me->query("next_delivery_time") - time()) 
                + "之后才可继续送花。\n"NOR);
			}else 
				return notify_fail(ob->name()+"现在没有任何送花任务！\n");
		}

		if(mapp(ob->query("delivery"))) 
		{
			mapping delivery;
			delivery =  ob->query("delivery");
			write(WHT""+ob->name()+"现在的任务是替"  + delivery["sender"] + "送花给住在"
+delivery["area"]+"的"+ delivery["receiver"]->name()+"。\n"NOR);
		}else 
		{
			return notify_fail(ob->name()+"现在没有任何送花任务！\n");            
		}

		nowtime = (int)time() - ob->query("delivery_time");
		if(nowtime  < 600) 
		{
			time_period(nowtime, ob);
		} else 
		{
			return notify_fail(ob->name()+"已经没有足够的时间来完成它了。\n");
			if (nowtime < 1200)
			{
				return notify_fail(HIW+ob->name()+"要过" 
				+  QUESTS_D->wait_period(1200-nowtime) 
				+ "之后才可继续送花。\n"NOR);
			}
		}
	}	
	return 1;
}

int time_period(int timep, object me) {
	int t, d, h, m, s;
	string time;
	t = timep;
	s = t % 60;             t /= 60;
	m = t % 60;             t /= 60;
	h = t % 24;             t /= 24;
	d = t;
	
	if(d) time = chinese_number(d) + "天";
	else time = "";
	
	if(h) time += chinese_number(h) + "小时";
	if(m) time += chinese_number(m) + "分";
	time += chinese_number(s) + "秒";
	tell_object(me,"任务已经开始了" + time + "\n");
	return 1;
}

int help(object me) {
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	指令格式 : delivery[0m
[0;1;37m────────────────────────────────[0m   
 
这个指令可以显示出你当前的送花任务。

[0;1;37m────────────────────────────────[0m  
HELP);
	return 1;
}
