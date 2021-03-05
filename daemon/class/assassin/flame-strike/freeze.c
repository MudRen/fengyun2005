// Silencer @ FY4 workgroup. Aug.2004
#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
    	string msg;
    	int enhance, mod,cl,duration;
    
  //  	if (!wizardp(me) && userp(me))
    //		return notify_fail("你不会使用此特技。\n");
    	 
    	if(!me->is_fighting())
		return notify_fail("麻婆寒练术只可以在战斗中施展！\n");
    	    	
    	if(me->query_skill("flame-strike", 1) < 150 )
        	return notify_fail("你的麻婆寒练术不够高！\n");
 	
          	duration = me->query("timer/pfm/jq_mphl") - time() + 1200 -  F_ABILITY->check_ability(me, "3_mphl_add", 3) * 30;
	if( duration > 0 ) {
		return notify_fail("你还需要等待"+(int)(duration/60+1)+"分钟左右才能再次使用『麻婆寒练术』。\n");
	} 
    
    	if( !target ) target = offensive_target(me);
    	if( !target
		||!target->is_character()
		||target->is_corpse()
		||target==me)
        	return notify_fail("你要对谁施展这个法术？\n");

    	if(target->query("disable_type") ==HIW "<冻僵中>" NOR)
		return notify_fail("对方已经不能动弹了。\n");

    	msg = HIW "$N左手虚握，形成一团奇冷的寒气，向$n射来！\n\n" ;
    	
        cl=F_ABILITY->check_ability(me,"mphl_add");
      if(!cl){
      cl=1;
      }
        
    	enhance = 400;
    	if (COMBAT_D->do_busy_attack(me, target, "flame-strike/freeze", "unarmed", enhance, 10))
    	{
		msg +="奇冷的寒气包围了$n的全身，将$n凝聚成冰块！\n";
        	target->set_temp("disable_inputs",1);
        	target->set("disable_type",HIW "<冻僵中>" NOR);
        	target->set_temp("is_unconcious",1);
        	target->start_call_out( (: call_other, __FILE__, "remove_frozen",target :),cl);
    	} else  
    		msg += "但是被$n机灵地躲开了。\n";
    
    	message_vision(msg+NOR, me, target);
    	target->kill_ob(me);
    	me->kill_ob(target);
    	me->perform_busy(2);
    	me->set("timer/pfm/jq_mphl", time());
    	return 1;
}


void remove_frozen(object me)
{
    	if (!me || me->is_ghost() || !objectp(me))	return;
    	me->delete("disable_type");
    	me->delete_temp("disable_inputs");
    	me->delete_temp("is_unconcious");
    	message_vision(HIR "\n\n$N发出一声怒吼，双臂一振，将周身凝聚的冰块震得粉碎！！\n\n" NOR, me);
}


