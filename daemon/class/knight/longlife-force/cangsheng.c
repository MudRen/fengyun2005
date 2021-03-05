#include <ansi.h>

int exert(object me, object target, int amount)
{
	
	int skill, cost, i,duration;
	object *enemy, *mem;
	string msg;
	
		if (me->query("class")!="knight")
			return notify_fail("怜苍生为快活林的特技。\n");

    	skill = me->query_skill("longlife-force",1);
    	if (skill < 100)
    		return notify_fail("怜苍生至少需要100级的苍生诀。\n");
    	
    	duration = me->query_temp("timer/pfm/cangsheng")+20 - time();
    	if (duration>0)
    		return notify_fail("需要等待"+ duration + "秒才能再次使用怜苍生。\n");
    	
    	if (!target)	return notify_fail("你想向谁使用怜苍生？\n");
    	if (target == me)	return notify_fail("怜苍生不能用在自己身上。\n");
    	  	
    	if (!COMBAT_D->legitimate_heal(me,target))
		return notify_fail("你不能向此人使用此疗伤心诀。\n");
    	
    	mem = me->query_team();
		if (!pointerp(mem) || member_array(target,mem) == -1)
			 return notify_fail("你只能给同一队伍中的人疗伤。\n");
    	
    	if( me->query("force") < 200 && userp(me))
			return notify_fail("需要200点的真气。\n");
		if (userp(me))  me->add("force", -200);
	
	//  2000;
		cost = skill * 5;
		if (me->query("kee") < cost)
			return notify_fail("你自身难保，还救什么人？（至少需"+ cost + "点气血）\n");
	
		msg = HIG"$N"HIG"面色惨绿，尖啸一声，一掌击在$n"HIG"的后心，两人都是浑身剧震。\n"NOR;
		message_vision(msg, me, target);
	
		me->set_temp("timer/pfm/cangsheng",time());
		me->receive_damage("kee",cost);
		me->set_temp("last_damage_from","使用怜苍生救人身死。\n");
		target->receive_fulling("kee", cost*2, me);
	
		if(target->is_fighting()) {
			enemy = target->query_enemy();
			for (i=0;i<sizeof(enemy);i++) {
				if (!enemy[i]->is_fighting(me)) {
					enemy[i]->kill_ob(me);
					me->kill_ob(enemy[i]);
				}
			}	
		}	
	
		me->perform_busy(1);
		return 1;
}