// Silencer@fengyun4

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	int skill, duration;
	mapping buff;

	if( me->query("class") != "lama" ) { 
		return notify_fail("只有大昭子弟才能使用『伏虎式』\n");
	}
	skill = me->query_skill("fengmo-staff", 1);		
	if( skill < 40 ) {
		return notify_fail("『伏虎式』需要40级的疯魔杖法！\n");
	}
	if( me->query_temp("pfm/fengmo_1") || me->query_temp("pfm/fengmo_2") || me->query_temp("pfm/fengmo_3") ) {
		return notify_fail("你已经在使用类似的武功了。\n");
	}
	duration = me->query("timer/pfm/fengmo_1") - time() + 240  - F_ABILITY->check_ability(me, "fuhu_add") * 12;
	if( duration > 0 ) {
		return notify_fail("你还需要等待"+duration+"秒钟左右才能再次使用『伏虎式』\n");
	}

	if( !target ) {
		target = me;
	}
	if( target != me ) { 
		return notify_fail("『伏虎式』只能用在自己身上。\n");
    }   
	if( me->query("force") < 100 ) {    
		return  notify_fail("『伏虎式』需要100点内力。\n");   	
	}
	if( userp(me) ) {
		me->add("force", -100);
	}
	buff =
		([
			"caster":me,
			"who":me,
			"type":"pfm/fengmo",
			"att":"bless",
			"name":"疯魔杖法·伏虎式",
			"buff1":"pfm/fengmo_1",
			"buff1_c":1,
			"time":80,
			"buff_msg":WHT"$N"NOR+WHT"左手扶杖，右手向左右各发侧掌，左手提杖打横，右手以阳手接住，踏上
两步，正是疯魔杖法第一段起手式。。。。"HIR"伏虎\n\n"NOR,
			"disa_msg":YEL"你一套『伏虎式』演化完毕，稳住身形。\n"NOR,
			"special_func":0,
		]);

	ANNIE_D->buffup(buff);
	me->set("timer/pfm/fengmo_1", time());
	return 1;
}