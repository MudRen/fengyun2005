// Silencer @ FY4 workgroup. Oct.2004
// 必中的BUSY, 每1.5分钟使用一次

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int lvl, i, mod, extra, n, skill, duration;

	if( userp(me) ) {
		if( me->query("class") != "legend" ) {
			return notify_fail("『五展梅』是铁雪山庄的独门武功。\n");
		}
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『五展梅』只能对战斗中的对手使用。\n");
	}
	extra = (int)me->query_skill("meihua-shou", 1);
	skill = me->query_skill("six-sense", 1);
	if( extra < 150 || skill < 250 ) {
		return notify_fail("『五展梅』需要250级的六灵暗识和150级的梅花手。\n");
	}
	duration = me->query("timer/pfm/tx_wzm") + 90 - time() - F_ABILITY->check_ability(me,"3_wuzhanmei_add",3)*3;
	if( duration > 0 ) {
		return notify_fail("你还需要等待"+(int)(duration)+"秒钟左右才能够再次使用五展梅。\n");
	}
	if( target->is_busy() ) {
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
	}
	mod = COMBAT_D->can_busy(me, target, "meihua-shou");	
	if( !mod ) {
		return notify_fail(HIW"此人功力深湛，不会被此掌法迷惑的。\n"NOR);
	}
	me->set("timer/pfm/tx_wzm",time());
	// INherently, Every busy has 4*level hate, unarmed makes it 14x
	if( target && !userp(target) ) {
		target->add_hate(me, F_LEVEL->get_level(me->query("combat_exp"))*10);
	}
	message_vision(HIY"\n$N飞身而起，一飞起就出手，出手便如点点血花，在$n眼前绽放！！！\n\n"NOR, me, target);
	msg = HIR "$N"HIR"双手幻出漫天梅花，飞雪似的向$n"HIR"落来！\n" NOR;
	msg += WHT"结果$n被$N攻了个手忙脚乱！\n"NOR;
	message_vision(msg, me, target);
	target->start_busy(3); // bypass zqlz
	me->perform_busy(1);
	return 1;
}