// libie-sword.c
#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","离别剑法");
	set("type","sword");
	set("difficulty",230);
	set("usage/sword",1);
	set("usage/parry",1);
	set("skill_class","npc");
	set("effective_level",230);
	
	action = ({
        ([      "action":               
"$N的$w乍起一道寒光，一式“谁知离别情”，刹那间已来到$n咽喉眉睫之间。",
                "dodge":                400,
                "damage":               330,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N身形乍退还回，一式“多情自古伤离别”，手中的$w舞出一个“别”字，\n"+
HIC+"$n竟不住心头涌上一阵离别之情，浑然忘了在恶战之中。"NOR,
                "dodge":                420,
                "damage":               -50,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N$w光忽隐突现，身行游走不停，一招“离恨天涯远”，$w尖颤动不已，处处
不离$n周身要害。",
                "dodge":                300,
                "damage":               -80,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N身行由缓至急，由慢至快。手中的$w亦如狂风暴雨般，招式源源不绝，正是
“叶叶声声是离别”。",
                "dodge":                370,
                "damage":		-140,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N满脸俱是愁苦之情，埋头一式“生怕离怀别苦”，将手中$w信手挥舞。",
                "dodge":                750,
                "damage":		1600,
                "damage_type":  "刺伤"
        ]),
	});
}
int valid_learn(object me)
{
    if((int)me->query("max_force") < 300 ) {
            return notify_fail("你的内力不够，没有办法练离别剑法。\n");
	}
	if(!::valid_learn(me)) {
		return 0;
	}
    return 1;
}


mapping query_action(object me, object weapon)
{
	int attack_act;
	object *victims,victim;
	
	attack_act=random(sizeof(action));
	me->set_temp("libie-act",attack_act);
	victims=me->query_enemy();
	victim=victims[random(sizeof(victim))];
	if(attack_act==1)
	victim->start_call_out( (: call_other, __FILE__, "action_busy", victim, me:), 0);
	
        return action[attack_act];
}

int practice_skill(object me)
{
	return notify_fail("离别剑法只能学的。\n");
}

 
/*
string *parry_msg = ({
	"$n手中$v如一片柳絮，轻飘飘地飞起，一式[暗柳萧萧]将$N迫退。\n",
        "剑光流散，$n黯然低首，[迷离晓梦啼莺] 随心而发，点点剑影零落
飘来，$N顿时有不知所措的感觉。\n",

});

string *unarmed_parry_msg = ({
	"$n手中$v如一片柳絮，轻飘飘地飞起，一式[暗柳萧萧]将$N迫退。\n",
        "剑光流散，$n黯然低首，[迷离晓梦啼莺] 随心而发，点点剑影零落
飘来，$N顿时有不知所措的感觉。\n",

});

string query_parry_msg(object weapon)
{	int parry_act;

	parry_act=random(sizeof(parry_msg));
	this_player()->set_temp("xiaohun-parry",parry_act);
        if( weapon )
                return parry_msg[parry_act];
        else
                return unarmed_parry_msg[parry_act];
}
*/
/*
mixed hit_ob(object me, object victim)
{	int act;
        int pro;
        int dam;
        int myskill;
	object weapon;
	
	weapon=me->query_temp("weapon");
	myskill=me->query_skill("sword");
	if(weapon->query("id")!="leave hook") return 0;
	act=me->query_temp("libie-act");	
	if(act==0)
	{
		if(me->query_skill("libie-sword",1)<60) return 0;	
		dam = (int) me->query("force");
		dam = (random(dam)+dam)/2;
		pro = victim->query("con");
        	if (pro>30)
		{
			dam = dam*(1-(pro-30)/30);
		}
		victim->receive_damage("gin",dam/5,me);
		return (HIY "$n只觉得眼前金星乱冒，似乎有些精力不济。\n" NOR);
	}

	else if(act==2)
	{
		if(me->query_skill("libie-sword",1)<80) return 0;
		dam = (int) me->query("force");
		dam = (random(dam)+dam);
		pro = victim->query("con");
        	if (pro>30)
		{
			dam = dam*(1-(pro-30)/30);
		}
		victim->receive_damage("kee",dam/5,me);
		return (HIY "$N暗运内力，通过兵刃送入$n体内。\n" NOR);
	}
	else if(act==3)
	{	
		if(me->query_skill("libie-sword",1)<120) return 0;
		dam = myskill+random(myskill);
		victim->receive_wound("kee",dam*2,me);
		return (HIR "$n只觉身如雷击，已然受了很严重的内伤。\n"NOR);
	}

		
}



mixed parry_ob(object victim, object me)
{	int busy_time;

	if (victim->query_temp("xiaohun-parry")==1)
	{
		busy_time=random(7);
		if(busy_time)
			victim->start_call_out( (: call_other, __FILE__, "parry_busy", victim, me,busy_time :), 0);
	}
	return 0;
}	
		
void action_busy(object victim, object me)
{	
	if (me->query_skill("libie-sword",1)<150) return;
//	if (random(2))
	if (me->is_fighting(victim))
	if (!victim->is_busy())
		victim->start_busy(2);
}			
*/