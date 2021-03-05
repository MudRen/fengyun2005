//About conditions types : （see condition.h 定义）高序列的解毒包括低序列。
//NO_CURE        -  不能医治的Conditions，一般是用在特定的场合。
//SPECIFIC_POISON     - 高级毒--- 此类毒无普遍解法，唯有对症的药物方行。
//MID_POISON   -    中级毒 -- 特定门派的解毒心法，或是名贵药物。 
//LOW_POISON    --  低级毒 -- 一般可以学到的心法，或是普通药物。
//GENERIC	-- 伤风咳嗽，醉酒花柳类。
//	--- Silencer@fy4  in 12/21/2002

inherit "/daemon/condition/generic_condition";
inherit SSERVER;

#include <ansi.h>
#include <condition.h>

int exert(object me, object target, int amount)
{
	int force, lvl;
	object obj, *mem;
	
	lvl = me->query_skill("iceheart",1);
    if( target != me && lvl < 100) 
       	return notify_fail("为他人逼毒需要100级冰心诀。\n");
                
    force =(int) me->query("force");
	if( force <=150) 
		return notify_fail("驱毒需要150点内力。\n");
	
	if (target == me)
	{
		message_vision(HIW"$N运功抗毒，头上冒出豆大的汗珠。。。。\n"NOR, me);	
		me->add("force", -100  );
		
		if (lvl < 75)
			me->clear_condition_type(GENERIC);
		else if (lvl < 150)
			me->clear_condition_type(LOW_POISON);
		else
			me->clear_condition_type(MID_POISON);
		message_vision(HIC"$N汗如雨下，哇地一声吐出一口黑血。\n"NOR, me);
       	return 1;	
	}	
	else	
	{
		if(!objectp(obj = present(target, environment(me))))
			return notify_fail("这里没有这个人。\n");

		if( !obj->is_character() || obj->is_corpse() )
			return notify_fail("看清楚一点，那并不是活物。\n");
		
		mem = me->query_team();
		if (!pointerp(mem) || member_array(target,mem) == -1)
			 return notify_fail("你只能给同一队伍中的人疗伤。\n");
	
		message_vision(HIW"$N一掌按在$n背心运功驱毒，头上冒出豆大的汗粒．．．\n"NOR, me,target);
		me->add("force", -150);
		
		if (lvl < 75)
			target->clear_condition_type(GENERIC);
		else if (lvl < 150)
			target->clear_condition_type(LOW_POISON);
		else
			target->clear_condition_type(MID_POISON);
		
			message_vision(HIC"$N汗如雨下，哇地一声吐出一口黑血，脸上的青气慢慢散去．．．\n"NOR, target);		
	}
	return 1;

}