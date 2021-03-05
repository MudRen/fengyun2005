// ckquest.c
// Silencer, quest-reward checkup
// 此命令是用来检查Quest的奖励情况，
	
#include <ansi.h>
inherit F_CLEAN_UP;
void give_reward(object who, object accomplisher, mapping quest);

int main(object me, string arg) {
	
	if (!wizardp(me))
		return notify_fail("巫师专用指令，违反者杀头。\n");
	write("\n\n");
	me->ccommand("quest");
	if (!me->query("quest"))
		return notify_fail("你没有Ｑｕｅｓｔ。\n");
//	write(sprintf(WHT"\n你的Quest是%O.\n"NOR,me->query("quest")));
	give_reward(me, me, me->query("quest"));
	me->add("FINISH_QUEST",1);
	if (me->query("MY_QUEST")%100 ==0)
		write (HIR"经验值= "+me->query("combat_exp")+"  完成数= "+me->query("MY_QUEST")+" 潜能＝"
			+me->query("potential")+"\n"NOR);
	return 1; 
}

void give_reward(object who, object accomplisher, mapping quest) 
{
	int i, base, d_reward, team_size, q_bonus, max_exp,e_reward,single_exp;
	int used_time,t_reward;
	int combat_exp,pot,score, ratio, sum_exp, i_pot,
		reward_silver, reward_exp, reward_score,reward_pot;
	int team_bonus, silver;
	int accomp_exp, accomp_pot, accomp_silver;
	
	string reward_msg;
	object ob;
	object* mem;
	
		
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

	//Max_exp player left team
	if (700*q_bonus > max_exp){
		q_bonus = max_exp/1024 ;
	}
	
	//Calculate base bonus
	
	// For less than 10K players, the base bonus is 20+ exp/3
	if(q_bonus < 10) {
		base= 20 + q_bonus/3;
	} else if (q_bonus < 800){
    // For players exp from 10k to 800k, the bonus is a curve
    // the reward grows almost linear at low end, but slower when 
    // close to 800k
		base= 30 + (q_bonus *2)/9- (q_bonus*q_bonus)/7000;
	// When exp is >800k, the reward is linear again but at much 
	// lower rate
	} else if (q_bonus < 2200) base= 50 + q_bonus/12;
	// <- < 2.2M reach reward max 
	else  base= 40 + q_bonus/24 + random(q_bonus/24);

        // Further lower high exp quest bonus, and cap base at 260
	if(base > 160) {
		base = 260 - 3*16000/(base*2);	
	}
	
	//Check difficulty
	if(quest["difficulty"]) {
		d_reward = base * (quest["difficulty"]-5)/10;
		if (accomplisher->query("combat_exp")>5500000)
			d_reward=d_reward/2;
	}
	
	used_time = (int) time() - who->query("task_time");
	if(used_time < 60) {  //Get 50% bonus for finishing within 1 minutes
		t_reward = base / 2;
	} else if (used_time < 360) {  //Get a little bonus for finishing within 6 minutes
		t_reward = base * (360 - used_time) /600;
	}
	
	t_reward = base/10;	// Add 10% bonus;
		
	combat_exp = base + d_reward + t_reward;
	combat_exp = combat_exp + random(combat_exp);

	//Add some bonus for team to share 
	
//	tell_object(who,"q_bonus is"+(string)(q_bonus)+".\n");
//	tell_object(who,"exp reward is"+(string)(combat_exp)+".\n");
	
	if (q_bonus<1024) {
		team_bonus = combat_exp;
		team_bonus = team_bonus < (team_size -1)* combat_exp/5 ? team_bonus : (team_size -1)* combat_exp/5 ;
		combat_exp += team_bonus;	
	} else {
		team_bonus =  combat_exp*2/5 ;
		team_bonus = team_bonus < (team_size -1)* combat_exp/12 ? team_bonus : (team_size -1)* combat_exp/12 ;
		combat_exp += team_bonus;	
	}
	
//	tell_object(who,"team_bonus is"+(string)(team_bonus)+".\n");
//	tell_object(who,"total exp reward"+(string)(combat_exp)+".\n");
	
	if(q_bonus < 200) 
	pot = combat_exp / 7 + 1;
	else
	pot = combat_exp / 6 + 1;
	
	silver = 20 + random(40);
	
	// add some more money for 1M+ players
	if (q_bonus>1000) silver = silver*3/2;
	
	accomp_exp = combat_exp;
	accomp_pot = pot;
	accomp_silver = silver;
	
	if (sum_exp == 0) sum_exp = 1;
	for(i=0; i<sizeof(mem); i++) {
		if (mem[i])
		if (mem[i]!=accomplisher) {
			
			ratio = (100* mem[i]->query("combat_exp"))/sum_exp;
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
			 						
			if (mem[i]->query("combat_exp")>7000000) {
					reward_exp=50;i_pot=i_pot/2;
					} 
				else if (mem[i]->query("combat_exp")>6500000) {reward_exp=100;i_pot=i_pot*2/3;}
				else if (mem[i]->query("combat_exp")>6000000) {reward_exp=reward_exp/4;i_pot=i_pot*2/3;}
				else if (mem[i]->query("combat_exp")>5500000) {reward_exp=reward_exp/3;i_pot=i_pot*2/3;}
				else if (mem[i]->query("combat_exp")>5000000) {reward_exp=reward_exp/2;i_pot=i_pot*2/3;}
				else if (mem[i]->query("combat_exp")>4000000) {reward_exp=reward_exp*3/5;i_pot=i_pot*3/5;}
				else if (mem[i]->query("combat_exp")>2000000) {reward_exp=reward_exp*3/4;i_pot=i_pot*3/4;}
			mem[i]->add("combat_exp", reward_exp);
			mem[i]->add("potential", i_pot);
			mem[i]->add("score", (score*ratio) / 100);	
			
//			log_quest(mem[i], who, quest, reward_exp, i_pot, used_time, base);
						 
			score =  mem[i]== accomplisher? 1 : 0;
			reward_msg = mem[i]==who ? HIW : HIW+"队伍成员 "+who->name()+" 的";
			reward_msg +="任务被"+accomplisher->name()+"完成，你被奖励了：\n\t\t" +
				chinese_number(reward_exp) + "点实战经验\n\t\t"+
				chinese_number(i_pot) + "点潜能\n\t\t" +
				chinese_number(score) + "点评价\n\t\t" + 
				chinese_number(reward_silver) + "两银子\n" + NOR;
			
			tell_object(mem[i],reward_msg);
		}
	}
	
	score = 1;
	if (accomplisher->query("combat_exp")>7000000) {
		accomp_exp=50;accomp_pot=accomp_pot/2;
		}
		else if (accomplisher->query("combat_exp")>6500000) {accomp_exp=100; accomp_pot=accomp_pot*2/3;}
		else if (accomplisher->query("combat_exp")>6000000) {accomp_exp=accomp_exp/4;accomp_pot=accomp_pot*2/3;}
		else if (accomplisher->query("combat_exp")>5500000) {accomp_exp=accomp_exp/3;accomp_pot=accomp_pot*2/3;}
		else if (accomplisher->query("combat_exp")>5000000) {accomp_exp=accomp_exp/2;accomp_pot=accomp_pot*2/3;}
		else if (accomplisher->query("combat_exp")>4000000) {accomp_exp=accomp_exp*3/5;accomp_pot=accomp_pot*3/5;}
		else if (accomplisher->query("combat_exp")>2000000) {accomp_exp=accomp_exp*3/4;accomp_pot=accomp_pot*3/4;}		
	accomplisher ->add("score", 1);
	accomplisher->add("combat_exp", accomp_exp);
	accomplisher->add("potential", accomp_pot);
	
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
	chinese_number(accomp_exp) + "点实战经验\n\t\t"+
	chinese_number(accomp_pot) + "点潜能\n\t\t" +
	chinese_number(1) + "点评价\n\t\t" + 
	chinese_number(accomp_silver) + "两银子\n" + NOR;
	
//	tell_object(accomplisher,reward_msg);
	
	who->set("quest", 0 );
	who->add("MY_QUEST",1);
}
