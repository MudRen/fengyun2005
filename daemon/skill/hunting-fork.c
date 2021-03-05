// silencer@fy4

#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","追命索魂叉");
	set("type","fork");
	set("difficulty",200);
	set("effective_level",150);
	set("usage/fork",1);
	set("usage/parry",1);
	set("skill_class","npc");
	set("parry_msg",			({
			"结果$n用手中的$v格开了$N的招式。\n",
			"$n挥动$v，在身前画了个半圆，正好挡开$N的攻势。\n",
			"$n丝毫不为所动，轻描淡写地挥叉一刺，逼得$N回手自防。\n",
			"$n将$v舞得风雨不透，$N无奈之下只好换招。\n",
			"$n一抖手中$v，在$N兵器上一按，借势纵开数丈。\n",
			})
	);
	set("unarmed_parry_msg",			({
			"结果$n用手中的$v格开了$N的招式。\n",
			"$n挥动$v，在身前画了个半圆，正好挡开$N的攻势。\n",
			"$n丝毫不为所动，轻描淡写地挥叉一刺，逼得$N回手自防。\n",
			"$n将$v舞得风雨不透，$N无奈之下只好换招。\n",
			"$n一抖手中$v，在$N兵器上一按，借势纵开数丈。\n",
			})
	);
	action = ({
			([      "action":               
					"$N不顾自身，手中$w连连刺向$n",
			        "damage":               40,
			        "dodge":                40,
			        "parry":                40,
			        "damage_type":  "刺伤"
			]),
			([      "action":               
					"$N一声清啸，但见漫天叉影，向$n铺天盖地地刺去",
			        "damage":               30,
			        "dodge":                -100,
			        "parry":                -100,
			        "damage_type":  "刺伤"
			]),
			([      "action":           
					"$N横过手中$w，使出「十年生死两茫茫」，刺向$n$l",
			        "damage":               40,
			        "dodge":                -10,
			        "parry":                -40,
			        "damage_type":  "刺伤"
			]),
			([      "action":               
					"$N使出一招「魂萦梦断」，$w一挺刺向$n$l",
			        "damage":               50,
			        "dodge":                -10,
			        "parry":                -40,
			        "damage_type":  "刺伤"
			]),
	});
}

int valid_learn(object me) {
	if(!::valid_learn(me)) {
		return 0;
	}
	
	if((int)me->query("str") + (int)me->query("max_force") / 10 < 35) {
		return notify_fail("你的膂力还不够，也许该练一练内力来增强力量。\n");
	}
	return 1;
}


int practice_skill(object me)
{
	
	if ((int)me->query("force") < 20) {
		return notify_fail("你的内力不够练追命索魂叉。\n");
	}
	if(!::practice_skill(me)) {
		return 0;
	}
	me->add("force", -10);
	return 1;
}
