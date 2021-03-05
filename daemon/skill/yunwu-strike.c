// yunwu-strike.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;

void setup() {
	set("name","云雾掌法");
	set("practice_limit",100);
	set("usage/parry",1);
	set("type","unarmed");
	set("effective_level",150);
	set("difficulty",200);
	set("usage/unarmed",1);
	set("skill_class","huangshan");
	set("parry_msg",			({
			"$n使出一招「雾锁苍山」，贴身急进，将$N的$w牢牢锁住。\n",
			"$n掌势层层，一招「云开雾散」拍向$N拿着$w的手。\n",
			"$n使出「云海茫茫」，双掌一划，引偏了$N的$w。\n",
			})
	);
	set("unarmed_parry_msg",	({
			"$n双掌一翻，一招「天高云淡」虚空拍出一掌，逼得$N撤招自保。\n",
			"$n施展出「白云浮玉」，轻描淡写的化解了$N的攻势。\n",
			})
	);
	action = ({
			([      "action":               
					"$N使出一招「乌云蔽日」，身形一纵，双掌自上而下，拍向$n的$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                100,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
					"$N使出一招「云映晴空」，双掌一分，直切$n的$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                 70,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
					"$N使出云雾掌法中的「雾霭迷蒙」，掌掌不离$n的$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                50,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
					"$N双掌一错，一掌虚晃，使出「云雾山中」，对准$n的$l单掌斜劈",
			        "dodge":                100,
			        "parry":                100,
			        "force":                150,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
					"$N身形稳稳站定，双掌齐挥，使出「青山云海」，袭向$n$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                140,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
					"$N使出「旭日浮云」，急挥双掌，从空中当头向$n的$l出掌攻击",
			        "dodge":                200,
			        "parry":                200,
			        "force":                150,
			        "damage_type":  "瘀伤"
			]),
	});
}		

int valid_learn(object me)
{
	object ob;
	if(!::valid_learn(me)) {
		return 0;
	}
	if (me->query("class")!="huangshan")
		return notify_fail("你还不能学这门武功。\n");
	if( (int)me->query("max_force") < 500 ) {
	        return notify_fail("你的内力不够，没有办法练云雾掌法。\n");
	}
	 return 1;
}

int practice_skill(object me)
{
        return notify_fail("云雾掌法只能学的。\n");
}
