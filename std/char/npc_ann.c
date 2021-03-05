/*  OK, we need four ranges of SMART_NPCs,

(1) NPC_BAS, 
	0-5M,  menpai skill only, Can have defense-parry, 
(2) NPC_MID, 
	5-10M  + all free-master skills and couple skill. 
	random_allowed in (5-15M);
(3) NPC_ADV, 
	10-15M + advanced basic, + haste/double, + adv-perk. 
(4) NPC_041,
	5M+ free-master skills and couple skill,4.1 skills.
(5) NPC_ANN,
	Free-master skills,couple skills.
	4.1 NPC.	Random abilities,use feat.

		ALL FOR ONE NPC
	
	此NPCLIST和相应的do_choose_attack_5 用以处理41-feat型的NPC引用，
	比原来的NPC要强，有优化，强弱由chat_combat_chance决定。
	对一般NPC建议设置在30以下
	你也可以只引用auto_setup设置而不引用Smart_fight.
	
	5M+ 此表共计 个NPC，1个random NPC。

	------- by Silencer@fy4 workgroup 3/20/2003
	------- by Annie. 11/01/2003
	------- by Annie. 01/01/2004
	
*/

inherit SKILL;

string weapon_unarmed(string weapon_i,string unarmed_i);
int check_health(object target, int percent);
int accompany(object me);
int is_he_pet(object target);
int enemy_type(object enemy);
object *resort_enemy(string flag);
object *resort(object *group);

mapping *npctype = ({
//	Lamaism
	// staff-one
	([      
		"group":		"fighter_w",
		"npc":                	"fengmo-staff",
                "name":			"肉松",
                "class":	      	"lama",
                "gender":		"男性",
                "skill_type_w":	   	"staff/fengmo-staff",
                "skill_type_u":		"bloodystrike",
				"u_adjust":			60,
                "skill_type_d":		"fengyu-piaoxiang",
				"d_adjust":			50,
                "unarmed":		"bloodystrike",
                "staff":		"fengmo-staff",
                "force":		"bolomiduo",
                "parry":		"fengmo-staff",
                "dodge":		"fengyu-piaoxiang",
                "move":			"fengyu-piaoxiang",
                "iron-cloth":	"jin-gang",
				"others2":		"lamaism",

		"perform_weapon_attack":"lama/staff/fengmo-staff/xianglong",
		"perform_weapon_attack2":"lama/staff/fengmo-staff/fuhu",
		"perform_unarmed_attack":	"lama/unarmed/bloodystrike/yinqi",     
		"perform_busy_u":	"lama/unarmed/bloodystrike/fofawubian",     
		"perform_busy_d":	"lama/dodge/fengyu-piaoxiang/zonghengsihai",     
        ]), 
	// kwan-yin one

//	Legend
	// deisword
	([      
		"group":		"fighter_w",
		"npc":                	"diesword",
                "name":			"蝶恋花",
                "class":	      	"legend",
                "gender":		"女性",
                "skill_type_w":	   	"sword/diesword",
                "skill_type_u":		"qidaoforce",
				"u_adjust":			40,
                "skill_type_d":		"fall-steps",
				"d_adjust":			40,
                "unarmed":		"qidaoforce",
                "sword":		"diesword",
                "force":		"qidaoforce",
                "parry":		"diesword" ,
                "dodge":		"fengyu-piaoxiang",
                "move":			"fengyu-piaoxiang",
				"perception":	"six-sense",
                "iron-cloth":	"xisui",
				"others1":		"meihua-shou",
   		"set_1":		 "宿命A/风云_蝴蝶",
		"perform_weapon_attack":"legend/sword/diesword/caidiekuangwu",
		"perform_busy_u":	"legend/unarmed/meihua-shou/meihai",     
		"perform_busy_d":	"legend/dodge/fall-steps/luoyeqiufeng",     
        ]), 

	// shortsong
	([      
		"group":		"fighter_w",
		"npc":                	"shortsong-blade",
                "name":			"陌上桑",
                "class":	      	"legend",
                "gender":		"男性",
                "skill_type_w":	   	"blade/shortsong-blade",
                "skill_type_u":		"qidaoforce",
				"u_adjust":			40,
                "skill_type_d":		"fall-steps",
				"d_adjust":			40,
                "unarmed":		"qidaoforce",
                "blade":		"shortsong-blade",
                "force":		"qidaoforce",
                "parry":		"diesword" ,
                "dodge":		"fengyu-piaoxiang",
                "move":			"fengyu-piaoxiang",
				"perception":	"six-sense",
                "iron-cloth":	"xisui",
				"others1":		"meihua-shou",
				"others2":		"xiaodao",
				"others3":		"dormancy",

		"perform_weapon_attack":"legend/blade/shortsong-blade/duangechangmeng",
		"perform_busy_u":	"legend/unarmed/meihua-shou/meihai",     
		"perform_busy_d":	"legend/dodge/fall-steps/luoyeqiufeng",     
        ]), 

//	Official
	// Mad-huwei tatics 
	([      
		"group":		"fighter_w",
		"npc":                	"leadership",
                "name":			"万骨枯",
                "class":	      	"official",
                "gender":		"男性",
                "skill_type_w":	   	"spear/yue-spear",
                "skill_type_u":		"changquan",
				"u_adjust":			100,
                "skill_type_d":		"puti-steps",
				"d_adjust":			50,
                "unarmed":		"changquan",
                "spear":		"yue-spear",
                "force":		"manjianghong",
                "parry":		"yue-spear" ,
                "dodge":		"puti-steps",
                "move":			"puti-steps",
                "iron-cloth":	"xisui",
				"others1":		"leadership",
				"others2":		"strategy",
				"set_1":		"annie/npc-zhtx7hit",
		"perform_weapon_attack":"official/spear/yue-spear/zonghengtianxia",
		"perform_weapon_attack2":"official/spear/yue-spear/juechufengsheng",
		"perform_unarmed_attack":"official/unarmed/changquan/yuhuan",
		"perform_busy_d":	"official/dodge/fall-steps/luoyeqiufeng",     
        ]), 

});


mapping query_npc(string group_name, string npc_name, int special){
	
	int total,i,x,n,m;
	string npc;
	
	total=sizeof(npctype);
	n=1;
	m=total;
	
	if (npc_name=="random") {
		if (group_name=="random") x=random(total);	
		else while(n) {
			x=random(total);
			if (npctype[x]["group"]==group_name) n=0;
			}
	} else {
		while (m--) {
			if (npctype[m]["npc"]==npc_name) {
				x=m; break;		
			}
		} 
	}	
	return npctype[x];
}



int total_npc(){
	return sizeof(npctype);
}

mapping *npclist(){
	return npctype;
}