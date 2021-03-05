// Originally coded by Lsb, modified by Tushen/Silencer 

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, duration;
	object weapon;
	int chance, busy;

	extra = me->query_skill("xuanyuan-axe", 1);
	if( me->query("class") != "knight" ) {
		return notify_fail("只有快活林弟子才能使出『九气破霄』的绝技。\n");
	}
	if( extra < 160 ) {
		return notify_fail("『九气破霄』需要160级的轩辕斧法！\n");
	}
	if( userp(me) && me->query_skill_mapped("force") != "longlife-force" ) {
		return notify_fail("轩辕斧法需要苍生诀的配合！\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『九气破霄』只能对战斗中的对手使用。\n");
	}
	duration = me->query("timer/pfm/jiuqipoxiao") + 30 - time();
	if( duration > 0 ) {
		return notify_fail("『九气破霄』耗力极大，需在" + duration + "秒后使用。\n");	
	}
	weapon = me->query_temp("weapon");
	me->add_temp("apply/attack",extra);
	target->set_temp("no_check_pfm_win",1);

/*	msg = HIY  "\n$N手中的"+ weapon->name()+HIY"舞动的速度愈来愈快，吼声愈来愈大
吼声中"+weapon->name()+HIY"突然雷霆霹雳般向$n"NOR+HIY"劈出一式『九气破霄』！！！\n\n" NOR;*/

	msg = YEL"$N"NOR+YEL"身边弥漫著浑沌之气，渐渐隐入了云雾之中，气流顺着一道奇异的轨迹
开始流动，由慢而快，竟然化作狂风。"HIY"

$N"HIY"大喝一声：开！手中"+ weapon->name()+ HIY"逆着那条轨迹直劈而去！\n"NOR,
	message_vision(msg,me,target);
	msg = HIW  "电光以炫其目！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);
	msg = HIW  "火石以乱其耳！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	msg = HIW  "撼三山以裂其心胆！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	msg = HIW  "震五岳以夺其斗志！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	msg = HIY  "九气破霄！"HIW"气流如破竹般撕裂，"+weapon->name()+HIW"夹着风雷之势当头劈下！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack",-extra);

	if( objectp(target) ) {
		if (target->query_temp("damaged_during_attack")) {
			 COMBAT_D->win_lose_check(me, target, 1);
		}
	}

	if( objectp(target) ) {
		target ->delete_temp("no_check_pfm_win"); 
		target->delete_temp("skip_damage_record");
	}

	msg = YEL"\n四周的气流似乎有响应一般，骤然散去，风息，雨歇，云开，雾散！\n\n\n"NOR,
	message_vision(msg, me, target);

	chance = F_ABILITY->check_ability(me, "resist_sen") * 10;
	if( random(100) < chance) {
		busy = 2;
	} else {
		busy = 3;
	}
	me->perform_busy(busy);
	me->set("timer/pfm/jiuqipoxiao", time());
	return 1;
}
/*
	message_vision(msg,me,target);
	msg = HIY  "电光以炫其目！手中的weapon" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	msg = HIY  "火石以乱其耳！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	msg = HIY  "撼三山以裂其心胆！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	msg = HIY  "震五岳以夺其斗志！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	TARGET身边弥漫著浑沌之气，ME渐渐隐入了云雾之中
	气流顺着一道奇异的轨迹开始流动，由慢而快，竟然化作狂风
	TARGET大惊失色，斗志尽失！
	大喝一声：开!手中AXE逆着那条轨迹直劈而去
	四周的气流如破竹一样被撕裂，TAR眼前一亮，ME手中的AXE竟夹着风雷之势追到了你的面前
	"九气破霄！" NOR;
	四周的气流似乎有响应一般，骤然散去
	风息，雨歇，云开，雾散。。。
	吟道：高山仰止 景行行止 虽不能至 心向往之 
 */