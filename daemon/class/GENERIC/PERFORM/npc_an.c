//mimicat@fy4

#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{	
	int extra,my_exp;
	extra=me->query_skill("kwan-yin-spells",1);
	my_exp=me->query("combat_exp");
	
	if(me->query("class")!="lama")
		return notify_fail("只有大昭寺的弟子才能使用真言。\n");
	
	if(extra<60) return notify_fail("你的观音六字明咒不够熟练。\n");
	
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("这种真言只能对战斗中的对手使用。\n");
		
	if( me==target)
		return notify_fail("真言法术不能用在自己身上。\n");

	if( (int)me->query("mana") < 400 )
		return notify_fail("你的法力不够。\n");

	message_vision(
		HIR "$N身、口、意与佛成为一体，面色庄重，沉声念道“唵”！ \n"NOR,
			me, target );
	
	extra=extra*extra*100;
	
	if(my_exp/2+random(my_exp)*3/2+random(extra)>target->query("combat_exp"))
	{
		message_vision(RED"$n只觉得心头好象被重锤一击，灵魂似乎要离窍而去。 \n\n"NOR,me,target);
		target->receive_wound("gin", 10 + (int)me->query_skill("spells")*3 + random(2)*75,me);
	        COMBAT_D->report_status(target);
        	COMBAT_D->win_lose_check(me,target,1);
	}
	else
		message_vision(RED"$n只觉得心头一紧，急忙凝气护心。 \n"NOR,me,target);

	if (userp(me)) me->add("mana", -400);
	me->set("mana_factor", 0);
	me->start_busy(3);
	return 1;
}
