/* rewardd.c	该daemon守护所有游戏中谜题或物品类的奖励。
	--- by Silencer@fy4

（1）风云奖励规则：

	经验：	Quest、杀死天骄
	潜能：  升级，部分Task
	金钱：  Task、Quest、杀死天骄、以及杀人放火所得（极少，减少robot）
	评价：  Task、天骄、谜题  （评价作用：叛师、拜free_master、房子等）
	秘籍/Mark/技能等：  谜题

（2）score奖励规则
	10	到达某一个新的地区：比如说到了帝王谷的那个黑洞
	30	解了一个简单的（或者老风云的）谜题（鱼汤、铜人什么的）
	50	一般的谜题
	100	较复杂的谜题或者有名的谜题（古月牌）
	200 	大谜题，如宿命类或者涉及数个区域的，

	杀死天骄的score：= difficulty (1-50)
	Task的	score = 1

*/

#include <ansi.h>
inherit F_LEVEL;

void create() {
    seteuid(ROOT_UID);
}

/*	每个等级得到的单个Quest经验值奖励最大值

	经验等级对照表
	2k - 100k		L0--L10			Delta_L= 10k
	100k-1.1M		L10-L30			Delta_L= 50k
	1.1M- 3.1M		L30-L70			Delta_L = 50k
	3.1- 11.1M		L70-L150		Delta_L = 100k
	11.1-21.1M and above	L150-L200		Delta_L = 200k
*/

int quest_reward(int level){

    int num, reward;

	// 狂照顾新手！！！！
    if (level < 10)
    switch (level) {
    	case 0:	
    	case 1:		
    	case 2:		
    	case 3:		
    	case 4:		
    	case 5:
    	case 6:		num = 20;	break;
    	case 7:		
    	case 8:
    	case 9:		num = 30;	break;
	}													// 共计 20*3+30*3+40*3 = 270 个
    	
//	暂定的奖励公式，看看Quest狂人要多久（5month?）能满，如果太快，中途再加以调节    	
    if (level>=10)	
    switch (level/10){
	    case 1:	
	    case 2:	
	    case 3:		
	    case 4:	num= 60;	break;						// 1000*4 ->  750*4
	    case 5:
	    case 6:
	    case 7:	
	    case 8:
	    case 9:	
	    case 10:num= 150;	break;						// 2000*6 --> 1000*6
	    case 11: 
	    case 12:
	    case 13:num= 200;	break;						// 3000*4 --> 2000*4
	    default:num= 500; 	
    }													

    if (level<10)		reward = 10000/num;		//经验段除以数目＝单个奖励值
    else if (level<70)	reward = 50000/num;
    else if (level<140)	reward = 100000/num;
    else 			reward = 1;					// COMBAT_EXP should always < L140

    return reward;

}

//	杀死天骄的奖励, difficulty = 1-50;
void 	tianjiao(object player, int difficulty){

    object money_reward;

    player->add("score",1);
    player->add("marks/tianjiao_num",1);		//--- 纪录playser杀死天骄的数目。

    tell_object(player,HIW"\n你成功地杀死了一个风云天骄，你被奖励了：一点评价和"
    + chinese_number(difficulty)+"两黄金。\n\n"NOR);

    if(player->query("env/savemymoney"))
	player->add("deposit",difficulty*10000);
    else
    {
		money_reward = new("/obj/money/gold");
		money_reward->set_amount(difficulty);
		if (!money_reward ->move(player))	{
	    	tell_object(player, HIR"由于你身上的东西带的太多，奖励被没收了。。。\n"NOR);
	    	destruct (money_reward);
	    }
		tell_object(player,WHT"（用 Set savemymoney 1 可将奖励自动存入银行）\n"NOR);
    }

    return;

}


//	每个TasK或TaskNPC的奖励, default amount= 50 silver
int 	task_reward(object player, int amount){

//  object money_reward;
    int task_level, task_num;
    object book;
    	
    player->add("score",1);
		player->add("deposit",amount * 100);
		player->add("TASK",1);   	
		
    tell_object(player,HIW"你完成了一个TASK，你得到一点评价、存款增加"
			+ chinese_number(amount)+ "两白银！\n"NOR);

		// TASK 对每个等级中潜能点的奖励
		task_level = F_LEVEL->get_level(player->query("combat_exp"));
		task_num = F_LEVEL->level_to_pot(task_level)/10/50;		// 1/10 leveling up reward    
    if (player->query("rewarded_task")< task_num) {
    	player->add("rewarded_task",1);
    	player->add("task_pot", 50);
    	player->add("potential",50);
    	tell_object(player,HIW"你的潜能点增加了50！\n"NOR);	
    } 
    else
    {
		  player->add("saved_quest",60/3);	// 6000= 1 ability, 60/3--> 300 tasks 1 ability    	
    	player->add("ability_task",1);
    	tell_object(player,HIW"你的能力点积累（Ability）提高了0.3！\n"NOR);
    }		
    
    if (!random(12)){
    	book=new("/obj/item/treasurebook");
		if (!book->move(player))
			book->move(environment(player));
    	tell_object(player,HIR"意外地，你得到了一页《怜花宝鉴》\n"NOR);
    }
    	
    return 1;
}


int check_m_success(object who, string riddle)
{
    return who->query("m_success/"+ riddle);
}

//	Riddle and score reward
varargs int riddle_reward(object who, string rname, int score,int g){

	if (!userp(who))	return 0;	 
    if (check_m_success(who,rname))		return 0;


    if (!g) g = 1;
    who->set("m_success/"+ rname, g);
    if (score)	
    {
	who->add("score",score);
	log_file("riddle/REWARD_LOG",
	  sprintf("%s(%s) 完成了 %s，奖励评价：%d \n",
	    who->name(1), geteuid(who), rname, score));
    }

    tell_object(who,HIY"\n\n恭喜你解开了〖"HIC+rname+HIY"〗"NOR);
    if (!score)
	tell_object(who,HIY"！\n\n"NOR);
    else
	tell_object(who,HIY"，得到"+score+"点评价！\n\n"NOR);

    log_file("riddle/RIDDLE_LOG", 
      sprintf("%s(%s) 完成了 %s，时间：%s \n",
	who->name(1), geteuid(who), rname, ctime(time())));
    return 1;
}

varargs int riddle_set(object who, string rname, int phase)
{
    if (!phase)
	phase = -1;
    who->set("riddle/"+rname,phase);
    if (phase == 1)
    	tell_object(who,WHT"恭喜：你开始了一个新谜题："+ rname + "\n"NOR);
    if (who->query("combat_exp")== 2000)	// likely newbie quest
    	tell_object(who,WHT"（你可以随时使用命令riddle来查看你的解谜进程。）\n\n"NOR);
    return 1;
}

varargs int riddle_clear(object who, string rname)
{
    // No, we dont want to clear m_success mark.
    who->set("riddle/"+rname,0);
    return 1;
}

varargs int riddle_check(object who, string rname)
{
    return who->query("riddle/"+rname);
}

varargs int riddle_done(object who, string rname, int score,int g)
{
    //	g=who->query("riddle/"+rname);
    if (!userp(who))	return 0;
    who->delete("riddle/"+rname);
    riddle_reward(who,rname,score,g);
    return 1;
}


//	Item reward
int give_item(object me, string riddle, string item_file){
    object item;

    item = new(item_file);

    if (!objectp(item)){
	tell_object(me, HIR"OOPS, 请报告巫师，这儿有ＢＵＧ。\n"NOR);
	log_file("riddle/REWARD_LOG",
	  sprintf("%s(%s) 完成了 %s，但是没有发现奖励物件：%s \n",
	    me->name(1), geteuid(me), riddle, item_file));
	return 1;
    }

    if (item->move(me)){
	tell_object(me,WHT"你得到了"+ item->name() + "。\n"NOR);
	log_file("riddle/REWARD_LOG",
	  sprintf("%s(%s) 完成了 %s，奖励物件：%s %s \n",
	    me->name(1), geteuid(me), riddle, item->name(), item_file));
    } else {
	destruct(item);
	log_file("riddle/REWARD_LOG",
	  sprintf("%s(%s) 完成了 %s，但是无法奖励物件：%s %s \n",
	    me->name(1), geteuid(me), riddle, item->name(), item_file));
	tell_object(me, YEL" OOPS, 你错过了一个物品奖励。。。\n"NOR);
    }
    return 1;										
}

/*	IMBUE event daemon, triggered by NPC
	保留那些滴滴答答的msg,无论落在哪里，imbue都在player身上发生。
	imbue {[
		"name": "魔眼剑",
		"target": me,
		"att_1": "str", "con" etc
		"att_1c": 
		"att_2": 
		"att_2c":
		"att_3": ------------> 这个会使reward参数随机产生
		"att_3c":
		"mark":	有时候可能有不同结局
	]));	

*/

int	imbue_check(object who, string name)
{
    return who->query("imbue/"+ name);
}

int 	imbue_att(mapping imbue)
{
    object who;
    int n;
    string *att = ({ "str", "cps", "agi", "con", "int", "kar" });
    string *att_c = ({"力量","定力","速度","体质", "才智", "运气" });

    who = imbue["target"];

    // A little check here
    if ( imbue_check(who,imbue["name"]))	return 0;

    if (stringp(imbue["att_1"]))	
    {
	n = member_array(imbue["att_1"], att);
	if (n == -1)	
	{
	    tell_object(who," Riddle is bugged, please notify Wizard.\n");
	    return 1;
	} 		
	tell_object( who, HIR"你的"+ att_c[n] + "增加了"+ chinese_number(imbue["att_1c"])+"点。\n"NOR);

	who->add(imbue["att_1"],imbue["att_1c"]);
	who->add("imbue/"+ imbue["att_1"], imbue["att_1c"]);	
	log_file("riddle/IMBUE_LOG",
	  sprintf("%s(%s) 解开 %s imbue 结局 %d，得到属性 %s(+%d)，%s \n",
	    who->name(1), geteuid(who), imbue["name"], imbue["mark"], 
	    imbue["att_1"], imbue["att_1c"], ctime(time()) ));
    }

    if (stringp(imbue["att_2"]))	
    {
	n = member_array(imbue["att_2"], att);
	if (n == -1)	
	{
	    tell_object(who," Riddle is bugged, please notify Wizard.\n");
	    return 1;
	}
	tell_object( who, HIR"\n你的"+ att_c[n] + "增加了"+ chinese_number(imbue["att_2c"])+"点。\n\n"NOR);
	who->add(imbue["att_2"],imbue["att_2c"]);
	who->add("imbue/"+ imbue["att_2"], imbue["att_2c"]);	
	log_file("riddle/IMBUE_LOG",
	  sprintf("%s(%s) 解开 %s imbue 结局 %d，得到属性 %s(+%d)，%s \n",
	    who->name(1), geteuid(who), imbue["name"], imbue["mark"], 
	    imbue["att_2"], imbue["att_2c"], ctime(time()) ));
    }

    // OK, 第三项是个随机参数...需要批准后才能使用:)
    if (stringp(imbue["att_3"]))	
    {
	n = random(6);
	tell_object( who, HIR"你的"+ att_c[n] + "增加了"+ chinese_number(imbue["att_3c"])+"点。\n\n"NOR);
	who->add(att[n],imbue["att_3c"]);
	who->add("imbue/"+ att[n], imbue["att_3c"]);	
	log_file("riddle/IMBUE_LOG",
	  sprintf("%s(%s) 解开 %s imbue 结局 %d，得到随机属性 %s(+%d)，%s \n",
	    who->name(1), geteuid(who), imbue["name"], imbue["mark"], 
	    att[n], imbue["att_3c"], ctime(time()) ));
    }

    who->set("imbue/"+ imbue["name"], imbue["mark"]);
    who->save();

    return 1;

}