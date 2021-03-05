// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup() {
	set("name","大悲千叶掌法");
	set("type","unarmed");
	set("effective_level",120);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("difficulty",200);
	set("skill_class","shaolin");
	set("practice_limit",100);
	set("parry_msg", ({
	        "$n双掌一分，使出一招「乾坤无私」，「啪」的一声将$N的$w夹在双掌之间。\n",
	        "$n略一转身，一招「万法同宗」拍向$N拿着$w的手。\n",
	        "$n使出「慈心作善」，吐气开声，双掌一划，引偏了$N的$w。\n",}) 
        );

	set("unarmed_parry_msg", ({
	        "$n凝神定气，一招「光明无量」虚空拍出三掌，逼得$N撤招自保。\n",
	        "$n施展出「乾坤无私」，轻描淡写的化解了$N的攻势。\n",}) 
        );
	
	action = ({
        ([      "action":               
"$N使出一招「无缘大慈」，单掌轻挥，一道浑厚内力打向$n的$l",
                "dodge":                100,
                "parry":                100,
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出一招「象外春光」，化出一道幻影，抡掌拍向向$n的$l",
                "dodge":               100,
                "parry":                100,
                "force":                 70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出大悲千叶掌法中的「正大光明」，口宣佛号，正步亮掌，一掌拍向$n的$l",
                "dodge":               100,
                "parry":                100,
                "force":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N身形急进，使出「万相归真」，身影突然合为一体，双掌已到了$n的眼前",
                "dodge":                100,
                "parry":                100,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双臂一振，内力无形而出，一招「毛吞大海」击向$n$l",
                "dodge":                100,
                "parry":                100,
                "force":                140,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双掌晃动，使出「同体大悲」，掌风暗带巨大旋力，从空中当头向$n的$l出掌攻击",
                "dodge":                200,
                "parry":                200,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),
	});
}


int help(object me)
{
	write(@HELP   
L20	『千手千变』（qianshouqianbian）
令对手忙乱两招，大悲千叶掌法等级越高，成功率越高。
此招会对敌人造成额外的憎恨。

HELP
    );
    return 1;
}
