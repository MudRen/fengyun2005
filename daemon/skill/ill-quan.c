// ill-quan.c
#include <ansi.h>

inherit SKILL;
void setup(){
	set("name","病维摩拳");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("type","unarmed");
	set("difficulty",200);
	set("effective_level",200);
	set("practice_limit",100);
	set("skill_class","tieflag");
	set("parry_msg", ({
        	"$n伸出一指，轻轻一拨$N的$w，$w调转头去，向$N反噬过去！\n",
		"$n一按$N的$w，整个人已经从$N的头顶飞越而过，轻轻巧巧落在$N身后！\n",
		"$n深吸一口气，就象粘在$N的$w上一样。\n",
        	"$n身子微微一侧，已躲开$N的攻势。\n",
        	"$N眼前一花，手中的$w好象击在了虚处，仔细一看，$n站在原地没有动过。\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n身子微微一侧，已躲开$N的攻势。\n",
        	"$n一招「围魏救赵」，不退反进，击向$N，逼得$N回招自保。\n",
		"$n双拳错落，护住全身要害。\n",
        	"$N眼前一花，所有的招式好象击在了虚处，仔细一看，$n站在原地没有动过。\n",
	}) );
	action = ({
        ([      "action":               
"$N一式宽衣解带，不是脱衣，胜似脱衣，双拳挥向$n的$l",
                "dodge":                230,
                "parry":                150,
                "force":                700,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N身形一转，右拳自下而上撩向$n的$l",
                "dodge":                140,
                "parry":                100,
                "force":                120,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双足一顿，连人带拳扑至$n身前，以迅雷不及掩耳之势击向$n的$l",
                "dodge":                130,
                "parry":                120,
                "force":                190,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N猛一转身，背对$n，右肘向$n的$l猛击",
                "dodge":                150,
                "parry":                200,
                "force":                290,
                "damage_type":  "瘀伤"
        ]),
	});
}

 
mixed hit_ob(object me, object victim, int damage_bonus)
{
    if( random(damage_bonus) < 350 ) {
    	return 0;
    }
    if(!victim->query_temp("weapon"))
    if(victim->query_skill_mapped("unarmed") == "changquan")
    if(me->query_skill("unarmed") > victim->query_skill("unarmed")) {
    	switch(random(3)) {
            case 0:
                    message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n因拳法相克，$n逐渐施展不开了！" NOR,me,victim);
                    break;
        }
    	return random(me->query_skill("unarmed")) * 5;
    }
    return 0;
}

