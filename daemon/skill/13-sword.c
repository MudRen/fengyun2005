// mimicat@fy4

#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","燕十三剑法");
	set("type","sword");
	set("skill_class","swordsman");
	set("effective_level",200);
	set("difficulty",400);
	set("usage/sword",1);
	set("usage/dodge",1);
	set("usage/parry",1);
	set("parry_msg",  ({
	        "$n运剑如飞，顿时就将$N的$w挡在了身外。\n",
	        "$n内力贯注剑尖，$N只觉手中一震，$w几欲飞出。\n",
	}) );
	set("unarmed_parry_msg", ({
	        "$n的剑势毫无破绽，令$N只觉得无处下手。\n",
	        "$n剑势奇妙，竟似有种奇异的力量，带偏了$N的招式。 \n",
	        "$n剑出如飞，逼得$N连连后退。\n",
	}) );
	set("dodge_msg",({
		"$n身形飘忽不定，令$N难以把握。\n",
		"$n竟倒纵开去，令$N一时无法追击。\n",
		"$n静立不动，等$N攻到身前时却略一移位，就使$N落了个空。\n",
		"$n右足一点，全身腾空，立时躲开了$N志在必得的这一击。\n",
	}) );
	action = ({
        ([      "action":               "$N使出燕十三剑法中的「第十二式」，剑交左手，顿时将$n攻了个措手不及！",
                "dodge":                400,
                "parry" :               300,
                "damage":               70,
                "force" :               0,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N使出燕十三剑法中的「第七式」，高高跃起，$w从上至下，击向$n的$l！",
                "dodge":                100,
                "parry" :               0,
                "damage":               400,
                "force" :               400,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N使出燕十三剑法中的「第十一式」，手中$w化做一道弧光，飞向$n的$l！",
                "dodge":                0,
                "parry" :               300,
                "damage":               150,
                "force" :               350,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N使出燕十三剑法中的「第三式」，反手一剑迅捷无比的刺向$n的$l！",
                "dodge":                -100,
                "parry" :               300,
                "damage":               450,
                "force" :               0,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N使出燕十三剑法中的「起手式」，手中的$w缓缓递出，指向$n的$l！",
                "dodge":                0,
                "parry" :               0,
                "damage":               0,
                "force" :               120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               "$N使出燕十三剑法中的「第五式」，化剑为刀，横劈$n的$l！",
                "dodge":                20,
                "damage":               50,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N使出燕十三剑法中的「第四式」，忽然欺身到$n近旁，$w由下至上，挑向$n的$l！",
                "dodge":                -200,
                "parry" :               300,
                "damage":               80,
                "force" :               60,
                "damage_type":  "刺伤"
        ]),
		([      "action":               "$N使出燕十三剑法中的「第六式」，移形换步，转至$n的身后，手中$w划向$n的后背！",
                "dodge":                400,
                "parry" :               0,
                "damage":               0,
                "force" :               160,
                "damage_type":  "割伤"
        ]),
		([      "action":               "$N使出燕十三剑法中的「第二式」，剑尖不断颤动，顿时就将$n的全身大穴笼罩其中！",
                "dodge":                0,
                "parry" :               -100,
                "damage":               0,
                "force" :               960,
                "damage_type":  "刺伤"
        ]),
		
		([      "action":               "$N使出燕十三剑法中的「第十三式」，$n只觉面前一寒，$w已欺至面门！",
                "dodge":                500,
                "parry" :               300,
                "damage":               100,
                "force" :               100,
                "damage_type":  "刺伤"
        ]),
		
		([      "action":               "$N使出燕十三剑法中的「第九式」，身剑合一，直奔$n的$l！",
                "dodge":                100,
                "parry" :               300,
                "damage":               0,
                "force" :               90,
                "damage_type":  "刺伤"
        ]),

		([      "action":               "$N使出燕十三剑法中的「第十式」，手里的$w竟似已化成了一阵风，轻轻的向$n吹了过来。",
                "dodge":                600,
                "parry" :               -50,
                "damage":               0,
                "force" :               1000,
                "damage_type":  "刺伤"
        ]),
		([      "action":               "$N一剑轻飘飘刺出，使出燕十三剑法中的「第八式」，本来毫无变化。可是变化忽然间就来了，\n来得就像是流水那麽自然，$w夹带着一种奇异的力量划向$n$l！",
                "dodge":                300,
                "parry" :               350,
                "damage":               20,
                "force" :               90,
                "damage_type":  "刺伤"
        ]),
});

}

int valid_learn(object me)
{
        object ob;

        if( (int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够，没有办法练燕十三剑法。\n");

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "sword" )
                return notify_fail("你必须先找一把剑才能练剑法。\n");

        return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object ob;
    	if( random(damage_bonus) < 350 ) return 0;
    	
    	if(ob=victim->query_temp("weapon"))
    	if(ob->query("skill_type") == "sword")
    	if(victim->query_skill_mapped("sword") == "softsword")
    	if(me->query_skill("sword")+100 > victim->query_skill("sword")) {
    	switch(random(3)) {
            case 0:
                    message_vision(HIR "\n$N料敌机先，渐渐占了上风！" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n$N随手一剑，正是$n的破绽所在！" NOR,me,victim);
                    break;
                    }
    		return random(me->query_skill("sword")) * 3;
    	}
    	return 0;
}
