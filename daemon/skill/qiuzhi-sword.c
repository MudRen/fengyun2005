// libie-sword.c
#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","虬枝剑式");
	set("type","sword");
	set("difficulty",230);
	set("usage/sword",1);
	set("usage/parry",1);
	set("skill_class","npc");
	set("effective_level",230);
	set("unarmed_parry_msg",({
		"$n手中$v一圈，一招“寒梅吐蕊”刚好封住$N的攻势。\n",
		"$n一招“乍惊梅多”手中的$v攻向$N必救之处。\n",	
		"$n手中的$v一抖，挽出一片剑花，一招“梅林花落”将$N全身围住。\n",
					})	
	);
	action = ({
        ([      "action":               
"$N手中$w一圈，然后猛然点向$n的$l，正是“虬枝剑式”中的“寒梅吐蕊”",
                "dodge":                40,
                "damage":               140,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N左手一弹，手中$w突地一探，方向却是斜掠而上，活像一枝梅几乍然横出，
攻向$n的$l。正是绝学“冷梅拂面”",
                "dodge":                42,
                "damage":               150,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N飞快的比出二式，却是虬枝剑招中的连环杀手，只见$N二臂齐举，一合之下，
双掌向上一翻一压，手中$w拂向$n。正是“乍惊梅多”的招式。",
                "dodge":                30,
                "damage":               130,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"缕剑气从$N$w透出，剑光一匝宛如长蛇出洞，刺向$n$l，正是“虬枝剑法”的
精妙绝学“梅占先春”",
                "dodge":                37,
                "damage":		240,
                "damage_type":  "刺伤"
        ]),

               
	});
}

int practice_skill(object me)
{

	return notify_fail("虬枝剑式只能用学的。\n");
}

 

mixed hit_ob(object me,object victim)
{
	if(me->query_temp("hanmeiluo"))
	return HIR "点点光华流散，耀目的剑光已刺入了$n要害！\n"NOR;

}

	      
