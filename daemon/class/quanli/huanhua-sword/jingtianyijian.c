// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,extra,aaa;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［惊天一剑］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("huanhua-sword",1) *3;
	aaa = me->query_skill("huanhua-sword",1) ;
	if ( aaa < 100) return notify_fail("你的［浣花剑法］还不够纯熟！\n");
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
	lvl = (int) me->query_skill("sword") / 100;
	
	if(target->is_busy())
		return notify_fail(target->name()+"还在发呆！\n");
      	
      	if(random(myexp * lvl) < yourexp )
	{
	        msg=HIR"$N凌空跃起，手中的"+ weapon->name() +HIR"自上而下，"+CYN"武林第一剑---［惊天一剑］"+HIR"犹如惊天之式刺向$n！"NOR;
		me->add_temp("apply/attack", extra)/10;	
		me->add_temp("apply/damage", extra)/10;
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		message_vision(HIW "只见天空中一道金虹一闪而没．．．．\n"NOR,target);
		me->add_temp("apply/attack", -extra);
		me->add_temp("apply/damage", -extra);
	        target->start_busy(1);    
	        me->start_busy(2);  
	}
	else{
		message_vision(BLU "$N持剑狂舞，$n被［惊天一剑］的剑招吓呆了，傻痴痴地一动也不动。\n"NOR,me,target);
		target->receive_damage("sen",500);
	        target->start_busy(4); 
	     }
      	return 1;
}
