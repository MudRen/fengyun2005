// 倒轉陰陽 manatwist
// mana cost x 3,damage x 2

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
	mapping buff;
	int extra, duration, time;

	if( ANNIE_D->check_buff(me,"feat") ) {
		return notify_fail("你正在施展类似技艺，无法使用倒转阴阳。\n");
	}
	if( ANNIE_D->check_buff(me,"manatwist") ) {
		return notify_fail("你正在施展倒转阴阳。\n");
	}
	extra = me->query_skill("necromancy",1);
	if( me->query_skill("taoism",1) < 220 || me->query_skill("gouyee")< 150 ) {
		return notify_fail("『倒转阴阳』心法需150级谷衣心法和220级天师正道。\n");
	}
	if( userp(me) ) {
		duration = me->query("timer/pfm/manatwist") + 1800 - time();
		if( duration > 0 ) {
			return notify_fail(MAG"『倒转阴阳』消耗心神太甚，还需等待"+(duration/60)+"分钟。\n"NOR);
		}
	}
	me->set("timer/pfm/manatwist",time());
	buff =
		([
			"caster":me,
			"who":me,
			"type":"feat",
			"type2":"manatwist",
			"att":"bless",
			"name":"三清禁法·倒转阴阳",
			"time":30,
			"buff_msg":HIB"$N"HIB"半蹲而下，心握太清灵智，身边蓝雾云集，不时有紫色火花在飞窜闪电里爆出。\n"NOR,
			"disa_type":1,
			"disa_msg":CYN"$N身边的云气渐渐散去，只见$N"NOR+CYN"气喘不息，汗如雨下。\n"NOR,
		]);
	ANNIE_D->buffup(buff);
	return 1;
}


/* bolt --> 50 + 560 + random(560) = [610+random(560)]*flag
  demonic --> 1800 *flag
  thunderbolt --> (690*flag)
  thunderstorm --> (1380) * flag
  */