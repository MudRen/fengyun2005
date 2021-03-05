// respirate.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	int gin_cost=30, atman_gain;
    	string magic_skill;
    
    	seteuid(getuid());
    
    	if (userp(me))
    		return notify_fail("此指令已被exercise取代，请help exercise \n");
    		
    	if(environment(me)->query("no_fight"))
        	return notify_fail("你不可以在这里修行。\n");
    	if( me->is_fighting() )
        	return notify_fail("战斗也是一种修行，但不能和灵力的修行同时进行。\n");
    	if( me->is_busy() )
        	return notify_fail("你上一个动作还没有完成，不能修行。\n");
    
    	if( arg && !sscanf(arg, "%d", gin_cost) )
        	return notify_fail("你要花多少精力修行？\n");
    
    	if( gin_cost < 10 ) return notify_fail("你最少要花 10 点精力才能进行修行。\n");
    
    	if( (int)me->query("gin") < gin_cost )
        	return notify_fail("你现在精力不足，无法修行灵力！\n");
    
    	if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 70 )
        	return notify_fail("你现在身体状况太差了，无法集中精神！（气血值至少在70%以上）\n");
    
    	if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 70 )
        	return notify_fail("你现在精神状况太差了，无法控制自己的心灵！（心神值至少在70%以上）\n");
    
    	write("你盘膝而坐，闭上眼睛开始凝聚思绪。\n");
    	me->start_busy(1);
    	me->add("gin", -gin_cost);
    
    	// This function ranged from 1 to 15 when gin_cost = 30
    	atman_gain = gin_cost * ((int)me->query_skill("magic")/10 + (int)me->query_int() ) / 30;
    	atman_gain = (atman_gain + random(atman_gain))/5;
    
    	if( atman_gain < 1 ) {
        	write("但是你一不小心却睡著了。\n");
        	return 1;
    	}
    
    	me->add("atman", atman_gain );
    
    	if( (int)me->query("atman") > (int)me->query("max_atman") * 2) {
        	if( (int)me->query("max_atman") >= ((int)me->query_skill("magic", 1) +
             					me->query_skill("magic")/5) * 5 ) {
            		write("你觉得一阵天旋地转，头涨得像要裂开一样，似乎灵力的修行已经遇到了瓶颈。\n");
        		me->set("atman", 2*me->query("max_atman"));	
        	} else {
            		write("你的灵力提高了！\n");
            		me->add("max_atman", 1);
            		me->set("atman", me->query("max_atman"));
        	}
        }	
    	return 1;
}

int help(object me)
{
    write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : respirate [<耗费「精」的量，预设值 30>][0m
[0;1;37m────────────────────────────────[0m 
打坐修行，利用「炼精化气，炼气化神，炼神还虚」的方法将你的精力
转变成灵力。

打坐的得到的灵力最大值 == 基本法术等级*5 + 当前的有效法术等级
举例:	 法术 (magic)                        - 出神入化  150
 	　法术 (magic)     ： 乾坤无形         有效等级：275 
灵力最大值 = 150*5 + 275 = 1025

平均转化效率＝ （有效法术等级／１０＋才智）／１００

请参考 help attributes.txt
相关指令：
	增加内力	ｅｘｅｒｃｉｓｅ	
	增加法力	ｍｅｄｉｔａｔｅ
	
	恢复体力：	ｅｘｅｒｔ　ｒｅｃｏｖｅｒ
	恢复心神：	ｅｘｅｒｔ　ｒｅｆｒｅｓｈ
	恢复精力：	ｅｘｅｒｔ　ｒｅｇｅｎｅｒａｔｅ
[0;1;37m────────────────────────────────[0m
HELP
        );
    return 1;
}
