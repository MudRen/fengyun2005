// annie 07.2003
// dancing_faery@hotmail.com

// Cast on busied npc only. (cast after npc pfm)
// A: zero self busy. high hitrate.
// D: damage self if failed(up to 200 kee). reduce target busy by 1 if failed. 18sec cooldown time. 
//    cannot use to issue 'first strike'. very bad against 真气流转 npc. high throwing cost. 

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg,temp1;
	object weapon,*pros,shadow,newweapon;
	int attack_points, dodge_points,skill,count,i,j,k,level,num1,mod,duration;

	if (me->query("class")!="moon" && userp(me))
		return notify_fail("『无空漩流』为皓月宫特技。\n");
	
	skill = me->query_skill("starrain",1);	
	if (skill < 50)
		return notify_fail("『无空漩流』需要至少50级的寒星雨觞。\n");

	if (me->query_skill_mapped("force") != "snowforce")
       	return notify_fail("『无空漩流』需以冷雪心经发动。\n");	// limit enforce

	duration = me->query("timer/pfm/pyramid") + 12 -time();
	if (duration >0 )
       	return notify_fail("你还需等待"+ duration + "秒钟才能再次施出『无空漩流』。\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『无空漩流』只能对战斗中的对手使用。\n");
		
	if (!target->is_busy())
		return notify_fail("此人身形未滞，想以『无空漩流』困住他只怕不太容易。\n");

	mod = COMBAT_D->can_busy(me, target, "starrain");	
	if (!mod)
		return notify_fail("此人身形灵动，想以『无空漩流』困住他只怕不太容易。\n");
		
	if (target->query_busy()>=3)
		return notify_fail("此人已经在极度忙乱中了（>3），快抓紧时间进攻吧。\n");

	weapon = me->query_temp("weapon");
	count = weapon->query_amount();
	if (count < 10)
		return notify_fail("至少需要10枚暗器。\n");

	if (userp(me))	weapon->add_amount(-10);
	me->set("timer/pfm/pyramid",time());

	msg = HIW"\n$N"HIW"微微一笑，突然翻转大袖，只见袖落处断霞千缕，星星点点的银芒
潇潇如雨，飞泻倾覆，直落九天。\n"NOR;
	message_vision(msg,me,target);
	msg = WHT"星芒流绕在$n"NOR+WHT"身侧，丝丝入扣，缕缕蚀魂……\n"NOR;
	message_vision(msg,me,target);

	if (COMBAT_D->do_busy_attack( me, target, "starrain/wukongxuanliu", "unarmed", 400, mod))
	{
		if (target->query_busy() <3)
		{
			target->force_busy(3);
			target->set_temp("busy_timer/starrain",time());
		}
	}
	else
	{
		msg = HIR BLK"$N"HIR BLK"一个踉跄，张嘴喷出一口鲜血，漩光流阵立散，$n"HIR BLK"也趁势得脱。\n"NOR;
		message_vision(msg,me,target);
		if (target->query_busy() == 1)
			target->stop_busy();
		else
			target->force_busy(target->query_busy()-1);
			me->receive_damage("kee",skill,target);	
	}
	return 1;
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/

