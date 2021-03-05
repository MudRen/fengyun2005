// exe 吐纳练习， 提高内力、法力、灵力 
//	本命令是exercise, meditate, respirate 的综合，
//	目的是减少玩家记忆繁琐的命令----- Silencer @ fy4


#include <skill.h>
inherit F_CLEAN_UP;

string *add = ({ "qi", "jing", "shen" });
mapping *type = ({
	([      "add":                	"force",
                "add_c":		"内力",
                "cost":           	"kee",
                "cost_c":            	"气血",
                "skill":		"force",
                "u_msg":		"你坐下来运气用功，一股内息开始在体内流动。\n",
                "l_msg":		"但是当你行功完毕，只觉得全身发麻。\n",
                "f_msg":		"当你的内息遍布全身经脉时却没有功力提升的迹象，似乎内力修为已经遇到了瓶颈！\n",
        ]),
	([      "add":                	"atman",
                "add_c":		"灵力",
                "cost":           	"gin",
                "cost_c":            	"精力",
                "skill":		"magic",
                "u_msg":		"你盘膝而坐，闭上眼睛开始凝聚思绪。\n",
                "l_msg":		"但是你一不小心却睡著了。\n",
                "f_msg":		"你觉得一阵天旋地转，头涨得像要裂开一样，似乎灵力的修行已经遇到了瓶颈。\n",
        ]),
        ([      "add":                	"mana",
                "add_c":		"法力",
                "cost":           	"sen",
                "cost_c":            	"心神",
                "skill":		"spells",
                "u_msg":		"你盘膝而坐，静坐冥思了一会儿。\n",
                "l_msg":		"但是当你睁开眼睛，只觉得脑中一片空白。\n",
                "f_msg":		"你忽然觉得脑中一片混乱，似乎法力的提升已经到了瓶颈。\n",
        ]),
});

int main(object me, string arg)
{
    	int kee_cost=30;
    	int n, amount, gain , i;
    	string add_1, h_cost, h_gain;
    	
    	seteuid(getuid());
        
    	if(environment(me)->query("no_fight"))
        	return notify_fail("你不可以在这里吐纳练功。\n");
               	
    	if( me->is_fighting() )
        	return notify_fail("战斗中不能吐纳练功，会走火入魔。\n");
    	if( me->is_busy() )
        	return notify_fail("你上一个动作还没有完成，不能吐纳练功。\n");
    
    	if (!arg || sscanf(arg, "%s %d", add_1, amount) != 2)
    		return notify_fail("指令格式：exercise <jing/qi/shen> <数目> \n");
    	
     	n = member_array(add_1, add);
    	if ( n == -1)
    		return notify_fail("格式：exercise <jing/qi/shen> <数目> \n");
    	   	   	
    	if (amount < 10)
    		return notify_fail(type[n]["add_c"]+"的修行最少需要耗费10点"+ type[n]["cost_c"]+ "。\n");
    		
//	write ("add_1 is "+  type[n]["cost"] + " amount is "+ amount +"\n");
 
		h_cost = type[n]["cost"];
		h_gain = type[n]["add"]; 
 
 		if( me->query(h_cost) < amount )
        	return notify_fail("你现在的"+ type[n]["cost_c"]+ "太少了，无法吐纳练习。\n");

		if (me->query("death_revive")+ 180 > time())
			return notify_fail("你现在的身体状况无法吐纳练功。\n");
	
		for (i=0;i<sizeof(type); i++) {
		if (i == n)	continue;
		if ( me->query( type[i]["cost"]) * 100 / me->query ("max_"+ type[i]["cost"]) < 70 )
        		return notify_fail("你现在身体状况太差了，无法吐纳练功！（" + 
        			type[i]["cost_c"] + "值至少在70%以上）\n");
    	}
        	
        	
		write(type[n]["u_msg"]);
        	
 		me->add(h_cost, -amount);
    	me->start_busy(1);

	// (500/10 + 40 )/30 = 3 , (3 + random (3))/ 5= 60% - 120% 效率 maxium at enable= 500, att = 40。
    	
    	gain = me->query_skill(type[n]["skill"]) /10;
    	switch (h_cost) {
    		case "kee":	gain =  amount * (gain + me->query_con()) / 30; break;
    		case "sen":	gain =  amount * (gain + me->query_spi()) / 30; break;
    		case "gin":	gain =  amount * (gain + me->query_int()) / 30; break;
    		default:	write(" 你发现了一个臭虫，请立即报告巫师。\n"); return 1;
    	}
    		
    	gain = (gain + random(gain))/5;

    	if( gain < 1 ) {
        	write(type[n]["l_msg"]);
        	return 1;
    	}

//	write ("amount is "+ amount + " gain is "+ gain + "\n");
    	me->add( h_gain, gain );

		if( me->query(h_gain) > me->query("max_" + h_gain) * 2) {
        	if( me->query("max_" + h_gain) >= ( me->query_skill( type[n]["skill"], 1) + 
             						me->query_skill(type[n]["skill"])/5 ) * 5 ) {       		
            		write(type[n]["f_msg"]);
			me->set(h_gain, 2 * me->query("max_" + h_gain));	
		} else {
            		write("你的"+ type[n]["add_c"] + "增强了！\n");
            		me->add("max_" + h_gain, 1);
            		me->set(h_gain, me->query("max_"+h_gain ));
        	}
        }
        me->status_msg("all");
        me->force_status_msg("all");
    	return 1;
}


int help(object me)
{
    write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	exercise <jing|qi|shen> <数量>[0m
[0;1;37m────────────────────────────────[0m
风云2005中的吐纳练功指令比早期版本有极大改进，将原来的exercise、
meditate、respirate命令综合为同一个，便于玩家上手记忆。

根据指令后参数的不同，吐纳练功有三种，分别提高灵力、内力、法力。

exercise jing <数量> 	打坐修行，利用「炼精化气，炼气化神，
			炼神还虚」的方法将你的精力转变成[0;1;31m灵力[0m。

exercise qi <数量> 	运气练功，控制体内的气在各经脉间流动，
			藉以训练人体肌肉骨骼的耐力、爆发力，
			并且用[0;1;31m内力[0m的形式将能量储备下来。
			
exercise shen <数量>	静坐冥思，将游离的精神力有效地集中凝
			聚成能够用来施展法术的能量，藉以增加
			自己的[0;1;31m法力[0m。


打坐得到的内力最大值 == 基本内功等级*5 + 当前的有效内功等级
举例:　内功心法 (force)                      　 -深不可测  200
　　 　内功 (force)          ： 混沌功           有效等级：295 
内力最大值 = 200*5 + 295 = 1295

平均转化效率＝ （有效内功等级／１０＋体质）／１００

灵力、法力的计算与内力完全相同。

相关指令：
	恢复体力：	ｅｘｅｒｔ　ｑｉ
	恢复心神：	ｅｘｅｒｔ　ｓｈｅｎ
	恢复精力：	ｅｘｅｒｔ　ｊｉｎｇ
[0;1;37m────────────────────────────────[0m
HELP
        );
    return 1;
}
 
