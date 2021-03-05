// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup(){
	set("name","天狼百破拳");
	set("practice_limit",100);
	set("usage/parry",1);
	set("damage_level",100);
	set("type","unarmed");
	set("usage/unarmed",1);
	set("effective_level",120);
	
	set("difficulty",200);
	set("skill_class","wolfmount");
	
	set("parry_msg", ({
       		"$n神色冷厉紧紧盯着$N，令$N感到无法进招。 \n",
		"$n左手一格，右手飞抓$N破绽，$N连忙退步自保。 \n",
		"$n双拳交叉挥出，劲风刚烈，迫得$N连连后退。 \n",
	}) );

	set("unarmed_parry_msg", ({
       		"$n神色冷厉紧紧盯着$N，令$N感到无法进招。 \n",
		"$n左手一格，右手飞抓$N破绽，$N连忙退步自保。 \n",
		"$n双拳交叉挥出，劲风刚烈，迫得$N连连后退。 \n",
	}) );
	
	action = ({
        ([      "action":               
"$N绕着$n来回游走，突然觑个空隙闪电般猛击$n的$l",
                "dodge":                110,
                "parry":                110,
                "damage":                50,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N横臂扫来，半途身子一弓，双手合拢抓向$n的$l",
                "dodge":                130,
                "parry":                130,
                "damage":                50,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N厉声长啸，忽然一跃而起，合肘攻向$n的$l",
                "dodge":                150,
                "parry":                150,
                "damage":                50,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N斜身一转，右掌成爪虚晃$n面门，左掌蓄力斜劈$n的$l",
                "dodge":                170,
                "parry":                170,
                "damage":                70,
                "damage_type":  "抓伤"
        ]),
	});
}

int valid_learn(object me)
{
	if(!::valid_learn(me)){
		return 0;
	}
	if(me->query_skill("summonwolf", 1) <= me->query_skill("wolf-strike",1)){
	    return notify_fail("你的唤狼术火候不足，无法练天狼百破拳。\n");
	}
	return 1;
}


int help(object me)
{
	write(@HELP   
学习天狼百破拳需要相同等级的唤狼术为基础

L30『断喉』（duanhou）
攻击对手，自我忙乱2轮
额外攻击力=天狼百破拳等级
额外伤害力=天狼百破拳等级*3/2
如果对方在失神状态则该招必中，额外伤害力*3，取最大可能值

L50『嗜骨』（shigu）
攻击对手并将伤害的30%转为自己的气血，自我忙乱2轮
额外攻击力=50+天狼百破拳等级
额外伤害力=50+天狼百破拳等级*2

L150『残肢』（canzhi）
连续击出六击，自我忙乱1轮，每90秒使用一次
额外攻击力 = 天狼百破拳等级

L200『凝血』（ningxue）
攻击对手，自我忙乱1轮。
额外攻击力=天狼百破拳等级*3
如果成功击中并伤害对手可进入“凝血”状态
该状态持续20回合，
攻击力+100，闪躲力+100，招架力+100
出现该状态后下一个『凝血』须等待90秒

HELP
    );
    return 1;
}
