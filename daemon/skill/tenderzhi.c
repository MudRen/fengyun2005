// tenderzhi.c

inherit SKILL;
#include <ansi.h>
void setup(){
	set("name","柔虹指");
	set("practice_limit",100);
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("type","unarmed");
	set("effective_level",200);
	set("difficulty",200);
	set("skill_class","taoist");
	
	set("parry_msg", ({
        	"$n中指微弹$N$w的尖端，$N手中的$w几乎脱手而出。\n",
	}) );
	set("unarmed_parry_msg", ({
        	"$n并起二指，凌空虚点，指风直奔$N的周身大穴。\n",
	}) );	
	action = ({
        ([      "action":               
"$N左手一挥，一招「菊楼采月」，右手点向$n$l",
                "dodge":                30,
                "parry":                30,
                "damage":                80,
                "damage_type":  "刺伤",
                "weapon":               "右手食指",
        ]),
        ([      "action":               
"$N使一招「雪桥翦梅」，身影忽前忽後，突然一转身左手往$n的$l点去",
                "dodge":                30,
                "parry":                30,
                "damage":                90,
                "damage_type":  "刺伤",
                "weapon":               "左手食指",
        ]),
        ([      "action":               
"$N身法稍顿，左手一扬使出「柳亭簪花」往$n的$l点去",
                "dodge":                30,
                "parry":                30,
                "damage":                140,
                "damage_type":  "刺伤",
                "weapon":               "左手食指",
        ]),
        ([      "action":               
"只见$N纤腰一摆，陡然滑出数尺，右手顺著来势一招「桃坟扑蝶」往$n的$l点去",
                "dodge":                30,
                "parry":                30,
                "damage":                90,
                "damage_type":  "刺伤",
                "weapon":               "右手食指",
        ]),
	});
}


int valid_learn(object me)
{
    	if((string)me->query("gender") != "女性") {
        	return notify_fail("柔虹指是只有女子才能练的武功。\n");
    	}
    	return ::valid_learn(me);
}
 

mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object my_weapon;
    	int badint;
//    	my_weapon=me->query_temp("weapon");
    	if(damage_bonus < 300 ) return 0;
        if (me->query("possessed"))	return 0;	// Nah, don't let pet do it.
        if(victim->query_skill_mapped("iron-cloth") == "yijinjing") {
        	badint = 2*victim->query_skill("iron-cloth")+ random(victim->query_skill("iron-cloth"));
		if(badint) {
			victim->receive_wound("kee",badint,me);
			switch(random(2)) {
        			case 0: return HIW"$N指尖射出丝丝寒气,击破了$n的护体神功！\n"NOR;
               			case 1: return HIW"$n只觉心头一凉,$N的阴寒指力竟透体而入 ．．．\n"NOR;
           		}
		}
	}
	return 0;
}



int help(object me)
{
	write(@HELP   
可破易筋经硬功

『乾坤』（qiankun）
指法攻击，需１００级柔虹指
额外伤害力＝有效拳脚等级
额外攻击力＝柔虹指等级
自我忙乱两回合
HELP
    );
    return 1;
}
