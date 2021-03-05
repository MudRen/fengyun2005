

int general_heal(object me, object target, string limit, int amount, int cost, string msg_self, string msg_target, string type) {
	
		if( me->is_fighting() || target->is_fighting()) {
        	tell_object(me,"战斗中运功疗伤？找死吗？\n");
        	return 1;
        }
  
  		if (!objectp(target))	target = me;
  			      
        switch (limit) {
        	case "party":	if (target != me && !me->team_member(target)) {
        						tell_object(me, "你只能给同一队伍中的人疗伤。\n");
        						return 1;
        					}
        					break;
        	case "others":	if (me == target) {
        						tell_object(me, "你只能用此心法疗他人的伤。\n");
        						return 1;
        					}
        					break;
        	case "self":	
        	default:		if (me != target) {	
        						tell_object(me, "你只能用此心法疗自己的伤。\n");
        						return 1;
        					}
        					break;
        }
       
       	if (!COMBAT_D->legitimate_heal(me,target)) {
			tell_object(me, "你不能向此人使用此疗伤心诀（江湖仇杀限制）\n");	  
            return 1;
        }
            
		if(me->query("force") < me->query("max_force")) {
        	tell_object(me, "疗伤时至少需要有最大内力值护体。\n");
        	return 1;
        }
       
       	if (target->query("eff_"+ type)>= target->query("max_"+type)) {
       		tell_object(me,"此人已经不需要使用此疗伤心法了。\n");
       		return 1;
       	}
       	
       	 
		if (me->query("force")< cost) {
			tell_object(me, "疗伤需要"+cost+"点内力。\n");
			return 1;
		}
		me->add("force", -cost);
					
		if (target != me)
			message_vision(msg_target, me, target);
		else
			message_vision(msg_self, me);
		tell_object(target,"你的伤势好了一些。\n");

		amount = amount* (100 + me->query_skill("prescription",1)/4)/100;
		amount = COMBAT_D->magic_modifier(me, target, type, amount);
		target->receive_curing(type, amount);

		return 1;
}

