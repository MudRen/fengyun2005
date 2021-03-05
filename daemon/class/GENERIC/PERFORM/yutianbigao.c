#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra,mod;
	int tmp;
	int basic;
	int i, flag;
	object weapon,*team, *team1;
	mapping buff;
	
	
	if (ANNIE_D->check_buff(me,"fg-afo-ytbg")<1)
		return notify_fail("你学的武功中没有此项特技。\n");
		
	weapon = me->query_temp("weapon");
	if (!weapon)
		return notify_fail("空手无法使用此特技。\n");
				
	extra = me->query_temp("pfm/fg-afo-ytbg");
	
//	write ("extra = " + extra + "\n");	
/*	if ( extra < 140 || me->query_skill("skyforce",1) < 140 || tmp < 120) 
		return notify_fail("至少需要140级的血战枪法、140级的碧空心法和120级的鲲鹏步法！\n");	*/
			
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『与天比高』只能对战斗中的对手使用。\n");
		
	basic=4;
	
	extra = extra * 60/200;			// coeff adjustion.	half of real ytbg
	
	msg = HIY "\n\n$N"HIY"以手中" +weapon->name()+ HIY"点地，身形如鲲鹏展翅，一飞冲天，竟然使出了一式『与天比高』！\n"NOR;
	message_vision(msg, me, target);
		
	mod =10;
	 	
	if(COMBAT_D->do_busy_attack( me, target, "xuezhan-spear/yutianbigao", "rev-unarmed", 100, mod))
	{
		message_vision(BLU"结果$N"NOR+BLU"目瞪口呆，不知如何招架！\n"NOR,target);
		target->start_busy(1);
       	me->add_temp("apply/damage",extra);
       	for(i=0;i<basic;i++)
       	{
	   		if (me->is_busy()) continue;
	   		msg = HIY"长笑声中，$N"YEL"凌空下击，接着又借力上跃！\n"NOR;
	   		
	   		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg,"刺伤");		
		}
		me->add_temp("apply/damage",-extra);
		target->stop_busy();
		me->perform_busy(3);	
	}
	else{
		me->perform_busy(2);
		message_vision(YEL"但是$N一眼看破$n"NOR+YEL"的攻势，$n"NOR+YEL"先手既失，处处受制！\n"NOR,target,me);
		if (!target->is_busy()){
			msg = YEL"$N"NOR+YEL"乘机向$n"NOR+YEL"攻击。\n"NOR;
			target->add_temp("apply/attack", extra);
			target->add_temp("apply/damage", extra);
			COMBAT_D->do_attack(target,me,TYPE_PERFORM,msg);
			target->add_temp("apply/attack",-extra);
			target->add_temp("apply/damage",-extra);
		}
	}
	
	ANNIE_D->debuff(me,"fg-afo-ytbg");
	
	return 1;
}



