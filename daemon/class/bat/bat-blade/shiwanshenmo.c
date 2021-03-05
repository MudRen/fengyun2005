// shiwanshenmo.c   十万神魔
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra, n, force;
	int tmp,chance;
	object weapon;
	
	if ( (string) me->query_skill_mapped("dodge") != "meng-steps")
		return notify_fail("『十万神魔』需要幻梦步法的配合！\n");
	
	extra = me->query_skill("bat-blade",1);
	if (extra < 100) return notify_fail("『十万神魔』需要100级蝙蝠刀法！\n");
	
	tmp = me->query_skill("meng-steps",1);
	if (tmp < 100)	return notify_fail("『十万神魔』需要100级幻梦步法！\n");
	
	if (me->query("class")=="bat") n=0;
		else n=20;
	
	if(userp(me) && me->query_temp("timer/shiwanshenmo")+n > time())
		return notify_fail("『十万神魔』需要聚气片刻。。\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『十万神魔』只能对战斗中的对手使用。\n");
	
	// 220 + 160
	chance=extra+tmp;
	
	// 110
	if (me->query_skill_mapped("force")=="wuzheng-force" && me->query("class")=="bat")
		force= me->query_skill("wuzheng-force",1)/2;
	
	// atk 220, dmg 160/3 + 220/2 = 160
	me->add_temp("apply/attack",tmp);
	me->add_temp("apply/damage",extra/3+force);
	target->set_temp("no_check_pfm_win",1);
	
	weapon = me->query_temp("weapon");
	msg = MAG  "\n\n$N凝聚起天地间十万妖魔的无边力量，一式－十－万－神－魔 －如急电般劈向$n！\n" NOR;
	message_vision(msg, me, target);
	
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        target->set_temp("skip_damage_record",1);
    
    	if (chance>random(300)) {
	        msg = HIB  "\n$N"+HIB"手中"+weapon->name()+HIB"幻出奇异的光华刺向$n！" NOR;
	        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		}
		if (chance>random(350)) {
	        msg = HIR  "\n$N"+HIR"手中"+weapon->name()+ HIR"发出摄人心魄的呼啸向$n"+HIR"劈去！" NOR;
	        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        }
        if (chance>random(400)) {
	        msg = HIW  "\n$N"+HIW"手中"+weapon->name()+HIW"竟然发出妙不可言的奇香扑向$n！" NOR;
	        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        }
        if (chance>random(450)) {
	        msg = HIC  "\n十万诸魔齐在云端隐现，$N"+HIC"手中"+weapon->name()+HIC"鬼神莫测已然到了$n"+HIC"的眼前！" NOR;
	        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		if(!userp(me) && random(10)>3)
                	target->apply_condition("qicaibat",random(10)+10);
        }
	
		me->add_temp("apply/attack",-tmp);
        me->add_temp("apply/damage",-extra/3-force);
        me->set_temp("timer/shiwanshenmo",time());
        

		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}
	       
        me->perform_busy(3);
        
		return 1;
}

