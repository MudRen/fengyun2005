// Silencer @ FY4 workgroup. Aug.2004
#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
	int i, skill, iron, num, duration, ratio;
	mapping buff;

	if( me->query("class") != "shenshui" && userp(me) ) {
		return notify_fail("只有神水宫弟子才能使出『化血神功』的绝技。\n");
	}
	if( me->query_skill("nine-moon-force",1) < 160 || me->query_skill("nine-moon-spirit",1) < 160 ) {
		return notify_fail("『化血神功』需要160级九阴心经和160级姹女神功。\n");
	}
	if( ANNIE_D->check_buff(me, "damage_to_heal") ) {
		return notify_fail("你已经在运用类似的武功了。\n");
	}
	if( userp(me) ) {
		duration = me->query("timer/pfm/9moon_huaxue") + 600 - time() - F_ABILITY->check_ability(me, "3_huaxue_add", 3) * 20;
		if( duration > 0 ) {
			return notify_fail("『化血神功』极耗心神，尚需等待"+duration/60+"分钟左右。\n");
		}
	}

	if( me->query("sen") < 100 ) {
		return notify_fail("『化血神功』需要100点心神。\n");
	}
	if( userp(me) ) {
		me->receive_damage("sen", 100);
	}
	skill = me->query_skill("nine-moon-claw", 1);
	ratio = 50;
	ratio = ratio+F_ABILITY->check_ability(me,"huaxue_add")*5;
	buff =
		([
			"caster":me,
			"who":me,
			"type":"damage_to_heal",
			"att":"bless",
			"name":"九阴心经·化血神功",
			"buff1":"damage_to_heal",
			"buff1_c":ratio,
			"time":120,
			"buff_msg":BMAG + HIM"$N"BMAG+HIM"运起化血神功，丹田内如竹之空、似谷之虚。\n"NOR,
			"special_func":0,
		]);

	ANNIE_D->buffup(buff);
	me->set("timer/pfm/9moon_huaxue", time());
	return 1;
}

