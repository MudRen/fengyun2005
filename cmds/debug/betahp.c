/* 	等级系统现在在／ｆｅａｔｕｒｅ／ｅｘｐ＿ｌｅｖｅｌ．ｃ
			－－ by Silencer
	
*/
 
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_LEVEL;

//	Some Reference for wizards.
//  100k (L34)，500k (L61)，1M(L78)，2M(L97)，3M(L109)
//  4M(L118)，5M(L128)，6M(L133),7M(L139),8M(L144),9M(L147),10M(L150)

string status_color(int current, int max);	//颜色 
 
int main(object me, string arg)
{
    	object ob;
    	mapping my, exp_data;
 	int level, old_level, pot_reward;
 	
    	seteuid(getuid(me));
 
    	if(!arg) ob = me;
    	else 
    	{
	        ob = present(arg, environment(me));
	        if (!ob) ob = find_player(arg);
	        if (!ob) ob = find_living(arg);
	        if (!ob) return notify_fail("你要察看谁的状态？\n");
    	}
    	     
    	my = ob->query_entire_dbase();
/*    	    printf(HIC"≡"HIY"────────────────────────────"HIC"≡\n"NOR);	
    	    printf(CYN"    			"+ my["name"] + "\n"NOR);	
    	    printf(HIC"≡"HIY"────────────────────────────"HIC"≡\n"NOR);	*/
	    printf(" 【精力】%s%5d/ %5d %s(%3d%%)" NOR "    【食物】%s%3d%%\n" NOR,
	           status_color(my["gin"], my["eff_gin"]),	my["gin"],	my["eff_gin"],
	           status_color(my["eff_gin"], my["max_gin"]),	my["eff_gin"] * 100 / my["max_gin"],
	           status_color(my["food"], ob->max_food_capacity()),
	           my["food"] * 100/ob->max_food_capacity()	
	        );
	    printf(" 【气血】%s%5d/ %5d %s(%3d%%)" NOR "    【饮水】%s%3d%%\n" NOR,
	           status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
	           status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
	           status_color(my["water"], ob->max_water_capacity()),
	           my["water"] * 100/ob->max_water_capacity()
	        );
	    printf(" 【心神】%s%5d/ %5d %s(%3d%%)" HIW "    【评价】 %d\n" NOR,
	           status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
	           status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"],
	           my["score"]
	        );
	    printf(" 【灵力】%s%5d/ %5d (%4d)" HIR "    【杀气】 %d\n" NOR,
	           status_color(my["atman"], my["max_atman"]),     my["atman"], my["max_atman"],
	           my["atman_factor"],
	           my["bellicosity"]
	        );
	    printf(" 【内力】%s%5d/ %5d (%4d)"  HIG "    【潜能】 %d\n" NOR,
	           status_color(my["force"], my["max_force"]),     my["force"], my["max_force"],
	           my["force_factor"],
	           (my["potential"] - my["learned_points"])
	        );
	    exp_data = exp_to_level(my["combat_exp"]);    
	    
	    if (wizardp(me) && me->query("oldexp")) {	// 此项允许Wiz用旧有的经验体系察看。
	    	printf(" 【法力】%s%5d/ %5d (%4d)"HIM "    【经验】%d\n" NOR,
	           status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
	           my["mana_factor"],
	           my["combat_exp"]		    		
	        );
	    } else 
	    	    printf(" 【法力】%s%5d/ %5d (%4d)"HIM "    【等级】 Ｌ%d （%d.%d％）\n" NOR,
		           status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
		           my["mana_factor"],
				exp_data["level"],
		    		exp_data["sub"]/10,
		    		exp_data["sub"]%10,
		    	);
//	printf(HIC"≡"HIY"────────────────────────────"HIC"≡\n"NOR);
   	level = exp_data["level"];
	if (ob == this_player() && level > ob->query("achieved_level")) {
    		
    		old_level = ob->query("achieved_level");
    		me->set("level",level);
    		me->set("achieved_level",level);
    		
    		write(HIR"\n恭喜，你的经验等级上升到"+chinese_number(me->query("level"))+"级。\n"NOR);
		
		// 每等级奖励一定潜能值。
		pot_reward = level_to_pot(level) - level_to_pot(old_level);
		me->add("potential",pot_reward);
		write(HIR"你得到了"+pot_reward+"点潜能。\n"NOR);
		
		write (WHT"由于你勤学苦练，你的精气神值增加了。\n\n"NOR);

		me->save();
		if (me->query("gender")==("女性")) 
			message_vision(CYN"$N快乐地跳起舞来！ 「 哈哈哈，升级了！」\n"NOR,me);
		else 
			message_vision(CYN"$N得意地作出胜利的手势 「 V 」  说: 「 哈哈哈，升级了！」\n"NOR,me);
			
	}    	
    	return 1;
}
 
string status_color(int current, int max)
{
    int percent;
 
    if( max>0 ) percent = current * 100 / max;
    else percent = 100;
    if( percent > 100 ) return HIC;
    if( percent >= 90 ) return HIG;
    if( percent >= 60 ) return HIY;
    if( percent >= 30 ) return YEL;
    if( percent >= 10 ) return HIR;
    return RED;
}
 
int help(object me)
{
    write(@HELP
    write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : hp [0m
[0;1;37m────────────────────────────────[0m 
这个指令显示你(玩家)的一些基本状态：

 【精力】 4086/  4086 (100%)    【食物】  0%
 【气血】 5001/  5001 (100%)    【饮水】  0%
 【心神】 4081/  4086 (100%)    【评价】 946454
 【灵力】 1125/  1125 (   0)    【杀气】 12
 【内力】 1385/  1385 (  70)    【潜能】 3168879
 【法力】 1109/  1109 (   0)    【等级】 Ｌ34 （85.1％）


[37m【等级】[32m风云中用来衡量一个武林人物的最重要参数，决定你能学到
	武功技能的高低以及在战斗中的威力。等级后的百分比表示
	此一等级的完成度，１００％时升级。升级的奖励：
	（１）潜能：可以用来学习各种技能
	（２）精气神值：逐步增长

[37m【食物、饮水】[32m	可由客栈购买补充（ｅａｔ／ｄｒｉｎｋ）。

[37m【评价】[32m评价可由完成Quest/Task、解谜探险等提高，是拜师学艺、
	购置房屋、开帮结派等的必需条件。
	
[37m【杀气】[32m会随杀人数目而增长，如果太高了会胡乱攻击在场的人，降
	低杀气可去风云城里的洗礼池，或者使用一些特殊的内功心
	法。
	
[37m【潜能】[32m用来学习各种技能

[37m【精力】[32m等属性请参看ｈｅｌｐ　ｎｅｗｂｉｅ

类似命令参看 : score
[0;1;37m────────────────────────────────[0m 

HELP
    );
    return 1;
}
