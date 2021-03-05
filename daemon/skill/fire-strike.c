// silencer@fengyun4

#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","火焰掌");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("type","unarmed");
	set("effective_level",200);
	set("practice_limit",100);
	set("damage_level",100);
	set("difficulty",200);
	set("skill_class","npc");
	set("parry_msg", ({
		"$n慢慢伏身，突然一团火焰将$N逼得连退几步。\n",
		"$n身上的火团又是一盛，$N的攻势打到了火团边缘，忽然都消融不见。\n",
	}) );
	set("unarmed_parry_msg", ({
        	"$n手中一道火光封向$N。\n",
        	"$n慢慢伏身，突然一团火焰将$N逼得连退几步。\n",
		"$n身上的火团又是一盛，$N的攻势打到了火团边缘，忽然都消融不见。\n",
	}) );
	action = ({
		([	"action":		"$N突然一矮身，火焰变成向$n的$l卷到",
			"dodge":		100,
			"parry" :		100,
			"force":		400,
	                "damage":               200,
			"damage_type":	"瘀伤"
		]),
		([	"action":		"$N袖子一扬，一团烈火，迎脸向$n的$l喷来",
	                "dodge":		30,
			"parry" :		100,
	                "damage":               200,
			"force":		300,
			"damage_type":	"瘀伤"
		]),
		([	"action":		"火焰中$N象狂风中的流云，忽聚忽散出掌击向$n的$l",
			"dodge":		120,
			"parry" :		80,
			"force":		100,
	                "damage":               200,
			"damage_type":	"瘀伤"
		]),
		([	"action":		"$N一晃又到了$n背后，打出一条绿色火焰",
			"dodge":		100,
			"parry" :		400,
			"force":		100,
	                "damage":               200,
			"damage_type":	"瘀伤"
		]),
		([	"action":		"$N聚起全身的功力，双手打出火团飞向$n",
			"dodge":		300,
			"parry" :		300,
			"force":		200,
			"damage":		200,
			"damage_type":	"瘀伤"
		]),
	});
}
int valid_learn(object me)
{
    if( (int)me->query_skill("force", 1) < 100 ) {
        return notify_fail("你的内功心法火候不足，无法练火焰掌法。\n");
	}
	return 1;
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
	int my_exp, your_exp, damage, lvl;
	my_exp=me->query("combat_exp");
	your_exp=victim->query("combat_exp");
	lvl= me->query_skill("fire-strike",1);
	damage = lvl*2;
	
	if( 10*random(my_exp)>your_exp) {
		victim->receive_wound("kee",damage+random(damage));
		victim->set_temp("last_damage_from",me);
		return RED "$n被烈火灼烧得焦头烂额。\n" NOR;
	}	
}
