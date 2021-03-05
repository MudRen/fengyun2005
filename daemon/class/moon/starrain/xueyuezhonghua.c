// annie 07.2003
// dancing_faery@hotmail.com
// NPC_ONLY * Final Strike

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg,temp1;
	object weapon,*pros,shadow,newweapon;
	int attack_points, dodge_points,skill,count,i,j,k,level,num1;

	if (userp(me) && !wizardp(me))
		return notify_fail("你的武功里没有此项特技。\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『雪月终华』只能对战斗中的对手使用。\n");
	
	skill = me->query_skill("starrain",1);

	if (skill < 200)
		return notify_fail("『雪月终华』需要至少200级的寒星雨觞。\n");

	if (me->query_skill_mapped("force") != "snowforce")
       	return notify_fail("『雪月终华』需以冷雪心经发动。\n");	// limit enforce

//	if (me->query("force") < 500)
//     	return notify_fail("『雪月终华』需要消耗至少500点内力。\n");	


	msg = HIW"$N"HIW"翩翩的细指如梦似幻般轻扬，点点雪色的萤光极速敛聚，在$N"HIW"手中结成了霜，
结成了舞，结成了一种令人目眩的辉煌。\n"NOR;
	message_vision(msg,me,target);

	msg = HIC"那是一种空幻的美感，带着死亡和新生的喜悦，在瞬间化为千万朵绚烂的烟花，
从人的心中拔除仅存的希望．．．\n"NOR;
	message_vision(msg,me,target);

	me->add_temp("apply/attack",me->query_skill("throwing")*4);
	me->add_temp("apply/damage",me->query_skill("throwing")*3);

	target->add_temp("combat_no_report",1);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM, " ");
	target->add_temp("combat_no_report",-1);

	me->add_temp("apply/attack",-me->query_skill("throwing")*4);
	me->add_temp("apply/damage",-me->query_skill("throwing")*3);

	if (target->query_temp("damaged_during_attack") )
	{
		message_vision(HIW"\n无数飞舞的素华凝聚进$n"HIW"的身体，又自$n"HIW"天庭蒸腾
而出，凝成了一缕白雾气。\n"NOR,me,target);
		COMBAT_D->report_status(target);
		target->perform_busy(3);
	}
	me->perform_busy(3);
	return 1;
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/

