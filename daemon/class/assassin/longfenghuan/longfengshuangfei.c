// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,cl,mun;
	object weapon;

	extra = me->query_skill("longfenghuan",1) ;
	if ( extra< 100) return notify_fail("你的龙凤双环还不够纯熟！\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『龙凤双飞』只能对战斗中的对手使用。\n");

	if (extra> 185 && me->query("class")=="assassin") extra *= 3;
		else if (extra >150 && me->query("class")=="assassin") extra = extra *5/2;
			else extra = extra*2;

	cl += F_ABILITY->check_ability(me, "3_lfbj_add", 3);
		if( cl + 5 > random(100) ) {
				extra = extra*2;
				message_vision(RED"$N暗运静行心法，徒增两分煞气。\n"NOR,me);		
			}
	cl=F_ABILITY->check_ability(me, "3_lfsf_add", 3)+1;



	extra=extra+extra*cl/20;	

	weapon = me->query_temp("weapon");
	me->add_temp("apply/attack", extra/3);	
	me->add_temp("apply/damage", extra);
	msg = HIR "$N双臂一震，一招『龙凤双飞』，手中的"+ weapon->name()+ HIR"飞出击向$n！" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);

	me->add_temp("apply/attack", -extra/3);
	me->add_temp("apply/damage", -extra);
	
	

        if(extra > 550 &&  target->query_temp("damaged_during_attack")) {
        	if (target->query_busy()<=1) target->start_busy(1);
		message_vision(WHT"$N被砸得晕头转向，不知所措。\n"NOR,target);
		}
		
	if ( me->query_skill_mapped("force") == "jingxing"
		&& me->query_skill("jingxing",1)>=150 && me->query("class")=="assassin")
			message_vision(YEL"      $N暗运静行心法，双掌一个回旋，"+weapon->name()+YEL"似有灵性般飞回到$N手中。\n"NOR,me);
		else if (userp(me) && weapon->unequip()) weapon->move(environment(me));

	me->perform_busy(2);
	return 1;
}
