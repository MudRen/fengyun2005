// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// huanhua-sword.c

inherit SKILL;
void setup() {
	set("name","秋水剑法");
	set("type","sword");
	set("difficulty",200);
	set("usage/sword",1);
	set("usage/parry",1);
	set("effective_level",250);
	set("skill_class","npc");
	set("parry_msg", ({
		"$n一招[海天一线]慢慢地将手中的$v横立于身前，强烈的剑风将$N逼得连退几步。\n",
	}) );

	set("unarmed_parry_msg", ({
        "$n手中的$v慢慢地挥出，剧烈颤动的剑锋封向$N。\n",
	}) );
	
	action = ({
		([	"action":		"$N手中的$w使出[长虹贯日]，剑锋带出裂锦般的声音，万马奔腾般地点向$n的$l",
			"dodge":		200,
			"parry" :		200,
			"force":		400,
	                "damage":               200,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N手中的$w狂舞，[烈炎龙沙]象暴风中的滚沙，裹向$n的$l",
	                "dodge":		100,
			"parry" :		200,
	                "damage":               200,
			"force":		300,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N手中的$w悠如流云，忽聚忽散地砍向$n的$l",
			"dodge":		30,
			"parry" :		100,
			"force":		100,
	                "damage":               200,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N晃动手中的$w，剑光忽隐忽现，象秋风中的落叶，一剑[天女散花]散向$n的$l",
			"dodge":		200,
			"parry" :		110,
			"force":		100,
	                "damage":               200,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N聚起全身的功力，手中的$w象刺骨寒风般割向$n",
			"dodge":		100,
			"parry" :		400,
			"force":		200,
			"damage":		200,
			"damage_type":	"割伤"
		]),
	});
}
