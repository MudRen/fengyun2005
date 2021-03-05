// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, bonus;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『右手诀』只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	
	extra = me->query_skill("sword");
	bonus = me->query_skill("lefthand-sword", 1);

	if (bonus>130) extra = extra + bonus;

	if (me->query("always_duxin") == 1)
	{
		// Fatal stroke ' 闪雷剑诀SCROLL
		me->add_temp("apply/attack", bonus*2);
		me->add_temp("apply/damage", extra*2);
		msg = HIY"\n$N"HIY"的手，突然按上了剑柄，剑光自鞘中逸出，一闪而没。\n"NOR;
	
		me->set_temp("annie/perform_duxin",1);
		target->add_temp("combat_no_report",1);
		message_vision(msg, me, target);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
		if (!target->query_temp("damaged_during_attack"))
			message_vision(YEL"\n$n"YEL"急退三步，险险避开了那道疾电寒光。\n\n"NOR,me,target);
		else
		{
			if (target->query("kee")<0)
				message_vision(WHT"
剑光只一闪已刺入了$n咽喉，剑锋入喉仅七分。
$n身子突然一阵抽搐，咽喉中发出了“格”的一响。"HIR"
剑出，鲜血飞激！
\n"NOR, me, target);
			else
			{
				msg = WHT"剑光只一闪已刺入了$n前胸，入肌三寸！\n"NOR;
				message_vision(msg, me, target);						
				COMBAT_D->report_status(target);
			}
		}
		target->add_temp("combat_no_report",-1);
		me->set_temp("annie/perform_duxin",0);
		me->add_temp("apply/attack", -bonus*2);
		me->add_temp("apply/damage", -extra*2);
		me->set("timer/pfm/duxin",time());

		// this perform ignore parry_busy' BUSY.
		me->stop_busy();
		me->perform_busy(2);
		return 1;
	}

	if ((!me->query("annie/duxin") 
		|| (target->query("kee") > target->query("max_kee")/4 
		&& target->query("kee")> 1000)
		|| me->query("timer/pfm/duxin") + 120 > time())
	)
	{
		me->add_temp("apply/attack", bonus);	
		me->add_temp("apply/damage", extra);
		msg = HIR"$N"+HIR"将"+weapon->name() +HIR"换到右手，更快，更毒，更准地向$n"+HIR"刺出！\n" NOR;
		message_vision(msg, me, target);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
		me->add_temp("apply/attack", -bonus);
		me->add_temp("apply/damage", -extra);
	}
	else
	{
		// Fatal stroke ' 闪雷剑诀SCROLL
		me->add_temp("apply/attack", bonus*2);
		me->add_temp("apply/damage", extra*2);
		msg = HIY"\n$N"HIY"的手，突然按上了剑柄，剑光自鞘中逸出，一闪而没。\n"NOR;
	
		me->set_temp("annie/perform_duxin",1);
		target->add_temp("combat_no_report",1);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		message_vision(msg,me,target);
		if (!target->query_temp("damaged_during_attack"))
			message_vision(YEL"\n$n"YEL"急退三步，险险避开了那道疾电寒光。\n\n"NOR,me,target);
		else
		{
			if (target->query("kee")<0)
				message_vision(WHT"
剑光只一闪已刺入了$n咽喉，剑锋入喉仅七分。
$n身子突然一阵抽搐，咽喉中发出了“格”的一响。"HIR"
剑出，鲜血飞激！
\n"NOR, me, target);
			else
			{
				msg = WHT"剑光只一闪已刺入了$n前胸，入肌三寸！\n"NOR;
				message_vision(msg, me, target);						
				COMBAT_D->report_status(target);
			}
		}
		target->add_temp("combat_no_report",-1);
		me->set_temp("annie/perform_duxin",0);
		me->add_temp("apply/attack", -bonus*2);
		me->add_temp("apply/damage", -extra*2);
		me->set("timer/pfm/duxin",time());

		// this perform ignore parry_busy' BUSY.
		me->stop_busy();
	}
	
	me->perform_busy(2);
	return 1;
}


/* too romantic, Jing is a killer, annie :)

msg = HIR"\n$N"+HIR"突然微笑起来，右手握住"+weapon->name() +HIR"剑柄，顿时光华自鞘中逸出，一闪而没。" NOR;
message_vision(HIR"\n只见$n胸前飞散出一片鲜血，仿佛是庭中花树摇落如雨如烟，风尽剑息洒下满地残红。\n"NOR,me,target);

╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
