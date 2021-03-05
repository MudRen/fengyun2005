// sharen-sword.c

#include <ansi.h>

inherit SKILL;
void setup(){
	set("name","杀人剑法");
	set("type","sword");
	set("difficulty",200);
	set("usage/sword",1);
	set("effective_level",150);
	set("damage_level",200);
	set("skill_class","assassin");
	
	action = ({
		([	"name":			"a",
			"action":		"$N手中的$w在一弹指间已向$n的$l连刺数剑",
			"dodge":		50,
			"parry" :		100,
			"force":		170,
			"damage" :		150,
			"damage_type":	"刺伤"
		]),
		([	"name":			"b",
			"action":		"$N身形一转，手中的$w从左肋下向$n的$l戳了过去",
			"dodge":		50,
			"damage":		170,
			"damage_type":	"刺伤"
		]),
		([	"name":			"c",
			"action":		"$N手腕一抖，$w挟著闪闪剑光逼向$n的$l",
			"dodge":		40,
			"damage" :		50,
			"force" :		120,
			"damage_type":	"刺伤"
		]),
		([	"name":			"d",
			"action":		"$N身形一矮，手中的$w由下往上刺向$n的$l",
			"dodge":		40,
			"damage":		80,
			"damage_type":	"刺伤"
		]),
		([	"name":			"e",
			"action":		"$N手中$w剑光暴长，如千年蛇蝎往$n$l咬去",
			"dodge":		160,
			"damage":		120,
			"damage_type":	"刺伤"
		]),
		([	"name":			"f",
			"action":		"$N手中的$w以无法形容的速度直射$n的$l",
			"dodge":		120,
			"force" :		100,
			"damage":		150,
			"damage_type":	"刺伤"
		]),
	});
}

int valid_learn(object me)
{
	if (me->query("family/master_id")!="master jing"	&& me->query_skill("sharen-sword",1)>160)
		return notify_fail ("高深的杀人剑法只能跟荆无命学。\n"); 
	if ( (int)me->query_skill("lefthand-sword",1)<75)
		return notify_fail ("学武要循序渐进，杀人剑法需要75级左手剑法为基础。\n");
	if(!::valid_learn(me)){
		return 0;
	}
	return 1;
}

/*
void skill_improved(object me)
{
	if( (int)me->query_skill("sharen-sword", 1)% 10 == 0 ) {
		tell_object(me,
			RED "\n你突然觉得一股恶气冲上心头，只觉得想杀人....\n\n" NOR);
		me->add("bellicosity", 200);
	} else
		me->add("bellicosity", 50);
}*/


int effective_level(object me)
{
	int skill, add;
	if( me ) {
		skill = me->query_skill("sharen-sword",1);
		add = F_ABILITY->check_ability(me,"sharen_add");
		if( skill >= 190 ) {
			return (190 + add);
		}
		if( skill >= 170 ) {
			return (180 + add);
		}
		if( skill >= 150) {
			return (170 + add);
		}
		if( skill >= 120 ) {
			return (160 + add);
		}
	}
	return 150 + add;
}





mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object ob;
    	string type;
    	
    	if( random(damage_bonus) < 200 ) return 0;
    	if(ob=victim->query_temp("weapon"))
    	{
    		type = ob->query("skill_type");
    		if (type != "hammer" && type != "staff" && type!="axe")	return 0;
    		if (me->query_skill("sword")+ 150 >= victim->query_skill(type))
    		{
	    		switch(random(3)) {
		        	case 0:
		                	message_vision(HIR "\n$N剑招毒辣，专走空门，占尽了上风！" NOR,me,victim);
		                	break;
		        	case 1:
		                	message_vision(HIR "\n$N忽然剑光暴涨，抢入$n的空隙之间！" NOR,me,victim);
		                	break;
		        	case 2:
		                	message_vision(HIR "\n因兵刃被克，$n逐渐施展不开了！" NOR,me,victim);
		                	break;
	                }
    			return (damage_bonus/2 + random(damage_bonus)/2);
    		}
    	}
    	return 0;

}
