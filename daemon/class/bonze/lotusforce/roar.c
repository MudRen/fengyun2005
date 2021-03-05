// silencer@fy4 workgroup: 
// This is a long duration 20 sec area effect mesmerize perform. (10sec immune afterwards) 
// It needs /feature/damage.c to work properly.


#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

void remove_effect(object target);
void stop_effect(object target);

int exert(object me, object who, int amount)
{
        int i, skill, limit_skill, myexp, mod;
        object *enemy,*t, room, target;
                
        if(me->query("class")!="bonze")
		return notify_fail("只有兴国禅寺的弟子才能使用『佛门狮子吼』！\n");

// 		Lower requirement for testing.	
		skill = me->query_skill("lotusforce", 1);
		if(skill < 150) return notify_fail("『佛门狮子吼』需要150级莲华心法！\n");
	
		if( !me->is_fighting() )
			return notify_fail("『佛门狮子吼』只能在战斗中使用。\n");
	      
        if( (int)me->query("force") < 300 )     
        	return notify_fail("需要300点的内力。\n");
        if (userp(me))	me->add("force", -300);
	
		message_vision(
                HIY 
	"$N"HIY"合掌当胸，神气贯通，运起『佛门狮子吼』神功，沉声断喝：\n\n"HIR"      苦－海－无－边 ，　回 － 头 － 是 － 岸 \n\n"NOR 
	YEL"    众人只觉得两耳嗡嗡作响，如十万天鼓齐鸣。\n\n" NOR, me);
  
        myexp = me->query("combat_exp");
		enemy = me->query_enemy();
       
  	for (i = 0 ; i< sizeof(enemy); i++) {		
		
		target = enemy[i];
		if (!objectp(target) || environment(target)!= environment(me))
			continue;
		
		// 每次stun后有30秒钟的免疫期。Otherwise ppl can use it to powerlevel.
		if (target->query_temp("timer/stun") + 30 > time()) {
			message_vision(YEL"	$N"NOR+YEL"懵懵懂懂，不知所然地没有反应。\n"NOR,target);
			continue;
		}
		
		mod = COMBAT_D->can_busy(me, target, "lotusforce");	
		if (!mod) mod = 10000;
						
		if (COMBAT_D->do_busy_attack(me, target, "lotusforce", "step", 200, mod))
		{
			target->set_temp("timer/stun",time());
			target->set_temp("mesmerize",time());
			target->start_call_out((: call_other, __FILE__, "remove_effect", target :), 20);	
			message_vision(HIW"$N"HIW"“蹬，蹬，蹬”退了三步，被震得神荡魂飞，目瞪口呆！！！\n" NOR,target);
			target->perform_busy(10);
			target->add_hate(me, skill*2);	// slight hate but enough to get area attention.
			target->set_temp("condition_type",WHT" <震撼中> "NOR);
			//	If success, Remove enemy from group killer list.		
			me->remove_killer(target);
			me->add_rival(target);
			if (t = me->query_team()) {
				foreach (object friend in t) {
					if (environment(friend)!= environment(target)) continue;
					if (friend->is_fighting(target)) {
						friend->remove_killer(target);
						friend->add_rival(target);
					}
				}
			}
		}
		else {
			message_vision(YEL"$n"NOR+YEL"心静如水，$N"NOR+YEL"的狮子吼在$n"NOR+YEL"听来似平水不波。\n" NOR,me,target);				
		}
	}
        me->start_busy(3); 
        return 1;
}
 
void remove_effect(object target){
    
    object *enemy;
    int i;
    
    if(!target||!living(target))	return ;
	if (!target->query_temp("mesmerize")) return;
	target->delete_temp("mesmerize");
	target->delete_temp("condition_type");
	tell_object(target, YEL"你耳中嗡嗡的鸣叫终于消失，心神渐渐宁静下来。\n"NOR);
	
	enemy = target->query_enemy();
	for (i=0;i<sizeof(enemy);i++){
		if (objectp(enemy[i])){
			enemy[i]->kill_ob(target);
			target->kill_ob(enemy[i]);
		}
	}	
/*	
	if (environment(target))
		target->move(environment(target));
//	target->init();		// reset target
*/
	
}

