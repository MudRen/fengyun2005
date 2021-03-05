// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,extra;
	int damage;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	target->is_corpse()
	||	target==me)
		return notify_fail("你要对谁施展［万毒归宗］？\n");

	if((int)me->query("kee") < 100 )
		return notify_fail("你的气血不够！\n");
	me->receive_wound("kee", 100);
	extra = me->query_skill("feiyuanpoison",1) ;
	if( extra <=60) return notify_fail("你的［非冤布毒术］还不够熟练！\n");
	msg = HIC "$N凝神贯注，偷偷地向$n布毒！\n\n" NOR;

	myexp = me->query("combat_exp");
	yourexp = target->query("combat_exp");
	lvl = me->query_skill("feiyuanpoison") / 20 ;
		damage = me->query_skill("feiyuanpoison");
	if( random(myexp * lvl) > yourexp )
	{
	msg +=  HIR "万灼之毒无声无息地渗入$n的体内．．．\n" NOR;
     	message_vision(msg,me,target);
	target->apply_condition("wanzhuo",random(15)+10);
	target->receive_damage("gin", damage, me);
	target->receive_wound("gin", damage, me);
	} 
		else
		{
		msg += "但是被$n发现了！！\n";
	        message_vision(msg,me,target);
		target->kill_ob(me);
		me->kill_ob(target);
		}

	me->start_busy(2);
	return 1;
}
