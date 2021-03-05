// yiyangzhi.c
inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","一阳指");
	set("type","unarmed");
	set("skill_class","shaolin");
	set("effective_level",200);
	set("usage/parry",1);
	set("usage/unarmed",1);
	
	set("damage_level",200);
	set("difficulty",200);
	set("practice_limit",100);
	
	set("parry_msg",			({
			"$n一招「真机默默」，急出一指，指风悄无声息的点歪了$N的$w。\n",
			"$n神色悠闲，一招「大智闲闲」，倏地一指递出，点向$N的$w。\n",
			})
	);
	set("unarmed_parry_msg",	({
			"$n并起二指，踏步挺身，一招「正直中行」，指风凛凛反击$N的周身大穴。\n",
			"$n身形蓦地消逝，一招「五蕴皆空」，一指解围。\n",
			"$n化出无数身影，一招「镜花水月」身身皆出一指，一齐点向$N。\n",
			})
	);
	action = ({
			([      "action":               
			"$N身形旋转如飞，一招「玄机暗藏」，蓦地斜出一指，点向$n$l",
			        "dodge":                130,
			        "parry":                130,
			        "force":                80,
			        "damage_type":  "刺伤",
			        "weapon":               "左手食指",
			]),
			([      "action":               
			"$N力透指尖，一招「沙含大千」，缓缓向$n的$l戳去",
			        "dodge":                30,
			        "parry":                130,
			        "force":                90,
			        "damage_type":  "刺伤",
			        "weapon":               "右手食指",
			]),
			([      "action":               
			"$N一招「明心见性」，急出数指，指风破空，往$n的$l点去",
			        "dodge":                30,
			        "parry":                180,
			        "force":                140,
			        "damage_type":  "刺伤",
			        "weapon":               "一缕指风",
			]),
			([      "action":               
			"只见$N进身跟步，一招「万象澄明」，连出数指，指指不离$n的$l",
			        "dodge":                30,
			        "parry":                100,
			        "force":                90,
			        "damage_type":  "刺伤",
			        "weapon":               "右手中指",
			]),
	});
}

int valid_learn(object me) {
	
	if(!::valid_learn(me)) {
		return 0;
	}
	if((string)me->query("gender") != "男性" ) {
		return notify_fail("一阳指是只有男子才能练的武功。\n");
	}
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object ob;
    	if( random(damage_bonus) < 150 ) return 0;
    	if(victim->query_temp("weapon")==0) {
    	if(victim->query_skill_mapped("unarmed") == "nine-moon-claw" 
    		&& me->query_skill("yiyangzhi",1)+ 30 > victim->query_skill("nine-moon-claw",1)) {
    	switch(random(3)) {
            case 0:
                    message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n$N射出满天指气，$n逐渐施展不开了！" NOR,me,victim);
                    break;
                    }
    		return random(me->query_skill("unarmed")) * 3;
    	}
    }
    return 0;
}

void skill_improved(object me)
{
        int s;
        s = me->query_skill("yiyangzhi", 1);
		if (s == 170 && me->query("class") == "shaolin" ) 
        {
        	tell_object(me, WHT"由于你潜心修炼指法，你悟出了学习一指禅的口诀。\n" NOR);
        	me->set("marks/yizhichan",1);
        }
}

int help(object me)
{
	write(@HELP   
一阳指可克制九阴神抓
L100『一指定乾坤』（qiankun）
HELP
    );
    return 1;
}
