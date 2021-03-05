// Silencer@fengyun	June.2005
// 『金石为开』：击中后可让对方流血三招，2-SB,CDT = Dot time.
//	特点：short self-busy, Dot bypass 所有防护

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string forceskill,msg, dot_owner,index,dir;
		int extra, tmp;
		object weapon;
		
		if (me->query("class") != "fugui")
			return notify_fail("『金石为开』是富贵弟子的绝招。\n");
		
		weapon=me->query_temp("weapon");
	 	extra = me->query_skill("xuezhan-spear",1);
		tmp = me->query_skill("skyforce",1);
	    	    	
	    if (tmp < 100 || extra < 100 )
	    	return notify_fail("『金石为开』需要100级的血战枪法和100级的碧空心法!\n");
	    	
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
	        	return notify_fail("『金石为开』只能对战斗中的对手使用。\n");
             
    	dot_owner = file_name(me);
    	sscanf(dot_owner,"%s#%s",dir,index);
    	dot_owner = me->query("id")+ index;
    	
    	if (target->query_temp("dot/xuezhan-spear/jswk/"+dot_owner))
    		return notify_fail("对手已经中了你的『金石为开』了。\n");
    		
        me->add_temp("apply/attack", 100 + extra);    
        me->add_temp("apply/damage", tmp);
        msg = HIG"\n$N"HIG"手中"+weapon->name()+HIG"咯哧一声，忽折为二，两条枪，左攻右肋，右刺左膀，前扫胸，后挑腿，
上点眉心下撩阴，倏扎盘时倏搠心，越打越狠，越打越快！\n" NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        me->add_temp("apply/attack", -100 - extra);
        me->add_temp("apply/damage", -tmp);
        
        if (target->query_temp("damaged_during_attack"))
        {
        	message_vision(WHT"$N"WHT"枪锋微微颤动，真力透入$n伤处。\n"NOR, me, target);
        	target->set_temp("dot/xuezhan-spear/jswk/"+dot_owner,1);
        	call_out("dot",4,me,target,3,0,extra,dot_owner);
        }
                
        me->perform_busy(1); 
        return 1;
}

void dot (object me, object enemy, int total, int count, int skill,string dot_owner)
{
	int num;
	if (!me || !enemy || !enemy->is_fighting(me)|| environment(me)!= environment(enemy)) {
		if (enemy) {
			tell_object(enemy, YEL"你的伤口血流渐缓。\n"NOR);
			enemy->delete_temp("dot/xuezhan-spear/jswk/"+dot_owner);
		}
		return;
	}
	message_vision(RED"$N身上的伤口忽然爆裂开来，血水飞溅。\n"NOR,enemy);
	
	// 3 times, 
	// num = 20 + 250/3 + 90/2 + 48 = 196, 	
	// Ability 196*130% = 254
	
	num = 20 + skill/3 + me->query("force_factor")/2 + me->query("level")/3;		
	num = num * ( 100 + F_ABILITY->check_ability(me,"jswk_add")*3)/100;
	
	num = COMBAT_D->magic_modifier(me, enemy, "kee", num);	
	enemy->receive_damage("kee",num,me);
	count = count+1;
	if (count<total) call_out("dot",4,me, enemy,total,count, skill,dot_owner);
	else {
		tell_object(enemy, YEL"你的伤口血流渐缓。\n"NOR);
		enemy->delete_temp("dot/xuezhan-spear/jswk/"+dot_owner);
		return;
	}
	return ;
}
