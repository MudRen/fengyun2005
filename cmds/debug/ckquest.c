// ckquest.c
// Silencer, quest-reward checkup
// 此命令是用来检查Quest的奖励情况，
	
#include <ansi.h>
inherit F_CLEAN_UP;
void give_reward(object who, object accomplisher, mapping quest);

int main(object me, string arg) {
	
//	if (!wizardp(me) || me->query("tester"))
//		return notify_fail("巫师专用指令，违反者杀头。\n");
	seteuid(ROOT_UID);
	write("\n\n");
	me->ccommand("quest");
	if (!me->query("quest"))
		return notify_fail("你没有Ｑｕｅｓｔ。\n");
	write(sprintf(WHT"\n你的Quest是%O.\n"NOR,me->query("quest")));
	write(HIR"你的经验值是"+ me->query("combat_exp") +"\n\n"NOR);
	give_reward(me, me, me->query("quest"));
	me->ccommand("hp");
	return 1; 
}

void give_reward(object who, object accomplisher, mapping quest) 
{
	int i, d_bonus, team_size, q_bonus, max_exp,e_reward,single_exp;
	int used_time,t_bonus, l_bonus;
	int combat_exp,pot,score, ratio, sum_exp, i_pot,
		reward_silver, reward_exp, reward_score,reward_pot;
	int team_bonus, silver;
	int accomp_exp, accomp_pot, accomp_silver;
	int my_exp_level,q_num;
	int random_n, real_exp;
	int base;
	
	mapping level_data;
	
	string reward_msg;
	object ob;
	object* mem;
	
	/* 4.0 system base:
		0-10k, 		20 - 23
		10-800k, 	32 - 116
		880k-2.2M: 	116 - 233
		2.2M+		131+ random(91) --- 260
		
	*/
			
	mem = pointerp(who->query_team()) ? who->query_team() : ({ who });
	team_size = sizeof(mem);
	sum_exp = 0;
	max_exp = 0;

	// Check if max_exp player left team and calculate max_exp, sum_exp
	for(i=0; i<team_size; i++) {
		if (mem[i]) {
		    q_bonus = (int)mem[i]->query("combat_exp");
		    max_exp = (max_exp>q_bonus) ? max_exp : q_bonus;
		    sum_exp += q_bonus;		    
		}
	}
	
	q_bonus = quest["exp_bonus"];

	//Max_exp player left team, heavy penalty on cheating :D
	if (700*q_bonus > max_exp){
		q_bonus = max_exp/1024 ;
	}
	
	tell_object(who,"队伍中最大经验值为 "+max_exp+" .\n");		
	
	//Calculate base bonus
	 			
	// BASE
	
	// base exp 和 pot 奖励，这个是应该持续上升饱和在5M左右
	
	if(q_bonus < 10) 		base= 20 + q_bonus/3;
	else if (q_bonus < 800)    	base= 30 + (q_bonus *2)/9- (q_bonus*q_bonus)/7000;
	else if (q_bonus < 2000) 	base= 50 + q_bonus/12;
	else 				base= 40 + q_bonus/24 + random(q_bonus/24);
	
	if(base > 160) {
		base = 260 - 3*16000/(base*2);	
	}
	
	real_exp = base;				//这个是用来计算 pot 的真实exp. 
	
	// 修正 5M 以上的 exp 奖励，反向逐渐减少。
	if (q_bonus > 5000)	{
		base = (q_bonus< 10000)?(10000 - q_bonus)/ 20:10;
	}
	
			
	combat_exp = base;				// 这是未经过team bonus的个人奖励exp。
	
	// 潜能的 Difficulty BONUS
	// 规则：
	// 	(1)	比较难杀+5, 
	//	(2)	比较远+5, (包括物品) After 5M, this is no longer the case.
	//	(3)	肯定有生命危险+10-15, 
	//	(4)	Random() +5, 
	//				--> 30 Maxium. 	If >30... 你定得级别有问题。
	if(quest["difficulty"]) {
		d_bonus = 100 * (quest["difficulty"]-5)/10;
		if (max_exp *9/10 > q_bonus) {
			d_bonus = d_bonus/2;
			tell_object(who,"经验明显高于quest，quest难度奖励/2 = d_bonus = " + d_bonus + "\n");
		}else if (max_exp > q_bonus) {
			d_bonus = d_bonus *2/3;
			tell_object(who,"经验高于quest，quest难度奖励2/3 = d_bonus = " + d_bonus + "\n");
		}else 
			tell_object(who,"经验小于等于quest，quest难度奖励 = d_bonus = " + d_bonus + "\n");
	}	else
			tell_object(who,"没有quest难度奖励 = d_bonus = 0 \n");
	
		
	// 潜能的 TIME BONUS
	if (quest["quest_type"] == "杀") {
		used_time = (int) time() - who->query("task_time");
		if(used_time < 60) {  		//Get 50% bonus for finishing within 1 minutes
			t_bonus = 100 / 2;
		} else if (used_time < 360) {  	//Get a little bonus for finishing within 6 minutes
			t_bonus = 100 * (360 - used_time) /600;
		}
	}
		
	
	//Add some bonus for team to share 
	// 1M 以下得到２０％／ppl, 以后为　８％／ｐｐｌ．
	if (q_bonus<1024) {
		team_bonus = 100;
		team_bonus = team_bonus < (team_size -1)* 20 ? team_bonus : (team_size -1)* 20 ;
	} else {
		team_bonus =  40 ;
		team_bonus = team_bonus < (team_size -1)* 100/12 ? team_bonus : (team_size -1)* 100/12 ;
	}
	
//	tell_object(who,"team_bonus is"+(string)(team_bonus)+".\n");
//	tell_object(who,"total exp reward"+(string)(combat_exp)+".\n");
	

//	考虑 TEAM BONUS 和　随机数　后的　经验，潜能奖励．
	random_n = random(100);	
	combat_exp = combat_exp + combat_exp * (random_n + team_bonus) /100;
	real_exp   = real_exp   + real_exp   * (random_n + team_bonus + d_bonus + 10) /100;

	if(q_bonus < 200) 			pot = real_exp / 7 + 1;
	else if (q_bonus < 4000)		pot = real_exp / 6 + 1;
	else if (q_bonus < 5500)		pot = real_exp *10 /55 + 1;
	else 					pot = real_exp / 5 + 1;


//	tell_object(who,"q_bonus is"+(string)(q_bonus)+".\n");
/*	tell_object(who,"  你正在做exp "+q_bonus*1000+" 段的ｑｕｅｓｔ.\n");
	tell_object(who,"  你得到奖励的Ｂａｓｅ是 "+base+" 点经验．\n");
	tell_object(who,"  你的时间奖励是(以１０模拟)" + t_bonus + "％ , 难度奖励是 " + d_bonus + "％ .\n");
	tell_object(who,"  你的 Random seed 增加" + random_n + "％ .\n");
	tell_object(who,WHT"  你得到奖励的exp 是 "+combat_exp+" 点经验．\n"NOR);

	level_data=F_LEVEL->exp_to_level(who->query("combat_exp"));
	
	tell_object(who,HIG" 按这个速度，"+level_data["level"]+"级共需要" 
		+(level_data["next_level"]/combat_exp)+" 个Ｑｕｅｓｔ来升到下一级。\n\n"NOR);*/
	

	// add money
	if (q_bonus< 50) silver = 10 + random(10);
	else if (q_bonus< 100) silver = 10 + random(20);
	else if (q_bonus< 500) silver = 10 + random(30);
	else if (q_bonus< 1000) silver = 20 + random(40); 
	else silver = 30+random(60);
	
	accomp_exp = combat_exp;
	accomp_pot = pot;
	accomp_silver = silver;
	
	if (sum_exp == 0) sum_exp = 1;
	for(i=0; i<sizeof(mem); i++) {
		if (mem[i])
		if (mem[i]!=accomplisher) {
			
			ratio = (10* mem[i]->query("combat_exp"))/sum_exp*10;
//			tell_object(mem[i],"ratio is "+ratio+"\n");
			reward_exp= (combat_exp*ratio)/100>0 ? (combat_exp*ratio)/100 : 1;
			if((silver/team_size ) > 0 && objectp(ob = new("/obj/money/silver"))) {
				reward_silver= (silver*ratio)/100>0 ? (silver*ratio)/100 : 1;
				ob->set_amount(reward_silver);
				if(mem[i]->query("env/savemymoney"))
					mem[i]->add("deposit",reward_silver*100);
				else
					ob->move(mem[i]);
			}
		
			accomp_exp = accomp_exp - reward_exp;
			accomp_pot = accomp_pot - pot * ratio/100;
			accomp_silver = accomp_silver - reward_silver;
			
			i_pot= pot* ratio/100;
			 						
			mem[i]->add("combat_exp", reward_exp);
			mem[i]->add("potential", i_pot);
			mem[i]->add("score", (score*ratio) / 100);	
			
//			if (reward_exp > 1000)
//				log_quest(mem[i], who, quest, reward_exp, i_pot, used_time, base);
						 
			score =  mem[i]== accomplisher? 1 : 0;
			reward_msg = mem[i]==who ? HIW : HIW+"队伍成员 "+who->name()+" 的";
			reward_msg +="任务被"+accomplisher->name()+"完成，你被奖励了：\n\t\t" +
				chinese_number(i_pot) + "点潜能\n\t\t" +
				chinese_number(score) + "点评价\n\t\t" + 
				chinese_number(reward_silver) + "两银子\n" + NOR;
			
			tell_object(mem[i],reward_msg);
			mem[i]->add("FINISH_QUEST",1);
		}
	}
	
	score = 1;
	accomplisher ->add("score", 1);
	accomplisher->add("combat_exp", accomp_exp);
//	accomplisher->add("potential", accomp_pot);
	
//	log_quest(accomplisher, who, quest, accomp_exp, accomp_pot,used_time, base);
	
	if(objectp(ob = new("/obj/money/silver"))) {
		ob->set_amount(accomp_silver);
		if(accomplisher->query("env/savemymoney"))
			accomplisher->add("deposit",accomp_silver*100);
		else
			ob->move(accomplisher);
	}
	reward_msg = accomplisher==who ? HIW : HIW+"队伍成员 "+who->name()+" 的";
	reward_msg +="任务被你完成，你被奖励了：\n\t\t" +
	chinese_number(accomp_exp) + "点江湖经验\n\t\t" +
	chinese_number(accomp_pot) + "点潜能\n\t\t" +
	chinese_number(1) + "点评价\n\t\t" + 
	chinese_number(accomp_silver) + "两银子\n" + NOR;
	
	tell_object(accomplisher,reward_msg);
	accomplisher->add("FINISH_QUEST",1);
	who->set("quest", 0 );
	return;
}


int help(object me) {
	write(@HELP
指令格式 : quest
 
这个指令可以显示出你当前的任务。
HELP);
	return 1;
}
