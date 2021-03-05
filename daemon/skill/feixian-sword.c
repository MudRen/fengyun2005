// feixian-sword.c
#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","飞仙剑法");
	set("practice_limit",100);
	set("type","sword");
	set("usage/sword",1);
	set("usage/parry",1);
	set("ignore_ic", 1);
	set("skill_class","baiyun");
	set("effective_level",180);
	set("difficulty",200);
	set("bypass_ic", 1);		// BYPASS iron-cloth.
	set("parry_msg", ({
	        "$n使出一招「凤舞九天」，手中的$v化作一条长虹，磕开了$N的$w。\n",
	        "$n使出「封」字诀，将$N的$w封于丈外。\n",
	        "$n使出一招「朝朝瑞雪」，手中的$v化做漫天雪影，荡开了$N的$w。\n",
	        "$n手中的$v一抖，一招「旱地春雷」，向$N拿$w的手腕削去。\n",
	}) );

	set("unarmed_parry_msg", ({
	        "$n将手中的$v舞得密不透风，封住了$N的攻势。\n",
	        "$n反手一招「阳光普照」，整个人消失在一团剑光之中。\n",
	        "$n使出一招「龙舞九天」，$v直刺$N的双手。\n",
	        "$n将手中的$v化做七条剑气，迫得$N连连后退。\n",
	}) );	
	action = ({
        ([      "action":               
"$N使一招「峰回路转」，手中$w如一条银蛇般刺向$n的$l",
                "dodge":                20,
                "damage":               30,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出飞仙剑法中的「空山鸟语」，剑光霍霍斩向$n的$l",
                "dodge":                20,
                "damage":               30,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招「御风而行」，身形陡然滑出数尺，手中$w斩向$n的$l",
                "dodge":                30,
                "damage":               20,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w中宫直进，一式「旭日东升」对准$n的$l刺出一剑",
                "dodge":                40,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N纵身一跃，手中$w一招「金光泻地」对准$n的$l斜斜刺出一剑",
                "dodge":                40,
                "damage":		120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w凭空一指，一招「一剑西来」刺向$n的$l",
                "dodge":                20,
                "damage":               140,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w向外一分，使一招「柳暗花明」反手对准$n$l一剑刺去",
                "dodge":                20,
                "damage":               120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N横剑上前，身形一转手中$w使一招「仙云密布」画出一道光弧刺向$n的$l",
                "dodge":                30,
                "damage":               50,
                "damage":		100,
                "damage_type":  "刺伤"
        ]),
	});
}


int valid_learn(object me)
{
    	if( (string)me->query_skill_mapped("force")!= "chessism") {
            return notify_fail("飞仙剑法必须配合『弈道』才能练习。\n");
	}
	if(!::valid_learn(me)) {
		return 0;
	}
    return 1;
}


mixed hit_ob(object me, object victim)
{	
        int level, myexp, yourexp;
        object weapon;
        
		if (me->query("class") != "baiyun")	return ("");
	
		if (me->query_skill_mapped("force") != "chessism")
			return ("");
    	
    	if (!me->query_temp("in_feixian_pfm")) return ("");
    	
    	myexp = me->query("combat_exp");
    	yourexp = victim->query("combat_exp");
    	level = me->query_skill("chessism", 1);
    	
    	if (!victim->is_busy())
    	if (3* random(myexp) > yourexp ) 
        {
			if (random(3))	
				victim->start_busy(1);  
			else 
				victim->start_busy(2);
 	       	return (WHT "$N心剑合一，弈道『攻算篇』先机在握，剑势变幻无方。$n被顿时攻得手忙脚乱！\n" NOR);
		}
	return ("");
		
}

mixed parry_ob(object victim, object me)
{	int busy_time;
	int skill;
	int my_exp, your_exp;
	
	if (me->query("class") != "baiyun")	return ("");
	my_exp=me->query("combat_exp");
	your_exp=victim->query("combat_exp");
	
	skill=me->query_skill("chessism",1);
	
	if (me->query_busy()>1)
	if (random(skill) + skill/3 > 100 && me->is_busy()) {
		message_vision(HIG"$N剑气回转，进退井然，弈道『得算篇』历历在目，身形骤然轻巧起来。\n"NOR, me);	
		if (me->query_busy()==1) me->stop_busy();
			else me->start_busy(me->query_busy()-1);
	}
	
	return 0;
}

int bypass_ironcloth(){
	return 1;
}
