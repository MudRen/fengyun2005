// quest.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
	
#include <ansi.h>
inherit F_CLEAN_UP;
string time_period(int timep);

int main(object ob, string arg) {
	
	int i, time, nowtime, newbie;
	object me;
	object* mem;
	mapping quest;
	string msg,n_msg;

// NEWBIE QUEST INFORMATION

	newbie = REWARD_D->riddle_check(ob,"新手入门");
	
	switch (newbie) {
		case 1: if (!ob->query_temp("marks/newbie_quest")) 
					n_msg = "
你现在的任务是，到风云阁（风云广场向上）去找天机老人（ｑｕｅｓｔ），不知道
天机广场在哪儿？风云城的正中心就是了。\n";
				else			
					n_msg = "
你现在的任务是，替天机老人去向武当掌门石雁问个好，出风云东城门到赤峰路向南，
上了武当山就能找到他。（从风云天下出发东行十步，南行八步，上山后找紫霄宫就是，
见面后石雁自然会有安排，对了，他有时候比较忙可能没注意到你，出去再进来他就会
看到你了）\n";
				write(n_msg);
				return 1;
		case 2: if (!ob->query_temp("marks/newbie_quest")
					|| ob->query_skill("literate",1)>=1)
					n_msg = "
你现在的任务是，返回风云城向天机老人交差（ｑｕｅｓｔ）\n";
				else
					n_msg= "
你现在的任务是，到北城及第街贡院王仁德那儿去学点读书写字，
（learn literate from kao guan with 1），如果不知道怎么走，到北城输入ｍａｐｓ
在地图上找贡院就是。\n";
				write(n_msg);
				return 1;
		case 3: n_msg = "
你现在的任务是，替天机老人去拜见一下关外大昭寺宝塔的塔祝，可以自此向南从沉香镇
走（参看ｈｅｌｐ　ｎｅｗｂｉｅ中的风云地区介绍），或者到西城风云驿站王风处租马
车穿越沙漠，（到那儿看看告示就知道向王凤问什么了）\n";
				write(n_msg);
				return 1;
		case 4: n_msg = "
你现在的任务是，返回风云城向天机老人交差（ｑｕｅｓｔ），可以从迎梅客栈坐马车，
也可以从沉香镇绕路，那就要小心看看ｈｅｌｐ　ｎｅｗｂｉｅ中风云地区的说明了。\n";
				write(n_msg);
				return 1;
	}		
		
// END Of Newbie QUest
	
	if(!arg || !wizardp(ob)) {
//	(1)	Player self-check
		me = this_player();
		mem = pointerp(me->query_team()) ? me->query_team() : ({ me });
		i = sizeof(mem);
		while(i--){
			if (mem[i]) {
		    	    if (mem[i] != me) {
		    	      	if(mapp(mem[i]->query("quest"))) {
		    	      		quest =  mem[i]->query("quest");
					if (quest["quest_type"] != "special") {
						msg = WHT"队友 "+ mem[i]->name() + " 现在的任务是: 到"+quest["quest_location"]
							+"去"+ HIR + quest["quest_type"] + NOR WHT"『"NOR + quest["quest"] + NOR+ WHT "』，";	
					}else
						msg = WHT"队友 "+ mem[i]->name() + " 现在的任务是: "NOR + quest["short"] + "，";															
					tell_object(me, msg);
					
					nowtime = time() - mem[i]->query("quest_time");
//					time = 	quest["duration"] >= 900 ? quest["duration"] : 900;
					time = 	quest["duration"] >= 1 ? quest["duration"] : 900;
					if( nowtime  < time ) {
						tell_object(me,"必须在" + time_period(time-nowtime) + "内完成这个任务。\n");
					} else 
	                			write(YEL"但是"+ mem[i]->name() +"已经没有足够的时间来完成它了。\n"NOR);
	                	}
		    	    }
			}
		}
	
	    	if(!me->query("quest")) {
		        if((me->query("next_time")) > time()) {
			    	return notify_fail(WHT"你要过" 
		                	+ time_period(me->query("next_time") - time()) 
		                	+ "之后才可要任务。\n"NOR);
		        }
		        else {
		       		return notify_fail(NOR"你现在没有任何任务！\n");            
		        }
	    	}
		
		if(mapp(me->query("quest"))) {
			quest =  me->query("quest");
	        if (quest["quest_type"] != "special") {
				msg = WHT"你现在的任务是: 到"+quest["quest_location"]+"去"+ HIR+ quest["quest_type"] + NOR WHT"『"NOR + quest["quest"] + NOR WHT"』，";	
			}else
				msg = WHT"你现在的任务是: " + quest["short"] + WHT"，";															              
			tell_object(me,msg);
			nowtime = (int)time() - me->query("quest_time");
//					time = 	quest["duration"] >= 900 ? quest["duration"] : 900;
					time = 	quest["duration"] >= 1 ? quest["duration"] : 900;
			if( nowtime  < time) {
				tell_object(me,"你必须在" + time_period(time-nowtime) + "内完成这个任务。\n"NOR);
			} else {
		                write("但是你已经没有足够的时间来完成它了。\n"NOR);
		                me->set("quest", 0 );
		                me->delete("cont_quest");	// 去除连续QUest记数
		                me->delete("annie_quest");
		                me->delete_temp("annie_quest");
		                me->delete_temp("luyu");
		                return notify_fail("这个任务自动取消了。\n");
			}
		} else if(!me->query("quest")) {
		        if((me->query("next_time")) > time()) {
			    return notify_fail(WHT"你要过" 
		                	+ time_period(me->query("next_time") - time()) 
		                	+ "之后才可要任务。\n"NOR);
		        }
		        else {
		            	return notify_fail(NOR"你现在没有任何任务！\n");            
		        }
	    	} else
	    		return notify_fail(HIR"程序错误，请通知巫师察看。\n"NOR);
		
	
	} 
// (2)	Wizard check Players' quests
	else {
	 	if(!(ob = present(arg, environment(ob))) && !(ob =  find_player(arg))) {
		return notify_fail("你要察看谁的任务？\n");
		}
		if(!ob->query("quest")) {
                	return notify_fail(ob->name()+"现在没有任何任务！\n");
		}
		if(mapp(ob->query("quest"))) {
			quest =  ob->query("quest");
               		if (quest["quest_type"] != "special") {
				msg = WHT""+ob->name() + "现在的任务是: 到"+quest["quest_location"]+"去"+ quest["quest_type"] + "『"NOR + quest["quest"] + NOR WHT"』，";	
			}else
				msg = WHT""+ob->name() + "现在的任务是: " + quest["short"] + "，"NOR;	
                	write(msg);
		} 
	
		nowtime = (int)time() - ob->query("quest_time");
//					time = 	quest["duration"] >= 900 ? quest["duration"] : 900;
					time = 	quest["duration"] >= 1 ? quest["duration"] : 900;
		if( nowtime  < time) {
			write("必须在" + time_period(time-nowtime) + "内完成这个任务。\n"NOR);
		} else {
	                write(NOR"但是已经没有足够的时间来完成它了。\n"NOR);
		}
	}	
	return 1;
}

/*
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
	tell_object(me,"必须在" + time + "完成这个任务。\n");
	return 1;
}*/

string time_period(int timep) {
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
	
	return time;
}



int help(object me) {
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 		ｑｕｅｓｔ[0m
[0;1;37m────────────────────────────────[0m

这个指令可以显示出你和你的队友当前的任务。

[0;1;37m────────────────────────────────[0m

HELP);
	return 1;
}
