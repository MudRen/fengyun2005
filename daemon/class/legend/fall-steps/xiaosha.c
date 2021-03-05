// Silencer@fengyun	June.2005
// L50： 『萧杀』持续3分钟，三刀三剑 的系数提高到１８０，定力下降１０

#include <ansi.h>
#include <combat.h>

inherit SSERVER;
int perform(object me, object target)
{
	string msg, type;
	int duration, extra, add, skill,num;
	mapping buff;

	extra = me->query_skill("fall-steps",1);
	skill = me->query_skill("six-sense",1);
	if( extra < 110 ) { 
		return notify_fail("『萧杀』需要110级的秋风步！\n");
	}
	if( me->query("class") != "legend" && userp(me) ) {
		return notify_fail("只有铁雪山庄的弟子才能够使用『萧杀』。\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me ) {
		return 	notify_fail("『萧杀』只能用在自己身上。\n");
	}	
	if( ANNIE_D->check_buff(me, "tx-atk-stance") > 0 ) {
		return notify_fail("你已经在使用『萧杀』了。\n");
	}
	duration = me->query_temp("timer/tx-stance")+30 - time();
	if( duration > 0 ) {
		return notify_fail("铁雪步法每30秒钟最多转换一次（"+duration+"）\n");
	}
	if( ANNIE_D->check_buff(me, "tx-df-stance") > 0 ) {
		ANNIE_D->debuff(me, "tx-df-stance");
		ANNIE_D->debuff(me, "kee1");
	}
	me->set_temp("timer/tx-stance", time());
	num = 20;
	if( extra >= 150 ) {
		if( skill >= 250 ) {
			num = 30;
		}
	}
	buff =
		([
			"caster":	me,
			"who": 		me,
			"type":		"tx-atk-stance",
			"att":		"bless",
			"name":		"秋风步·萧杀",
			"buff1": 	"pfm/legend_berserk",
			"buff1_c":	num,
			"buff2": 	"apply/composure",
			"buff2_c": 	-10,
			"time":  	600,
			"buff_msg":	WHT"寒意侵骨，杀气如水银泻地般弥漫在$N四周。\n"NOR,
		]);
	ANNIE_D->buffup(buff);
	return 1;
}
