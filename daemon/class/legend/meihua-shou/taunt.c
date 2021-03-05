// 聚威：Taunt：

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        int amount, skill, dorm, add, duration, fix;
        string msg,dot_owner,dir,index;
		object hatred;
	
		if(me->query("class")!="legend")
			return notify_fail("只有铁雪山庄的嫡传弟子才能够使用争春。\n");

 		skill = me->query_skill("meihua-shou",1);
 		dorm = me->query_skill("dormancy",1);
 		
 		if(skill <100)
			return notify_fail("『争春』需要100级的梅花手。\n");
 	 		 	
 		if( !target ) target = offensive_target(me);
		if( !target
			||	!target->is_character()
			||	!me->is_fighting(target) )
			return notify_fail("『争春』只能对战斗中的对手使用。\n");
                
        fix = 10;        
        duration = me->query("timer/pfm/tx_taunt")+ fix - time();
        if (duration>0)
        	return notify_fail("你还需要等待"+ duration+"秒钟左右才能够再次使用争春。\n");
        
        dot_owner = file_name(me);
    	sscanf(dot_owner,"%s#%s",dir,index);
    	dot_owner = me->query("id")+ index;
    	
    	if (target->query_temp("dot/meihua-shou/taunt/"+dot_owner))
    		return notify_fail("对手已经中了你下的争春了。\n");
        
        me->set("timer/pfm/tx_taunt",time());
        
        msg = HIR"\n$N向着$n双手乱晃，忽然露出好大的一个破绽！\n"NOR;
        
        if (!COMBAT_D->do_busy_attack(me, target, "taunt", "unarmed", 500, 10))
        {
        	msg += WHT"$n成竹在胸，对$N的虚招视而不见。\n"NOR;
        	message_vision(msg, me, target);
        	return 1;
        }
        
       	amount = F_LEVEL->get_level(me->query("combat_exp"))* 10;
       	
//	    printf("%O's hate is %O\n",target,target->query_hate_list());
                
        // 事实上增加的hate为 lvl* 14。
		
		if (!userp(target))			
      		target->add_hate(me, amount);
 		target->set_temp("dot/meihua-shou/taunt/"+dot_owner,1);
 		target->add_temp("marks/kongmen_adjust",-1);
 		
		call_out("dot",6,me,target,3,0, amount,dot_owner, msg);       
               
        if( me == target->query_max_hate())
        	msg+= YEL"$n一看有机可乘，急急地攻向$N！\n"NOR;
        else
        	msg+= RED"$n似乎有些心动，向$N狠狠地瞪了一眼。\n"NOR;
        	
		message_vision(msg, me, target);

//		printf("%O's hate is %O\n",target,target->query_hate_list());
	       
		return 1;       
}



void dot (object me, object enemy, int total, int count, int amount, string dot_owner, string msg)
{
		if (!me || !enemy || !enemy->is_fighting(me)) {
			if (enemy) {
				enemy->delete_temp("dot/meihua-shou/taunt/"+dot_owner);
				enemy->add_temp("marks/kongmen_adjust",1);
			}
			return;
		}
	
		message_vision(msg, me, enemy);
		if (!userp(enemy))
			enemy->add_hate(me, amount/2);
		
		count = count+1;
		if (count<total) 
			call_out("dot",6,me, enemy,total,count, amount, dot_owner,msg);
		else {
			tell_object(me,YEL"你对"+enemy->name()+YEL"的争春效果结束了。\n"NOR);
			if (enemy) {
				enemy->delete_temp("dot/meihua-shou/taunt/"+dot_owner);
				enemy->add_temp("marks/kongmen_adjust",1);
			}
		}
		return;
}
