// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    string forceskill,msg;
	int extra, exp_bonus, chance;
	int tmp;
	object weapon;
	
	forceskill= me->query_skill_mapped("force"); 
	weapon=me->query_temp("weapon");
 	extra = me->query_skill("yue-spear",1);		
	tmp = me->query_skill("manjianghong",1);
    	
    if (tmp < 60 || extra < 60 )
    	return notify_fail("『纵横天下』需要60级的岳家中平枪法和满江红心法!\n");
    	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
        	return notify_fail("『纵横天下』只能对战斗中的对手使用。\n");
    
    weapon = me->query_temp("weapon");
    
    
    chance = F_ABILITY->check_ability(me,"3_zhtx_add",3)* 10;
    if (random(100)< chance)
    	chance = 1;	
    else
    	chance = 0;
    
    if ( (me->query("family/master_id")!="master yue" 
    	||extra < 160 ||me->query("class")!="official") && !me->query("annie/npc-zhtx7hit")){ 
   		// extra= 120, tmp = 130*3
   		me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", tmp*3);
    	msg = HIR  "$N"HIR"仰天长啸，手中"+weapon->name()+HIR"幻化出千重矛影，一式『纵横天下』从四面八方直刺$n！！\n" NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -tmp*3);
        me->perform_busy(2 - chance); 
    	return 1;
    }
        
        else {
	
		if ( forceskill != "manjianghong") tmp = 0;
        	
        target->set_temp("no_check_pfm_win",1);
		me->add_temp("apply/attack",extra);
		// +atk 180
		msg = HIW "\n$N"HIW"仰天长啸，浩然正气直冲霄汉，手中"+weapon->name()+HIW"幻化出千重矛影，正是『岳家中平枪法』
百战无敌之式『--纵-横-天-下--』!!\n"NOR;
		message_vision(msg, me, target);
		
			msg = HIC"动\n$N"HIC"手中$w"HIC"划破长空，陡然直刺$n!" NOR;
						
			COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg, "刺伤");
    		target->set_temp("skip_damage_record",1);
    		
    		msg = HIC  "寒光\n$N"HIC"怒喝一声，千重矛影惊涛骇浪般滚向$n！" NOR;
			COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg, "刺伤");
    		msg = HIC  "星黯然\n$N"HIC"握枪之手移至中间，枪头枪尾有若两道急电点向$n！" NOR;
			COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg, "刺伤");
    			// +atk 180*3, +dgm 150*2
    			me->add_temp("apply/attack",extra*2);
        		me->add_temp("apply/damage",tmp*2);  
    		msg = HIC  "纵横天下\n$N"HIC"手中$w"+HIC"如狂风落叶，无处不在，漫天枪影中一点红光直刺$n！" NOR;
        		COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg, "刺伤");
    			me->add_temp("apply/attack",-extra*2);
        		me->add_temp("apply/damage",-tmp*2); 
    		msg = HIC  "马长嘶\n$N"HIC"枪尖抖动,虎虎生风，咝咝作响，仿若万马奔腾,势不可挡！" NOR;
        		COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg, "刺伤");
    		msg = HIC  "血溅\n$N"HIC"手中$w"+HIC"枪头颤震，倏然爆开，化作满天血光！" NOR;
			COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg, "刺伤");
    		msg = HIC  "静\n万籁俱寂，$N"HIC"手中$w"+HIC"枪影消失。" NOR;
			COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg, "刺伤");
        	me->add_temp("apply/attack",-extra);
   
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}
           
		me->perform_busy(6 - chance);   
        }
        return 1;
}
