// bat-dao.c  蝙蝠刀法

inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","蝙蝠刀法");
	set("type","blade");
	set("difficulty",200);
	set("effective_level",200);
	set("usage/blade",1);
	set("usage/parry",1);
	set("skill_class","bat");
	set("unarmed_parry_msg",({
		"$n使出一招「以牙还牙」，不先自救，手中的$v反刺$N的前胸。\n",
		"$n刀势陡然有了几分魔意，令$N的攻势顿时慢了下来。\n",
		"$n手中的$v幻出一片刀花，分刺$N的身法中的数处破绽。\n",
		"$n刀法又是一变，$v发出阴冷的寒气逼得$N连退数步。\n",
					})
	);
		
	action = ({
			([      "action" : "$N高举手中$w,使出一招「追风逐电」，一刀斜劈$n的$l",
			        "dodge" : 200,
			        "parry" : 100,
			        "damage" : 90,
			        "damage_type" : "割伤",
			]),
			([      "action" : "$N就地一滚，使一招「斩尽杀绝」，手中$w从一个无法思议的角度挥向$n的$l",
			        "dodge" : 150,
			        "parry" : 150,
			        "damage" : 250,
			        "damage_type" : "割伤",
			]),
			([      "action" : "$N手中的$w光芒暴长，使出「谁是英雄」，如雷霆万钧砍向$n的$l",
			        "dodge" : 120,
			        "parry" : 120,
			        "damage" :220,
			        "damage_type" : "砍伤",
			]),
			([      "action" : "$N一招看似平淡无奇的「空山灵雨」，$w变的如一团雨丝向$n落去",
			        "dodge" : 80,
			        "parry" : 80,
			        "damage" : 110,
			        "damage_type" : "割伤",
			]),
			([      "action" : "$N天人合一，内外交融，手中$w象幽灵般刺向$n的$l",
			        "dodge" : 70,
			        "parry" : 70,
			        "damage" : 90,
			        "damage_type" : "刺伤",
			]),
			([      "action" : "$N飞身而起，手中的$w幻出一片刀光，，忽然反手一刀横斩$n的$l",
			        "dodge" : 120,
			        "parry" : 120,
			        "damage" : 220,
			        "damage_type" : "割伤",
			]),
	});
}

int valid_learn(object me) {
//	object ob;
	
	if(!::valid_learn(me)) {
		return 0;
	}
		
	if((string)me->query_skill_mapped("force")!= "wuzheng-force") {
		return notify_fail("蝙蝠刀法必须配合无争心法才能练。\n");
	}
	
	if (me->query_skill("wuzheng-force",1)<me->query_skill("bat-blade",1))
		return notify_fail("你的无争心法火候不够。\n");
	
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 250 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "axe")
    if(victim->query_skill_mapped("axe") == "xuanyuan-axe" ||
    	 victim->query_skill_mapped("axe") == "wuche-axe")
    if	(me->query_skill("bat-blade",1)+50 > victim->query_skill("xuanyuan-axe",1)
    		|| me->query_skill("bat-blade",1)+50 > victim->query_skill("wuche-axe",1)) {
    switch(random(3)) {
            case 0:
                    message_vision(HIR "\n$N料敌机先，渐渐占了上风！" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n$N刀走偏锋，$n逐渐施展不开了！" NOR,me,victim);
                    break;
                    }
    return random(me->query_skill("blade")) * 4;
    }
    return 0;
}