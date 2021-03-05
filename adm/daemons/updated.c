// updated.c
#include <ansi.h>

#define f_price "/obj/prize/f_p.c"
#define s_price "/obj/prize/s_p.c"
#define t_price "/obj/prize/t_p.c"
void checkrace(object ob);
void loadall(object me);
void create() { seteuid(getuid()); }
void check_user(object ob)
{
	mapping my,tf_s;
	string user_name;
	int /*tmp,dorm_force,*/ thief,pot, level;
	object food, drink, drug;
	int t3,task_level, task_num, i;
	string *tf_skills;
	
//	checkrace(ob);
	if( !ob->query_temp("already_loaded"))	
		loadall(ob);

//	在每次login时我们重新检查设定PK限制，以当前list为准。	
	user_name = ob->query("id");
	if (PK_D->check_list(user_name,"PK_LIST") || PK_D->check_list(user_name,"HUNTER_LIST"))
		ob->set("NO_PK",0);
	else
		ob->set("NO_PK",1);			
	
	if(!wizardp(ob))
	{
		ob->delete("env/invisibility");
		ob->delete("env/immortal");
	}

	if (ob->query("old_force_factor"))
	{
		ob->set("force_factor",ob->query("old_force_factor"));
		ob->set("old_force_factor",0);
	}
	
	my = ob->query_entire_dbase();
	if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
	if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
	if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"];
	if( my["eff_gin"] > my["max_gin"] ) my["eff_gin"] = my["max_gin"];
	if( my["eff_kee"] > my["max_kee"] ) my["eff_kee"] = my["max_kee"];
	if( my["eff_sen"] > my["max_sen"] ) my["eff_sen"] = my["max_sen"];
	if( my["gin"] > my["eff_gin"] ) my["gin"] = my["eff_gin"];
	if( my["kee"] > my["eff_kee"] ) my["kee"] = my["eff_kee"];
	if( my["sen"] > my["eff_sen"] ) my["sen"] = my["eff_sen"];
	my["gift_points"] = 10;
	
//	gift time

	if (!ob->query_temp("first_time_login") && ob->query("level")<10
		&& !ob->query_temp("reconnected"))
	{
		food = new("/obj/food_item/newbie_food");
		drink = new("/obj/food_item/newbie_drink");
		drug = new("/obj/medicine/newbie_drug"); 
		if (food)	food->move(ob);
		if (drink)	drink->move(ob);
		if (drug)	drug->move(ob);
	}

//	FY NEWS
	"/cmds/usr/fynews"->list_news(ob, 1);
	
	ob->delete("NO_KILL");		// a dreamland residue bug. fixed now but some ppl got this mark

//	1)
	if ( (thief=ob->query("thief"))) {
		ob->add("score", thief);
		tell_object(ob,WHT"系统对偷窃命令改动，你的评价恢复了"+ thief +"点。\n"NOR);
		log_file("LOGIN_UPDATE_LOG", 
					sprintf("(%s)%s 从steal的改动中恢复%d评价。\n",
   					ctime(time()), 
   					ob->name(1)+"("+ ob->query("id")+")", 
					thief
				));	
		ob->delete("thief");
	}
//	2)	
	if ( ob->query("combat_exp")>= 100000 && !REWARD_D->check_m_success(ob,"新手入门"))
	{
		REWARD_D->riddle_done(ob,"新手入门",200,1);
		tell_object(ob,WHT"恭喜，你的实际行动证明了你有能力完成这个谜题。\n"NOR);
	}
				
// 	3)
	if (!ob->query("update/11_revive"))	{
		t3 =  ob->query("annie/revive_others_heart_1")*4 + ob->query("annie/revive_others_heart_2")*32 
			+ ob->query("annie/revive_others_yegui")*5;
		if (t3 > 0) {
			ob->delete("annie/revive_others_heart_1");
			ob->delete("annie/revive_others_heart_2");
			ob->delete("annie/revive_others_yegui");
			ob->add("score",t3);
			tell_object(ob,WHT"系统对死亡系统变动，你以往恢复他人所耗费的评价恢复了"+ t3 + "点。\n"NOR);
			ob->set("update/11_revive",1);
			log_file("LOGIN_UPDATE_LOG", 
					sprintf("(%s)%s 从死亡损失的改动中恢复%d评价。\n",
   					ctime(time()), 
   					ob->name(1)+"("+ ob->query("id")+")", 
					t3,
				));
		}
	}	
			
// 4) 
	if (REWARD_D->check_m_success(ob,"华山救美") == 2) {
		ob->delete("m_success/华山救美");
		ob->add("score",100);
		tell_object(ob,WHT"系统改进华山救美谜题，你的评价恢复了100点，可重新再做。\n"NOR);
		log_file("LOGIN_UPDATE_LOG", 
					sprintf("(%s)%s 从steal的改动中恢复%d评价。\n",
   					ctime(time()), 
   					ob->name(1)+"("+ ob->query("id")+")", 
					thief
				));
	}

//	5）
	if (!ob->query("update/11_tianfeng_1") && REWARD_D->check_m_success(ob,"浪人的悲哀")) {
		if (mapp(ob->query("tianfeng"))) {
		if (sizeof(tf_s = ob->query("tianfeng"))>1 ) {
			tf_skills = keys(tf_s);
			for (i=0;i<sizeof(tf_skills);i++) {			
				level = ob->query_skill(tf_skills[i],1);
				if (level >=1) {
					pot = ob->query("annie/skill_cost/"+tf_skills[i]);
					ob->delete_skill(tf_skills[i]);
					ob->add("learned_points", -pot); 
					ob->set("annie/skill_cost/"+tf_skills[i],0);
					tell_object(ob,WHT"系统调整天枫十四郎谜题，你"+tf_skills[i]+"等级（"+level+"->0）和潜能（+"+pot+"）被重新调节。\n"NOR);
					log_file("LOGIN_UPDATE_LOG", 
							sprintf("(%s)%s 从%s的改动中技能从%d调整到0，潜能恢复%d。\n",
		   					ctime(time()), 
		   					ob->name(1)+"("+ ob->query("id")+")", 
							tf_skills[i],
							level,
							pot,
						));
				}	
			}	
		}
		ob->delete("tianfeng");	// This mark is no longer used		
		}
	}			
	ob->set("update/11_tianfeng_1",1);

//	version 1.1
	if (!ob->query("update/11_music") && ob->query("free_learn/music")){
		ob->delete("annie/music_choose");
		tell_object(ob,WHT"系统调节琴道，你可以重新在琴心处选择了。\n");
		log_file("LOGIN_UPDATE_LOG", 
					sprintf("(%s)%s 从music的改动中除去annie/music_choose mark。\n",
   					ctime(time()), 
   					ob->name(1)+"("+ ob->query("id")+")", 
				));
	}
	ob->set("update/11_music",1);
			
	if (!ob->query("update/11_lingxi-zhi") && ob->query_skill("lingxi-zhi",1)>0 ) {
		level = ob->query_skill("lingxi-zhi",1);
		pot = ob->query("annie/skill_cost/lingxi-zhi");
		ob->add("learned_points",-pot);
		ob->delete_skill("lingxi-zhi");
		ob->set("annie/skill_cost/lingxi-zhi",0);
		tell_object(ob,WHT"系统调整灵犀指难度，你的技能等级（"+level+"->0）和潜能（+"+pot+"）被重新调节。\n"NOR);
		log_file("LOGIN_UPDATE_LOG", 
					sprintf("(%s)%s 从lingxi-zhi的改动中技能从%d调整到0，潜能恢复%d。\n",
   					ctime(time()), 
   					ob->name(1)+"("+ ob->query("id")+")", 
					level,
					pot,
				));
	}
	ob->set("update/11_lingxi-zhi",1);
	
	if (!ob->query("update/11_bai-quan") && ob->query_skill("bai-quan",1)>0 ) {
		level = ob->query_skill("bai-quan",1);
		pot = ob->query("annie/skill_cost/bai-quan");
		ob->add("learned_points",-pot);
		ob->delete_skill("bai-quan");
		ob->set("annie/skill_cost/lingxi-zhi",0);
		tell_object(ob,WHT"系统调整白家拳，你的技能等级（"+level+"->0）和潜能（+"+pot+"）被重新调节。\n"NOR);
		log_file("LOGIN_UPDATE_LOG", 
					sprintf("(%s)%s 从bai-quan的改动中技能从%d调整到0，潜能恢复%d。\n",
   					ctime(time()), 
   					ob->name(1)+"("+ ob->query("id")+")", 
					level,
					pot,
				));
	}
	ob->set("update/11_bai-quan",1);
	
	if ( ob->query_skill("starrain",1)>51 && !ob->query("update/11_starrain")) {
		level = ob->query_skill("starrain",1);
		pot = ob->query("annie/skill_cost/starrain");
		ob->set_skill("starrain",51);
		ob->add("learned_points", -pot); 
		ob->set("annie/skill_cost/starrain",0);
		tell_object(ob,WHT"系统调整寒星雨觞难度，你的相关技能等级（"+level+"->50）和潜能（+"+pot+"）被重新调节。\n"NOR);
		log_file("LOGIN_UPDATE_LOG", 
					sprintf("(%s)%s 从starrain的改动中技能从%d调整到51，潜能恢复%d。\n",
   					ctime(time()), 
   					ob->name(1)+"("+ ob->query("id")+")", 
					level,
					pot,
				));
	}
	ob->set("update/11_starrain",1);
	
	if (ob->query_skill("wuche-axe",1)>150 && !ob->query("update/11_wuche-axe")){
		level = ob->query_skill("wuche-axe",1);
		pot = ob->query("annie/skill_cost/wuche-axe")-99;
		ob->set_skill("wuche-axe",100);
		ob->add("learned_points", -pot);
		ob->set("annie/skill_cost/wuche-axe",99);
		tell_object(ob,WHT"系统调整少林悟彻斧难度，你的相关技能等级（"+level+"->100）和潜能（+"+pot+"）被重新调节。\n"NOR);
		log_file("LOGIN_UPDATE_LOG", 
					sprintf("(%s)%s 从wuche-axe的改动中技能从%d调整到99，潜能恢复%d。\n",
   					ctime(time()), 
   					ob->name(1)+"("+ ob->query("id")+")", 
					level,
					pot,
				));
	}
	ob->set("update/11_wuche-axe",1);		

	if (ob->query_skill("liuxing-hammer",1)>150 && !ob->query("update/11_liuxing-hammer")){
		level = ob->query_skill("liuxing-hammer",1);
		pot = ob->query("annie/skill_cost/liuxing-hammer")-99;
		ob->set_skill("liuxing-hammer",100);
		ob->add("learned_points", -pot);
		ob->set("annie/skill_cost/liuxing-hammer",99);
		tell_object(ob,WHT"系统调整少林流星锤难度，你的相关技能等级（"+level+"->100）和潜能（+"+pot+"）被重新调节。\n"NOR);
		log_file("LOGIN_UPDATE_LOG", 
					sprintf("(%s)%s 从liuxing-hammer的改动中技能从%d调整到99，潜能恢复%d。\n",
   					ctime(time()), 
   					ob->name(1)+"("+ ob->query("id")+")", 
					level,
					pot,
				));
	}
	ob->set("update/11_liuxing-hammer",1);		

	if (ob->query_skill("duanhun-spear",1)>150 && !ob->query("update/11_duanhun-spear")){
		level = ob->query_skill("duanhun-spear",1);
		pot = ob->query("annie/skill_cost/duanhun-spear")-99;
		ob->set_skill("duanhun-spear",100);
		ob->add("learned_points", -pot);
		ob->set("annie/skill_cost/duanhun-spear",99);
		tell_object(ob,WHT"系统调整少林断魂枪难度，你的相关技能等级（"+level+"->100）和潜能（+"+pot+"）被重新调节。\n"NOR);
		log_file("LOGIN_UPDATE_LOG", 
					sprintf("(%s)%s 从duanhun-spear的改动中技能从%d调整到99，潜能恢复%d。\n",
   					ctime(time()), 
   					ob->name(1)+"("+ ob->query("id")+")", 
					level,
					pot,
				));
	}
	ob->set("update/11_duanhun-spear",1);		
	
	if (ob->query_skill("fumostaff",1)>150 && !ob->query("update/11_fumostaff")){
		level = ob->query_skill("fumostaff",1);
		pot = ob->query("annie/skill_cost/fumostaff")-99;
		ob->set_skill("fumostaff",100);
		ob->add("learned_points", -pot);
		ob->set("annie/skill_cost/fumostaff",99);
		tell_object(ob,WHT"系统调整少林伏魔杖难度，你的相关技能等级（"+level+"->100）和潜能（+"+pot+"）被重新调节。\n"NOR);
		log_file("LOGIN_UPDATE_LOG", 
					sprintf("(%s)%s 从fumostaff的改动中技能从%d调整到99，潜能恢复%d。\n",
   					ctime(time()), 
   					ob->name(1)+"("+ ob->query("id")+")", 
					level,
					pot,
				));
	}
	ob->set("update/11_fumostaff",1);		
	
	if ((level=ob->query("scroll/dragonstrike_baili"))){
		if (level >= ob->query("scroll/begging_baili"))
			ob->set("scroll/begging_baili",level);
		ob->delete("scroll/dragonstrike_baili");
		log_file("LOGIN_UPDATE_LOG", 
					sprintf("(%s)%s 从震惊百里卷轴mark的记号中有所改动（%d）\n",
   					ctime(time()), 
   					ob->name(1)+"("+ ob->query("id")+")", 
					level,
				));
	}
	
	if (!ob->query("update/11_task_ability")) {
		level = ob->query("TASK");
		task_level = F_LEVEL->get_level(ob->query("combat_exp"));
		task_num = F_LEVEL->level_to_pot(task_level)/10/50;
		if (level > task_num + ob->query("ability_task")) {
			ob->add("saved_quest",60/3 * (level - task_num-ob->query("ability_task")));
			tell_object(ob,WHT"系统调节TASK奖励方式，你至今共完成"+level+"个TASK，其中"+ task_num+"个为增加潜能，
"+ ob->query("ability_task")+"个已经用于提高ABILITY，剩余"+ (level-task_num-ob->query("ability_task"))+"个补偿为"+
(level-task_num-ob->query("ability_task"))/3+"个能力Quest。\n"NOR);
			log_file("LOGIN_UPDATE_LOG", 
					sprintf("(%s)%s 从TASK的变化中：Task(%d),Task_num(%d),Ability_task(%d),补偿%d。\n",
   					ctime(time()), 
   					ob->name(1)+"("+ ob->query("id")+")", 
					level,
					task_num,
					ob->query("ability_task"),
					(level-task_num-ob->query("ability_task")),
				));
			ob->set("ability_task", level - task_num);
		}	
	}
	ob->set("update/11_task_ability",1);
	
	if (!ob->query("update/11_ability")){
		level = ob->query("learned_ability");
		// kee/sen/gin are already added before updated.
		ob->add("max_kee",-ob->query("ability/kee"));
		ob->add("max_sen",-ob->query("ability/sen"));
		ob->add("max_gin",-ob->query("ability/gin"));
		ob->add("str",-ob->query("ability/strength"));
		ob->add("int",-ob->query("ability/intelligence"));
		ob->add("agi",-ob->query("ability/agility"));
		ob->add("cps",-ob->query("ability/composure"));
		ob->add("kar",-ob->query("ability/karma"));
		ob->add("con",-ob->query("ability/constitution"));
		ob->delete("ability");
		ob->delete("ability2");
		ob->delete("learned_ability");
		// mana/force/atman have marks to delete
		ob->add("max_mana",-ob->query("Add_mana/ability"));
		ob->delete("Add_mana/ability");
		ob->add("max_force",-ob->query("Add_force/ability"));
		ob->delete("Add_force/ability");
		ob->add("max_atman",-ob->query("Add_atman/ability"));
		ob->delete("Add_atman/ability");
		tell_object(ob,WHT"系统调整ABILITY，你的"+level+"个ABILITY可重新分布。
请重新登陆或吐纳（tuna）一次以得到正确的精气神计算。\n"NOR);
		log_file("LOGIN_UPDATE_LOG", 
					sprintf("(%s)%s 从ABILITY改动中恢复%d可重新分布。\n",
   					ctime(time()), 
   					ob->name(1)+"("+ ob->query("id")+")", 
					level,
				));
	}
	ob->set("update/11_ability",1);
	
	ob->status_msg("all");
    ob->force_status_msg("all");
        
// donation time!!
/*	if( my["deposit"]/10000000 > (my["age"]-10))
	{
		write("钱庄被山西抢匪掠洗一空！你损失了"
		+ chinese_number(my["deposit"]-(my["age"]-10)*10000000) +"文钱．\n");
		my["deposit"] -= (my["deposit"]-(my["age"]-10)*10000000);
	}*/
}



void checkrace(object ob)
{
	object reward;
	int title_race;
	title_race = (int) ob->query("title_race");
	if (title_race == 1)
	{
		reward = new(f_price);
		reward->move(ob);
		ob->set("title_race", -1);
	}
        if (title_race == 2)
        {
                reward = new(s_price);
                reward->move(ob);
                ob->set("title_race", -2);
        }
        if (title_race == 3)
        {
                reward = new(t_price);
                reward->move(ob);
                ob->set("title_race", -3);
        }
	return;
}

void loadall(object me)
{
	int MAX = 3;
	string name,id, *created;
	int j;
	object thing;
	id = me->query("id");
	created = get_dir(DATA_DIR + "login/" + id[0..0] + "/" + id + "/");
	write("\n\n");
	for(j=0; (j<sizeof(created) && j < (MAX+1) ); j++)
	if( sscanf(created[j], "%s.c", name) == 1 )
		{
			thing = new( DATA_DIR + "login/" + id[0..0] + "/" + id + "/" + name + ".c");
			write( thing->name() + "\n");
                        thing->restore();
			if(thing->move(me))  write("ＯＫ．\n\n");
		}
	me->set_temp("already_loaded",1);
}