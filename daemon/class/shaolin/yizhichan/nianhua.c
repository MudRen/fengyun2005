//mimicat@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    string msg;
    int extra,i, enp, ext, enf, damage;
	string *perform_msg=({
  BBLU + YEL"一股指风无声无息地袭向$n。\n"NOR,
  BBLU + YEL"\n如同天界响起了梵唱，指劲引动气流发出低低的声音。\n"NOR,
  BBLU + YEL"\n缓缓的指劲似清风拂上凝露的花瓣，然而露珠滚落时，花瓣也随风飘散了。\n\n"NOR,
	});

    if(me->query("class")!="shaolin")
	return notify_fail("拈花是少林绝技，你怎么可能会使呢？\n");

    extra = me->query_skill("yizhichan",1);
    if(extra<170) return notify_fail("拈花需要170级的一指禅修为。\n");

    if( !target ) target = offensive_target(me);
    if( !target
      ||      !target->is_character()
      ||      !me->is_fighting(target) )
	return notify_fail("拈花只能对战斗中的对手使用。\n");

    if (target->query("sen")<= target->query("max_sen")/2)
		return notify_fail("释迦文佛拈花示众，用意是制敌而非伤人，得饶人处且扰人吧。\n");

    message_vision(BBLU + HIY"\n$N右手食中两指轻轻搭住作拈花之状，左手缓缓伸起，向着$n弹了过去。\n"NOR,me,target);

	damage =0;
	
	for (i=0;i<3;i++) {
		msg = perform_msg[i];	
		enf = me->query_skill("force");			// 400
		ext = extra * extra* extra+me->query("combat_exp"); // 170^3+ my_exp= 4.9M + my_exp
		enp = target->query("combat_exp");
		message_vision(msg,me,target);
		if(random(ext+enp)>enp)
		{
		    damage = damage + enf + random(enf*extra)/200;		// 400+random(680)
		}
	}
	
	if (damage > 0) {
		message_vision(HIR"$n被一股柔和的指力一击，只觉心头别地一跳！\n"NOR,me,target);
		damage = COMBAT_D->magic_modifier(me, target,"sen", damage);     
	    target->receive_damage("sen",damage ,me );	
		COMBAT_D->report_status(target);
		COMBAT_D->win_lose_check(me,target,1);
	}
	else
	    message_vision(HIC"$n看破指风来势，以巧妙身法闪开了这一击！ \n\n"NOR,me,target);
	
	
	me->perform_busy(3);
    return 1;        
}     


