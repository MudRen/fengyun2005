// 神话世界·西游记·版本４．５０
// 风波十二叉 fengbo-cha.c
// 9-17-97 pickle
//	--- modified by Silencer@fy4 for fy skills.

inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","风波十二叉");
	set("type","fork");
	set("usage/fork",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("difficulty",200);
	set("skill_class","npc");
	set("unarmed_parry_msg",({
		"$n以手中$W画了个圆弧，将周身破绽都封死了。\n",
		"$n不避不让，挺$W在身前空处连次数叉。这招看来平平无奇，却于平淡中将$N的攻势封死了。\n",
		"$n挥动$W，在身前画了个半圆，正好挡开$N的攻势。\n",
		"$n丝毫不为所动，轻描淡写地挥叉一刺，逼得$N回手自防。\n",
		"$n连挥手中$W，只听叮叮当当一阵密响，终于将$N挡了回去。\n",
		"$n不顾自身，手中$W连连刺向$N。这围魏救赵之计果然奏效，将$N逼了回去。\n",
	})
	);
		
	action = ({
			([      "action" : "$N手中$w在身前试探了数叉，叉尖所指之处，正是$n的$l",
			        "dodge" : 200,
			        "parry" : 100,
			        "damage" : 90,
			        "damage_type" : "刺伤",
			]),
			([      "action" : "$N身形不动，手中$w拍向$n的$l。似窒滞生硬，但毫不拖泥带水，攻势甚是凌厉",
			        "dodge" : 150,
			        "parry" : 150,
			        "damage" : 250,
			        "damage_type" : "刺伤",
			]),
			([      "action" : "$N一声清啸，但见漫天叉影，化作朵朵白云，扰得$n眼花缭乱",
			        "dodge" : 120,
			        "parry" : 120,
			        "damage" :220,
			        "damage_type" : "刺伤",
			]),
			([      "action" : "$N手中$w一颤，迅捷无比地在$n上下左右各刺一叉",
			        "dodge" : 80,
			        "parry" : 80,
			        "damage" : 110,
			        "damage_type" : "刺伤",
			]),
			([      "action" : "$N朗笑一声，手中$w泛出重重暗影，好似一阵阵浓雾，推向$n\n",
			        "dodge" : 70,
			        "parry" : 70,
			        "damage" : 90,
			        "damage_type" : "刺伤",
			]),
			([      "action" : "$N怒叱一声，手中$w其快无比地在$n身前来来回回连划七划",
			        "dodge" : 120,
			        "parry" : 120,
			        "damage" : 220,
			        "damage_type" : "刺伤",
			]),
			([      "action" : "$N突然脸上青气一显，叉上嗡嗡之声大做，狂风骤雨般连攻五叉",
			        "dodge" : 120,
			        "parry" : 120,
			        "damage" : 220,
			        "damage_type" : "刺伤",
			]),
	});
}
