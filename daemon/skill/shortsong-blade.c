#include <ansi.h>
inherit SKILL;

void setup()
{
	set("name","短歌刀法");
	set("type","blade");
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",150);
	set("practice_limit",100);
	set("difficulty",200);
	set("eff_parry_level",150);
	set("skill_class","legend");
	set("parry_msg", ({
		"$n使出一招「唯有杜康」，用手中的$v急削$N的五指。\n",
		"$n左脚踏前一步，一招「青青子衿」，手中的$v从侧面飘向$N之必救。\n",
		"$n手中的$v一抖，挽出一片刀花，一招「悠悠我心」，撒向$N的全身。\n",
		"$n微退一步，手中的$v划出一条光弧，一招「但为君故」，将$N的全身围住。\n",
	}) );
	set("unarmed_parry_msg", ({
		"$n使出一招「沉吟至今」，用手中的$v急砍$N。\n",
		"$n左脚踏前踏，一招「呦呦鹿鸣」，手中的$v挥向$N之必救。\n",
		"$n手中的$v一抖，一招「山不厌高」，奔向$N。\n",
		"$n手中的$v划出一招「天下归心」，将$N的全身围住。\n",
	}) );	
	action = ({
		([	"action":		"$N使一招「对酒当歌」，手中$w风似地向$n的$l斩去！",
			"damage":		150,
			"dodge":		70,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N弯刀似月，$w随著一招「人生几何」由下而上撩往$n的$l",
			"damage":		250,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N身形一转，一招「譬如朝露」$w如朝露闪烁，斩向$n的$l",
			"damage":		90,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N舞动$w，一招「去日苦多」往$n的$l斜斜砍出一刀",
			"damage":		50,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N手中$w一晃，一招「慨当以慷」迅捷无伦地劈向$n的$l",
			"damage":		150,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N提气丹田，身型咋展，一招「忧思难忘」直劈$n$l",
			"damage":		110,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N移步侧身，使一招「何以解忧」刀光霍霍斩向$n的$l",
			"damage":		130,
			"damage_type":	"割伤"
		]),
	});
}


int valid_learn(object me)
{
	if( (string)me->query_skill_mapped("force")!= "qidaoforce" ) {
		return notify_fail("短歌刀法必须配合铁雪内功才能练。\n");
	}
	if( me->query_skill("qidaoforce",1) <= me->query_skill("shortsong-blade",1) && me->query_skill("qidaoforce",1) < 150 ) {
		return notify_fail("短歌刀法必须有相当的铁雪内功作基础。\n");
	}
	if( !::valid_learn(me) ) {
		return 0;
	}
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object ob;
	if( random(damage_bonus) < 300 ) {
		return 0;
	}
	if( ob = victim->query_temp("weapon") ) {
		if( ob->query("skill_type") == "sword" ) {
			if( victim->query_skill_mapped("sword") == "diesword" ) {
				if( me->query_skill("blade") > victim->query_skill("sword") ) {
					switch( random(3) ) {
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
					return random(me->query_skill("blade")) * 2;
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
	int /*skill,*/n;
	if (me) {
		n = me->query_temp("pfm/legend_jushen")*200;
		return n;
	}
	return 0;
}

int effective_level(object me)
{
	int /*skill,*/n;
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
		skill = me ->query_skill("shortsong-blade", 1);
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
短歌刀法１５０级以下必须有相同等级的棋道心法为基础
短歌刀法２００级以上，学习系数增加到４００。

『刀剑若梦』（daojianruomeng）
两人合击之六连击，需要30级蝶恋花剑法（或短歌刀法）。	
自我忙乱三回合
额外攻击力＝额外伤害力＝对应短歌与蝶恋花等级
但最高不超过１００

『短歌长梦』（duangechangmeng）
攻击特技，需要棋道心法配合，自我忙乱2回合
额外伤害力＝短歌刀法等级
Ｌ３０	　二连击
Ｌ２００　每６０秒钟必可三连击一次，另有１０％几率
出三连击，若使用萧杀身法则几率上升到４０％－６０％

『短歌』（duange）
若对手成功躲闪了『短歌长梦』的最后一击，在五回合内使用
此招可攻出威力更大的额外一击，无自我忙乱。
额外攻击力＝短歌刀法等级＊３
额外伤害力＝短歌刀法等级＊２
若没有抓住时机，则此招只是普通一击，自我忙乱两轮。
需１００级短歌刀法

『长梦』（changmeng）
若对手成功招架了『短歌长梦』的最后一击，在五回合内使用
此招可攻出威力更大的额外一击，无自我忙乱。
额外攻击力＝短歌刀法等级＊３
额外伤害力＝短歌刀法等级＊２
若没有抓住时机，则此招只是普通一击，自我忙乱两轮。
需１５０级短歌刀法

HELP
    );
    return 1;
}