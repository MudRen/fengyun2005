//mimicat@fy4

#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","易筋经");
	set("type","force");
	set("skill_class","shaolin");
	set("effective_level",150);
	set("usage/parry",1);
	set("usage/force",1);
	set("usage/iron-cloth",1);
	set("usage/unarmed",1);
	set("difficulty",250);
	set("damage_level",200);
	set("ic_effect",75);
	set("bounce_ratio",25);
		
	set("absorb_msg",			({
			"眼看$N招式迅急，$n反而向前迎了一步，一圈气墙应念而生将$N挡开。\n",
			"$n双手合十，瞑目静气，一波内劲透体而出将$N挡了回去。\n",
			})
	);
	set("unarmed_parry_msg",	({
			"眼看$N招式迅急，$n反而向前迎了一步，一圈气墙应念而生将$N挡开。\n",
			"$n双手合十，瞑目静气，一波内劲透体而出将$N挡了回去。\n",
			})
	);

	action = ({
			([      "action":
					"$N单掌一按，平和的掌力如春风涨绿，击向$n$l",
			        "parry":                300,
			        "force":		100,
			        "damage_type":  "瘀伤"
			]),
			([      "action":
					"$N展袖一挥，便似有一股力道化成一堵无形高墙压向$n",
			        "parry":                200,
			        "force":		140,
			        "damage_type":  "瘀伤"
			]),
			([ 	"action":
					"$N一掌轻轻拍落，看似寻常，却不知为何挡无可挡，避无可避",
			        "parry":                300,
			        "dodge":		400,
			        "force":		160,
			        "damage_type":  "瘀伤"
			]),
	});
}


int valid_learn(object me) {
	if((string)me->query("class") != "shaolin" ) 
		return notify_fail("易筋经是只有少林高僧才能练的武功。\n");
	if( (int)me->query_skill("zen",1) < (int)me->query_skill("yijinjing",1))
		return notify_fail("你的禅道修为不够，无法领悟更高深的易筋经。\n");
	return ::valid_learn(me);
}

int effective_level(object me)
{
	if (me)
	if (userp(me) && me->query("class") != "shaolin")
		return 75;
		
	return 150;
}

int help(object me)
{
	write(@HELP   
易筋经为少林武功，叛出后有效系数将下降一半
易筋经需要相同等级的禅道为基础

L100『金光云拂』（shield/shieldoff）
运用内力护体，敌人的伤害将首先由内力抵消，（魔法攻击除外）阅读
卷轴后可提高内力消耗与抵消伤害的比例（1:1.5、1:1.8、1:2.0）
注意，在使用金光云拂期间使用其他特技每次至少消耗300点内力。

L150『佛光普照』（foguang）
20分钟使用一次，周围敌人中招后10回合内无法闪避

L200『三藏净身』（sanzang）
15分钟使用一次，瞬间恢复内力最大值的75%
HELP
    );
    return 1;
}

