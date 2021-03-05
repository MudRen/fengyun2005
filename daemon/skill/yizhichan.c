//mimicat@fy4
#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","一指禅");
	set("type","unarmed");
	set("skill_class","shaolin");
	set("effective_level",210);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("difficulty",200);
	set("practice_limit",1);
	
	set("parry_msg",			({
			"然而$n轮指虚点，锐利的指风将$N逼退。\n",
			"$n身子一晃之间，已抢到$N对面，虚托一掌，一指点向$N肋下迫得$N闪身后退 。\n",
			})
	);
	set("unarmed_parry_msg",	({
			"然而$n轮指虚点，锐利的指风将$N逼退。\n",
			"$n身子一晃之间，已抢到$N对面，虚托一掌，一指点向$N肋下迫得$N闪身后退 。\n",
			})
	);
	action = ({
			([      "action":               
			"$N斜挥食指，急点两下，隐隐然有一股内力发出击向$n$l ",
			        "dodge":                90,
			        "parry":                150,
			        "force":                100,
			        "damage_type":  "刺伤",
			        "weapon":               "气劲",
			]),
			([      "action":               
			"$N一指点出，大开大阖，气派宏伟，以石破天惊、风雨大至之势刺向$n$l ",
			        "dodge":                140,
			        "parry":                210,
			        "force":                190,
			        "damage_type":  "刺伤",
			        "weapon":               "气劲",
			]),
			([      "action":               
			"只见$N弓步前冲，右手乘势单指直点，激起的气流发出“嗤嗤”的响声 ",
			        "dodge":                230,
			        "parry":                170,
			        "force":                220,
			        "damage_type":  "刺伤",
			        "weapon":               "气劲",
			]),
			([      "action":               
			"$N伸指向前一捺，一股凌厉的指力射将过去，点向$n$l ",
			        "dodge":                380,
			        "parry":                360,
			        "force":                390,
			        "damage_type":  "刺伤",
			        "weapon":               "气劲",
			]),
	});
}

int valid_learn(object me) {
	
	if(!::valid_learn(me)) {
		return 0;
	}
	if((string)me->query("class") != "shaolin" ) 
		return notify_fail("一指禅是只有少林高僧才能练的武功。\n");
	
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    
	int chance, damage;
	if( !userp(victim) ) {
		victim->add_hate(me, me->query_skill("zen",1)*3);
    }
	chance = 30 + F_ABILITY->check_ability(me, "3_yzc_add", 3) * 2;
	if ( random (100) < chance ) {
		damage = COMBAT_D->magic_modifier(me, victim, "sen", damage_bonus/3+random(damage_bonus/2));     
		victim->receive_damage("sen",damage, me);
		return HIB"$n只觉心口刺痛，无形间已被$N气劲所伤！\n"NOR;
	}
	return 0;
}


int help(object me)
{
	write(@HELP   
攻击时有30%几率造成敌人的心神损伤。
击中敌人时产生额外的仇恨（禅道等级*3）
通过门派技能增强可以增加到50%几率。

L100『参合』（canhe）
攻击对手气血，自我忙乱2回合
额外攻击力=一指禅等级
额外伤害力=有效拳脚等级

L140『和风』（hefeng）
吸引对手攻击，每10分钟使用一次。
对手清除所有仇恨，对使用特技者仇恨增加。
				
L150『破气』（poqi）
卸除对手的额外加力，每10分钟使用一次。
成功后维持60秒。

L170『拈花』（nianhua）
攻击对手心神，只能在对手心神高于一半时使用，
自我忙乱3回合。
该攻击的成功率仅与双方相对经验值相关
HELP
    );
    return 1;
}
