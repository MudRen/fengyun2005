// Silencer@fengyun	June.2005
// 『寸进』可用来锁脉

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, duration;
	mapping buff;
	int mod;
	
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『寸进』只能对战斗中的对手使用。\n");
	}
	extra = me->query_skill("eagle-claw", 1);
	if( extra < 150 ) {
		return notify_fail("『寸进』需要150级的鹰爪功。\n");	
	}
	if( target->query("race") != "人类" ) {
		return notify_fail("『寸进』只能在“人”身上使用。\n");
	}
	duration = me->query("timer/pfm/fg_cunjin") - time() + 600;
    if( duration > 0 ) {
       	return notify_fail("你还需要等待"+(int)(duration/60+1)+"分钟左右才能再次使用寸进。\n");
	}
	if( target->query_temp("timer/lockup") + 60 > time() ) {
		return notify_fail("此人已经有防备了，恐怕不能得手，过上一阵再说吧。\n"); 
	}
	if( ANNIE_D->check_buff(target, "lockup") ) {
		return notify_fail("此人已经受到类似武功牵制了。\n");
	}
	mod = COMBAT_D->can_busy(me, target, "eagle-claw");	
	if( !mod ) {
		return notify_fail("此人功力深厚，此招无法得手。\n");
	}
	msg = BCYN + HIG "$N"BCYN+HIG"使出鹰爪功中的『寸进式』，大喝一声，纵身而上，双手犹如狂风骤雨，
“捕风式”、“捉影式”、“抚琴式”、“鼓瑟式”、“批亢式”、疾攻而至。
指风如刀，招招扣向$n"BCYN+HIG"的关节要害！\n" NOR;
	message_vision(msg, me, target);

	if( target->query("boss") || target->query("big_boss") ) {
		duration = 10;
	} else {
		duration = 30;
	}
	duration = duration + F_ABILITY->check_ability(me, "3_cunjin_add", 3) * 2;
	if( COMBAT_D->do_busy_attack(me, target, "eagle-claw/cunjin", "unarmed", 300, mod) ) {
		msg = BLU"$N"NOR+BLU"手势忽然变快，轻飘飘的点下去，从$n"NOR+BLU"左手无名指的第二个骨节一路
跳跃过去，跳过左肘，肩井，脊椎。。。。\n"NOR;
		message_vision(msg + "\n", me, target);
		tell_object(target, WHT"（你中了鹰爪功的锁脉式!）\n"NOR);
		buff =
		([
			"caster":me,
			"who":	 target,
			"type": "lockup",
			"att":  "curse",
			"name": "鹰爪功·锁脉",
			"time":  duration,
			"buff1": "till_death/lockup",
			"buff1_c": 1,
			"buff_msg": "",
			"warn_msg":"",
			"disa_msg": WHT"$N身形晃动，终于从指风中脱离出来。\n"NOR,
			"disa_type": 1, 
		]);
		ANNIE_D->buffup(buff);		
	} else {
		message_vision(YEL"$n步走蛇形，立刻移宫换斗，闪过了$N的铁指寸进。\n"NOR, me, target);
	}	
	target->set_temp("timer/lockup", time());
	me->set("timer/pfm/fg_cunjin", time());
	me->perform_busy(1);
	return 1;
}