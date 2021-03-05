// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup(){
	set("name","地狱狼魂爪");
	set("usage/parry",1);
	set("damage_level",300);
	set("type","unarmed");
	set("usage/unarmed",1);
	set("effective_level",150);
 	
	set("difficulty",200);
	set("skill_class","wolfmount");
	set("parry_msg", ({
        	"$n并指斜斩$N手腕关节，$N只好收招。 \n",
        	"$n飞身急抓$N双目，酸冷的阴风迫得$N一跃退开。 \n",
        	"$n爪影飘忽封住了$N的攻势。 \n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n并指斜斩$N手腕关节，$N只好收招。 \n",
        	"$n飞身急抓$N双目，酸冷的阴风迫得$N一跃退开。 \n",
        	"$n爪影飘忽封住了$N的攻势。 \n",
	}) );	
	action = ({
        ([      "action":               
"$N凝目注视$n，显出一付若有所思的神情，蓦然急掠而前抓向$n的$l。 ",
                "dodge":                10,
                "parry":                10,
                "damage":                70,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N斜腰弓步，双爪连环抓出，疾取$n的$l。 ",
                "dodge":                30,
                "parry":                30,
                "damage":                90,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N目光漂移不定，似乎$n身后出现了什么异状，忽然趁$n分神，闪电般抓向$n的$l。 ",
                "dodge":                50,
                "parry":                50,
                "damage":                100,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N缓缓出爪，虚罩$n的全身，身形闪动，忽如一缕幽风欺近身来猛下杀手！ ",
                "dodge":                70,
                "parry":                70,
                "damage":                140,
                "damage_type":  "抓伤"
        ]),
	});
}

int valid_learn(object me)
{
	if(!::valid_learn(me)){
		return 0;
	}
   	if((int)me->query_skill("wolf-force", 1) < 170){
        return notify_fail("你的天狼心法火候不足，无法练地狱狼魂爪。\n");
    }
    	return 1;
}
