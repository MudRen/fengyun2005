// cloudstaff.c

inherit SKILL;

void setup() {
	set("name","白云杖法");
	set("type","staff");
	set("effective_level",200);
	set("usage/staff",1);
	set("usage/parry",1);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","bonze");
	set("parry_msg",		({
			"$n横持$v，一招『白云出岫』，杖端化出无数个圆圈，凝滞沉重，把$N挡在外围。\n",
			"$n双手合十，躬身一招『宛似云门』，$v自肘弯飞出，将$N的$w荡开。\n",
			"$n全身滚倒，$v盘地横飞，突出一招『与云俱开』，杖风把自身裹得滴水不透。\n",
			})
	);

	set("unarmed_parry_msg",	({
			"$n横持$v，一招『白云出岫』，杖端化出无数个圆圈，凝滞沉重，把$N挡在外围。\n",
			"$n全身滚倒，$v盘地横飞，突出一招『与云俱开』，杖风把自身裹得滴水不透。\n",
			})
	);
	
	action = ({
			([      "action":               
		"$N使一招『天光乍现』，手中$w东一击，西一扫，如随意漂浮的游云，轻描淡写地击向$n",
			        "damage":               40,
			        "dodge":                40,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "砸伤"
			]),
			([      "action":               
		"$N挥动$w，内力震荡，仿佛被撕裂了的云块，喷射着，迷漫着，连绵不尽地攻向$n",
			        "damage":               40,
			        "dodge":                20,
			        "parry":                60,
			        "post_action":  "bash_weapon",
			        "damage_type":  "砸伤"
			]),
			([      "action":           
		"$N一点手中$w，如被晨风徐徐吹送的一缕白云，轻纱一样击向$n$l",
			        "damage":               40,
			        "dodge":                10,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "砸伤"
			]),
			([      "action":               
		"$N舞动$w，忽有风雷之声，漫天杖影凝成一堵云的高墙，缓缓地，无可阻挡地撞向$n",
			        "damage":               40,
			        "dodge":                10,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "砸伤"
			]),
	});
}


int help(object me)
{
	write(@HELP   
『龙现于野』〔longxianyuye〕
L0：	一击，自我忙乱2轮
Ｌ120：	二击，自我忙乱3轮
Ｌ160：	三连击，自我忙乱3轮
额外攻击力=白云杖法等级
额外伤害力=白云杖法等级

HELP
    );
    return 1;
}
