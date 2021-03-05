inherit SKILL;

//original design by mimicat
#include <ansi.h>
int check_skill(object victim) ;
void setup() {
	set("name","灵犀指");
	set("type","unarmed");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("difficulty",200);
	set("skill_class","task");
	
	set("parry_msg",			({
        	"$n右手在$N的手腕上轻轻一拂，$N只觉一麻，便再也使不出力道来。\n",
		"$n左手在$N的手腕上轻轻一拂，$N只觉一麻，便再也使不出力道来。\n"
	})	);
	set("unarmed_parry_msg",		({
         	"$n右手在$N的手腕上轻轻一拂，$N只觉一麻，便再也使不出力道来。\n",
		"$n左手在$N的手腕上轻轻一拂，$N只觉一麻，便再也使不出力道来。\n"
	})	);
	action = ({
([      "action" : "$N左指挥出，一式「昨夜长风」，削向$n的掌缘",
        "force" : 100,
        "dodge" : 5,
        "lvl" : 0,
        "skill_name" : "昨夜长风",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N全身之力聚于一指，一式「天似无情」，指向$n的胸前",
        "force" : 140,
        "dodge" : 5,
        "lvl" : 15,
        "damage" : 25,
        "skill_name" : "天似无情",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N左掌贴于神道穴，右手一式「情根深种」，向$n的$l划过",
        "force" : 180,
        "dodge" : 8,
        "lvl" : 25,
        "damage" : 55,
        "skill_name" : "情根深种",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双目怒视，一式「情在天涯」，双指拂向$n的额、颈、肩、臂、胸、背",
        "force" : 220,
        "dodge" : 5,
        "damage": 65,
        "lvl" : 45,
        "skill_name" : "情在天涯",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N一式「独饮情伤」，左掌掌心向外，右指蓄势点向$n的$l",
        "force" : 260,
        "dodge" : 15,
        "damage": 80,
        "lvl" : 60,
        "skill_name" : "独饮情伤",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N右手伸出，十指叉开，一式「无诉别情」，小指拂向$n的太渊穴",
        "force" : 330,
        "dodge" : 20,
        "damage": 100,
        "lvl" : 70,
        "skill_name" : "无诉别情",
        "damage_type" : "瘀伤"
]),
([      "action" : "$N双手迸出无数道劲气，一式「情意绵绵」射向$n的全身",
        "force" : 400,
        "dodge" : 25,
        "damage": 120,
        "lvl" : 80,
        "skill_name" : "情意绵绵",
        "damage_type" : "瘀伤"
]),
});

}

int valid_learn(object me)
{	
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                return notify_fail("练灵犀指法必须空手。\n");
        return 1;
}



mixed parry_ob(object victim,object me)
{
	int myexp,hisexp,mylvl,extra, n;
	int alr_busy_time;
	object owner, weapon;
	string msg;
	
	if (victim->query("race")!="人类") return 0;
	
	if (victim->is_busy()) return 0;
	
	if (!check_skill(victim)) return 0;

	myexp=me->query("combat_exp")/10000;
	hisexp=victim->query("combat_exp")/10000;
	
	mylvl=me->query_skill("lingxi-zhi",1);
	
	hisexp	*=180;
	myexp	*=mylvl;
	
	if (ANNIE_D->check_buff(me,"parry_busy")||!userp(me))
	{
		if (objectp(owner = me->query("owner")))
		if (userp(owner))	return 0;		// It's a copycat from Player
					
		if (victim->query_temp("weapon"))
			msg=HIY"$n"+HIY"忽然伸出食中两指，将$N"+HIY"的兵刃夹住！！\n"NOR;
		else 
			msg=HIY"$n"+HIY"忽然伸出食中两指，将$N"+HIY"的出招夹住！！\n"NOR;
		
		victim->force_busy(3);				
		return msg;
	}

	if (random(myexp+hisexp) > hisexp 
		&& me->query_skill("lingxi-zhi",1)>100 && userp(me))
	{
		if (!random(2)) {
			victim->force_busy(1);
			return HIW"结果$N被$n的反击攻了个手忙脚乱。\n"NOR;
		}
	}
	
	if (random(3*myexp+hisexp) > hisexp && !userp(me))
	{
		victim->force_busy(1);
		return HIW"结果$N"HIW"被$n"HIW"的反击攻了一个手忙脚乱。\n"NOR;
	}

}


int check_skill(object victim) {
	
	object weapon;
	
	if (weapon=victim->query_temp("weapon"))
	if (weapon->query("skill_type")=="blade" && victim->query_skill("blade",1)>100 
		&& victim->query_skill("shenji-blade",1)>100
		&& victim->query_skill_mapped("blade")=="shenji-blade")
		return 0;

	if (weapon=victim->query_temp("weapon"))
	if (weapon->query("skill_type")=="sword" && victim->query_skill("sword",1)>100 
		&& victim->query_skill("daimonsword",1)>100
		&& victim->query_skill_mapped("sword")=="daimonsword")
		return 0;

	if (victim->query_temp("marks/no_parry_busy_pfm"))
		return 0;
		
	return 1;
}

		
int effective_level(object me)
{
	if(me) {
		if(me->query_skill("lingxi-zhi",1)<160)
			return 150;
		else return 200;
	}
	return 200;	
}


int help(object me)
{
	write(@HELP   
灵犀指可从陆小凤处学到150级，武功系数为150，
如果肯花功夫往上研究（research）十级，武功系数将提高到200，
同时可使用特技『心有灵犀』

100级以上的灵犀指用作招架成功时有一定几率中断敌人的攻击
并令敌人忙乱一轮。

『心有灵犀』
需要160级灵犀指，持续时间5回合。
使用此特技后招架成功必然令对方忙乱3轮。
在战斗中使用此特技会有2轮自我忙乱，战斗外使用无自我忙乱。

HELP
    );
    return 1;
}

