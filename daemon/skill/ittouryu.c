//mimicat@fy4
//ittouryu.c
inherit SKILL;

void setup(){
	set("name","一刀流剑术");
	set("type","blade");
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("difficulty",200);
	set("skill_class","ninja");
	set("parry_msg", ({
        	"$n一招「切返」以守为攻，化解了$N的攻势。\n",
		"$n突然从怀中掏出一把短刀，「二刀」当地一声挡住了$N的攻击。\n",
	}) );
		set("unarmed_parry_msg", ({
    		"$n一招「切返」以守为攻，化解了$N的攻势。\n",
		"$n突然从怀中掏出一把短刀，「二刀」当地一声挡住了$N的攻击。\n",
	}) );
	action = ({
		([      "action" : 
		"$N双手持刀，高举过顶，突然向$n攻出一招「南无三」，$w以破竹之势直奔$n的要害而去",
		        "dodge" : 10,
		        "parry" : 20,
		        "damage" : 120,
		        "damage_type" : "割伤",
		]),
		([      "action" : 
		"$N一招「地狱」猛地挥动$w向$n当头击下，$n退了一步，但$w的刀气不依不饶地袭向$n",
		        "dodge" : 17,
		        "parry" : 14,
		        "damage" : 120,
		        "damage_type" : "瘀伤",
		]),
		([      "action" : 
		"$N手中的$w刀光暴长，「岚」！不可一世地撞向$n",
		        "dodge" : 12,
		        "parry" : 11,
		        "damage" :110,
		        "damage_type" : "砍伤",
		]),
		([      "action" : 
		"$N挥动$w，一招「叶切合」如蛆附骨，点点不离$n",
		        "dodge" : 80,
		        "parry" : 80,
		        "damage" : 140,
		        "damage_type" : "刺伤",
		]),
		([      "action" : 
		"$N手中的$w在$n攻击的间隙中抢攻了进去，$N手中的$w有如梦一般罩了下去",
		        "dodge" : 70,
		        "parry" : 70,
		        "damage" : 90,
		        "damage_type" : "刺伤",
		]),
		([      "action" : 
		"$N低头躲过$n的一击，接着想也不想，反手一招「浮舟」$w带着三分惆怅，斩向$n的胸口",
		        "dodge" : 120,
		        "parry" : 120,
		        "damage" : 120,
		        "damage_type" : "割伤",
		]),
	});
}

/*
int valid_learn(object me)
{
	object ob;
	
	if(!::valid_learn(me)) {
		return 0;
	}
	if (REWARD_D->check_m_success( me, "浪人的悲哀" )!= 1) 
		return notify_fail("天枫十四郎未答应转授你这门武功。\n");
	if ((int)me->query("tianfeng/ittouryu")!=1){
		return notify_fail("天枫十四郎未答应教你这门武功。\n");
	}
	if( (int)me->query("max_force") < 500 ) {
        return notify_fail("你的内力不够，没有办法练一刀流剑术。\n");
	}
	 return 1;
}*/

int help(object me)
{
	write(@HELP   
一刀流剑术其实是刀法而不是剑术。
	
『棋盘切』（gobankiri）
需要100级一刀流剑术，有一定几率打落对手武器，如果不能打落则攻击
对手一招，攻击时有小几率双方对拼而令对手亦忙乱两轮。自我忙乱两轮。
须注意的是，无论成败，60秒内无法对同一对手作击落武器的尝试。

『百鬼夜狂』（hyakki）
需要150级的一刀流剑术，用尽所有杀气攻击对手，出此招的条件为
	（１）至少具有一点杀气
	或者（２）每１２０秒一次
击中敌人越多，自我忙乱越短，若七击皆落空，自我忙乱八轮。
若击中五招以上，对方和自身均会忙乱三轮。
HELP
    );
    return 1;
}
