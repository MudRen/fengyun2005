// Silencer @ FY4 workgroup. Aug.2004
//	-160 sen DS

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
	int i, skill, duration, iron;

	if( me->query("class") != "lama" ) {
		return notify_fail("只有大昭弟子才能运用『舍身』\n");
	}
	skill = me->query_skill("bolomiduo", 1);
	if( skill < 100 ) {
		return notify_fail("『舍身』需要100级婆萝蜜多心经。\n");
	}
	iron = me->query_skill("lamaism", 1);
	if( iron < 100 ) {
		return notify_fail("『舍身』需要100级密宗佛法。\n");
	}
	duration = me->query_temp("timer/pfm/dz_sheshen") + 20 - time();
	if( duration > 0 ) {
		return notify_fail("你还需要等待"+ duration + "秒才能再次使用『舍身』\n");
	}
	amount = me->query("max_kee")*15/100;
	if( (int)me->query("kee") < amount ) {
		return notify_fail("『舍身』至少需要15%的气血。\n");
	}
	me->receive_damage("kee", amount);
	message_vision(BBLU+HIY"$N面透慈悲之色，双手合十，掌尖之处金光霍然绽放，从小变大，瞬间璀璨，放射出万道金光，
直冲云霄。低低梵唱，从小变大，瞬间响彻天地。\n"NOR, me);
	me->set_temp("timer/pfm/dz_sheshen", time());
	amount = me->query("max_mana")*4/5;
	if( me->query("mana") + amount < me->query("max_mana")*2 ) {
		me->add("mana", amount);
	} else {
		me->set("mana", me->query("max_mana")*2);	
	}
	me->force_status_msg("mana");
	me->perform_busy(1);
	return 1;
}