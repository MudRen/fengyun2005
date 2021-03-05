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
	object obj;
	lvl = me->query_skill("bibo-force",1);
	if (lvl<80)
		return notify_fail("逼毒需要８０级的碧波心法！\n");
		
        if( target != me)
        	return notify_fail("碧波心法只能为自己驱毒。\n");
                
        force = me->query("force");
	if( force <=100) return notify_fail("逼毒需要１００点的真气。\n");
	me->add("force", -100  );
		
	message_vision(HIW"$N运功抗毒，头上冒出豆大的汗．．．\n"NOR, me);	
		
	if (random(lvl) < 50)		
		return notify_fail("你失败了。\n");
	else if (lvl < 100)
		me->clear_condition_type(GENERIC);
	else
		me->clear_condition_type(LOW_POISON);
	
	me->perform_busy(1);
	return 1;
		
}	
