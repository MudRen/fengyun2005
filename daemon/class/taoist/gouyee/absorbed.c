// hippo @ fy2005 workgroup. 2010.03.07

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
	mapping buff;
	int extra, duration, time;

	if( me->query("class")!="taoist" ) {
		return notify_fail("只有三清弟子才能使用此心法！\n");
	}
	if( ANNIE_D->check_buff(me,"feat") ) {
		return notify_fail("你正在施展类似技艺，无法使用『专注』。\n");
	}
	if( ANNIE_D->check_buff(me,"manatwist") ) {
		return notify_fail("你正在施展『专注』。\n");
	}
	extra = me->query_skill("necromancy",1);
	if( me->query_skill("taoism",1) < 220 || me->query_skill("gouyee")< 150 ) {
		return notify_fail("『专注』心法需150级谷衣心法和220级天师正道。\n");
	}
	
	if( userp(me) ) {
		duration = me->query("timer/pfm/manatwist") + 180 - time();
		if( duration > 0 ) {
			return notify_fail(MAG"『专注』消耗心神太甚，还需等待"+duration+"秒。\n"NOR);
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
      "name":"谷衣心法·专注",
      "time":120,
      "buff_msg":HIB"$N"HIB"默念清心咒，仿佛身心已到另个境界。\n"NOR,
      "disa_type":1,
      "disa_msg":CYN"$N"CYN"的身心疲惫，再也无法集中精神。\n"NOR,
    ]);
    ANNIE_D->buffup(buff);
    return 1;
}