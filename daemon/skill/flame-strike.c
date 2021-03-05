inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","烈焰寒冰掌");
	set("type","unarmed");
	set("effective_level",200);
	set("difficulty",200);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("damage_level",250);
	set("practice_limit",100);
	set("skill_class","assassin");
	
	set("parry_msg",			({
			"$n化掌为刀，一招「火上浇油」急切$N拿着$w的手。\n",
			"$n双掌交错，使出一招「趁热打铁」，「啪」的一声将$N的$w夹在双掌之间。\n",
			"$n略一转身，一招「滴水成冰」拍向$N拿着$w的手。\n",
			"$n使出「炎」字诀，双掌一划，引偏了$N的$w。\n",
		})
	);
	set("unarmed_parry_msg", 	({
			"$n步走七星，一招「反客为主」虚空拍出十三掌，逼得$N撤招自保。\n",
			"$n化掌为指，一招「似火非火」反点$N的周身要穴。\n",
			"$n施展出「掌指双飞」，轻描淡写的化解了$N的攻势。\n",
		})
	);
	
	action = ({
			([      "action":               
			"$N使出一招「火中取栗」，右掌一翻，从左肘后穿出击向$n的$l",
			        "dodge":                130,
			        "parry":                100,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
			"$N使出一招「如火似荼」，左掌连拍三次，化虚为实击向$n的$l",
			        "dodge":                100,
			        "parry":                230,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
			"$N使出「二郎担山」，如鬼魅般欺至$n身前，一掌拍向$n的$l",
			        "dodge":                130,
			        "parry":                210,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
			"$N双掌一错，「怀中抱月」，一股极其阴寒的功力扑向$n的$l",
			        "dodge":                220,
			        "parry":                230,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
			"$N左掌画了个圈圈，右掌推出，一招「冰魄寒光」击向$n$l",
			        "dodge":                120,
			        "parry":                130,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
			"$N使出「寒星点点」，身形散作七处同时向$n的$l出掌攻击",
			        "dodge":                170,
			        "parry":                110,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
			"$N吐气扬声，一招「冰火九重天」双掌并力推出",
			        "dodge":                170,
			        "parry":                240,
			        "damage_type":  "瘀伤"
			]),
	});
}

int valid_learn(object me) {
	if(!::valid_learn(me)){
		return 0;
	}
	if((int)me->query_skill("jingxing", 1)+30 < (int)me->query_skill("flame-strike", 1) ) {
		return notify_fail("你的静行心法火候不足，无法练烈焰寒冰掌。\n");
	}
	if((int)me->query("max_force") < 100 ) {
		return notify_fail("你的内力太弱，无法练烈焰寒冰掌。\n");
	}
	return 1;
}


//	200+150 = 350 extra
mixed hit_ob(object me, object victim, int damage_bonus)
{
	int damage, lvl;
	
	if (me->query("class")!="assassin") return;
	lvl= me->query_skill("flame-strike",1);
	
	damage = lvl + F_LEVEL->get_level(me->query("combat_exp"));
	
	damage = COMBAT_D->magic_modifier( me, victim, "kee", damage/2 + random(damage/2));
	victim->receive_wound("kee", damage ,me);
	if (random(2)) 
		return RED "$N掌中扑出一股猩红的热焰，燎烤着$n的全身。\n" NOR;
	else	
		return WHT "$N掌中透出丝丝寒气,$n如堕冰窟。\n" NOR;
}

/*
mapping query_action(object me, object weapon) {
	mapping act=([]);
	if(sizeof(action) > 0) {
		if (random(2))
			act["action"] = RED + action[random(sizeof(action))]["action"] + NOR;
		else 
			act["action"] = WHT + action[random(sizeof(action))]["action"] + NOR;
	}
	return act; 
}*/
