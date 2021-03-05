// Silencer@fy4 workgroup
// Add 100% force instantly every 15mins.

#include <ansi.h>

int exert(object me, object target)
{
	int extra, timer, duration, i, num, time;
	mapping buff;
	object *enemy;

	if( me->query("class") != "shaolin" ) {
		return notify_fail("只有少林高僧才能使用『佛光普照』\n");
	}
	extra = me->query_skill("yijinjing", 1);
	if( extra < 150 ) {
		return notify_fail("需要150级易筋经才能使用『佛光普照』\n");
	}
	duration = me->query("timer/pfm/sl_fgpz") - time() + 1200 - F_ABILITY->check_ability(me,"foguang_add")* 30;
	if( duration > 0 ) {
		return notify_fail("你还需要等待"+(int)(duration/60+1)+"分钟左右才能再次使用『佛光普照』。\n");
	}
	enemy = me->query_enemy();
	num = sizeof(enemy);
	if( num == 0 ) {
		return notify_fail("『佛光普照』只能对战斗中的对手使用。\n");
	}
	if( me->query("force") < 200 ) {
		return notify_fail("『佛光普照』需要200点内力。\n");
	}
	if( userp(me) ) {
		me->add("force", -200);
	}
	time = 20 + F_ABILITY->check_ability(me, "3_foguan_add", 3) * 2;
	message_vision(BRED + HIY"\n$N"BRED + HIY"双手合十，一招万佛朝宗以跪拜之势平平升起，身后霞霓万丈，佛光普照。\n\n"NOR,me);
	for( i = 0; i < num; i++) {
		buff =
		([
			"caster":me,
			"who":enemy[i],
			"type":"nulldodge",
			"att":"curse",
			"name":"易筋经·佛光普照",
			"buff1":"cant_dodge",
			"buff1_c":1,
			"time":time,
			"buff_msg":HIG"$N"HIG"为$n"HIG"的无上气势所震撼，怔怔地竟不知闪避。\n"NOR,	
			"disa_msg":WHT"$N"NOR+WHT"浑身一凛，恍若大梦初醒。\n" NOR,
			"disa_type":1,		
		]);
		ANNIE_D->buffup(buff);
	}	
	me->set("timer/pfm/sl_fgpz", time());
	return 1;
}


