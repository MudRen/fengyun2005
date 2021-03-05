// xiaohun-sword.c
#include <ansi.h>
inherit SKILL;
int check_skill(object victim) ;

void setup(){
	set("name","黯然销魂剑法");
	set("type","sword");
	set("difficulty",250);
	set("usage/sword",1);
	set("usage/parry",1);
	set("effective_level",250);
	set("skill_class","task");
	set("parry_msg", ({
		"$n手中$v如一片柳絮，轻飘飘地飞起，一式[暗柳萧萧]将$N迫退。\n",
        "剑光流散，$n黯然低首，[迷离晓梦啼莺] 随心而发，点点剑影零落
飘来，$N顿时有不知所措的感觉。\n",
	}) );

	set("unarmed_parry_msg", ({
		"$n手中$v如一片柳絮，轻飘飘地飞起，一式[暗柳萧萧]将$N迫退。\n",
        "剑光流散，$n黯然低首，[迷离晓梦啼莺] 随心而发，点点剑影零落
飘来，$N顿时有不知所措的感觉。\n",
	}) );
	
	action = ({
        ([      "action":               
"$N一展$w，一招[旧时月色]剑光朦胧，如梦如幻，洒向$n。。。 ",
                "dodge":                50,
                "damage":               230,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w轻摆，如萧萧凉风拂过竹林，给人如在梦镜的感觉。忽然间，
几点剑光闪出飞向$n，正是黯然销魂剑法的[竹外疏花]。",
                "dodge":                120,
                "damage":               330,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N缓缓一剑推出，一招[夜雪初积]，只见剑光如织盖向$n",
                "dodge":                155,
                "damage":               450,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N回剑反削，使出[红萼无言]，片片剑影飞起，却寂然无声，点点笼向$n",
                "dodge":                300,
                "damage":		320,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N神情落寞，手中$w向下斜指。$w忽然色转苍碧，黯然销魂剑法的绝技
[幽阶一夜苔生]已经发出，剑气波动，如苍苔铺地向$n卷来。",
                "dodge":                150,
                "damage":		600,
                "damage_type":  "刺伤"
        ]),
	});
}
int valid_learn(object me)
{
	if (!me->query("m_success/销魂传人"))
		return notify_fail("蓝一尘的销魂剑法已有传人了，学他的销魂鞭法吧。\n");
	
	if(!::valid_learn(me)){
		return 0;
	}
	return 1;
}

mapping query_action(object me, object weapon) 
{
	int act;
	act=random(sizeof(action));
	me->set_temp("xiaohun-act",act);
	return action[act];

}

string query_parry_msg(object weapon) {
	mapping msg;
	int act;
	
	if(objectp(weapon)) {
		msg = skill_attr["parry_msg"];
	}
	
	if(sizeof(msg) == 0) {
		msg = skill_attr["unarmed_parry_msg"];
	}
	
	if(sizeof(msg) > 0) {
		act=random(sizeof(msg));
		if (this_player()) 
			this_player()->set_temp("xiaohun-parry",act);
		return msg[act];
	}
	
	return 0;
}

mixed hit_ob(object me, object victim){	
	int act, pro, dam;
	
	act=me->query_temp("xiaohun-act");	
	if(act==4)
	{
		dam = me->query("force");
		dam = dam/2 + random(dam/2);
		dam = COMBAT_D->magic_modifier(me, victim, "sen", dam);
		victim->receive_damage("sen",dam/10, me);
		return (HIY "$n只觉黯然神伤，神智逐渐模糊起来。\n" NOR);
	}
}

// 50% chance parry busy. busy time random(4)

mixed parry_ob(object victim, object me)
{	int busy_time,alr_busy_time;
	int level;
	if (victim->query("race")!="人类") return 0;
	if (victim->query_temp("xiaohun-parry")!=1)	return 0;
		
	if (!check_skill(victim)) return 0;
	level = me->query_skill("xiaohun-sword",1);
	if (level < 100)	return 0;
	
	alr_busy_time=victim->query_busy();
	
	busy_time=random(4);
	if(!busy_time) return 0;
	
	if(busy_time>alr_busy_time)	victim->start_busy(busy_time);
	return HIB"$N被$n的剑招所惑，一时竟忘了如何反应。\n"NOR;
}	

int check_skill(object victim) {
	
	object weapon;
	if (weapon = victim->query_temp("weapon"))
	if (weapon->query("skill_type")=="blade" && victim->query_skill("blade",1)>100 
		&& victim->query_skill("shenji-blade",1)>100
		&& victim->query_skill_mapped("blade")=="shenji-blade")
		return 0;

	return 1;
}	


int help(object me)
{
	write(@HELP   
L120『离别』（libie）每五分钟籍离别钩可发挥其最大威力
HELP
    );
    return 1;
}
