// low damage
// hard to dodge / parry
// annie. 07.02.2003

#include <ansi.h>
#include <combat.h>
inherit SKILL;

void setup(){
	seteuid(getuid());
	set("name","阿修罗冷秋无影手");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("type","unarmed");
	set("difficulty",200);
	set("effective_level",120);
	set("skill_class","demon");
	set("parry_msg", ({
        "$n一式「闲心浅淡云一出」指尖淡淡拂过，$N只觉腕脉一麻，已然力气全失。 \n",
        "$n使一招「小楼一夜听春雨」，指风若冰寒细雨一般迫退$N。 \n",
	}) );

	set("unarmed_parry_msg", ({
        "$n一式「闲心浅淡云一出」指尖淡淡拂过，$N只觉腕脉一麻，已然力气全失。 \n",
        "$n使一招「小楼一夜听春雨」，指风若冰寒细雨一般迫退$N。 \n",
	}) );	
	action = ({
        ([      "action":               
"$N凝目注视$n，阿修罗冷秋无影手中的「秋水望断别经年」寂寂寥寥的使出 ",
                "dodge":                500,
                "parry":                500,
                "damage":               -100,
                "damage_type":  "抓伤",
        ]),
        ([      "action":               
"$N寞寞的望着$n身外，一式「空向墟烟寄乡愁」看似随意的挥洒而出",
                "dodge":                600,
                "parry":                600,
                "damage":               -200,
                "damage_type":  "抓伤",
        ]),
        ([      "action":               
"$N施出「花开花落两由之」，一双柔荑看似拍向别处，却近了$n身边。 ",
                "dodge":                700,
                "parry":                700,
                "damage":               -300,
                "damage_type":  "抓伤",
        ]),
        ([      "action":               
"$N轻叹一声，指尖已迫到$n身边，这无形无影的一招正是「伤心一际画尤难」",
                "dodge":                800,
                "parry":                800,
                "damage":               -400,
                "damage_type":  "抓伤",
        ]),
	});
}

int valid_learn(object me)
{
	if(!::valid_learn(me)){
		return 0;
	}
	if (me->query("gender") != "女性")
		return notify_fail("一个大男人，也好意思学这扭扭捏捏的手法？\n");
	if( me->query_agi()  * 5 < me->query_skill("daimonstrike",1) )
		return notify_fail("你的速度太低，不适合修习阿修罗冷秋无影手。\n");

    	return 1;
}

mapping query_action(object me, object weapon) 
{
	int act;
	act=random(sizeof(action)-1);
		return action[act];
}

mixed hit_ob(object me, object victim){	
	object wep;
	int i=0,t;
	wep = me->query_temp("right_hand");
	if (!wep)
		return -800;
	if (wep != me->query_temp("left_hand"))
		return -800;
	if (wep->query("annie/for_daimonstrike"))
	{
		t = random(me->query_skill("daimonstrike",1));
		i = t / 100;
		if (i && !me->query_temp("extra_action"))
		{
			me->set_temp("extra_action_msg",CYN"\n$N身影如风，眨眼之间又是一招！\n"NOR);
			me->set_temp("extra_action",i);
		}
		return wep->query("weapon_prop/damage") * 20;	// 0 ~ 30 : 0 ~ 600 extra damage,让它们不成为一种好的空手武器
	}
	return -800;
}

