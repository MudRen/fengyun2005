// assassin-hammer.c
inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","搏浪七杀");
	set("type","hammer");
	set("effective_level",200);
	set("usage/hammer",1);
	set("usage/parry",1);
	set("damage_level",250);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","wolfmount");
	set("unarmed_parry_msg", ({
		"$n一招「樊哙啖炙」，手中$v从胸前封出，$N急忙避其锋锐。 \n",
		"$n舞动$v，使出「豫让漆身」，锤影如密云环布，迫得$N无法进招。\n", 
		"$n挥$v斜取$N下盘，一招「曹沫掷刀」击得$N踉跄而退。 \n"})
	);
	action = ({
        ([      "action":               
"$N手中$w斜挥而上，一招「专诸擘鱼」砸向$n的$l，锤未到，劲风已迫得
$n气为之窒！ ",
                "force":                90,
                "dodge":                120,
                "parry":                120,
                "post_action": "bash_weapon",
                "damage_type":  "砸伤"
        ]),
        ([      "action":               
"$N沉声大喝，抡起$w横扫中路，眼看招势使老，突然不知如何锤交左手，
一招「要离断臂」砸向$n的$l！ ",
                "damage":               120,
                "dodge":                30,
                "parry":                60,
                "post_action":  "bash_weapon",
                "damage_type":  "砸伤"
        ]),
        ([      "action":               
"$N锤势渐缓，但内力催动，$w竟然发出低低的鸣响，正是一式「渐离击
筑」。$N一振臂，$w忽发清角之音，击向$n的$l！ ",

                "damage":               270,
		"dodge":                100,
                "parry":                240,
                "post_action":  "bash_weapon",
                "damage_type":  "砸伤"
        ]),
        ([      "action":               
"$N手中$w横展，一招「荆轲进图」层层劲风压来，忽然一转锤路，撞向
$n的$l！",
                "damage":               100,
		"dodge":                200,
                "parry":                400,
                "post_action":  "bash_weapon",
                "damage_type":  "砸伤"
        ]),
        ([      "action":
"$N使出「聂政闯阶」，步步向前进逼，$n感到气为之夺。$N一抖手直挥
而上，$w挟着一股烈风猛扑$n！",
                "force":               30,
        	"damage" :      	160,
                "dodge":                100,
                "parry":                600,
                "post_action": "bash_weapon",
                "damage_type":  "砸伤"
        ]),
});
}

int valid_learn(object me) {
	
	if(!::valid_learn(me)) {
		return 0;
	}
	
    	if( (int)me->query("str") + (int)me->query("max_force") / 10 < 60 ) {
		return notify_fail("你的力气太小，练一练内力和搏击吧。\n");
	}
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object ob;
    	if( random(damage_bonus) < 350 ) return 0;
    	if(ob=victim->query_temp("weapon"))
    	if(ob->query("skill_type") == "blade")
    	if(victim->query_skill_mapped("blade") == "bat-blade"
     		||victim->query_skill_mapped("blade") == "ittouryu")
    	if(me->query_skill("hammer") > victim->query_skill("blade")) {
    	switch(random(3)) {
            case 0:
                    message_vision(HIR "\n$N料敌机先，渐渐占了上风！" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n$N力大招沉，$n逐渐施展不开了！" NOR,me,victim);
                    break;
                    }
    	return random(me->query_skill("hammer")) * 2;
    	}
    	return 0;
}


int help(object me)
{
	write(@HELP
搏浪七杀若有效等级高于蝙蝠刀法或一刀流时具有额外伤害。
搏浪七杀的特技与传统的风云特技不同，引入了风云2005的憎恨系统
概念，以下两个特技为模拟暗算或偷袭，杀伤力很大，但只能在狼山
弟子不处在敌人憎恨最高的时候使用。如何避免成为敌人最憎恨的对
象呢？狼山有自己的一系列手段，其他门派也有许多特技来为此创造
机会。这两个特技的杀伤力与武器重量、伤害无关，仅取决于搏浪七
杀的有效等级，属魔法攻击类，所以也不受对方护甲或铁布衫影响。
在经验等级高于95和105时杀伤力有进一步增加。
   
『荆轲刺秦』（jingkeciqin）
需100级搏浪七杀，只能在战斗外使用，出招前有3轮自我忙乱

『搏浪一击』（bolangyiji）
需140级搏浪七杀，可以在在战斗中使用，仍需满足前面说到的条件，
出招前有3轮自我忙乱。

HELP
    );
    return 1;
}
