// doomsword.c

#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","寒天吹血剑法");
	set("type","sword");
	set("usage/sword",1);
	set("usage/parry",1);
	set("effective_level",270);
	set("difficulty",200);
	set("skill_class","fighter");
	set("parry_msg", ({
	    "$n不退反进，气走周天，一招「鬼魅无边」，手中的$v狠狠磕开了$N的$w。\n",
	    "$n回剑自守，一招「鬼火飘零」，架住了$N的$w。\n",
	    "$n一招「群魔乱舞」，手中的$v化作千百把，护住了全身。\n",
	    "$n手中的$v自上削下，几乎将$N的$w削成两段。\n",
	}) );

	set("unarmed_parry_msg", ({
	    "$n使出一招「万炼魔障」，在身前布起了一道铜墙铁壁，封住了$N的攻势。\n",
	    "$n一抖手中的$v，使出一招「碧灵魔遁」，手中的$v护住了全身。\n",
	    "$n将$v往地上一刺，$v反弹起来，刚好直刺$N的双臂。\n",
	    "$n举剑静立，一股内力从剑梢透出，逼开了$N。\n",
	}) );
	action = ({
    ([	"name":			"群魔乱舞",
     "action":		"$N使一招「白云出岫」，手中$w狂风骤雨般地向$n的$l连攻数剑",
     "dodge":		200,
     "parry" :		200,
     "damage":		270,
     "force" : 		200,
     "damage_type":	"刺伤"
	]),
    ([	"name":			"厉鬼缠身",
     "action":		"$N身形一转，一招「天绅倒悬」$w斩向$n的$l",
     "dodge":                200,
     "parry" :               200,
     "damage":               350,
     "force" :               100,
     "damage_type":	"刺伤"
	]),
    ([	"name":			"百鬼夜行",
     "action":		"$N舞动$w，一招「白虹贯日」挟著闪闪剑光刺向$n的$l",
     "dodge":                200,
     "parry" :               300,
     "damage":               350,
     "force" :               250,
     "damage_type":	"刺伤"
	]),
    ([	"name":			"饿鬼拦路",
     "action":		"$N手中$w一抖，使出「如鬼如魅」往$n的$l刺出一剑",
     "dodge":                100,
     "parry" :               100,
     "damage":               250,
     "force" :               150,
     "damage_type":	"刺伤"
	]),
    ([	"name":			"鬼影幢幢",
     "action":		"$N手中$w剑光暴长，一招「鬼影幢幢」往$n$l刺去",
     "dodge":                250,
     "parry" :               250,
     "damage":               290,
     "force" :               220,
     "damage_type":	"刺伤"
	]),
    ([	"name":			"秋坟鬼唱",
     "action":		"$N手中$w直指$n$l，一招「秋坟鬼唱」发出逼人剑气刺去",
     "dodge":		200,
     "parry" :          100,
     "damage":		150,
     "damage_type":	"刺伤"
	]),
	});
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object ob;
    	if( random(damage_bonus) < 200 ) return 0;
    	if(ob=victim->query_temp("weapon"))
	if(ob->query("skill_type") == "sword")
        if(victim->query_skill_mapped("sword") == "taiji-sword"
        	|| victim->query_skill_mapped("sword") == "feixian-sword")
        	if(me->query_skill("sword") > victim->query_skill("sword"))
                {
                    switch(random(3)) {
                    case 0:
			message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
			break;
                    case 1:
			message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
			break;
                    case 2:
			message_vision(HIR "\n因剑法相克，$n逐渐施展不开了！" NOR,me,victim);
			break;
                    }
                return random(me->query_skill("sword")) * 4;
                }
    return 0;
}


int valid_learn(object me)
{
	object ob;
	
	if(!::valid_learn(me)) {
		return 0;
	}
	if ((int)me->query("max_force") < 500) {
		return notify_fail("你的内力不够。\n");
	}
	return 1;
}
