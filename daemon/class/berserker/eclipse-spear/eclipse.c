// damage = 111,222,333,444,... 999
// = 4995

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra;
	object *pros;
	extra = me->query_skill("eclipse-spear",1);
	if ( extra < 200) return notify_fail("你的朔望长枪还不够纯熟！\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(MAG"蚀魂"NOR"只能对战斗中的对手使用。\n");
	
	msg = MAG"$N"MAG+me->query_weapon()->name()+"飒然倒卷，烈风鼓动，飞砂走石中化作半弯下弦朔月划向$n！\n"NOR;
	message_vision(msg, me, target);
	
	me->add_temp("apply/attack", extra*3/2);
	me->set_temp("annie/eclipse",1);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
	me->set_temp("annie/eclipse",0);
	me->add_temp("apply/attack", -extra*3/2);

	if (target->query_temp("damaged_during_attack"))
	{
		if (!target->query_temp("annie/eclipse_dot"))
		{
			target->receive_damage("kee",111,me);
			call_out("dot",1, me,target,1);  
			target->add_temp("annie/eclipse_dot",1);
		}
	}

	me->perform_busy(2);
	return 1;
}

void dot (object me, object enemy, int count)
{
	int num;
	if (!objectp(enemy))	return;
	
	if (!me || !enemy->is_fighting(me))
	{
		enemy->add_temp("annie/eclipse_dot",-1);
		return;
	}
	
	num = COMBAT_D->magic_modifier(me, enemy,"kee", count*111);
	enemy->receive_damage("kee",num,me);
	count= count + 1;
	if (count<10)
		call_out("dot",1,me, enemy,count);
	else
		enemy->add_temp("annie/eclipse_dot",-1);
	return ;
}



/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
