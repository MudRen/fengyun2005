//	by FY2005 Silencer
//	本代码的目的是自动设置NPC技能及打斗方式。

#include <ansi.h>
#include <command.h>
#include <condition.h>
#include <combat.h>

inherit NPC;

void 	alchemy_fight(object me, object target, string weapon_name);
void 	do_defense(object me, int n);
void 	do_remove_defense(object me, int n);
void 	find_officer(object me);
void 	help_friend(object me);
void 	multi_busy(object me, object *enemy);
void 	sheet_fight(object me);
void 	single_busy(object me, object target);
void 	universal_attack(object me, object target);
void 	universal_pfm(string perform_weapon_attack, object me, object target);

int get_max_busy(object *enemy);

string  do_choose_attack1(object me, object target);
string  do_choose_attack2(object me, object target);
string  do_choose_attack3(object me, object target);
string  do_choose_attack4(object me, object target);
string  do_choose_attack5(object me, object target);
string  super_message();
string  both_message();
string  weapon_unarmed(object me, string weapon_i,string unarmed_i);
string  my_worst_wound(object me);			// return  

object 	accompany(object me);
int 	check_health(object target, int percent);
int 	check_gks(object me, string type, int percent);
int 	check_weapon(object me, string weapon);
int 	enemy_type(object me, object target);
int 	enemy_value(object me, object *all_enm);
int 	find_weapon(object me, string type);
int 	is_he_pet(object target);
int 	pickup_weapon(object me, string weapon);
void		sq_guard(object me);

object 	*resort(object me, object *group);
object 	*resort_enemy(object me, string flag);

void auto_npc_setup(object me, string name, int basic, int special, int auto_weapon, string weapon_dir, string char_type, string my_char, int level);

/*	string name:	NPC id
	basic:		basic skill level			
	special:	special skill level
	auto_weapon:	1: auto find weapon, 0: will be set in NPC file
	weapon_dir:	auto_weapon directory
	char_type:	figher/caster/
	my_char:	exact name of the NPC, the name refers to the one in npclist
	level:		which npclist we should choose
*/


void create() {
    	seteuid(getuid());
    	set("name", "打斗精灵");
    	set("id", "smartd");
}

void auto_npc_setup(object me, string name, int basic, int special, int auto_weapon, string weapon_dir, string char_type, string my_char, int level) {
	
	// Basic skills
	string *basic_skill= ({"move","dodge","parry","unarmed","blade","sword",
	"staff","axe","spells","magic","spear","throwing","hammer","whip","fork","force",
	"perception","iron-cloth","cursism","scratching","dagger","herb"});

	// Performs
	string *pfm_setup = ({
		"perform_weapon_attack","perform_weapon_attack2","perform_weapon_attack3","perform_weapon_attack4",
		
		"perform_unarmed_attack4","perform_unarmed_attack5",
		"perform_unarmed_attack","perform_unarmed_attack2","perform_unarmed_attack3",
		
		"perform_busy_d", "perform_busy_d1",
		"perform_busy_u","perform_busy_u1","perform_busy_u2","perform_busy_u3",
		"perform_busy_w",
		
		"perform_busy_d_g",	"perform_busy_u_g","perform_unarmed_attack_g"
		});
	
	// Basic skill enable setup
	string *base_skill_setup = ({"skill_type_w","skill_type_u","skill_type_d",});
	
	// This is for those required "knowledge" skills
	string *other_skills = ({"others1","others2","others3","others4","others5","others6"});
	
	// This is for temp_mark setup, set_temp("set_temp1", "set_temp1c");
	string *temp_setup = ({"set_temp1","set_temp2","set_temp3","set_temp4"});	
	string *temp_setupc = ({ "set_temp1c", "set_temp2c", "set_temp3c","set_temp4c" });
	
	// This is for permanent mark setup
	string *mark_setup = ({"set_1","set_2","set_3","set_4"});	
	
    string *buff_setup = ({"perform_buff_1", "perform_buff_2", "perform_buff_3" });
    	
    	// These 4 groups are for random NPCs
    	string *g_unarmed_busy = ({
    		"legend/unarmed/meihua-shou/meihai", 
    		"shaolin/unarmed/dabei-strike/qianshouqianbian",
    		"huangshan/unarmed/yunwu-strike/miwu", 
    		"lama/unarmed/bloodystrike/fofawubian"});
    	string *g_dodge_busy = ({
    		"legend/dodge/fall-steps/luoyeqiufeng",
    		"npc/dodge/shenji-steps/shenjimiaosuan",
    		"shenshui/dodge/nine-moon-steps/lianhuanbu",
    		"fugui/dodge/hawk-steps/yingjichangkong",
    		 "huashan/dodge/cloud-dance/yexuechuji",
    		 "knight/dodge/windy-steps/fengliu",
    		 "knight/herb/dream-herb/kaixiehua",
    		});
    	string *g_weapon_attack = ({
    		"assassin/sword/lefthand-sword/duxin",
    		"shenshui/sword/nine-moon-sword/shuanglengcanxia",
    		"beggar/staff/dagou-stick/tianxiawugou", 
    		"bonze/staff/cloudstaff/longxianyuye",
    		"fighter/sword/doomsword/hunranyijian",
    		"huangshan/sword/siqi-sword/siqi",
    		"huangshan/blade/qiusheng-blade/jingsheng", 
    		"ninja/blade/ittouryu/hyakki", 
    		"shaolin/axe/wuche-axe/sanbanfu",
    		"shaolin/hammer/liuxing-hammer/fanbei",
    		"taoist/sword/snowshade-sword/baixueaiai",
    		"yinshi/whip/thunderwhip/tianleiyiji"
    		});
    	string *g_unarmed_attack = ({ 
    		"beggar/unarmed/dragonstrike/xianglongwuhui",
    		"knight/unarmed/hanshan-strike/zhangjian",
    		"ninja/unarmed/enmeiryu/mukuha",
    		"ninja/unarmed/enmeiryu/shiden", 
    		"yinshi/unarmed/pofeng-strike/luanpofeng",
    		"wolfmount/unarmed/wolf-strike/shigu"
    		});
    	
    	int i, total, x;
    	mapping npc;
    	string myclass,type,skill,pfm,weapon, general_pfm;
    	object weapon1;
    	
   	
   	if (level==1) {
		npc = NPC_BAS->query_npc(char_type,my_char,special);
		me->set("do_attack_type",1);
	}	
	else if (level==2) {
		npc = NPC_MID->query_npc(char_type,my_char,special);
		me->set("do_attack_type",2);
	}
	else if (level==4) {
		npc = NPC_041->query_npc(char_type,my_char,special);
		me->set("do_attack_type",4);
	}	
	else if (level==5) {
		npc = NPC_ANN->query_npc(char_type,my_char,special);
		me->set("do_attack_type",5);
	}  
	else {
		npc = NPC_ADV->query_npc(char_type,my_char,special);
		me->set("do_attack_type",3);
	}
	
	me->set("class",npc["class"]);	// NPC's basic class
	me->set("npc",npc["npc"]);		// NPC's basic identity
	me->set("myname",npc["name"]);	// NPC's basic name
//	me->set("nickname",npc["name"]);

//	setting up all skills		设置所有技能。
	i= sizeof(basic_skill);
	while (i--) {
		if (npc["npc"] == "smallguy" || basic_skill[i]=="parry")
			me->set_skill(basic_skill[i],basic);
		if (npc[basic_skill[i]]) {
			me->set_skill(basic_skill[i],basic);
			me->set_skill(npc[basic_skill[i]],special);
			me->map_skill(basic_skill[i],npc[basic_skill[i]]);
		}
	}
	me->set_skill("anxiang-steps", special);	// 所有的move都用anxiang-steps以简化，这个enable基本上不起作用
	me->map_skill("move","anxiang-steps");
	
	
	if (!me->query_skill_mapped("iron-cloth"))	// 对iron-cloth再做一些调整。
		me->delete_skill("iron-cloth");
	if (me->query_skill_mapped("iron-cloth")=="xisui")
		me->set_skill("xisui",me->query_skill("xisui",1)*2/3);
	
//	setting up the basic enable skill set that NPC uses after switching skills.基本的特殊技能设置。
	for (i=0;i<sizeof(base_skill_setup);i++){
		if (npc[base_skill_setup[i]])
			me->set(base_skill_setup[i],npc[base_skill_setup[i]]);
	}
	
//	setting up defense skill.. will only use one of them.
	switch (me->query("defense_type")) {
		case 1: me->set_skill("xiaohun-sword",special);
			  me->set_skill("sword",basic);
			  break;	
		case 2: me->set_skill("xiaohun-whip",special);
			  me->set_skill("whip",basic);
			  break;
		case 3: me->set_skill("yue-strike",special);
			  me->set_skill("unarmed",basic);
			  break;
		case 4: me->set_skill("lingxi-zhi",special);
			  me->set_skill("unarmed",basic);
			  break;
	}
	

//	setting up all pfm messages. also setting up secondary pfm skills if necessary
//	the next four setup is a further randomization of skills.
	
	i = sizeof(pfm_setup);
	while (i--) {
		if (npc[pfm_setup[i]]) 
		if (sscanf(npc[pfm_setup[i]],"%s/%s/%s/%s",myclass,type,skill,pfm)==4) {
			me->set_skill(skill,special);
			me->set(pfm_setup[i],npc[pfm_setup[i]]);
		}
	}

	if (npc["perform_busy_d"]=="random") {
			general_pfm =g_dodge_busy[random(sizeof(g_dodge_busy))];
			if (sscanf(general_pfm,"%s/%s/%s/%s",myclass,type,skill,pfm)==4) {
				me->set_skill(skill,special);
				me->set("perform_busy_d",general_pfm);
				me->set("skill_type_d",skill);
				me->map_skill("dodge",skill);
			}
	}
	if (npc["perform_busy_u"]=="random") {
			general_pfm =g_unarmed_busy[random(sizeof(g_unarmed_busy))];
			if (sscanf(general_pfm,"%s/%s/%s/%s",myclass,type,skill,pfm)==4) {
				me->set_skill(skill,special);
				me->set("perform_busy_u",general_pfm);
			}	
	}

	if (npc["perform_weapon_attack"]=="random") {
			general_pfm =g_weapon_attack[random(sizeof(g_weapon_attack))];
			if (sscanf(general_pfm,"%s/%s/%s/%s",myclass,type,skill,pfm)==4) {
				me->set_skill(skill,special);
				me->set("perform_weapon_attack",general_pfm);
				me->set("skill_type_w",type+"/"+skill);
				me->map_skill(type,skill);
				me->map_skill("parry",skill);
			}
	}
	if (npc["perform_unarmed_attack"]=="random") {
			general_pfm =g_unarmed_attack[random(sizeof(g_unarmed_attack))];
			if (sscanf(general_pfm,"%s/%s/%s/%s",myclass,type,skill,pfm)==4) {
				me->set_skill(skill,special);
				me->set("perform_unarmed_attack",general_pfm);
				me->set("skill_type_u",skill);
				me->map_skill("unarmed",skill);
			}
	}

//	setting up some suplementary skill such as chess,lamasism,...
	i= sizeof(other_skills);
	while (i--){
		if (npc[other_skills[i]])
			me->set_skill(npc[other_skills[i]],special);
	}

//	setting up buff perform
	i = sizeof(buff_setup);
	while (i--) {
		if (npc[buff_setup[i]])
			me->set(buff_setup[i],npc[buff_setup[i]]);
	}

//	the main weapon/unarmed/dodge skill level needs to be adjusted due to coff difference.
//	TO avoid pow(1/3) calculation, and to give the designer maximum flexibility,
//	we leave the skill_level choice to Designers. REMEMBER!! you are obliged to adjust it for NPCs you made.
//  Under investigation due to compatibility with Blanche's power(1/3) NPCs... Silencer
/*	if (npc["skill_type_w"] && npc["w_adjust"]) {
		sscanf(npc["skill_type_w"],"%s/%s",type,skill);
		me->set_skill(skill,(100+npc["w_adjust"])*me->query_skill(skill,1)/100);
	}
	if (npc["u_adjust"] && npc["skill_type_u"]) 
		me->set_skill(npc["skill_type_u"],(100+npc["u_adjust"])*me->query_skill(npc["skill_type_u"],1)/100);
	if (npc["d_adjust"] && npc["skill_type_d"]) 
		me->set_skill(npc["skill_type_d"],(100+npc["d_adjust"])*me->query_skill(npc["skill_type_d"],1)/100);
*/

		
//	setting up temp for chill/juqi
	i= sizeof(temp_setup);
	while (i--) {
		if (npc[temp_setup[i]])
			me->set_temp(npc[temp_setup[i]],special/2 + random(special/2));
		if (npc[mark_setup[i]])
			me->set(npc[mark_setup[i]],1);
	}

//	setting up master
	if (npc["set_master"])
		me->set("family/master_id",npc["set_master"]);

//	setting up weapons, the encumbrance here is necessary otherwise the check for wield would fail.

//	seteuid(getuid());
	me->set_max_encumbrance(800000);	
	if (auto_weapon && me->query("skill_type_w"))
	if (sscanf(me->query("skill_type_w"),"%s/%s",weapon,skill)==2) {
		weapon1 = new(weapon_dir+weapon);
		weapon1->move(me);
		weapon1->wield();
	}
	me->reset_action();
}

void auto_smart_fight(object me, int chance)
{
	int i,j,k,count,num,km_chance, act;
	object *enemy, weapon, *inv, *zombie, *npc_enemy, *pc_enemy, target;
	string pfm, pfm_weapon;
		
//	message_vision(HIY" ------------------------------------------ROUND START !!!.\n"NOR,me);
	
	// parry-busy defense setup
	num = me->query("defense_type");
	
//	resort enemy here, prepare to attack the most hated enemy.	
//	message_vision(sprintf(" 1 my enemy is %O\n",me->query_enemy()),me);
	enemy = resort_enemy(me, "ALL");
	
//	if NPC is healer, it heals every 10 secs. Not used much now.
	if (me->query("npc")=="healer") 
	{
		if (me->query_temp("timer/npc_heal") + 10 < time())
		{
			if (me->query_temp("timer/npc_heal")+ 90 < time()) // 90sec 没 heal，假设恢复内力了
				me->set_temp("timer/heal_num",0);
			help_friend(me);
			if (num) 
				do_defense(me, num);			 
		}
	}	

	// Get weapon !
	if (!ANNIE_D->check_buff(me,"disarmed") && me->query("skill_type_w")) {
			if (sscanf(me->query("skill_type_w"),"%s/%s",pfm_weapon,pfm)==2) 
			if (!check_weapon(me, pfm_weapon)) { 
				pickup_weapon(me, pfm_weapon);
				me->stop_busy();
		}
	}

	// Auto buff
	for (i=1;i<5;i++){
		if (stringp(me->query("perform_buff_"+i)))
			universal_pfm(me->query("perform_buff_"+i),me, me);
		if (me->is_busy())	
			me->stop_busy();
	}
	
//	this is to control the fight frequency. It decides the NPC difficulties.
//	message_vision(sprintf(" 1 my enemy is %O\n",enemy),me);
	chance= chance + enemy_value(me, enemy);
//	message_vision("chance is "+(string)(chance)+" .\n",me);

	if (random(100) < chance) 
		act = 1;
		
//	Here we introduce a new set "smart_busy" to seperate busy and attack frequency, 
//  If an NPC is "smartnpc_busy", he will always try to use his busy when the odds turns good
//	Chat_combat's number will only control the attack , not the busy pfm
//	Don't use it if NPC has more than two types of busy...they will alternate and busy ppl for most of the time.
		
	if (act || me->query("smartnpc_busy"))
	{
		if (random(2000) < 10 - me->query_temp("marks/kongmen_adjust")*10 && !me->query("boss")) {
			message("vision", HIR"\n"+me->name()+HIR"一招不慎，露出了好大的一个破绽！！！\n"NOR,environment(me), me);
			me->perform_busy(3);
			return;
		}
	
		i = sizeof(enemy);
//	(1)	if there is only one enemy:
		if (i==1) {
			if( enemy[0] && living(enemy[0])) 
				if (!enemy[0]->is_busy()) {	
					single_busy(me, enemy[0]);
				}
				if (!me->is_busy() && act ) {
					universal_attack(me, enemy[0]);
				}		
		}
	
// 	(2)	if there are multiple enemies, things become complicated.
//			We do a multi-busy first to all those can be busied, then we attack hate-NO-1 no matter what.

		if (sizeof(enemy)>1) {
			multi_busy(me, enemy);	
			target = me->select_opponent();	
	//		CHANNEL_D->do_sys_channel("sys",sprintf("target is %O\n",target));
			if (target && !me->is_busy() && act)
				universal_attack(me, target);
		}
	}

	if (num) do_defense(me, num);	
//	message_vision(HIW" -----------------------------------------        ROUND END.\n"NOR,me);
	return;
}


//		This function lets NPC judge the possibility of busy chance
//		Remember, the actual chance is not modified, it's just a simulation
//		NPC will NOT try busy when the similuation gives LOW odds

int can_busy(object attacker, object victim, string pfm) {
	
	int immune,diff, mod;
	int busy_time, interval, time_mod;
	string skill, *unarmed = ({ "meihua-shou", "dabei-strike", "bloodystrike","taiji","eagle-claw"});
	string pfm_class, pfm_type, pfm_name;
	int at_result, df_result, perc, chance, enhance;
	mapping busy_enhance = ([
			"canglongzhaxian":	600,
			"nianzijue":		600,
		]);
			
	mod = 10;	// MOD=10 是没有修饰,
	
	sscanf(pfm,"%s/%s/%s/%s",pfm_class, pfm_type, skill,pfm_name);
	if (!stringp(skill))	return 0;
		// 纠正两个generic performs 的问题
	if (pfm_name == "rufengsibi")		{ pfm_type = "force"; skill = "liangyi-force";}
	if (pfm_name == "shimian")			{ pfm_type = "magic"; skill = "music";}

//	CHANNEL_D->do_sys_channel("sys","pfm is "+pfm+ " "+ skill + " pfm_name="+ pfm_name);			

//	Rule 2: Since we are designing 0-10M game, we limit the busy power.
//		Only unarmed busy is designed to fight high exp enemy.
//		Remember, the qlist will never ask you to kill someone > yourexp + 400k
	if (member_array(skill, unarmed) ==-1) {	
		diff = victim->query("combat_exp") - attacker->query("combat_exp");
		if (diff > 4000000 )		mod = 20;
		else if (diff > 2000000) 	mod = 15;
		else if (diff > 1000000)	mod = 12;
	}
	
//	Rule 3: same menpai, effect /2 , applies to player only
//	if (userp(attacker) && SKILL_D(skill)->skill_class() == victim->query("class"))
	if (SKILL_D(skill)->skill_class() == victim->query("class"))
		mod = mod * 2;

//	Rule 5: 对使用同一perform连续成功busy的限制
		
	time_mod = 100;
	if (busy_time = victim->query_temp("busy_timer/"+skill)) {
		interval = time()-busy_time;
		if 	(interval <= 8 ) 			time_mod = 9000;	
		else if  (interval <= 10)	time_mod = 3000;
		else if (interval < 18)			time_mod = 2000;
	}
	
	mod = mod * time_mod /100;
	
//	CHANNEL_D->do_sys_channel("sys","target is "+ victim->query("id")+ "  mod is "+ mod );

	at_result = attacker->query("combat_exp") / 10;
	df_result = victim->query("combat_exp") / 100 * mod;
		
	at_result = (at_result <= 100 )? 100: at_result;
	df_result = (df_result <= 100 )? 100: df_result;
	
	// 相对定力的影响
	perc = (attacker->query_cps() - victim->query_cps())* 100 /( victim->query_cps()+1);
	perc = (perc > 10) ? 10: perc;
	perc = (perc < -10) ? -10: perc;
		
	if (pfm_type != "unarmed") {
		if ( busy_enhance[pfm_name])
			enhance = busy_enhance[pfm_name];
		else
			enhance = 300;		// just choose an average value for step busy
		at_result = at_result /100 * (100 + perc) /100 * enhance;
		if (df_result - attacker->query("combat_exp")/2 >= at_result)
			chance = 0;
		else
			chance = (at_result - df_result + attacker->query("combat_exp")/20) * 100 / at_result;
	} else {
		if ( busy_enhance[pfm_name])
			enhance = busy_enhance[pfm_name];
		else
		enhance = 900;		// Normal ratio
		at_result = at_result /100 * (100 + perc) /100 * enhance;
		chance = at_result * 20 / (at_result + df_result) *5 ;
	}
	
//	CHANNEL_D->do_sys_channel("sys",sprintf(" enhance is %d, chance is %d",enhance,chance));
	
	return chance; 	// MODIFY BUSY RATE	
}
	

void	single_busy(object me, object target) {
					
		int busy_chance, b_flag;
		
//		CHANNEL_D->do_sys_channel("sys","in single busy \n");
//		we supply 2 dodge busy, 1 weapon busy, and 1 unarmed busy		
// 		if you have multiple unarmed busy, you need set them up during fight

		if (me->query("perform_busy_d")) {
			busy_chance = can_busy(me, target, me->query("perform_busy_d"));
			if (busy_chance >= 70) {
				universal_pfm(me->query("perform_busy_d"), me, target); 
			}
		}
		
		if ( !target->is_busy() && !me->is_busy() && me->query("perform_busy_d1")) {
			busy_chance = can_busy(me, target, me->query("perform_busy_d1"));
			if (busy_chance >= 70) {
				universal_pfm(me->query("perform_busy_d1"), me, target); 
			}
		}
		
		if ( !target->is_busy() && !me->is_busy() && me->query("perform_busy_w")) {
			busy_chance = can_busy(me, target, me->query("perform_busy_w"));
			if (busy_chance >= 65) 
				universal_pfm(me->query("perform_busy_w"), me, target); 
		}				
		
		if ( !target->is_busy() && !me->is_busy() && me->query("perform_busy_u")) {	
			busy_chance = can_busy(me, target, me->query("perform_busy_u"));
			if (busy_chance >= 60) 
				universal_pfm(me->query("perform_busy_u"), me, target); 
		}
		
}

void	multi_busy(object me, object *enemy) {
	int k, max, busy_chance;
//	message_vision(sprintf("%O\n",enemy),me);
	max=sizeof(enemy);
	
// 	first use dodge busy on all not-so-high enemies;　
//	Not optimized yet, should start with lowest exp one
	if (me->query("perform_busy_d")) {
		k = -1;
		while (++k<max) {
			if( enemy[k] && living(enemy[k]) && !enemy[k]->is_busy()) 
			{
				busy_chance = can_busy(me, enemy[k], me->query("perform_busy_d"));
				if (busy_chance >= 70) {
					universal_pfm(me->query("perform_busy_d"), me, enemy[k]); 
				}
			}
			if (me->is_busy())	break;
		}
	}
	if (me->query("perform_busy_d1")) {
		k = -1;
		while (++k<max) {
			if( enemy[k] && living(enemy[k]) && !enemy[k]->is_busy()) 
			{
				busy_chance = can_busy(me, enemy[k], me->query("perform_busy_d1"));
				if (busy_chance >= 70) {
					universal_pfm(me->query("perform_busy_d1"), me, enemy[k]); 
				}
			}
			if (me->is_busy())	break;
		}
	}
	
	if (me->query("perform_busy_w")) {
		k = -1;
		while (++k<max) {
			if( enemy[k] && living(enemy[k]) && !enemy[k]->is_busy()) 
			{
				busy_chance = can_busy(me, enemy[k], me->query("perform_busy_w"));
				if (busy_chance >= 65) {
					universal_pfm(me->query("perform_busy_w"), me, enemy[k]); 
				}
			}
			if (me->is_busy())	break;
		}
	}
//	secondly, if have friends around, use unarmed busy as well;	
//	need to busy the most dangerous one since this can only be done once.
//	we do not recommend using unarmed busy when soloing multiple>2 enemies
	if (me->query("perform_busy_u") && !me->is_busy() && (accompany(me) || max <=2)) {
		k = -1;
		while (++k<max) {
			if (!enemy[k]->is_busy() && (userp(enemy[k]))) 
			{
				busy_chance = can_busy(me, enemy[k], me->query("perform_busy_u"));
				if (busy_chance >= 60) {
					universal_pfm(me->query("perform_busy_u"), me, enemy[k]); 
				}
			}				
			if (me->is_busy())	break;
		}	
	}
}


void 	universal_attack(object me, object target) {
	object *inv;
	string attack;
	string attack_class,attack_type,attack_skill,attack_name;
	string msg;
	string weapon,pfm;
	int k;
	
	if (me->query("do_attack_type")==2) attack = do_choose_attack2(me, target);	
	else if (me->query("do_attack_type")==3) attack = do_choose_attack3(me, target);
	else if (me->query("do_attack_type")==4) attack = do_choose_attack4(me, target);
	else if (me->query("do_attack_type")==5) attack = do_choose_attack5(me, target);
	else attack = do_choose_attack1(me, target);
	
//	CHANNEL_D->do_sys_channel("sys",sprintf("attack is %s\n", attack));

//	This servers two funtion, 1. keep opponents busied by not pfm in enemy->query_busy(1)
//	2. pickup lost weapon . It's a good idea to let NPC has "none" in fight.		
	if (attack=="none" || !attack ) {
//		message_vision("say I will idle one turn so i can busy again I can try pickup weapon too",me);
		if (me->query("defense_type")==1 && !check_weapon(me, "sword")) pickup_weapon(me, "sword");
		if (me->query("defense_type")==2 && !check_weapon(me, "whip")) pickup_weapon(me, "whip");
		return;
	}

	if (sscanf(attack,"%s/%s/%s/%s",attack_class,
			attack_type,attack_skill,attack_name)==4)
		universal_pfm(attack,me,target);

//	A lousy self-bragging message. either global or specific
	if (!check_health(target,10) && !check_health(me,10)) {
		if (!me->query("both_msg"))
			message_vision(both_message(),me,target);
		else message_vision(me->query("both_msg"),me,target);
	}
		
	if (!check_health(target,5)) {
		if (!me->query("win_msg"))
			message_vision(super_message(),me,target);
		else message_vision(me->query("win_msg"),me,target);
	}
	
	return;
}


//	the purpose of this function is to auto switch weapon/skill to pfm
//	after pfm, the skill/weapon shall be returned to the original value.
//	parameter: perform_xxx_xxx =  legend/sword/diesword/caidiekuangwu

void 	universal_pfm(string perform_attack, object me, object target) {

	string attack;
	string attack_class,attack_type,attack_skill,attack_name;
	object weapon, new_weapon, *inv;
	int k, force;
	string old_basic_skill,old_special_skill,old_class;

	sscanf(perform_attack,"%s/%s/%s/%s",attack_class,
			attack_type,attack_skill,attack_name);

//	CHANNEL_D->do_sys_channel("sys",sprintf("type=%s, skill=%s, pfm = %s\n", attack_type, attack_skill, attack_name));
		
	weapon = me->query_weapon();
	old_basic_skill=attack_type;
	old_special_skill=me->query_skill_mapped(old_basic_skill);
	old_class=me->query("class");
//	message_vision("i had "+old_basic_skill+" and "+old_special_skill+" .\n",me);
	
	if (attack_type!="unarmed" && attack_type!="dodge" && attack_type != "force"
		&& attack_type!="herb" && attack_type!="cursism"
		&& attack_type!="magic" && attack_type!="spells"
		|| (attack_type == "unarmed" && weapon && weapon->query_skill("type")!="unarmed")
		) {
		if ((!weapon || weapon->query("skill_type")!=attack_type) && check_weapon(me, attack_type)){
			me->ccommand ("unwield all");
			inv=all_inventory(me);
			for (k=0;k<sizeof(inv);k++){
				if (inv[k]->query("skill_type")==attack_type)
					me->ccommand("wield "+inv[k]->query("id"));
			}			
		}

//	allow players to drop enemy weapon so no more endless cloning.:
/*		if (!me->query_weapon()) {
			new_weapon = carry_object("/obj/weapon/"+attack_type);
			command("wield "+new_weapon->query("id"));	
		}*/
	} else if (weapon && weapon->query("skill_type")!="unarmed" && attack_type=="unarmed" ) me->ccommand ("unwield all");	
	
	force = me->query("force_factor");
//	message_vision("say "+me->query("class")+" "+me->query("force_factor")+"\n",me);	
	
	me->set("class",attack_class);
	me->map_skill(attack_type,attack_skill);	

//	message_vision("when pfm, i have "+old_basic_skill+" and "+attack_skill+" "+attack_name+" .\n",me);
	
	if (attack_type == "cursism") {
		SKILL_D(attack_skill)->curse_curses(me, attack_name, target);
	} else if (attack_type == "force") {
		SKILL_D(attack_skill)->exert_function(me, attack_name);
	} else if (attack_type == "magic") {
		SKILL_D(attack_skill)->conjure_magic(me, attack_name, target);
	} else if (attack_type == "spells") {
		SKILL_D(attack_skill)->cast_spell(me,attack_name,target);
	}	
	else if (attack_name=="sharenruma" || attack_name=="mantianhuayu" || attack_name=="tianxiawugou" 
			|| attack_name=="qiankun" || attack_type=="herb" 	
			|| attack_name == "xianglong" || attack_name == "fuhu"	)
			me->perform_action(attack_type+"."+attack_name);
	else 
			SKILL_D(attack_skill)->perform_target(me,attack_name,target);
		
	me->set("class",old_class);
	me->map_skill(attack_type,old_special_skill);
//	message_vision("after pfm, i have "+old_basic_skill+" and "+old_special_skill+" .\n",me);

	if (weapon)
	if (me->query_weapon()!=weapon) {
			me->ccommand("unwield all");
			me->ccommand("wield "+weapon->query("id"));
	} 
	
	me->set("force_factor",force);	// in case we change this in perform.
//	message_vision("say "+me->query("class")+" "+me->query("force_factor")+"\n",me);
}


//	BASIC_NPC attack template. We don't have many contents here.
string  do_choose_attack1(object me, object target) {

	object weapon, *inv, *instr,*enemy;
	string type,dot_owner,index,dir;
	int danger, number,i;
	int npc_number, pc_number;
	int m, n;
	danger = enemy_type(me, target);
	enemy = me->query_enemy();
	number = sizeof(enemy);
	pc_number = sizeof(resort_enemy(me, "PC"));
	npc_number = sizeof(resort_enemy(me, "NPC"));
	weapon = me->query_weapon();
	
//	message_vision("number is "+(string)(number)+" .\n",me);
	switch (me->query("npc")) {
	case "diesword":
	case "shortsong-blade":								
		me->ccommand("exert juqi");
		if (!me->query_temp("timer/tx-stance")) {
			me->ccommand("perform dodge.xiaosha");
		}
		if (!me->query("scroll/dormancy_juxue"))
			me->set("scroll/dormancy_juxue",1);
		if (!check_health(me,30))	me->ccommand("juxue "+me->query("id"));
		if (target->query_busy()==1 && number<2 && !accompany(me))
			type = "none";
		else type = me->query("perform_weapon_attack");
		break;
	case "dragonstrike":						
		if  (me->query_temp("timer/pfm/xianglongwuhui")+ 40 < time())
			type = me->query("perform_unarmed_attack");
		else if (target->query_busy()>=2)
			type = me->query("perform_unarmed_attack3");
		else if (me->query_skill("dragonstrike",1)>=150) {
			if (!ANNIE_D->check_buff(target,"pseudo-busy") 
					&& target->query_temp("busy_timer/dragonstrike")+ 18 < time()) {
				SKILL_D("dragonstrike")->perform_target(me,"shichengliulong",target);
			}
			if (ANNIE_D->check_buff(target,"pseudo-busy")) {
				if (target->query_temp("annie/beggar/time")+6 >= time())
				{
					switch (target->query_temp("annie/beggar/6")) {
						case "zjbl":SKILL_D("dragonstrike")->perform_target(me,"zhenjingbaili",target);
						default:
					}
				}
			}
			type = "none";
		} else
			type = "none";
		break;
	case "dagou-stick":
			me->ccommand("perform dodge.gouweixudiao"); 
			if (number>1)	type=me->query("perform_weapon_attack");			
			else if  (me->query_temp("timer/pfm/xianglongwuhui")+ 40 < time())
					type = me->query("perform_unarmed_attack");	
			else {
				switch (random(2)) {
				 	case 0: type=me->query("perform_weapon_attack"); break;
				 	default: type=me->query("perform_weapon_attack2");	
				}
			}	
			break;	
	case "herb":
		me->perform_action("herb.xiumugong");
		dot_owner = file_name(me);
    	sscanf(dot_owner,"%s#%s",dir,index);
    	dot_owner = me->query("id")+ index;
		if (target->query_temp("dot/dream-herb/cyb/"+dot_owner)) 
			type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack2");
		else 
			type=me->query("perform_unarmed_attack");
		break;
	case "zhangjian":
	case "xuanyuan-axe":
		me->perform_action("herb.xiumugong");
		me->perform_action("herb.beisusan");
		if (!me->is_busy())
		switch (random(2)) {
			case 0:  type= weapon_unarmed(me,"perform_weapon_attack","perform_unarmed_attack"); break;
			case 1:  type= weapon_unarmed(me,"perform_weapon_attack2","perform_unarmed_attack"); break;
		}
		break;
	case "sharen-sword":
	case "lefthand-sword":
	case "longfenghuan":
		if (!ANNIE_D->check_buff(target, "lockup")) {
			type = me->query("perform_unarmed_attack");
		}
		else
			type = me->query("perform_weapon_attack");
		break;
	case "necromancy":
			if (my_worst_wound(me)=="kee")
				type = me->query("perform_unarmed_attack");
			else if (my_worst_wound(me) == "gin")
				type = me->query("perform_unarmed_attack2");
			else 
				type = me->query("perform_unarmed_attack3");				 
		break;
	case "thunderwhip":
		if (!ANNIE_D->check_buff(me, "haste") && !ANNIE_D->check_buff(me, "agiup"))
			SKILL_D("celecurse")->curse_curses(me, "boostcurse");
		if (weapon) {
			dot_owner = file_name(me);
	    	sscanf(dot_owner,"%s#%s",dir,index);
	    	dot_owner = me->query("id")+ index;
			if (!target->query_temp("dot/celecurse/bloodcurse/"+dot_owner)) 
				SKILL_D("celecurse")->curse_curses(me,"bloodcurse",target);
			if (me->is_busy())	type = "none";
			else
				type = me->query("perform_weapon_attack");
		} else
			type = me->query("perform_unarmed_attack"); 
		break;	
	case "celecurse1":
		if (!ANNIE_D->check_buff(target,"strdown"))
			SKILL_D("celecurse")->curse_curses(me,"weakcurse",target);
		else
			SKILL_D("celecurse")->curse_curses(me,"bloodcurse",target);
		type = "none";
		break;					
	case "tanzhi-shentong":
	case "tanzhi-shentong2":
	case "qingfeng-sword":
		if (!check_health(me,70) && me->query_temp("pfm/hs_aoshuang") + 40 < time()) {
			me->ccommand("exert aoshuang");
			me->set_temp("pfm/hs_aoshuang",time());
			type = "none";
		} else if (me->query_weapon() && me->query("perform_weapon_attack")) 
			type =me->query("perform_weapon_attack");
		else if (me->query("perform_unarmed_attack"))
			type =me->query("perform_unarmed_attack");
		else 	type="none";
		break;	
	case "taiji":
	case "taiji-sword":
	case "three-sword":	if (target->query("sen")<1000)
			me->perform_action("dodge.bazhentu");
			break;
	case "cloudstaff":
	case "mind-sense":
		if (!ANNIE_D->check_buff(me,"xg-evil"))
			me->ccommand("exert zhuxian");
		if (!ANNIE_D->check_buff(me,"agiup") && !me->is_busy()) {
			me->map_skill("move","nodust-steps");
			me->ccommand("perform dodge.juechen");
		} 
		if (!check_health(me,70))
			me->ccommand("exert douzhansheng");
		for (i=0;i<sizeof(enemy);i++){
			if (!ANNIE_D->check_buff(enemy[i],"powerdown")
				&&!ANNIE_D->check_buff(enemy[i],"blocked"))
			SKILL_D("essencemagic")->conjure_magic(me, "void_sense", enemy[i]);
		}
		type = weapon_unarmed(me,"perform_weapon_attack","perform_unarmed_attack");
		break;
	case "xuezhan-spear2":
		dot_owner = file_name(me);
    	sscanf(dot_owner,"%s#%s",dir,index);
    	dot_owner = me->query("id")+ index;
		me->perform_action("dodge.jiyingbotu");
		if (weapon && me->query_skill("xuezhan-spear",1)>=180 
			&& me->query("timer/pfm/xz_liguang")+ 120 < time())
			me->ccommand("perform liguangsheshi");			
		if (!me->is_busy() && weapon && !target->query_temp("dot/xuezhan-spear/jswk/"+dot_owner)) {
			type = me->query("perform_weapon_attack");
		} else 
			type = "none";
		break;	
	case "xuezhan-spear3":
		dot_owner = file_name(me);
    	sscanf(dot_owner,"%s#%s",dir,index);
    	dot_owner = me->query("id")+ index;
		me->perform_action("dodge.jiyingbotu");
		if (weapon && me->query_skill("xuezhan-spear",1)>=180 
			&& me->query("timer/pfm/xz_liguang")+ 120 < time())
			me->ccommand("perform liguangsheshi");			
		if (!me->is_busy() && weapon && !target->query_temp("dot/xuezhan-spear/jswk/"+dot_owner)) {
			type = me->query("perform_weapon_attack2");
		} else 
			type = me->query("perform_weapon_attack");
		break;	
	case "eagle-claw":
		if (target->query_temp("timer/lockup") + 60 < time()) {
			me->delete("timer/pfm/fg_cunjin");
			type = me->query("perform_unarmed_attack");
		} else
			type = "none";
		break;
	case "scratmancy":
		me->set("perform_busy_u",me->query("perform_unarmed_attack"));
		if (me->query_skill("scratmancy")>400) {
				me->set_skill("scratmancy",200);
				me->set_skill("scratching",200);
		}
		if ( !me->query_temp("max_guard")) {
			sheet_fight(me); 
		}
		type="none";
		break;				
	case "fy-sword":
		if (target->query_weapon()) {
			type=me->query("perform_weapon_attack2"); 
			break;
		}
		if (!ANNIE_D->check_buff(target, "defdown")) 
			type=me->query("perform_weapon_attack"); 
		else type="none";			
		break;	
	case "assassin-hammer":
		  if (me->query_temp("max_guard")==0 && me->query("timer/alert")+40 < time()) {
		  	me->ccommand("xiao");
		 	SKILL_D("assassin-hammer")->perform_target(me,"npc_bolangyiji",target);
		 	type = "none";
		 } else if (!me->is_busy())
		  	type = me->query("perform_unarmed_attack");
		 break;	
	case "wolf-strike":
		 if (me->query_temp("max_guard")==0 && me->query("timer/alert")+40 < time()) {
		  	me->ccommand("xiao");
		  } 
		 if (me->query("timer/pfm/wm_ningxue")+ 90 < time())
		 	me->ccommand("perform ningxue");
		 if (me->query("timer/pfm/wm_canzhi")+ 90< time())
		  	 type = me->query("perform_unarmed_attack2");
		  else 
		  	 type = me->query("perform_unarmed_attack");
		 break;	
	case "jin-gang":
		 if (weapon && me->query("timer/pfm/fengmo_1") + 120 < time()
		 	&& !me->query_temp("pfm/fengmo_1") && !me->query_temp("pfm/fengmo_2")){
		 	me->delete("timer/pfm/fengmo_1");
		 	type = me->query("perform_weapon_attack");
		 } else if (weapon && me->query("timer/pfm/fengmo_2") + 180 < time()
		 	&& !me->query_temp("pfm/fengmo_1") && !me->query_temp("pfm/fengmo_2")){
		 	me->delete("timer/pfm/fengmo_2");
		 	type = me->query("perform_weapon_attack2");
		 }  else if (!weapon)
		 	type = me->query("perform_unarmed_attack");
		else
			type = "none";
		break;			
	case "kwan-yin-spells":
		if ((!check_gks(me,"gin",80) || !check_gks(me,"sen",80)) && me->query("a/ma")+ 20< time()) {
			type = "none";
			me->set("a/ma",time());
			me->ccommand("cast ma "+me->query("id"));
		}			
		else if (number >= 2) {
			type = me->query("perform_unarmed_attack2");
		} else {
			type = me->query("perform_unarmed_attack");
		} 
		break;	
	case "ittouryu":
		if (weapon) {
			if (target->query_weapon() && !target->query_temp("marks/disarmed") + 60 < time())
				type = me->query("perform_weapon_attack2");
			else 
				type = me->query("perform_weapon_attack");			
		} else {
			if (!check_health(me,20) && me->query("a/shimon")+ 20 < time()){ 
				type=me->query("perform_unarmed_attack2");	
				me->set("a/shimon",time());
			} else
				type = me->query("perform_unarmed_attack");
		}
		break;
	default: 
		{
			type = "none";
			if (weapon && weapon->query("skill_type")!="unarmed") {
				n = stringp(me->query("perform_weapon_attack"))
					+	stringp(me->query("perform_weapon_attack2"))
					+   stringp(me->query("perform_weapon_attack3"))
					+ 	stringp(me->query("perform_weapon_attack4"));
				if (n) {
					m = random(n);
					if (m)
						type = me->query("perform_weapon_attack"+(m+1));
					else
						type = me->query("perform_weapon_attack");
				}
			} else {
				n = stringp(me->query("perform_unarmed_attack"))
					+	stringp(me->query("perform_unarmed_attack2"))
					+   stringp(me->query("perform_unarmed_attack3"))
					+ 	stringp(me->query("perform_unarmed_attack4"));
				if (n) {
					m = random(n);
					if (m)
						type = me->query("perform_unarmed_attack"+(m+1));
					else
						type = me->query("perform_unarmed_attack");
				}
			}	
		}
	}
//	Do not pfm attack while there is lots of NPC pets attacking.	
	if (number>2 && pc_number<1 && npc_number>2)
		type = "none";
//	message_vision("attack type is "+type+" .\n",me);
	return type;
}


string weapon_unarmed(object me, string weapon_i,string unarmed_i) {
//	CHANNEL_D->do_sys_channel("sys",sprintf("%s %s\n", weapon_i, unarmed_i));
	object weapon;
	string weapon_type;
	
	weapon = me->query_weapon();

	if (objectp(weapon)) {
		weapon_type = weapon->query("skill_type");
		if (weapon_type!="unarmed" && me->query(weapon_i)
			&& check_weapon(me, weapon_type))
			return me->query(weapon_i);
		else if (weapon_type=="unarmed" && me->query(unarmed_i))
			return me->query(unarmed_i);
	} else if (me->query(unarmed_i))	
		return me->query(unarmed_i);
	
	return "none";
}

int get_max_busy(object *enemy)
{
	int i,flag = 99;
	for (i=0;i<sizeof(enemy) ; i++)
		if (enemy[i]->query_busy() < flag)
			flag = enemy[i]->query_busy();
	return flag;
}


string  do_choose_attack2 (object me, object target) {

	object weapon, *inv, *instr, *real_enemy, *npc_enemy;
	string type,dot_owner,index,dir;
	int danger, number, j, i;
	int npc_number, pc_number,max_busy;
	int n, m, timer;	
	danger = enemy_type(me, target);
	number = sizeof(me->query_enemy());
	real_enemy = resort_enemy(me,"PC");
	npc_enemy = resort_enemy(me,"NPC");
	pc_number = sizeof(real_enemy);
	npc_number = sizeof(npc_enemy);
	weapon = me->query_weapon();
	max_busy = get_max_busy(me->query_enemy());
	
	
//	message_vision("number is "+(string)(number)+" .\n",me);
	switch (me->query("npc")) {
	
	case "diesword":
	case "shortsong-blade":								
		me->set_skill("dormancy",300);
		me->set_skill("six-sense",300);
		if (!ANNIE_D->check_buff( me, "juqi"))
			me->ccommand("exert juqi");
		if (!me->query_temp("timer/tx-stance")) {
			me->ccommand("perform dodge.xiaosha");
		}
		if (!check_health(me,70))	me->ccommand("exert juxin");
		if (!me->query("scroll/dormancy_juxue"))
			me->set("scroll/dormancy_juxue",2);
		if (!check_health(me,30))	me->ccommand("juxue "+me->query("id"));
		if (!check_health(me,80)) {	
			if (me->query("timer/pfm/jushen")+300 < time()) 	me->ccommand("exert jushen");
			if (me->query("timer/pfm/juli")+300 < time()) 		me->ccommand("exert juli");
			if (me->query("timer/pfm/tx_juwei") + 120 <time()) 	me->ccommand("exert juwei");
		}		
		if (target->query_busy()==1 && number<2 && !accompany(me))
			type = "none";
		else type = me->query("perform_weapon_attack");
		break;
	case "dagou-stick":
	case "dagou-stick1":
			me->ccommand("perform dodge.gouweixudiao"); 
			if (number>1)	type=me->query("perform_weapon_attack");			
			else {
				if  (me->query_temp("timer/pfm/xianglongwuhui")+ 40 < time())
					type = me->query("perform_unarmed_attack");
				else if (target->query_busy()>=2)
					type = me->query("perform_unarmed_attack3");
				else if (me->query_skill("dragonstrike",1)>=150) {
					if (!ANNIE_D->check_buff(target,"pseudo-busy") 
						&& target->query_temp("busy_timer/dragonstrike")+ 18 < time()) {
						me->ccommand("unwield all");
						SKILL_D("dragonstrike")->perform_target(me,"shichengliulong",target);
					}
					if (ANNIE_D->check_buff(target,"pseudo-busy")) {
						if (target->query_temp("annie/beggar/time")+6 >= time())
						{
						me->ccommand("unwield all");
						switch (target->query_temp("annie/beggar/6")) {
							case "cuo":	me->ccommand("wield all");
										SKILL_D("dagou-stick")->perform_target(me,"chuozijue",target);
										break;
							case "ban":me->ccommand("wield all");
										SKILL_D("dagou-stick")->perform_target(me,"banzijue",target);
										break;
							case "yin":me->ccommand("wield all");
										SKILL_D("dagou-stick")->perform_target(me,"yinzijue",target);
										break;		
							case "tiao":me->ccommand("wield all");
										SKILL_D("dagou-stick")->perform_target(me,"tiaozijue",target);
										break;	
							case "zjbl":SKILL_D("dragonstrike")->perform_target(me,"zhenjingbaili",target);
							default:
						}
						}
					}
					me->ccommand("wield all");
				}
			}
			if (!type && !me->is_busy())	type = me->query("perform_weapon_attack2");
			if (!type) type = "none";
			break;	
	case "longfenghua1":
	case "sharen-sword":
		me->set("fy41/jq_sharenruma",1);
		type = me->query("perform_weapon_attack");
		break;
	case "longfenghuan":
		me->set("fy41/jq_sharenruma",1);
		if (!ANNIE_D->check_buff(target, "lockup")) {
			type = me->query("perform_unarmed_attack");
		}
		else
			type = me->query("perform_weapon_attack");
		break;
	case "mapo":
		// Use disable_type to avoid conflict with others.
		if (!target->query("disable_type") && me->query("a/mapo_freeze")+ 30 < time()) 
			SKILL_D("mapo")->cast_spell(me,"freeze",target);
		// this time we can check mapo
		if (ANNIE_D->check_buff( target,"freeze"))
			me->set("a/mapo_freeze",time());
		type = "none";			
		break;
	case "nine-moon-sword":
		if (!ANNIE_D->check_buff(me,"powerup"))	me->ccommand("exert powerup");
		if (me->query("timer/pfm/9moon_huaxue")+600 < time() && !check_health(me,70)) me->ccommand("exert huaxue");
		if (weapon && !random(3) && userp(target))	me->perform_action("sword.yirancangyun");	
		if (me->query("timer/pfm/polu") + 8 < time()) type = me->query("perform_unarmed_attack");
		else type=me->query("perform_weapon_attack");
		break;
	
	case "thunderwhip":
		 me->set("defense_type",2);
		if (weapon) {
			dot_owner = file_name(me);
	    	sscanf(dot_owner,"%s#%s",dir,index);
	    	dot_owner = me->query("id")+ index;
			if (!target->query_temp("dot/celecurse/bloodcurse/"+dot_owner)) 
				SKILL_D("celecurse")->curse_curses(me,"bloodcurse",target);
			if (me->is_busy())	type = "none";
			else
				type = me->query("perform_weapon_attack");
		} else
			type = me->query("perform_unarmed_attack"); 
		break;					 
	case "tanzhi-shentong":
	case "qingfeng-sword":
		if (!check_health(me,90) && !me->query_temp("pfm/hanmei_remedy"))
			me->ccommand("exert remedy");
		
		if (!me->query_temp("pfm/hs_yingyueliuhui") 
				|| me->query_temp("timer/hs_yingyueliuhui")+ 300 < time()){
			me->ccommand("perform iron-cloth.yingyueliuhui");
			me->set_temp("timer/hs_yingyueliuhui",time());
			type = "none";
			break;
		}
			
		if (!me->is_busy() && !ANNIE_D->check_buff(me, "ironup")) {
			me->ccommand("perform iron-cloth.bingwantianzhang");
			type = "none";
			break;
		}
		if (!check_health(me,70) && me->query_temp("a/hs_aoshuang")+40 < time()) {
//			CHANNEL_D->do_sys_channel("sys",sprintf("aooooooooooooo\n"));
			me->ccommand("exert aoshuang");
			me->set_temp("a/hs_aoshuang",time());
			type = "none";
			break;
		} 
		
		if (!me->is_busy() && number >=3) {
			me->ccommand("exert chill");
			type = "none";
			break;
		}
		
		if (weapon && me->query("perform_weapon_attack2")
			&& target->query_skill("iron-cloth")>400)
			type =me->query("perform_weapon_attack2");
		else if (weapon && me->query("perform_weapon_attack")) 
			type =me->query("perform_weapon_attack");
		else if (me->query("perform_unarmed_attack"))
			type =me->query("perform_unarmed_attack");
		else 	type="none";
		break;	
	case "taiji":		// Another 100% BUSY NPC	
		if (!check_health(me,20) && me->query("a/shimon")+ 20 < time()) 
		{
			type=me->query("perform_unarmed_attack2");
			me->set("a/shimon",time());
			break;
		}				
		if (sizeof(real_enemy)>=1)
		for (i=0;i<sizeof(real_enemy);i++) 
		{
			if (real_enemy[i]->query("sen")<1000) {
				me->ccommand("perform dodge.bazhentu "+real_enemy[i]->get_id());
				
			}
		}
		if (!me->is_busy())	
		{
			for (i=0;i<sizeof(real_enemy);i++) {
//					message_vision("real_enemy is"+real_enemy[i]->query("name")+"\n",me);
					if (!me->is_busy())
					for (j = 1; j<5; j++) {
//						message_vision("in "+j+" \n",me);
						if (!real_enemy[i]->is_busy()) {
							me->ccommand("unwield all");
							me->ccommand("perform nianzijue "+real_enemy[i]->get_id());
						}	
					}
				}
		}
		type = "none";
		break;
	case "taiji-sword":	// THIS NPC CAN 100% BUSY !!!
		if (!check_health(me,20) && me->query("a/shimon")+ 20 < time()) 
		{
			type=me->query("perform_unarmed_attack2");
			me->set("a/shimon",time());
			break;
		}			
		if (!me->is_busy())
		{
			for (i=0;i<sizeof(enemy);i++) {
//				message_vision("real_enemy is"+real_enemy[i]->query("name")+"\n",me);
				if (!me->is_busy() &&  weapon && weapon->query("skill_type")=="sword")
				{
//					message_vision("in "+j+" \n",me);
					if (!enemy[i]->is_busy()) {
						SKILL_D("taiji-sword")->perform_target(me,"chanzijue",enemy[i]);
					}	
				}
			}
		}
		type = "none";
		break;
/*	case "doomsword":
		if (target->query("kee")<2000) type=me->query("perform_weapon_attack");
			else if (!check_health(me,20)) type=me->query("perform_unarmed_attack2");
			else type=me->query("perform_weapon_attack");
		break;*/
	case "xuezhan-spear":
		if (me->query_temp("timer/bafang")+60<time()
				&& target->query_skill("iron-cloth")<=400 ) 
			type=me->query("perform_weapon_attack2");
		else if (target->query("kee")<4000 || number>1) 
				type=me->query("perform_weapon_attack");
		else if (target->query_busy()==1) type = "none";
		else type=me->query("perform_weapon_attack3");
		break;	
	case "xuezhan-spear2":	
		dot_owner = file_name(me);
    	sscanf(dot_owner,"%s#%s",dir,index);
    	dot_owner = me->query("id")+ index;
		
		if (!check_health(me,50) && me->query("timer/pfm/hl_erchuan")+ 120 < time())
			me->ccommand("perform iron-cloth.erchuan");
			
		if (!ANNIE_D->check_buff(me,"ironup") && !target->query_skill("dragonstrike")) {
			me->ccommand("perform iron-cloth.yichuan");
			me->stop_busy();
		}		 
		
		if (!ANNIE_D->check_buff(target,"lockup")&& me->query("timer/pfm/fg_cunjin")+600 < time())
			type = me->query("perform_unarmed_attack");
		else if (!target->query_temp("dot/xuezhan-spear/jswk/"+dot_owner)) {
			type = me->query("perform_weapon_attack");
		} else if (me->query("timer/pfm/xz_liguang")+ 120 < time())
			type = me->query("perform_weapon_attack3");
		else if (me->query("timer/pfm/bafang")+ 30< time())
			type = me->query("perform_weapon_attack2");
		else 
			type = "none";
		break;	
	case "mind-sense":
		if (!ANNIE_D->check_buff(me,"xg-evil"))
			me->ccommand("exert zhuxian");
		if (!ANNIE_D->check_buff(me,"agiup") && !me->is_busy()) {
			me->map_skill("move","nodust-steps");
			me->ccommand("perform dodge.juechen");
		} 
		if (!check_health(me,70))
			me->ccommand("exert douzhansheng");
		for (i=0;i<sizeof(enemy);i++){
			if (!ANNIE_D->check_buff(enemy[i],"powerdown")
				&&!ANNIE_D->check_buff(enemy[i],"blocked"))
			SKILL_D("essencemagic")->conjure_magic(me, "void_sense", enemy[i]);
		}
		if (number>=3)
			type = me->query("perform_unarmed_attack2");
		else	
			type = me->query("perform_unarmed_attack");
		break;
	case "shenji-blade": 
	case "bat-blade": 
		if (target->query("kee")<1000) 
			type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack2");			
		else if (target->query_busy()<= 2) {
			type=weapon_unarmed(me, "perform_weapon_attack2","perform_unarmed_attack");
		}else 
			type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");
		break;
	case "demon-blade": 
		if  (weapon)
			type = me->query("perform_weapon_attack");			
		else {
			if ( my_worst_wound(me) == "kee") type = me->query("perform_unarmed_attack3"); 
			else if (my_worst_wound(me) == "gin" ) type = me->query("perform_unarmed_attack2");
			else type =  me->query("perform_unarmed_attack");
		}
		break;
	case "demon-strike":
		if ( my_worst_wound(me) == "kee") type = me->query("perform_unarmed_attack3"); 
		else if (my_worst_wound(me) == "gin" ) type = me->query("perform_unarmed_attack2");
		else type =  me->query("perform_unarmed_attack");
		break;
	case "softsword":
		if (target->query("kee")<2000) type=me->query("perform_weapon_attack");
			else {switch (random(3)){
				case 0: type=me->query("perform_weapon_attack");
				default: type=me->query("perform_unarmed_attack");
			}
		}
		break;	
	case "wuche-axe":
		if (!check_weapon(me,"spear"))	me->carry_object("/obj/weapon/spear");
		if (!check_weapon(me,"axe"))		me->carry_object("/obj/weapon/axe");
		if (!check_weapon(me,"hammer"))	me->carry_object("/obj/weapon/hammer");
		if (!check_weapon(me,"staff"))	me->carry_object("/obj/weapon/staff");	
		timer = 60 - F_ABILITY->check_ability(me,"xuanfeng_add")*2;	// timer for all three
		if (check_weapon(me,"axe") && me->query("timer/pfm/sl_xfz")+timer<time()) {
			type = "shaolin/axe/wuche-axe/xuanfengzhan";
			break;
		} else if (check_weapon(me,"spear") && me->query("timer/pfm/sl_qxdp")+timer<time()) {
			type = "shaolin/spear/duanhun-spear/qixingduopo";
			break;
		} 
		if (target->query_temp("weapon") &&  target->query_temp("marks/disarmed") + 60 < time()
			&& check_weapon(me,"spear"))
			type = me->query("perform_weapon_attack3"); 
		else if (target->query_skill_mapped("unarmed")=="nine-moon-claw")
			type=me->query("perform_unarmed_attack");
		else if (target->query_skill_mapped("iron-cloth")=="yijinjing")
			type=me->query("perform_unarmed_attack2");
		else {
			pickup_weapon(me,"spear");
			pickup_weapon(me,"staff");
			pickup_weapon(me,"hammer");
			if (!weapon)	type = me->query("perform_unarmed_attack");
			else if (check_weapon(me,"hammer")) type = me->query("perform_weapon_attack2");
			else type = me->query("perform_weapon_attack");
		} 
		break;
	case "chant":
	case "yijinjing":
		if (!me->query_temp("timer/chanting"))	me->ccommand("chant");
		if (target->query("sen") >= target->query("max_sen")/2)
			type = me->query("perform_unarmed_attack");
		break;	
	case "ittouryu":
		if (!ANNIE_D->check_buff(me,"powerup")) {
			me->ccommand("exert juyin");
		}
		if (weapon) {
			if (!check_health(target,20)) 
				type=me->query("perform_weapon_attack3");
			else if (!check_health(me,20) && me->query("a/shimon")+ 20 < time()){ 
				type=me->query("perform_unarmed_attack2");	
				me->set("a/shimon",time());
			}
			else if (target->query_weapon() && !target->query_temp("marks/disarmed") + 60 < time())
				type = me->query("perform_weapon_attack");
			else {switch (random(2)) {
				case 0: type = me->query("perform_weapon_attack2"); break;
				case 1: type = me->query("perform_weapon_attack3");break;	
				}
			}
		} else {
			if (!check_health(me,20) && me->query("a/shimon")+ 20 < time()){ 
				type=me->query("perform_unarmed_attack2");	
				me->set("a/shimon",time());
			} else
				type = me->query("perform_unarmed_attack");
		}
		break;
	case "yue-spear1":
	case "yue-spear1a":
		if (!check_health(target,10) && me->query("perform_unarmed_attack"))
				type=me->query("perform_unarmed_attack2");
		else if (accompany(me)) 
			type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");			
		else if (target->query_busy()==1 && number<2) 
			type ="none";
		else type= weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");			
		break;
	case "yue-spear2":
	case "yue-spear2a":
		me->set_skill("strategy",250);
		me->set_skill("leadership",250);
		me->set_skill("changquan",220);
		if (me->query("timer/pfm/yue_array")+ 10 < time()) {
				if (me->query_temp("timer/pfm/gf_san")+ 125 + F_ABILITY->check_ability(me,"shi_add")*9 < time())
				{
					me->delete_temp("guard_count");
					me->ccommand("perform dodge.san");	// NPC huwei will disappear after a certain time
				}
/*				if (!check_health(me,70)) {		// 这个太厉害了，要秒杀的
					me->ccommand("unwield all");
					me->ccommand("perform dodge.jiu");
					me->ccommand("wield spear");
				} */
				if (!check_health(me,20))
					me->ccommand("perform dodge.ba");
				if (random(2))
					me->ccommand("perform dodge.qi");
				else
					me->ccommand("perform dodge.wu");						
		}
		type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");			
		break;
	case "assassin-hammer":
		 if (!me->query_temp("max_guard") && me->query("timer/alert")+40 < time()) {
		  	me->ccommand("xiao");
		 	SKILL_D("assassin-hammer")->perform_target(me,"npc_bolangyiji",target);
		 	type = "none";
		 } 
		 if (!check_health(me,80) && me->query("timer/pfm/wm_paragon")+1200<time()) {
		 	me->set_skill("summonwolf",300);
		 	me->ccommand("exert paragon");
		 }
		 if (!me->is_busy()) {
		 	me->set_skill("summonwolf",300);
		 	if (number>1)	me->ccommand("curse mindcurse");
		  	if (!me->is_busy()) {
		  		if (me->query("timer/pfm/wm_ningxue")+ 90< time())
		  	 		type = me->query("perform_unarmed_attack3");
		  		else if (me->query("timer/pfm/wm_canzhi")+ 90 < time())
		 			type = me->query("perform_unarmed_attack2");
		  		else 
		  	 		type = me->query("perform_unarmed_attack");
		 	} 
		 }
		 break;		
	case "jin-gang":
		 if( !ANNIE_D->check_buff(me, "damageshield"))
		 	me->ccommand("perform iron-cloth.daoqiangburu");
		 if (weapon && me->query("timer/pfm/fengmo_1") + 90 < time()
		 	&& !me->query_temp("pfm/fengmo_1") && !me->query_temp("pfm/fengmo_2")){
		 	me->delete("timer/pfm/fengmo_1");
		 	type = me->query("perform_weapon_attack");
		 } else if (weapon && me->query("timer/pfm/fengmo_2") + 120 < time()
		 	&& !me->query_temp("pfm/fengmo_1") && !me->query_temp("pfm/fengmo_2")){
		 	me->delete("timer/pfm/fengmo_2");
		 	type = me->query("perform_weapon_attack2");
		 }  else if (!weapon)
		 	type = me->query("perform_unarmed_attack");
		else
			type = "none";
		break;
	case "kwan-yin-spells":
		 if( !ANNIE_D->check_buff(me, "damageshield"))
		 	me->ccommand("perform iron-cloth.daoqiangburu");
		if ((!check_gks(me,"gin",80) || !check_gks(me,"sen",80)) && me->query("a/ma")+ 30< time()) {
			me->set("marks/pfm/3word","ma+ma+ma");
			me->ccommand("cast 3word on "+me->query("id"));
			me->start_busy(3);
			type = "none";
			me->set("a/ma",time());
			break;				
		}			
		else if (number>= 4 && !check_gks(me,"kee",80) && check_gks(me,"kee",40)) {
			me->set("marks/pfm/2word","ni+ni");
		} else {
			me->set("marks/pfm/2word","an+an");
		} 
		type = me->query("perform_unarmed_attack");
		break;	
	case "necromancy":
	case "scratmancy":
	case "alchemy":
			sq_guard(me);
			if (number>=3 && accompany(me))
				me->ccommand("cast thunderbolt");
			else if (number==1 && target->query_busy()>=3)
				me->ccommand("cast demonicbolt");
			else if (!check_gks(me,"kee",80) && check_gks(me,"kee",60))
				me->ccommand("cast netherbolt");
			else if (me->query("gin")< me->query("max_gin")*4/5)
				me->ccommand("cast drainerbolt");
			else 
				me->ccommand("cast feeblebolt");				 
			type="none";
		break;

	case "xuanyuan-axe":
		me->set_skill("herb",300);
		me->perform_action("herb.xiumugong");
		me->perform_action("herb.buzichi");
		
		if (me->query_temp("timer/pfm/longlife_pangu")+30 > time()) {
			type = me->query("perform_weapon_attack3");
			break;
		}			
		if (me->query("timer/pfm/jiuqipoxiao")+30<time()){
			type = me->query("perform_weapon_attack2");
			break;
		}			
		dot_owner = file_name(me);
    	sscanf(dot_owner,"%s#%s",dir,index);
    	dot_owner = me->query("id")+ index;
		if (!target->query_temp("dot/dream-herb/cyb/"+dot_owner))  
			me->ccommand("perform herb.canyunbi");
		if (!target->query_temp("dot/dream-herb/yjl"+dot_owner))
			me->ccommand("perform herb.yujiliang");
	
		type=weapon_unarmed(me,me->query("perform_weapon_attack"),me->query("perform_unarmed_attack"));
		break;
	case "musician":
		inv = all_inventory(me);
		instr = filter_array(inv,(: $1->query("timbre") :));
		if (!instr || !sizeof(instr)) 
			type = weapon_unarmed(me,"perform_weapon_attack","perform_unarmed_attack");
		else {
			if (!target->is_busy())
				me->perform_action("unarmed.npc_by_shimian");
			if (target->query_busy()==1) {
				type = "none";
				break;
			}
			else 
				me->perform_action("unarmed.npc_by_bihai");
			type = "none";
		}
		break;
	default: 
		{	type = "none";
			if (weapon && weapon->query("skill_type")!="unarmed") {
				n = stringp(me->query("perform_weapon_attack"))
					+	stringp(me->query("perform_weapon_attack2"))
					+   stringp(me->query("perform_weapon_attack3"))
					+ 	stringp(me->query("perform_weapon_attack4"));
				if (n) {
					m = random(n);
					if (m)
						type = me->query("perform_weapon_attack"+(m+1));
					else
						type = me->query("perform_weapon_attack");
				}
			} else {
				n = stringp(me->query("perform_unarmed_attack"))
					+	stringp(me->query("perform_unarmed_attack2"))
					+   stringp(me->query("perform_unarmed_attack3"))
					+ 	stringp(me->query("perform_unarmed_attack4"));
				if (n) {
					m = random(n);
					if (m)
						type = me->query("perform_unarmed_attack"+(m+1));
					else
						type = me->query("perform_unarmed_attack");
				}
			}	
		}
	}
//	message_vision("attack type is "+type+" .\n",me);
	return type;
}

string  do_choose_attack3(object me, object target) {
	object weapon, *inv, *instr;
	string type;
	int danger, number, j, i;
	int npc_number, pc_number;
		
	danger = enemy_type(me, target);
	number = sizeof(me->query_enemy());
	pc_number = sizeof(resort_enemy(me, "PC"));
	npc_number = sizeof(resort_enemy(me, "NPC"));
	weapon = me->query_weapon();
	
	
//	message_vision("number is "+(string)(number)+" .\n",me);
	switch (me->query("npc")) {
	
	case "diesword":
	case "shortsong-blade":
		if (!target->is_busy())
			type= me->query("perform_busy_u");
		else if (target->query_busy()==1 && number<2 && !accompany(me))
			type = "none";
		else type = me->query("perform_weapon_attack");
		break;
	case "longfenghuan":
		me->set("fy41/jq_sharenruma",1);
		if (target->query("kee")<3000)
				type=me->query("perform_weapon_attack2");
			else type= me->query("perform_weapon_attack");			
		break;	
	case "longfenghua1":
		me->set("fy41/jq_sharenruma",1);
		if (target->query_busy()==1 && random(2)) type="none";
			else type= me->query("perform_weapon_attack");
	case "longfenghuan1a":
		me->set("fy41/jq_sharenruma",1);
		if (me->query_temp("timer/sharen")+20<time() && target->query("kee")<3000 )
				type=me->query("perform_weapon_attack2");
			else type= me->query("perform_weapon_attack");			
		break;	
	case "nine-moon-sword":
	case "nine-moon-sword2":
		if (me->query("timer/polu") + 8 < time() 
			|| !target->is_busy()) type = me->query("perform_unarmed_attack");
			else type=me->query("perform_weapon_attack");
			break;
	case "dagou-stick":
		if (me->query("kee")<me->query("max_kee")*20/100) type=me->query("perform_weapon_attack3");			
			else if (number>1)	type=me->query("perform_weapon_attack");			
			else if (target->query_skill("iron-cloth")>300) type=me->query("perform_unarmed_attack");			
			else {switch (random(3)) {
				 case 0: type=me->query("perform_weapon_attack"); break;
				 case 1: type=me->query("perform_unarmed_attack"); break;
				 default: type=me->query("perform_weapon_attack2");	
				}
				}	
			break;	
	case "thunderwhip":
		 me->set("defense_type",2);
		 if (me->query("kee")<6000)
		 	me->set("perform_unarmed_u",me->query("perform_unarmed_attack3"));
		 if (target->query("combat_exp")<me->query("combat_exp")
		 	&& target->query("max_gin")<6000)
		 	type=me->query("perform_weapon_attack2");
		 else if (target->query_busy() && target->query("kee")<4000 
		 	|| target->query_busy()>=3)
		 	type=me->query("perform_weapon_attack3");
		 else if (target->query_skill("iron-cloth")>320)
		 	type=me->query("perform_unarmed_attack2");
		 else {switch (random(3)) { 
		 	case 2:  type=me->query("perform_unarmed_attack");
		 	default: type=me->query("perform_weapon_attack");
		 	}
		 }
		 break;
	case "qingfeng-sword":
		if ((danger==2||danger==4) && target->query("force")>100)
			type=me->query("perform_weapon_attack");
			else if (number>1) type=me->query("perform_weapon_attack2");
			else if (target->query_busy()==1) type = "none";
				else type=me->query("perform_weapon_attack2");
		break;
	case "tanzhi-shentong":
		if (number>1) type=me->query("perform_weapon_attack3");
			else if(target->query_busy()==1) type="none";
			else if (number>1) type=me->query("perform_weapon_attack3");
			else type=me->query("perform_weapon_attack");
		break;
	case "taiji":	if (!check_health(me,20)) type=me->query("perform_unarmed_attack2");			
			else {
				for (j = 1; j<5; j++) {
					if (!target->is_busy() && !me->is_busy()) {
						me->perform_action("unarmed.nianzijue");
					}
				}
				if (target->is_busy() && !me->is_busy()) {
					if (number>1)	type="none";
					else if (target->query_busy()==1 
						&& target->query("combat_exp")<2*me->query("combat_exp")) 
						type ="none";
					else {	switch (random(2)) {
							case 0: type =me->query("perform_unarmed_attack");break;
							default: type="none";
						}
					}
				}
			}
			break;
	case "taiji-sword":
		if (!check_health(me,20)) type=me->query("perform_unarmed_attack2");			
			else if (number>1)	type="none";
			else if (target->query_busy()==1 
				&& target->query("combat_exp")<2*me->query("combat_exp")) 
					type ="none";
			else {switch (random(2)) {
				case 0: type =me->query("perform_unarmed_attack");break;
				default: type="none";
				}
			}
		break;
	case "doomsword":
		if (target->query("kee")<2000) type=me->query("perform_weapon_attack");
			else if (!check_health(me,20)) type=me->query("perform_unarmed_attack2");
			else type=me->query("perform_weapon_attack");
		break;
	case "xuezhan-spear":
		if (!me->query_temp("daoqian") && !target->query_skill("dragonstrike")) {
			me->perform_action("iron-cloth.npc_jinzhongzhao");
			type="none";
			} 
		else if (me->query_temp("timer/bafang")+60<time()
				&& target->query_skill("iron-cloth")<=400 ) 
			type=me->query("perform_weapon_attack2");
		else if (target->query("kee")<4000 || number>1) 
				type=me->query("perform_weapon_attack");
		else if (target->query_busy()==1) type = "none";
		else type=me->query("perform_weapon_attack3");
		break;	
	case "mind-sense":
	case "yue-spear1":
	case "yue-spear1a":
		if (!check_health(target,10) && me->query("perform_unarmed_attack") && !is_he_pet(target))
				type=me->query("perform_unarmed_attack2");
		else if (accompany(me)) 
			type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");			
		else if (target->query_busy()==1 && number<2
				&& target->query("combat_exp")<2*me->query("combat_exp")) 
			type ="none";
		else type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");			
		break;
	case "yue-spear2":
	case "yue-spear2a":
		type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");			
		break;
	case "shenji-blade": 
		if  (!check_health(me,20)) {
			type=me->query("perform_unarmed_attack3");
			break;
		}
		if  (accompany(me)) {
			if (!check_health(target,10)) type=weapon_unarmed(me, "perform_weapon_attack3","perform_unarmed_attack2");			
			else if (!check_health(target,20)) type=me->query("perform_unarmed_attack");
				else type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");			
		} else {
			if (target->query("kee")<1000) type=me->query("perform_weapon_attack3");
				else if (target->query("kee")<3000 && (userp(target)||number<3)) 
					type=weapon_unarmed(me, "perform_weapon_attack3","perform_unarmed_attack");			
				else if ((target->query("kee")<5000 || target->query_busy()>3)
						&& (userp(target)||number<3)) 
					type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");			
				else if (target->query_busy()==1 && number<2) type ="none";
			      	else { if (random(3) && weapon) type=me->query("perform_weapon_attack2");
			       		else type=me->query("perform_unarmed_attack2");
			       	}
			}
		break;
	case "bat-blade": 
		if  (!check_health(me,20)) {
			type=me->query("perform_unarmed_attack3");
			break;
		}
		if (target->query("kee")<1000) 
			type=weapon_unarmed(me, "perform_weapon_attack3","perform_unarmed_attack");			
		else if (target->query_busy()<= 2) {
			if (number>1 || accompany(me)) 
				type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack2");
			else type="none";
		}else 
			type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");
		break;
	case "softsword":
		if (target->query("kee")<2000) type=me->query("perform_weapon_attack");
			else if ((danger==1 || danger==2||danger==4) && target->query("force")>100)
				type=me->query("perform_weapon_attack2");	
			else {switch (random(3)){
				case 0: type=me->query("perform_weapon_attack3");
				default: type=me->query("perform_weapon_attack");
			}
			}
		break;	
	case "wuche-axe":
		me->set("force_factor",150);
		if (target->query_busy()>=3) type=me->query("perform_weapon_attack");
		else if (target->query_busy()==1 && !accompany(me)) type ="none";
		else if (target->query_skill_mapped("unarmed")=="nine-moon-claw")
			type=me->query("perform_unarmed_attack");
		else if (target->query_skill_mapped("iron-cloth")=="yijinjing")
			type=me->query("perform_unarmed_attack2");
		else { switch (random(3)) {
			case 0: type=me->query("perform_unarmed_attack");break;
			case 1: type=me->query("perform_weapon_attack2");break;
			case 2: type=me->query("perform_weapon_attack3");
			}
		}
		break;
	case "yijinjing":
		me->set("force_factor",150);
		if (me->query("kee")<5000 && me->query("force")>0 
			&& !me->query_temp("shield_force/type")) {
			message_vision(YEL"$N深吸一口真气，内力澎湃而出。。。。。\n"NOR,me);
			message_vision(YEL"气流扰动，似乎在$N周围结成一围气墙。\n"NOR,me);
			me->set_temp("till_death/shield_lock",1);
			me->set_temp("shield_force/type","force");
			me->set_temp("shield_force/ratio",1000);
			me->set_temp("shield_force/msg",
				YEL"$N招式甫及$n身前三尺之外，便似遇上了一层柔软之极，却又坚硬之极的屏障。\n"NOR);
		}
		if (!me->is_fighting() && me->query_temp("shield_force/type")){
			me->delete_temp("shield_force");
			me->delete_temp("till_death/shield_lock");
			me->set("force",me->query("max_force"));
			}
		if (!me->query_temp("shield_force"))
			type=me->query("perform_unarmed_attack");
			else type="none";
		break;	
	case "ittouryu":
		if (!check_health(me,60)&& !me->query("perform_busy_d")) {
				message_vision(CYN"$N皱了皱眉说：“不错，可做我对手。“\n"NOR,me);
				me->set("perform_busy_u",me->query("perform_unarmed_attack3"));
				me->set("perform_busy_d",me->query("perform_unarmed_attack"));
			}
		if (!check_health(target,20)) 
				type=me->query("perform_weapon_attack3");
			else if (!check_health(me,20)) 
				type=me->query("perform_unarmed_attack2");	
			else if (!me->query("perform_busy_d")&&!target->is_busy()
					&& target->query_weapon() && accompany(me)) 
				type=me->query("perform_weapon_attack");
			else {switch (random(3)) {
				case 0: type=me->query("perform_weapon_attack2"); break;
				case 1: type = me->query("perform_weapon_attack3");break;	
				default:type=me->query("perform_unarmed_attack4");
				}
			}
		break;
	case "xinyue-dagger":
		 if (me->query_temp("max_guard")<3) universal_pfm("wolfmount/unarmed/wolf-strike/npc_xiao",me,target);
		 if (me->query_temp("max_guard")<3) universal_pfm("wolfmount/unarmed/wolf-strike/npc_xiao",me,target);
		 if (me->query_temp("max_guard")<3) universal_pfm("wolfmount/unarmed/wolf-strike/npc_xiao",me,target);
		 if (me->query("kee")<me->query("max_kee")*40/100) 
				me->set("perform_busy_u",me->query("perform_unarmed_attack3"));
			else me->delete("perform_busy_u");
		 if (target->query_busy()>=2
		 	||(target->is_busy()&& accompany(me)))
			 	type=me->query("perform_weapon_attack");
		 	else type=me->query("perform_unarmed_attack2");
		 break;	
	case "assasin-hammer":
		 if (me->query_temp("max_guard")<3) universal_pfm("wolfmount/unarmed/wolf-strike/npc_xiao",me,target);
		 if (me->query_temp("max_guard")<3) universal_pfm("wolfmount/unarmed/wolf-strike/npc_xiao",me,target);
		 if (me->query_temp("max_guard")<3) universal_pfm("wolfmount/unarmed/wolf-strike/npc_xiao",me,target);
		 if (me->query("kee")<me->query("max_kee")*40/100) 
				me->set("perform_busy_u",me->query("perform_unarmed_attack3"));
			else me->delete("perform_busy_u");
		 type=me->query("perform_unarmed_attack2");
		 break;	
	case "jin-gang":
		if (!me->query_temp("daoqian") && !target->query_skill("dragonstrike")) {
			me->perform_action("iron-cloth.npc_daoqiangburu");
			type="none";
			} 
		else if (!check_health(me,60) 
				&& check_health(me,41) && !me->query("perform_busy_d")) {
			message_vision(CYN"$N说，老衲说不得要用点旁门左道了。\n"NOR,me);
			me->set("perform_busy_d",me->query("perform_weapon_attack2"));
			type="none";
			} 
		else if (target->query_busy()>=3) 
				type=me->query("perform_weapon_attack");			
		else if (!check_health(me,40)&& check_health(target,20)
				&& number<2 && !accompany(me)) {
					me->delete("perform_busy_d");
					type = "none";
			}  
		else	type=me->query("perform_weapon_attack");
		break;
	case "kwan-yin-spells":
		if (target->query("kee")<2000) type=me->query("perform_weapon_attack");
			else if (!me->query_temp("daoqian")) {
				me->perform_action("iron-cloth.daoqiangburu");
				type="none";
			} 
			else if (!target->query_temp("block_msg/all") && userp(target)) {
				me->cast_spell("npc_hong");
				type="none";
			}
			else if (target->query("gin")<6000) {
				me->cast_spell("npc_an");
				type="none";
			} else type=me->query("perform_weapon_attack");
		break;	
	case "necromancy":
		if (me->query("kee")<5000) me->set("perform_busy_u",me->query("perform_unarmed_attack2"));
		else { if (me->query_temp("max_guard")<4) 
					me->cast_spell("npc_invocation");
				else me->cast_spell("superbolt");
			type="none";
		}
		break;
	case "scratmancy":
		if (me->query("kee")<5000 && me->query("mana")>0 
			&&!me->query_temp("shield_force/type")) {
			message_vision(MAG"$N暗运法力，脸色忽青忽紫。。。。。\n"NOR,me);
			message_vision(MAG"紫气越来越浓，笼罩在$N周围。\n"NOR,me);
			me->set_temp("till_death/shield_lock",1);
			me->set_temp("shield_force/type","mana");
			me->set_temp("shield_force/ratio",500);
			me->set_temp("shield_force/msg",
				MAG"$N招式甫及$n身前三尺之外，便如牛入海,消失在紫气中。\n"NOR);
		}
		if (!me->is_fighting() && me->query_temp("shield_force/type")){
			me->delete_temp("shield_force");
			me->delete_temp("till_death/shield_lock");
			me->set("force",me->query("max_mana"));
			}
		me->set("perform_busy_u",me->query("perform_unarmed_attack"));
		if (me->query_skill("scratmancy")>400) {
			me->set_skill("scratmancy",200);
			me->set_skill("scratching",200);
			}
		if ( me->query_temp("max_guard") < 1 ) {
			sheet_fight(me); 
		}
			else if (me->query_temp("shield_force"))
				me->delete("perform_busy_u");
			type="none";
		break;	
	case "alchemy":
		if (me->query("kee")<10000 && me->query("mana")>0
			&& !me->query_temp("shield_force/type")) {
			message_vision(MAG"$N暗运法力，脸色忽青忽紫。。。。。\n"NOR,me);
			message_vision(MAG"紫气越来越浓，笼罩在$N周围。\n"NOR,me);
			me->set_temp("till_death/shield_lock",1);
			me->set_temp("shield_force/type","mana");
			me->set_temp("shield_force/ratio",500);
			me->set_temp("shield_force/msg",
				MAG"$N招式甫及$n身前三尺之外，便如牛入海,消失在紫气中。\n"NOR);
		}
		if (!me->is_fighting() && me->query_temp("shield_force/type")){
			me->delete_temp("shield_force");
			me->delete_temp("till_death/shield_lock");
			me->set("mana",me->query("max_mana"));
			}
		if (me->query_skill("scratmancy")>400) {
			me->set_skill("scratmancy",200);
			me->set_skill("scratching",200);
			}
		if (!target->query_busy())
			alchemy_fight(me, target, "chain"); 
		else 
			alchemy_fight(me, target, "anything");
		type="none";
		break;	
	case "xuanyuan-axe":
		if (target->query_busy()>=3) {
			if (me->query_temp("timer/jiuqipoxiao")+30<time())
				type=me->query("perform_weapon_attack2");
				else type = me->query("perform_unarmed_attack");
		}else if (me->query_temp("timer/jiuqipoxiao")+30<time()) type=me->query("perform_weapon_attack2");
				else if (target->query_busy()<2 && number<2) type="none";
					else type=me->query("perform_weapon_attack");
		break;	
	case "siqi-sword":
	case "qiusheng-blade":
		if (!check_health(target,30) && me->query("perform_weapon_attack"))
				type=me->query("perform_weapon_attack");
		else if (target->query_busy()==1 && number<2 && !accompany(me)
				&& target->query("combat_exp")<2*me->query("combat_exp")) 
					type ="none";
				else type=me->query("perform_weapon_attack");	
		break;
	case "musician":
		inv = all_inventory(me);
		instr = filter_array(inv,(: $1->query("timbre") :));
		if (!instr || !sizeof(instr)) 
			type = weapon_unarmed(me,"perform_weapon_attack","perform_unarmed_attack");
		else {
			if (!target->is_busy())
				me->perform_action("unarmed.npc_by_shimian");
			if (target->query_busy()==1) {
				type = "none";
				break;
			}
			else 
				me->perform_action("unarmed.npc_by_bihai");
			type = "none";
		}
		break;
	default: if (me->query_weapon() && me->query("perform_weapon_attack")) 
				type =me->query("perform_weapon_attack");
			else if (me->query("perform_unarmed_attack"))
				type =me->query("perform_unarmed_attack");
			else 	type="none";
	}
	if (me->all_pet()) type="none";
//	message_vision("attack type is "+type+" .\n",me);
	return type;
}

string  do_choose_attack4 (object me, object target) {

	object weapon, *inv, *instr, *real_enemy, *npc_enemy;
	string type;
	int danger, number, j, i,k;
	int npc_number, pc_number,max_busy;
		
	danger = enemy_type(me, target);
	number = sizeof(me->query_enemy());
	real_enemy = resort_enemy(me,"PC");
	npc_enemy = resort_enemy(me,"NPC");
	pc_number = sizeof(real_enemy);
	npc_number = sizeof(npc_enemy);
	weapon = me->query_weapon();
	max_busy = get_max_busy(me->query_enemy());
	
	
//	message_vision("number is "+(string)(number)+" .\n",me);
	switch (me->query("npc")) {
	
	case "tempestsword":
		type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");	
		if (!me->is_busy())
		{
			me->ccommand("exert powerup");
			me->ccommand("exert damageup");
		}

		if (target->query_weapon() && me->query("timer/pfm/venusfinger_fail")+ 30 < time())	// fail means ppl is aware the trick :D
			if (!target->query_temp("weapon")->query("nodrop_weapon"))
					if (target->query("combat_exp") < me->query("combat_exp") / 10 * 12)
						type=me->query("perform_unarmed_attack");

		if (accompany(me) && accompany(me)->query("npc")=="spring-blade" && !me->query_team() && !accompany(me)->query_team())
		{
			me->add_team_member(accompany(me));
			type=me->query("perform_weapon_attack2");
		}

		if (accompany(me) && accompany(me)->query("npc")=="spring-blade" && me->query_temp("team_name") == accompany(me)->query_temp("team_name"))
			type=me->query("perform_weapon_attack2");
		
		if (!check_health(target,30) && !me->query("annie/dug"))
			type=me->query("perform_weapon_attack3");
		break;

	case "spring-blade":
		type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");	
		if (!me->is_busy())
		{
			me->ccommand("exert forceup");
			me->ccommand("exert damageup");
		}

		if (target->query_weapon() && me->query("timer/pfm/venusfinger_fail")+ 30 < time())	// fail means ppl is aware the trick :D
				if (!target->query_temp("weapon")->query("nodrop_weapon"))
					if (target->query("combat_exp") < me->query("combat_exp") / 10 * 12)
						type=me->query("perform_unarmed_attack");
		
		if (accompany(me) && accompany(me)->query("npc")=="tempestsword" && !me->query_team() && !accompany(me)->query_team())
		{
			me->add_team_member(accompany(me));
			type=me->query("perform_weapon_attack2");
		}

		if (accompany(me) && accompany(me)->query("npc")=="tempestsword" && me->query_temp("team_name") == accompany(me)->query_temp("team_name"))
			type=me->query("perform_weapon_attack2");
		
		if (!check_health(target,30) && !me->query("annie/dug"))
			type=me->query("perform_weapon_attack3");

		break;
	case "starrain":
		type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");	

		if (!check_health(me,30) && ANNIE_D->check_buff(me,"feat")<1)
			me->ccommand("cast zhaoyuwanqing");
		//  ice-shield
		if (me->query("timer/iceshield")+ 60 < time())
			me->ccommand("exert bingpojingbi");
		// bouncing damage
		if (!ANNIE_D->check_buff(me,"damageshield"))
			me->ccommand("perform dodge.hanxueliulan");
		// Another specialty
		if (me->query("timer/no_busy") + 1800 < time())
			me->ccommand("exert wufangbianhuan");
		if (weapon) {
			if (me->query("timer/pfm/starrain_sp")+ 20 < time())
				me->ccommand("perform qixingbanyue");
			if (target->is_busy() && target->query_busy()<3 && me->query("timer/pfm/pyramid") +12 < time())
				me->ccommand("perform wukongxuanliu");			
			if (!target->query_busy())									// fengloufeiyan
				type = me->query("perform_weapon_attack");
			else if (target->query_busy()>= 3 && me->query("timer/tianheyixian")+ 300< time())	// tianheyixian
				type = me->query("perform_weapon_attack4");
			else
				type = "none";		// Here we don't use blade...
		}
				
		break;
		
	case "chillblade":
		type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");	

		if (!check_health(me,30) && !ANNIE_D->check_buff(me,"feat"))
			me->ccommand("cast zhaoyuwanqing");
		
		//  ice-shield
		if (me->query("timer/iceshield")+ 60 < time())
			me->ccommand("exert bingpojingbi");
		
		// bouncing damage
		if (!ANNIE_D->check_buff(me,"damageshield"))
			me->ccommand("perform dodge.hanxueliulan");

		// Another specialty
		if (me->query("timer/no_busy") + 1800 < time())
			me->ccommand("exert wufangbianhuan");
			
		if (weapon) {
			// Blade buff, binglunyingjing is default on
			if (!weapon->query("ice_blade"))
				weapon->set("ice_blade",1);
			if( !ANNIE_D->check_buff(me,"skillup"))
				me->ccommand("perform kunlun");
			if( !ANNIE_D->check_buff(me,"haste"))
				me->ccommand("perform dodge.shuangtianxuewu");
			if( !ANNIE_D->check_buff(me,"enchantweapon")) 
				me->ccommand("perform liuguang");
			type = "none";
		}			
		// The king/queen of normal hits
		break;
	case "sheolmagic":
		type = "none";
		 if (me->query("kee")<6000)
		 	me->set("perform_busy_u",me->query("perform_busy_u1"));
		 if (me->query("timer/demon_guardian1")+90<time() && !present("guardian",environment(me)))
		 	type=me->query("perform_unarmed_attack");
		 if (target->query("combat_exp") >= 400000 && me->query("timer/demon_guardian2")+90<time() && !present("guardian",environment(me)))
		 	type=me->query("perform_unarmed_attack2");
		 if (target->query("combat_exp") >= 1000000 && me->query("timer/demon_guardian3")+90<time() && !present("guardian",environment(me)))
		 	type=me->query("perform_unarmed_attack3");
		 if (target->query("combat_exp") >= 3000000 && me->query("timer/demon_guardian4")+90<time() && !present("guardian",environment(me)))
		 	type=me->query("perform_unarmed_attack4");
		 if (target->query("combat_exp") >= 6500000 && me->query("timer/demon_guardian5")+90<time() && !present("guardian",environment(me)))
		 	type=me->query("perform_unarmed_attack5");

		 break;
	case "sheolmagic2":
		type = "do_nothing";
		 if (me->query("kee")<6000)
		 	me->set("perform_busy_u",me->query("perform_busy_u3"));
		else
		 	me->set("perform_busy_u",me->query("perform_busy_u1"));
		 if (!target->is_busy() && type != "do_nothing")
			type=me->query("perform_busy_u2");	// 用rascal busy搶先手
		 break;
	case "feixiansword":
		 if (me->query("kee")<6000)
		 	me->set("perform_busy_d",me->query("perform_busy_u1"));
		type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");	
		if (me->query_weapon() && target->query("force") <= 0)
			message_vision(CYN"\n$N邪恶的笑了起来，对$n道：来生再见．．．"NOR,me,target);
		if (!target->is_busy() && number < 2)
			type=me->query("perform_busy_u");
		 break;
	case "feixiansword2":
		type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");	
		if (me->query_weapon())
		{
			type=me->query("perform_weapon_attack2");
			if (target->query_temp("weapon") && target->query("combat_exp") / 10 * 9 < me->query("combat_exp"))
				type=me->query("perform_weapon_attack");
			if (target->query_skill("iron-cloth") >= 250)
				type=me->query("perform_weapon_attack2");
			if (ANNIE_D->check_buff(target,"powerup"))
				type=me->query("perform_weapon_attack");
		}
		if (target->query_busy() == 1 && !accompany(me))
			type="none";
		
		if (me->ccommand("perform force.check_gspm"))
			type = me->query("perform_unarmed_attack2");
		break;

	case "demonblade":
		if (me->ccommand("perform force.check_gspm"))
			type = me->query("perform_unarmed_attack2");
		else
		 type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");	
		 break;
	case "demonblade2":
		 if (me->query("kee")<6000)
		 	me->set("perform_busy_d",me->query("perform_busy_u1"));

		 if (me->query("timer/spicyclaw1")+15<=time() && me->query_skill("spicyclaw",1) >= 0)
		 	type=me->query("perform_unarmed_attack");
		 if (me->query("timer/spicyclaw2")+15<=time() && me->query_skill("spicyclaw",1) >= 50)
		 	type=me->query("perform_unarmed_attack2");
		 if (me->query("timer/spicyclaw3")+15<=time() && me->query_skill("spicyclaw",1) >= 100)
		 	type=me->query("perform_unarmed_attack3");
		 if (me->query("timer/spicyclaw4")+15<=time() && me->query_skill("spicyclaw",1) >= 150)
		 	type=me->query("perform_unarmed_attack4");
		 if (me->query("timer/spicyclaw5")+15<=time() && me->query_skill("spicyclaw",1) >= 200)
		 	type=me->query("perform_unarmed_attack5");

		if (!target->is_busy() && number < 2)
			type=me->query("perform_busy_u");
		 break;
	case "illusionstick":
		type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");	
		if (!target->is_busy() && number < 2 && me->query_temp("zonghengsihai") + 10 <= time())
			type=me->query("perform_busy_u1");
		 break;
	case "illusionstick2":
		if (!target->is_busy() && number < 2 && me->query_temp("zonghengsihai") + 10 <= time())
			type=me->query("perform_busy_u1");
		else
		{
			type="none";
			if (target->is_fighting(me))
				me->cast_spell("soul-flame");
			if (number < 2)
				type=me->query("perform_busy_u2");
		}
		 break;
	case "divineforce":
		type=me->query("perform_unarmed_attack");
		if (target->query_skill("iron-cloth") && !target->query_temp("buff/no_abs"))
			type = me->query("perform_unarmed_attack3");
		if (!target->query("possessed") && target->query("force") > 500)
			type = me->query("perform_unarmed_attack2");
		if (number>1)
			type = me->query("perform_unarmed_attack4");
		 break;
	case "divineforce2":
		type=me->query("perform_unarmed_attack");
//		if (!random(3))
//			type = me->query("perform_unarmed_attack4");
		if (target->query_skill("iron-cloth") && !target->query_temp("buff/no_abs"))
			type = me->query("perform_unarmed_attack3");
		if (!target->query("possessed") && !ANNIE_D->check_buff(target,"lowresist"))
			type = me->query("perform_unarmed_attack2");
		if (number>1)
			type = me->query("perform_unarmed_attack4");
		 break;
	case "kaleidostrike":
		type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");	
		if (!target->is_busy() && number < 2  && me->query_temp("zonghengsihai") + 10 <= time())
			type=me->query("perform_busy_u1");
		 break;
	case "kaleidostrike2":
		if (!target->is_busy() && number < 2  && me->query_temp("zonghengsihai") + 10 <= time())
			type=me->query("perform_busy_u1");
		else
			type="none";
		 break;
	case "dragonwhip":
		if (!me->query_weapon())
		{
			me->set("perform_busy_d",me->query("perform_unarmed_attack2"));
			if (max_busy == 1 && number<2 && accompany(me))
				type="none";
			else
				type=me->query("perform_unarmed_attack");
		}
		else
		{
			if (max_busy>2)
				type=me->query("perform_weapon_attack2");
			else if (max_busy<1 && number<2)
				type=me->query("perform_weapon_attack");
			else
				type="none";
		}
		 break;
	case "dragonwhip2":
		if (!target->is_busy() && number < 2 && me->query_temp("zonghengsihai") + 10 <= time())
			type=me->query("perform_busy_u1");
		else
			type=me->query("perform_unarmed_attack");
		 break;
	case "daimonsword":
		type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");	
		if (target->query_busy()==1 && number<2 && !accompany(me))
			type = "none";
		if (!ANNIE_D->check_buff(target,"chaosmind"))
			type=me->query("perform_unarmed_attack2");
		if (me->query_weapon())
		{
			if (ANNIE_D->get_buff_num(target,1))
				type=me->query("perform_weapon_attack2");
			if (target->query("kee")<4000 || me->query("kee") < 4000)
				type=me->query("perform_weapon_attack3");
		}
		 break;
	case "daimonsword2":
		type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");	
		if (!ANNIE_D->check_buff(target,"chaosmind")) {
			type="none";
			me->ccommand("perform force.wudumiaodi");
		}
		 break;
	case "mixed_demon":
		if (me->query_weapon())
		{
			if (max_busy > 2)
			{
				type=me->query("perform_weapon_attack4");
				if (target->query("kee")<4000)
						type=me->query("perform_unarmed_attack_g");
				if (target->query("kee")<2000 || me->query("kee") < 4000)
						type=me->query("perform_busy_u_g");
			}
			else if (target->query_busy() == 2)
				type=me->query("perform_busy_u3");
			else if (!target->query_busy())
				type=me->query("perform_weapon_attack3");
		}

		if (target->query_weapon())
			if (target->query_weapon()->query("weapon_prop/damage") > 5 )
				type=me->query("perform_busy_u3");
			
		if (target->query_skill("iron-cloth") && !target->query_temp("buff/no_abs"))
			type = me->query("perform_busy_u3");	// absorb iron-cloth

		if (me->query_weapon())
			if (ANNIE_D->get_buff_num(target,1) > 0)
				type=me->query("perform_busy_d_g");

		if (sizeof(target->query_skills()) >= 30 && !ANNIE_D->check_buff(target,"chaosmind"))
			type=me->query("perform_unarmed_attack2");	// chaosmind 
		if (target->query("force") > 500)
			type = me->query("perform_unarmed_attack4");// mana burst
		if (number>1)
			type = me->query("perform_weapon_attack");	// disorder 最高优先

		if (target->query("combat_exp") >= 3000000 && me->query("timer/demon_guardian4")+30<time())
		 	type=me->query("perform_busy_u1");
		if (target->query("combat_exp") >= 6500000 && me->query("timer/demon_guardian5")+30<time())
		 	type=me->query("perform_busy_u2");

		if (target->query_busy() == 1 && type != me->query("perform_busy_u_g"))
			type = "rest during" + target->name() + "busy " + target->query_busy();

		if (!type)
			type = "rest during" + target->name() + "busy " + target->query_busy() +"max busy" + max_busy;

		if (type == me->query("perform_busy_u_g"))
			me->set("perform_busy_u_g","perform_unarmed_attack_g");

		break;
	default: if (me->query_weapon() && me->query("perform_weapon_attack")) 
				type =me->query("perform_weapon_attack");
			else if (me->query("perform_unarmed_attack"))
				type =me->query("perform_unarmed_attack");
			else 	type="none";
	}
	if (me->all_pet()) type="none";
//	message_vision("attack type is "+type+" .\n",me);
	return type;
}


string  do_choose_attack5 (object me, object target) {

	object weapon, *inv, *instr, *real_enemy, *npc_enemy;
	string type;
	int danger, number, j, i,k;
	int npc_number, pc_number,max_busy;
		
	danger = enemy_type(me, target);
	number = sizeof(me->query_enemy());
	real_enemy = resort_enemy(me,"PC");
	npc_enemy = resort_enemy(me,"NPC");
	pc_number = sizeof(real_enemy);
	npc_number = sizeof(npc_enemy);
	weapon = me->query_weapon();
	max_busy = get_max_busy(me->query_enemy());
	
	
//	message_vision("number is "+(string)(number)+" .\n",me);
	switch (me->query("npc")) {
	case "fengmo-staff":

		if (me->query_temp("pfm/fengmo_2") || me->query_temp("pfm/fengmo_1"))
			type="none";
		else
		{
			if (!target->is_busy() && number<2)
			{
				me->ccommand("unwield all");
				me->ccommand("perform fofawubian");
				me->ccommand("wield all");
			}

		me->ccommand("perform iron-cloth.daoqiangburu");
		me->ccommand("exert mingzun");

		if (me->query("kee") < me->query("max_kee")/3)
			me->ccommand("roar");
		type = "none";
		
		if (!me->ccommand("perform xianglong"))
			if (!me->ccommand("perform fuhu"))
				type =me->query("perform_unarmed_attack");
		}

		if (ANNIE_D->check_buff(target,"forceshield"))
			type =me->query("perform_unarmed_attack");

		break;
	case "deisword":

		if (target->query_busy() >= 3)
		{
			me->ccommand("exert jushen");
			type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");	
		}
		else
			type = "none";

		if (!target->is_busy() && number<2 )
			type= me->query("perform_busy_u");

		me->ccommand("exert juqi");

		if (me->query("kee") < me->query("max_kee")/3)
			me->ccommand("exert juxue");

		if (ANNIE_D->check_buff(me,"feat"))
			type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");	
		// 留人生路

		break;
	case "shortsong-blade":

		if (target->query_busy() >= 3)
		{
			me->ccommand("exert juli");
			type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");	
		}
		else
			type = "none";

		if (!target->is_busy() && number<2)
			type= me->query("perform_busy_u");

		me->ccommand("exert juqi");

		if (me->query("kee") < me->query("max_kee")/3)
			me->ccommand("exert juxue");

		if (ANNIE_D->check_buff(me,"feat"))
			type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");	
		// 留人生路

		break;
	case "leadership":

		if (me->ccommand("exert fengchen"))
			if (me->ccommand("exert fengchen"))
				if (me->ccommand("exert fengchen"))
					if (me->ccommand("exert fengchen"))
						me->ccommand("exert fengchen");

		me->ccommand("exert chongguan");

		if (!target->is_busy() && number < 2 && !accompany(me) && target->query("combat_exp")*10 < me->query("combat_exp")*11)
			me->ccommand("exert baoguo");

		me->ccommand("exert check_huanglong");
		if (me->query_temp("annie/check_hl") >= 6) // 6hit以上才使用。
			me->ccommand("exert huanglong");

		if (target->query_busy() >= 2)
			type=weapon_unarmed(me, "perform_weapon_attack","perform_unarmed_attack");	
		else
			type = "none";
		break;
	default: if (me->query_weapon() && me->query("perform_weapon_attack")) 
				type =me->query("perform_weapon_attack");
			else if (me->query("perform_unarmed_attack"))
				type =me->query("perform_unarmed_attack");
			else 	type="none";
	}
	if (me->all_pet()) type="none";
//	message_vision("attack type is "+type+" .\n",me);
	return type;
}


string super_message(){
	string msg;
	
	switch (random(10)) {
	case 0: msg=CYN"\n$N长剑当胸，几绺长发飘散风中，那神情气度不由令人心生景仰。\n\n"NOR; break;
	case 1: msg=CYN"\n$N大笑起来，苍天之下，唯我独尊！\n\n"NOR; break;
	case 2: msg=CYN"\n$N边给$n化妆，边叹道：孩子，你活着的时候就没打扮过，现在装殓前我给你好好打扮打扮。\n\n"NOR;break;	
	case 3: msg=CYN"\n$N惋惜地看着$n说：黄泉漫漫，一路保重。\n\n"NOR;break;
	case 4: msg=CYN"\n$N说：杀你，真不容易。\n\n"NOR;break;
	case 5: msg=CYN"\n$N向$n微微一笑，似已稳操胜算。\n\n"NOR;break;
	case 6: msg=CYN"\n$N狂笑道：上有天王，下有龙王，上天入地，唯我是王。\n\n"NOR;break;
	case 7: msg=CYN"\n$N对$n说：对不起，走好哈。\n\n"NOR;break;
	case 8: msg=CYN"\n$N瓮声瓮气地唱到 : 大灰狼，大灰狼，每天晚上杀人忙~~~\n\n"NOR;break;
	default: msg = CYN"\n$N对著$n挥了挥手。\n\n"NOR;
	}
	return msg;
}

string both_message(){
	string msg;
	
	switch (random(5)) {
	case 0: msg=CYN"\n$N狠狠地说：罢了罢了，今天不是你死就是我亡！\n\n"NOR; break;
	case 1: msg=CYN"\n$N笑道：好好好，黄泉路上你我同行！\n\n"NOR; break;
	case 2: msg=CYN"\n$N叹道：你我本无冤仇，为何不死不休！\n\n"NOR; break;
	case 3: msg=CYN"\n$N叫道：你杀了我，我还会回来的！\n\n"NOR; break;
	case 4: msg=CYN"\n$N只觉心中酸楚，长叹一声道：人生不如意事者，常十之八九，节哀顺便吧。！\n\n"NOR; break;
	}
	return msg;
}

int check_health(object target, int percent){
	int health;
	if (target->query("kee") < target->query("max_kee")*percent/100)
		health=0; 
	else 
		health = 1;
	return health;
}
	
void 	find_officer(object me) {
	object *enemy,owner;
	int i;
		
	enemy=me->query_enemy();
//	message_vision(CYN"say in officer now.\n"NOR,me);
	
	for (i=0;i<sizeof(enemy);i++) {
		if (!userp(enemy[i])) {	
			if(owner=enemy[i]->query("possessed")) {
				if (!me->is_fighting(owner)&& environment(me)==environment(owner)
					&& owner->query("combat_exp")>=12000000) {
					message_vision(HIY"$N喝道：在我面前想溜是不成的！\n"NOR,me);
					me->kill_ob(owner);
					owner->kill_ob(me);
				}
			}
		}
	}
}


int 	all_pet(object me) {
	object *enemy,owner;
	int i;
		
	enemy=me->query_enemy();
	for (i=0;i<sizeof(enemy);i++) {
		if (!enemy[i]->query("possessed")) return 0;				
	}
	return 1;

}

//	this function set NPC with same group starting to protect each other.
void 	baohu(object me) {
	object *pros, *inv, ob;
	string type;
	int i,j, gotit;
	
	pros= ({});
	pros = me->query_temp("protectors");

//	message_vision(" in baohu.\n",me);	
	type = me->query("group");
	
	inv = all_inventory(environment(me));
	for(i=0;i<sizeof(inv);i++){
		ob = inv[i];
		if ( ob->query("group") != type || ob==me ) continue;
		if (userp(ob) || !ob->is_character()|| ob->is_corpse()) continue;
		
//		message_vision(" looking for a baohu.\n",me);
		
		if (sizeof(pros))
		if (member_array(ob,pros)!=-1) continue;

		if(sizeof(pros))
			pros += ({ ob });
		else
			pros = ({ ob });
//		message_vision(" one baohu is added.\n",me);
	}
	
	me->set_temp("protectors",pros);
//	message_vision(" out baohu.\n",me);
}	
		

//	this function resort the query_enemy(), put highest-hated-player on top, and
//	put lowest one.

object *resort_enemy(object me, string flag) {
	object *enemy,*pc_enemy,*npc_enemy, *total_enemy;
	int i,k;
	
	pc_enemy= ({});
	npc_enemy= ({});
	total_enemy=({});
	
	enemy = me->query_enemy();
	
	npc_enemy=filter_array(enemy,(: !userp($1) :));
	pc_enemy=filter_array(enemy, (: userp($1) :));
	if (sizeof(npc_enemy)>1) npc_enemy=resort(me, npc_enemy);
	if (sizeof(pc_enemy)>1) pc_enemy=resort(me, pc_enemy);

	if (flag=="NPC") return npc_enemy;
	if (flag=="PC")  return pc_enemy;
	if (sizeof(enemy)<=1) return enemy;
	
/*	for(i=0;i<sizeof(pc_enemy);i++){
		message_vision("pc_enemy "+(string)(i)+" is "+pc_enemy[i]->query("name")+" .\n",me);
		}
	for(i=0;i<sizeof(npc_enemy);i++){
		message_vision("npc_enemy "+(string)(i)+" is "+npc_enemy[i]->query("name")+" .\n",me);
		}*/
		
	enemy = resort(me, enemy);
	return enemy;
}	

// 	Sort according to hate_list	

object *resort(object me, object *group){
	int j,k, highest, num;
	object *sorted_group, mem;
	
	sorted_group= ({});
	num= sizeof(group);
	
	for (j=0;j<num;j++) {	
		highest=-100000;
		for (k=0;k<sizeof(group);k++) {
			if (me->query_hate(group[k]) > highest) {
				mem = group[k];
				highest = me->query_hate(mem);
			}
		}
		sorted_group += ({ mem });
		group -= ({ mem });
	}
	return sorted_group;
}	


int is_he_pet(object target){
	if (target->query("possessed")) return 1;
		else return 0;
}


//	this function checks if there are similar group NPCs around.
object accompany(object me) {
	string type;
	object *inv;
	int i;
	
	type = me->query("group");
	if (!type) return 0;
	inv=all_inventory(environment(me));
	for (i=0;i<sizeof(inv);i++) {
		if (inv[i]==me) continue;
		if (inv[i]->query("group")==type) return inv[i];
	}	
	return 0;
}


// Here NPC will use its parry busy skill/. 
void do_defense(object me, int n) {
	object *inv,weapon,newweapon;
	int k; 
	
	switch (n) {
		case 1:	me->map_skill("parry","xiaohun-sword");
			me->map_skill("sword","xiaohun-sword");
			find_weapon(me, "sword");
			if (!me->query_weapon()) {
				me->carry_object("/obj/weapon/sword");
				me->ccommand("wield sword");
			}
			break;
		case 2: me->map_skill("parry","xiaohun-whip");
			me->map_skill("whip","xiaohun-whip");
			find_weapon(me, "whip");
			if (!me->query_weapon()) {
				me->carry_object("/obj/weapon/whip");
				me->ccommand("wield whip");
			}
			break;
		case 3: me->ccommand("unwield all");	me->map_skill("unarmed","yue-strike");break;
		case 4: me->ccommand("unwield all");	me->map_skill("unarmed","lingxi-zhi");break;
		default:break;
		}		
}

void do_remove_defense(object me, int num) {
	
	object weapon,*inv;
	int k;
	string weapon_type,weapon_skill,unarmed_skill;
	
	if (num) {
		unarmed_skill = me->query("skill_type_u");
		me->map_skill("unarmed",unarmed_skill);
		if (me->query("skill_type_w")) {
			if (sscanf(me->query("skill_type_w"),"%s/%s",weapon_type,weapon_skill)==2){
				me->map_skill("parry",weapon_skill);
				me->map_skill(weapon_type,weapon_skill);
				find_weapon(me, weapon_type);
			}
		} else me->ccommand("unwield all");
	}
}


int find_weapon(object me, string type) {
		object weapon, *inv;
		int k;
		
		weapon=me->query_weapon();
		if (!weapon || weapon->query("skill_type")!=type)	{
			inv=all_inventory(me);
			k=sizeof(inv);
			while (k--) {
				if (inv[k]->query("skill_type")==type) {
					me->ccommand("unwield all");
					me->ccommand("wield "+inv[k]->query("id"));
				}
			}
		}
}

int check_weapon(object me, string weapon_type) {
	
	object *inv,weapon;
	int i;
	
	inv=all_inventory(me);
	if (sizeof(inv))
		weapon=filter_array(inv,(: $1->query("skill_type")==$2 :),weapon_type);
	if (weapon)
	if (sizeof(weapon)) return 1;
	
	if (weapon_type == "unarmed")
		return 1;	
		
//	me->command("say I don't have "+weapon_type+"\n");
	return 0;
}


int pickup_weapon(object me, string weapon_type) {
	
	object *inv;
	int k;
	
//	me->command("say in pickup now");
	
	inv=all_inventory(me);
	k=sizeof(inv);
	while (k--){
		if (inv[k]->query("skill_type")==weapon_type)
			me->ccommand("wield "+inv[k]->query("id"));
	}			
	inv=all_inventory(environment(me));
	k=sizeof(inv);
	while (k--){	
		if (inv[k]->query("skill_type")==weapon_type && !inv[k]->query("no_get")) {
			me->ccommand("touch "+ inv[k]->query("id"));
			me->ccommand("get "+inv[k]->query("id"));
			me->ccommand("wield "+inv[k]->query("id"));
			if (!random(2))
				me->ccommand("ya");
			else
				me->ccommand("dance");
			break;
		}
	}
//	command("say end of pickup");
	return 1;
}

void cast_attack(object me) {
	string cast_type;
	cast_type=me->query("cast_attack");
	me->set("mana",me->query("max_mana"));
	me->cast_spell(cast_type);
	me->set("mana",me->query("max_mana"));
	return;
}


void sheet_fight(object me) {

        object obj, soldier;
		int spells;
	
        if( me->query_temp("max_guard")) return;
        message_vision("$N集中精神，祭起三味真火，唿的一声天师符着了起来！\n", me);
     	me->start_busy(1);
        spells = me->query_skill("scratching");
        seteuid(getuid());
        soldier = new("/obj/npc/hell_guard");
        soldier->move(environment(me));
        soldier->invocation(me, spells);
		soldier->set("possessed", me);
		me->add_temp("max_guard",1);
        message_vision(HIB "\n$N躲在$n的背后喊道：给我快杀！\n" NOR, me, soldier );
}


void sq_guard(object me) {
        object obj, soldier;
		int spells;
	
        if( me->query_temp("max_guard")) return;
        message_vision("$N集中精神，祭起三味真火，唿的一声上君符着了起来！\n", me);
     	me->start_busy(1);
        spells = me->query_skill("scratching");
        seteuid(getuid());
        soldier = new("/obj/npc/taoist_guard");
        soldier->move(environment(me));
        soldier->invocation(me, spells);
		soldier->set("possessed", me);
		me->add_temp("max_guard",1);
        message_vision(HIB "\n$N躲在$n的背后喊道：给我快杀！\n" NOR, me, soldier );
		
}

void alchemy_fight(object me, object target, string weapon_name) {
		
	string x;
	object weapon;
			
	if (!me->query_temp("set_alchemy")) {
		switch( random(3)){
			case 0: me->set_temp("set_alchemy","zhui");
				break;
			case 1: me->set_temp("set_alchemy","mirror");
				break;
			default: me->set_temp("set_alchemy","flag");
	
		}
	} 
	
	if (weapon_name != "chain")
		weapon_name = me->query_temp("set_alchemy");		
	x = weapon_name[0..0];
	
	weapon = new("/obj/specials/alchemy/magic/"+weapon_name);
	weapon->move(me);
	
	if(target && objectp(target) && environment(me)==environment(target)) {
		me->ccommand("shoot"+x+" "+ target->get_id());
		me->start_busy(2);
	} else
		destruct(weapon);
		
}

// Healer function, NPC are not grouped, so we write a special function here for them.
/*L20 heal:100内力，300heal,2 sec delay, self-busy 1
L80 mheal: 200内力，600heal,2 sec delay, self-busy 1 : 400k
L120 gheal: 300内力，1500heal,3 sec dealy, self-busy 1: 1.4M
L180 sheal:500 内力，4000heal,4 sec delay, self-busy 1: 4.6M
L190 fheal:500 内力  3000heal, 2 sec delay, self-busy 1 
L200 cheal:600 内力  8000heal, 6 sec delay,self-busy 1	*/
	
void help_friend(object me) {
	object *inv, ob;
	string type;
	int i, j, exp, amount, delay;
		
	type = me->query("group");
	
	exp = me->query("combat_exp");
	if (exp < 1500000)		amount = 600;
	else if (exp < 4500000)	amount = 1500;
	else if (exp < 6400000) amount = 3000;
	else					amount = 5000;
	
	delay = 3;
		
	inv = all_inventory(environment(me));
	
	i=sizeof(inv);
	while (i--) {
		ob = inv[i];
		if (userp(ob) || !ob->is_character() || ob->is_corpse() || !ob->query("group")
			|| ob->query("group")!=type || ob->query_temp("in_heal")) {
			continue;
		}
		
		if (check_health(ob, 40))	continue;
		
		if (me->query_temp("timer/heal_num")>4) {
			if (!random(5))
				me->ccommand("say ＯＯＭ　ＯＯＰ　内力耗尽，现在没法ｈｅａｌ啦，顶住顶住几分钟！！！");
			return;
		}	
		if (ob!=me)
			message_vision(HIY "$N运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"NOR,me,ob);
		else
			message_vision(HIY "$N运起内功，缓缓地将真气在体内流转....\n\n"NOR,me);
		ob->set_temp("in_heal",1);
		me->set_temp("timer/npc_heal",time());
		me->add_temp("timer/heal_num",1);
		call_out("heal_him", delay, me, ob, amount);
		me->start_busy(1);
		return;				
	}
	return;
}


int heal_him(object me, object target, int amount)
{
	if (!objectp(me) || !target || target->is_corpse()) return 1;
	if (me->is_unconcious()) return 1;
	if (!present(target,environment(me))) return 1;		
	if (target!=me)
		message_vision(HIY"$N额头上冒出豆大的汗珠，$n吐出一口瘀血，脸色看起来红润多了。\n"NOR,me,target);
	else 
		message_vision(HIY"$N吐出一口瘀血，脸色看起来红润多了。\n"NOR,me);
	target->receive_fulling("kee", amount);
	target->receive_fulling("sen", amount);
	target->receive_fulling("gin", amount);
	target->delete_temp("in_heal");
	return 1;
}

int call_guard(object me) {

	int oldbusy;
	if (me->query_temp("guard_count")<4
		&& me->query("class")=="official") {
		me->set_skill("strategy",200);
		me->set_skill("leadership",250);
		oldbusy=me->query_busy();
		me->stop_busy();
		me->perform_action("unarmed.npc_alert");
		me->start_busy(oldbusy);
	}
	return 1;
}

int enemy_value(object me, object *all_enm)
{
	int i,val,exp,e_exp;
	int v1, v2, v3, v4,j;
	string class_type;
	object *pc_enemy;
	
	val=0;
	exp = me->query("combat_exp");
		
	i= sizeof(all_enm);
	
	pc_enemy=resort_enemy(me,"PC");
	j = sizeof(pc_enemy);
	v1 = j*5-5;		// 人多
	if (v1<0)	v1 = 0;
			
	while(i--) {
		e_exp = all_enm[i]->query("combat_exp");
		if (e_exp>exp*2)			v2 = 40;	// 超高经验对手，give him my best
		if (e_exp>exp)				v3 = 10;	// 高经验对手
		if (all_enm[i]->is_busy()) 	v4 = 10;	// 利用有利形势
	}
//	message_vision("v1 v2 v3 v4 = " + v1 + " "+ v2 + " " + v3 + " " + v4 + "\n", me);	
	val = v1 + v2 + v3 + v4;
	return val;
}

int enemy_type(object me, object enemy) {
	string class_type;
	int type;
	
	class_type=enemy->query("class");
//	message_vision("this is enemy type "+class_type+".\n",me);	
	switch (class_type) {
	//	this need cut mana by any means, then leave them alone
	case "taoist": if (enemy->query("mana")>200) type =1;
				else type =6;
			break;
	//	this needs cut mana than using special way to kill
	case "lama":	if (enemy->query("mana")>200) type =1;
				else type =3;
			break;
	//	this needs cut force if he is using shield, then put in asap kill
	case "shaolin": if (enemy->query("force")>50) type =2;
				else type =3;
			break;				
	//	this needs to be killed asap purely due to their damage and busy power	
	case "fugui":
	case "legend":
	case "knight":
	case "huashan": type = 4;	break;
	//	this needs to be taken notice
	case "official": type = 5;	break;
	//	these are tricky classes and requires skills to play, so mostly we can 
	//	let them live a while.
	case "wudang":
	case "bonze":
	case "beggar":
	case "yinshi":
	case "shenshui":
	case "swordsman":
	case "assassin":
	case "bat":
	default:	type =6;	break;
	}
//	message_vision("this is enemy return "+(string)(type)+".\n",me);	
	return type;
}	
	
// 	rough estimation, it's hard to say using ratio or value... we just use ratio here :P
string  my_worst_wound(object me)	{
	int kee, gin, sen;
	string wound;
	
	kee = me->query("kee");
	gin = me->query("gin");
	sen = me->query("sen");
	
	if (kee<= gin && kee<= sen)	wound = "kee";
	else if (gin<=kee && gin <= sen) wound = "gin";
	else if (sen<=kee && sen <= gin) wound = "sen";
	else wound = "kee";
		
	return wound;
}	

int check_gks(object target, string type, int percent){
	int health;
	if (target->query(type) < target->query("max_"+type)*percent/100)
		health=0; 
	else 
		health = 1;
	return health;
}