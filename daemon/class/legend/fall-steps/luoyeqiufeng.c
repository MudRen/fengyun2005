#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg, type;
	int extra;
	int mod, rate;
	
	if( me->query("class") != "legend" ) {
		return notify_fail("落叶秋风为铁雪特技。\n");
	}
	if( me->query_temp("pfm/luoyeqiufeng") + 2 > time() ) {
		return notify_fail("你刚刚施展过『落叶秋风』，还没喘过气来。\n");
	}
	extra = me->query_skill("fall-steps",1);
	if( extra < 100 ) {
		return notify_fail("『落叶秋风』需要100级的秋风步！\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『落叶秋风』只能对战斗中的对手使用。\n");
	}
	if( ANNIE_D->check_buff(me,"tx-turtle-stance") ) {
		return notify_fail("你现在的身法纯属守势，无法使用灵活多变的落叶秋风。\n");
	}
	mod = COMBAT_D->can_busy(me, target, "fall-steps");
	if( !mod ) {
		return notify_fail(HIW"此人功力深湛，不会被此步法迷惑的。\n"NOR);
	}
	if( target->is_busy() ) {
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
	}
	message_vision(HIY"$N"+HIY"脚踏八方，身形如秋风中的落叶，飘渺不定！\n"NOR, me, target);
	me->set_temp("pfm/luoyeqiufeng",time());
	rate = 250;
	if( me->query_temp("pfm/legend_berserk") ) {
		rate = 200;
	}
	if( COMBAT_D->do_busy_attack(me, target, "fall-steps/luoyeqiufeng", "step", rate, mod) ) {
		message_vision(YEL"结果$N被扰得眼花潦乱，应接不暇！\n"NOR,target);
		target->force_busy(3);
		target->set_temp("busy_timer/fall-steps",time());
	} else {
		if( random(100) < F_ABILITY->check_ability(me,"3_luoye_add",3)*10 ) {
			message_vision(YEL"但是$N一眼看破$n"NOR+YEL"的步法，静气凝神,不为所动！\n"NOR,target,me);
		} else {
			msg = HIR"可惜$N"+HIR"看出了$n"+HIR"的身法，向$p"+HIR"倏然攻击！"NOR;
			me->add_temp("cant_dodge",1);
			me->add_temp("cant_parry",1);
			COMBAT_D->do_attack(target, me, TYPE_PERFORM, msg);
			me->add_temp("cant_dodge",-1);
			me->add_temp("cant_parry",-1);
		}
	}
	return 1;
}