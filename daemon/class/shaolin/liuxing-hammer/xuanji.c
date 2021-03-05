// Silencer@fengyun	June.2005
//	+atk 85. +dmg 0;

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, duration, timer, time;
	object* enemy;
	mapping buff;

	if( me->query("class") != "shaolin" ) {
		return notify_fail("『玄机』是少林弟子的绝招。\n");
	}
	extra = me->query_skill("liuxing-hammer",1);
	if( extra < 170 || me->query_skill("hammer", 1) < 170 ) { 
		return notify_fail("『玄机』需要170级的反转流星锤法和170级的基本锤法。\n");
	}
	timer = 600;	
	duration = me->query("timer/pfm/sl_xuanji") + timer - time();
	if( duration > 0 ) {
		return notify_fail("『玄机』需要"+chinese_number(duration)+"秒后才能再次使用。\n");
	}
	enemy = me->query_enemy();
	if( !sizeof(enemy) ) {
		return notify_fail("『玄机』只能对战斗中的对手使用。\n");
	}
	if( target ) {
		return notify_fail("『玄机』不需要指定使用对象！！\n");
	}
	if( ANNIE_D->check_buff(me, "riposte") ) {
		return notify_fail("你已经在使用类似的武功了。\n");
	}
	me->set("timer/pfm/sl_xuanji", time());
	time = 60 + F_ABILITY->check_ability(me, "3_xuanji_add", 3) * 6;
	buff = 
		([
			"caster":me,
			"who":me,
			"type":"riposte",
			"att":"bless",
			"name":"流星锤法·玄机",
			"buff1":"counter_action_extra",
			"buff1_c":1,
			"time":time,
			"buff_msg":BBLU+HIY"$N"NOR+BBLU+HIY"招式放缓，古朴浑厚，目光锐利，尽指向对手破绽之处！\n"NOR,
		]);
	ANNIE_D->buffup(buff);
	return 1;
}
