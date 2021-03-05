// lefthand-sword.c

#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","左手剑");
	set("damage_level",100);
	set("practice_limit",100);
	set("type","sword");
	set("difficulty",200);
	set("usage/sword",1);
	set("usage/parry",1);
	set("effective_level",120);
	set("skill_class","assassin");
	set("unarmed_parry_msg",({
			"$n使出一招「以牙还牙」，不先自救，手中的$v反刺$N的前胸。\n",
			"$n身形一转，反手一挥，手中$v刺向$N的$l。\n",
			"$n以攻为守，一剑直指$N的咽喉。\n",
	}));



	action = ({
		([	"name":			"one",
			"action":		"$N上前一步，手中$w毒蛇般刺向$n的$l",
			"dodge":		50,
			"damage":		70,
			"damage_type":	"刺伤"
		]),
		([	"name":			"two",
			"action":		"$N身形一转，反手一挥，手中$w刺向$n的$l",
			"dodge":		50,
			"damage":		20,
			"damage_type":	"刺伤"
		]),
		([	"name":			"three",
			"action":		"$n眼前一花，$N手中的$w已经迅捷无比的刺向$n的$l",
			"dodge":		40,
			"force" :		100,
			"damage_type":	"刺伤"
		]),
		([	"name":			"four",
			"action":		"$N只攻不守，手中$w一抖，往$n的$l刺出一剑",
			"dodge":		40,
			"damage":		40,
			"damage_type":	"刺伤"
		]),
		([	"name":			"five",
			"action":		"$N的「左手剑法」只有刺，简单而有效地往$n的$l刺去",
			"dodge":		60,
			"damage":		80,
			"force" :		100,
			"damage_type":	"刺伤"
		]),
		([	"name":			"six",
			"action":		"$N手中$w直指$n$l，发出逼人剑气闪电般刺去",
			"dodge":		20,
			"damage":		20,
			"damage_type":	"刺伤"
		]),
	});
}


int valid_learn(object me)
{	
	if(!::valid_learn(me)){
		return 0;
	}
	if (me->query("combat_exp")<1000000 && me->query_skill("lefthand-sword",1)>160){
		tell_object(me,"你的实战经验太差,无法进一步领略左手剑法。\n");
		return 0;
	}
	if (me->query("combat_exp")<2000000 && me->query_skill("lefthand-sword",1)>170){
		tell_object(me,"你的实战经验太差,无法进一步领略左手剑法。\n");
		return 0;
	}
	if (me->query("combat_exp")<3000000 && me->query_skill("lefthand-sword",1)>180){
		tell_object(me,"你的实战经验太差,无法进一步领略左手剑法。\n");
		return 0;
	}	
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        object ob;
        if( random(damage_bonus) < 200 ) return 0;
        if(ob=victim->query_temp("weapon"))
        if(victim->query_skill_mapped("sword") == "snowshade-sword")
        if(me->query_skill("sword")+100 > victim->query_skill("sword")) {
        switch(random(3)) {
                case 0:
                        message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                        break;
                case 1:
                        message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                        break;
                case 2:
                        message_vision(HIR "\n因武功路数相克，$n逐渐施展不开了！" NOR,me,victim);
                        break;
                        }
        return random(me->query_skill("sword")) * 3;
        }
        return 0;
}

