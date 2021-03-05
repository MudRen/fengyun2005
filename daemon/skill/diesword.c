#include <ansi.h>
inherit SKILL;

void setup()
{
	set("name","蝶恋花剑法");
	set("type","sword");
	set("effective_level",150);
	set("eff_parry_level",150);
	set("usage/sword",1);
	set("usage/parry",1);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","legend");
	
	set("parry_msg", ({
		"$n使出一招「望极春愁」，手中的$v荡开了$N的$w。\n",
		"$n使出「黯黯生天际」，将$N的$w封于丈外。\n",
		"$n使出一招「强乐还无味」，手中的$v化做漫天残照，荡开了$N的$w。\n",
		"$n手中的$v一抖，一招「对酒当歌」，向$N拿$w的手腕削去。\n",
	}) );
	set("unarmed_parry_msg", ({
		"$n将手中的$v舞得密不透风，一招「拟对强衣为」封住了$N的攻势。\n",
		"$n反手一招「伫望黯草无」，整个人消失在一团剑光之中。\n",
		"$n使出一招「倚极黯色言」，$v直刺$N的双手。\n",
		"$n将手中的$v一抖，一招「把酒乐带伊」，迫得$N连连后退。\n",
	}) );
	action = ({
		([	"action":		"$N使一招「伫倚危楼风细细」，手中$w如柔风一般卷向$n的$l",
			"dodge":		20,
			"damage" :		200,
			"damage_type":	"刺伤"
		]),
		([	"action":		"$N使出蝶恋花剑中的「草色烟光残照里」，剑光象残照般洒向$n的$l",
			"dodge":		20,
			"damage":		200,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N一招「无言谁会凭栏意」，手中$w默默的削向$n的$l",
			"dodge":		30,
			"damage":		50,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N手中$w一式「拟把疏狂图一醉」对准$n的$l一连刺出七剑",
			"damage":		90,
			"damage_type":	"刺伤"
		]),
		([	"action":		"$N的$w凭空一指，一招「衣带渐宽终不悔」刺向$n的$l",
			"dodge":		20,
			"damage":		300,
			"damage_type":	"刺伤"
		]),
		([	"action":		"$N手中$w向外一分，使一招「为伊消得人憔悴」反手对准$n$l一剑刺去",
			"dodge":		20,
			"damage":		100,
			"damage_type":	"刺伤"
		]),
	});
}


int valid_learn(object me)
{
	if( (string)me->query_skill_mapped("force")!= "qidaoforce")
        return notify_fail("蝶恋花剑法必须配合铁雪内功才能练。\n");
	if (me->query_skill("qidaoforce",1)<= me->query_skill("diesword",1)
		&& me->query_skill("qidaoforce",1)<150)
		return notify_fail("蝶恋花剑法必须有相当的铁雪内功作基础。\n");
			
	if(!::valid_learn(me))
    		return 0;
    
    return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	object ob;
	if( random(damage_bonus) < 300 ) {
		return 0;
	}
	if( ob = victim->query_temp("weapon") ) {
		if( ob->query("skill_type") == "blade" ) {
			if( victim->query_skill_mapped("blade") == "shortsong-blade" ) {
				if( me->query_skill("sword") > victim->query_skill("blade") ) {
					switch(random(3)) {
						case 0:
							message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
							break;
						case 1:
							message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
							break;
						case 2:
							message_vision(HIR "\n因刀剑相克，$n逐渐施展不开了！" NOR,me,victim);
							break;
					}
					return random(me->query_skill("sword")) * 2;
				}
			}
		}
	}
	return 0;
}


int damage_level(object me)
{
	int skill, n;
	if( me ) {
		if( !me->query_temp("pfm/legend_berserk") && userp(me) ) {
			return 0;
		}
		skill = me->query_skill("six-sense",1);
		if( skill <= 100 ) {
			return 0;
		}
		if( skill >= 300 ) {
			return 200;
		}
		n = skill-100;
		return n;
	}
	return 200;
}


int accuracy_level(object me)
{
	int skill,n;
	if( me ) {
		n = me->query_temp("pfm/legend_jushen")*200;
		return n;
	}
	return 0;
}

int effective_level(object me)
{
	int skill,n;
	if( me ) {
		n = 150 + me->query_temp("pfm/legend_berserk");
		return n;
	}
	return 150;
}

int skill_difficulty()
{
	object me = this_player();
	int skill;
	if( me && userp(me) ) {
		skill = me ->query_skill("diesword", 1);
		if( skill < 200 ) {
			return 200;
		} else {
			return 400;
		}
	}
	return 200;
}

int help(object me)
{
	write(@HELP
蝶恋花剑法１５０级以下必须有相同等级的棋道心法为基础
蝶恋花剑法２００级以上，学习系数增加到４００。

『刀剑若梦』（daojianruomeng）
两人合击之六连击，需要30级蝶恋花剑法（或短歌刀法）。
自我忙乱三回合
额外攻击力＝额外伤害力＝对应短歌与蝶恋花等级
但最高不超过１００

『彩蝶狂舞』（caidiekuangwu）
攻击特技，需要棋道心法配合，自我忙乱2回合
额外伤害力＝蝶恋花剑法等级
Ｌ３０	　二连击
Ｌ２００　每６０秒钟必可三连击一次，另有１０％几率
出三连击，若使用萧杀身法则几率上升到４０％－６０％

『彩蝶』（caidie）
若对手成功躲闪了『彩蝶狂舞』的最后一击，在五回合内使用
此招可攻出威力更大的额外一击，无自我忙乱。
额外攻击力＝蝶恋花剑法等级＊３
额外伤害力＝蝶恋花剑法等级＊２
若没有抓住时机，则此招只是普通一击，自我忙乱两轮。
需１００级蝶恋花剑法

『狂舞』（kuangwu）
若对手成功招架了『彩蝶狂舞』的最后一击，在五回合内使用
此招可攻出威力更大的额外一击，无自我忙乱。
额外攻击力＝蝶恋花剑法等级＊３
额外伤害力＝蝶恋花剑法等级＊２
若没有抓住时机，则此招只是普通一击，自我忙乱两轮。
需１５０级蝶恋花剑法
HELP
    );
    return 1;
}
