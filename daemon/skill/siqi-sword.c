//TIE@FY3
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","四奇剑法");
	set("type","sword");
	set("difficulty",200);
	set("usage/sword",1);
	set("usage/parry",1);
	set("skill_class","huangshan");
	set("effective_level",150);
	set("parry_msg", ({
       	 	"$n使出「桃源探幽」，手中$v曲曲折折，将$N手中的$w引偏了出去。\n",
		"$n$v飘忽不定，一招「飞凤青鸾」竟从意想不到的角度架住了$N手中的$w。\n",
		"$n手中的$v布满内力，一招「古柏劲松」，急削$N握$w的手指。\n",
		"$n手中的$v急运如飞，剑气连绵有如群山，一招「群峰叠翠」，锁住了$N的$w。\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n手中$v圆转，内力激荡，一招「云山雾绕」，强劲的剑气逼得$N连联后退。\n",
		"$n手中$v鼓出凛凛剑气，一招「引人入胜」，带得$N站立不稳。\n",
		"$n$v虚晃，身随剑势，在空中盘旋，一招「飞去来兮」，消失得无影无踪。\n",
		"$n转身，$v一招「云笼奇峰」，泛起一片光芒，将自己全身护得密不透风。\n",
	}) );	
	action = ({
		([	
			"action":		
			"$N使一招「苍松迎客」，身形暴长，手中$w一摆，向$n的$l刺去",
			"dodge":		50,
			"force":		170,
			"damage_type":	"刺伤"
		]),
		([	
			"action":		
			"$N身形拔地而起，手中$w舞动，满天剑气森森，一招「浮云漂渺」罩向$n的$l",
			"dodge":		-70,
			"force":		200,
			"damage_type":	"刺伤"
		]),
		([	
			"action":		
			"$N手中$w光芒闪闪，一招「飞瀑流泉」，瞬间已向$n的$l连攻数剑",
			"dodge":		-40,
			"damage":		90,
			"damage_type":	"刺伤"
		]),
		([	
			"action":		
			"$N手中$w一圈，带起满天沙尘，突然剑身一颤，化出无数剑尖，一招「怪石峥嵘」笼住$n的$l",
			"dodge":		-40,
			"damage":		40,
			"damage_type":	"刺伤"
		]),
		([	
			"action":		
			"$N$w闪动，幻出满天剑影，团团簇簇，一招「梦笔生花」往$n$l刺去",
			"dodge":		60,
			"damage":		120,
			"damage_type":	"刺伤"
		]),
		([	
			"action":		
			"$N身行跃起，手中$w挽出朵朵剑花，一招「喜鹊登梅」裹住$n的全身",
			"dodge":		-60,
			"damage":		150,
			"damage_type":	"刺伤"
		]),
	});
}
int valid_learn(object me)
{
    if( (string)me->query("gender") != "女性" )
                return notify_fail("四奇剑法是只有女子才能练的武功。\n");
	if( (int)me->query("max_force") < 50 )
		return notify_fail("你的内力不够，没有办法练四奇剑法。\n");
	if(!::valid_learn(me)){
		return 0;
	}
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 300 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "sword")
    if(victim->query_skill_mapped("sword") == "three-sword" )
    if(me->query_skill("siqi-sword",1) > victim->query_skill("three-sword",1)) {
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
    return random(me->query_skill("sword")) * 10;
    }
    return 0;
}

