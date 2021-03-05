// human.c 人类

// A normal human is at least 40 kg weight
#define BASE_WEIGHT 40000

inherit F_DBASE;
inherit F_LEVEL;

void	race_basic_setup(object ob);	// To make it easy, this function is the same for all races.

mapping *combat_action = ({
	([	"action":		"$N挥拳攻击$n的$l",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N往$n的$l一抓",
		"damage_type":	"抓伤",
	]),
	([	"action":		"$N往$n的$l狠狠地踢了一脚",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N提起拳头往$n的$l捶去",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N对准$n的$l用力挥出一拳",
		"damage_type":	"瘀伤",
	]),
});

void create() {
	seteuid(getuid());
	set("unit", "位");
	set("gender", "男性");
	set("can_speak", 1);
	set("attitude", "peaceful");
	set("limbs", ({
		"头部",	"颈部",	"胸口",	"後心",	"左肩",	"右肩",	"左臂",
		"右臂",	"左手",	"右手",	"腰间",	"小腹",	"左腿",	"右腿",
		"左脚",	"右脚", "左肋", "右肋", "前胸", "后背", "眉心",
		"后腰", "后颈", "左胯", "右胯", "后脑", "左眼", "右眼",
		"左颊", "右颊"
	}) );
}

void setup_human(object ob) {
		
	mapping my;
	my = ob->query_entire_dbase();
	
	race_basic_setup(ob);
	
	if (!userp(ob)) {
		if(undefinedp(my["national"])) my["national"] = "汉族";
		if(undefinedp(my["age"])) my["age"] = 15 + random(50); 
		if(undefinedp(my["per"])) my["per"] = 15 + random(20);
		if(undefinedp(my["score"])) my["score"] = random(500);
	}
	
	ob->set_default_object(__FILE__);
	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));	
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 200);
}


mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}


void	race_basic_setup(object ob)
{
	mapping my;
	int combat_exp/*, bonus*/, npc_str, npc_att;
	int n, npc_force, npc_f_factor/*, temp_damage*/;
	int *extra_d, num,tough;
	mapping extra = ([]);
			
	my = ob->query_entire_dbase();
			
//	Setting up char EXP as well as corresponding level
	if (!my["combat_exp"] || my["combat_exp"]< 2000) my["combat_exp"] = 2000;
	combat_exp = my["combat_exp"];
	my["level"] = F_LEVEL->get_level(combat_exp);
		
// 	Setting NPC default attributes, the bonus will be added to the base
//	... Remember the new PLAYER == !userp(ob) before the first setup !
	if (!userp(ob)) {
		n= combat_exp/100000;	// 10
	//	<100k, NPC is in fact weaker than PC,
		if (combat_exp<100000) {
			npc_str = 10 + random(5); 			
			npc_att = 10 + random(5);    			
			npc_force = (combat_exp <= 10000)? 0: combat_exp*250/100000;	// 250 
			npc_f_factor = npc_force/20;
		}	
		
	//	100k-1M, PC should have finished 45-100force, and 100-120 unarmed. 
		else if (n<=10 && n>=1) {
			npc_str= 13 + n*12/10 + random(n); 	// 11-23 (+10)
			npc_att= 10 + n*12/10 + random(n/2);  	// 11-22 (+5).
			npc_force = 200 + 50*n ;				// 250-700
			npc_f_factor = 20 + n*3 + random(n);	// 23 - 50 +(10)				
		}
			
	//	1-3M, PC should have 160 unarmed, 120-170 force, and full menpai force
		else if (n<=30 && n>10) {
			npc_force = 600 + n*20;								// 800-1200 full guyupai etc
			npc_str = 34 + (n-10)/2 + n/10 + random(n-10)/4;	// 35- 47 (+5)
			npc_att=  20 + (n-10)/2 + random(n-10)/2;			// 20 -30 (+10)
			npc_f_factor = 40 + n + random(10);					// 50 -80 (+9)			
		}
		
	//	3-5M, PC should have 180 unarmed, 200 force, and full menpai force
	//	NPC starts to be better than PC.	
		else if (n<=50 && n>30) {
			npc_force = 1200+ n*7;					// full guyupai etc 1410-1550
			npc_str = 45 + n/10 +random(n-30)/4;	// 48-50 (+5)
			npc_att=  35 + random(n-30)/2;			// 35 	 (+10)
			npc_f_factor = 90 + n/6 + random(n);	// 95 - 99 (+50)
			
		}
		
	//	5M-10M NPC will have longer gin/kee/sen, this is by design
		else if (n>50 && n< 120) {							// count up to 10M for PCs below
			npc_force =  500 + 20*n;						// 1500 - 2900
			npc_str= 45 + (n-50)/5 + random(n-50)/7 + n/10;	// 50-70 + random(10)
			npc_att= 35 + (n-50)/5 + random(n-50)/5;		// 35-45 + random(15)
			npc_f_factor = 100 + random(n-50);				// 100 (+50)
	
	//	此类ＮＰＣ最好就是单独在文件里定义了		
		} else {
			npc_force =  3000;			
			npc_str= 60 + random (10) + n/10;			// 70+
			npc_att= 45 + random(30);					// 45 +30
			npc_f_factor = 140 + random(30);			// 140 +30
			
		}
		
	
//	Adding attributes bonus to NPCs

		if(npc_f_factor)
		if(undefinedp(my["force_factor"])) 
			my["force_factor"] = npc_f_factor> 150 ? 150 : npc_f_factor;
		
		if(undefinedp(my["str"])) my["str"] = npc_str;
		
		if(undefinedp(my["con"])) my["con"] = npc_att+1;
		if(undefinedp(my["int"])) my["int"] = npc_att;
		if(undefinedp(my["cps"])) my["cps"] = npc_att;
		if(undefinedp(my["kar"])) my["kar"] = npc_att;
		if(undefinedp(my["agi"])) my["agi"] = npc_att;
		
		if(undefinedp(my["cor"])) my["cor"] = npc_att;
		if(undefinedp(my["dur"])) my["dur"] = npc_att;
		if(undefinedp(my["spi"])) my["spi"] = npc_att;
		if(undefinedp(my["fle"])) my["fle"] = npc_att;
		if(undefinedp(my["tol"])) my["tol"] = npc_att;
		
		if(undefinedp(my["max_force"])) my["max_force"]= npc_force;
		if(undefinedp(my["force"])) my["force"]= npc_force;
		if(undefinedp(my["max_mana"])) my["max_mana"]= npc_force;
		if(undefinedp(my["mana"])) my["mana"]= npc_force;
		if(undefinedp(my["max_atman"])) my["max_atman"]= npc_force;
		if(undefinedp(my["atman"])) my["atman"]= npc_force;		
		
		if(undefinedp(my["score"])) my["score"] = random(90000);
	
	}
		
//	Auto calculate PC's force/mana/atman， 所有的额外都记录在Add_force/Add_mana/Add_atman三个map中。
//  	一个新的增加Force的地方在/d/bashan/npc/jat。
//  	此外，Ability也会提供额外的AMF。
//	why we put it in race_basic ... because someday we might make a 鸟人兽人龙人。。。

	if (userp(ob)) {
		my["max_force"] = ob->query_skill("force",1) * 5 + ob->query_skill("force");
		my["max_atman"]=ob->query_skill("magic",1) * 5 + ob->query_skill("magic");
		my["max_mana"]=ob->query_skill("spells",1) * 5 + ob->query_skill("spells");
		
		if ( extra = ob->query("Add_force")) {
			num = sizeof(extra);
			extra_d = values(extra);
			while (num--) {
				my["max_force"] += extra_d[num];
			}	
		}
		if ( extra = ob->query("Add_atman")) {
			num = sizeof(extra);
			extra_d = values(extra);
			while (num--) {
				my["max_atman"] += extra_d[num];
			}
		}
		if ( extra = ob->query("Add_mana")) {
			num = sizeof(extra);
			extra_d = values(extra);
			while (num--) {
				my["max_mana"] += extra_d[num];
			}
		}
	}


//	Setting NPC and PC Gin/Kee/Sen,
	
	if (!userp(ob))
	{
		tough = ob->query("toughness");
		if ((my["level"]>80 && !tough)) {
			tough = my["level"] + 20;
			my["innate_tough"] = tough;
		}
	} 	
	
	if(userp(ob) || undefinedp(my["max_gin"])) {
		my["max_gin"] = my["int"]* my["int"] + my["con"]* my["con"] /4;
		
		if(my["max_atman"] > 0) {
			my["max_gin"] += my["max_atman"] * 2 ;
		} else
			my["max_atman"] = 0;
	
		if (my["class"]!= "moon" || !userp(ob))
			my["max_gin"] += ( my["int"] + my["con"]/2) *  my["level"] * my["level"] /300;
		else
			my["max_gin"] += ( my["int"] + my["con"]/2) *  my["level"] * my["level"] /600;
				
		my["max_gin"] += F_ABILITY->check_ability(ob,"gin",0) * 100;
		my["max_gin"] += F_ABILITY->check_ability(ob,"gin",3) * 100;
				
		if ( extra = ob->query("Add_gin")) {
			num = sizeof(extra);
			extra_d = values(extra);
			while (num--) {
				my["max_gin"] += extra_d[num];
			}
		}
		
		if (!userp(ob) && tough)	my["max_gin"] = my["max_gin"] * tough /100;
		
	}
	
	if(userp(ob) || undefinedp(my["max_sen"])) {
		my["max_sen"] = my["int"]* my["int"] + my["con"]* my["con"] /4;
		
		if(my["max_mana"] > 0) {
			my["max_sen"] += my["max_mana"] * 2 ;
		} else
			my["max_mana"] = 0;
	
		if (my["class"]!= "moon" || !userp(ob))
			my["max_sen"] += ( my["int"] + my["con"]/2) *  my["level"] * my["level"] /300;
		else
			my["max_sen"] += ( my["int"] + my["con"]/2) *  my["level"] * my["level"] /600;
					
		my["max_sen"] += F_ABILITY->check_ability(ob,"sen",0) * 100;
		my["max_sen"] += F_ABILITY->check_ability(ob,"sen",3) * 100;
		
		if ( extra = ob->query("Add_sen")) {
			num = sizeof(extra);
			extra_d = values(extra);
			while (num--) {
				my["max_sen"] += extra_d[num];
			}
		}
		
		if (!userp(ob) && tough) 	my["max_sen"] = my["max_sen"] * tough /100;
		
	}
	
	if(userp(ob) || undefinedp(my["max_kee"])) {
		
		my["max_kee"] = my["con"]*my["con"] + my["str"] * my["str"]/4;
		
		if(my["max_force"] > 0) {
			my["max_kee"] += my["max_force"] * 2;
		} else
			my["max_force"] = 0;
		
		if (my["class"]!= "moon" || !userp(ob))
			my["max_kee"] += ( my["con"] + my["str"]/2) *  my["level"] * my["level"] /300;
		else
			my["max_kee"] += ( my["con"] + my["str"]/2) *  my["level"] * my["level"] /600;

		my["max_kee"] += F_ABILITY->check_ability(ob,"kee",0) * 100;
		my["max_kee"] += F_ABILITY->check_ability(ob,"kee",3) * 100;
		
		if ( extra = ob->query("Add_kee")) {
			num = sizeof(extra);
			extra_d = values(extra);
			while (num--) {
				my["max_kee"] += extra_d[num];
			}
		}
				
		if (!userp(ob) && tough)	my["max_kee"] = my["max_kee"] * tough /100;
			
	}
	
	// 只加 force/atman/mana
		if (userp(ob)) {
			if ( extra = ob->query("Add_force_only")) {
				num = sizeof(extra);
				extra_d = values(extra);
				while (num--) {
					my["max_force"] += extra_d[num];
				}	
			}
			if ( extra = ob->query("Add_atman_only")) {
				num = sizeof(extra);
				extra_d = values(extra);
				while (num--) {
					my["max_atman"] += extra_d[num];
				}
			}
			if ( extra = ob->query("Add_mana_only")) {
				num = sizeof(extra);
				extra_d = values(extra);
				while (num--) {
					my["max_mana"] += extra_d[num];
				}
			}
	}
	
	return;
}