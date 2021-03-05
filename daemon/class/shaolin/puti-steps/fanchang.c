// Silencer @ FY4 workgroup. Oct.2004

#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
    	int skill,duration;
    	object room;
    	    	
    	if (me->query("class")!="shaolin")  
     		return notify_fail("唯有少林高僧才能使用『天籁梵唱』\n");
     		    	
    	skill = me->query_skill("puti-steps", 1);
		if(skill < 150 || me->query_skill("zen",1)<160) 
			return notify_fail("『天籁梵唱』至少需要150级菩提虚空步法和160级禅道！\n");
	 
	 	if (me->is_fighting())
	 		return notify_fail("『天籁梵唱』不能在战斗中使用。\n");
	 		
    	if (!target)
    		return notify_fail("你想向哪具尸体使用『天籁梵唱』？\n");
    	
    	if (!target->is_corpse())
    		return notify_fail("『天籁梵唱』对死去的人使用。\n");
    	       	
        if( (int)me->query("force") < 100 )     
    		return notify_fail("『天籁梵唱』需要耗费100点内力。\n");
    	if (userp(me))	me->add("force", -100);
	    
		message_vision(HIW"$N面对"+target->query("victim_name")+"的尸体团坐下来，左右手指在丹田慢慢合拢，低声颂佛，
佛音如网交织，无处不在，无方不显，声如蚊纳，绵绵不绝有如天籁梵唱。\n"NOR, me);
		
		room = environment(me);
		call_out("getup", 6, me, room);
		me->perform_busy(3);
		return 1;
}


int getup(object me, object room) {
	
	int amount;
	
	if (!me)	return 1;
	if ( room != environment(me))	return 1;
	
	tell_object(me,WHT"你颂经完毕，慢慢起身，只觉心中一片空明。\n"NOR);
	amount = me->query_skill("zen",1) * 4;	// 800 top
	me->receive_curing("kee", amount);
	return 1;
}

		