#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)

{
    string msg,id_enemy;
    int damage, ap, dp;
    int extradam, my_exp;
  
    if(userp(me))
		return notify_fail("你所选用的武功中没有这种必杀技。。\n");  
    if(me->query("class")!="yinshi")
		return notify_fail("只有帝王谷弟子才能下降头。\n");

    if( !target ) target = offensive_target(me);
    if( !target
	||!target->is_character()
	||target->is_corpse()
	||target==me)
        return notify_fail("你要对谁施展这个降头？\n");
    
    me->receive_wound("kee", 5);
    msg = RED "$N的眼中红光一闪，一条细如发丝的血线射向$n！\n\n" NOR;
    
    ap = me->query_skill("cursism");
    my_exp=me->query("combat_exp");
    dp = target->query("combat_exp");
    
    extradam = 100;
    if (extradam <0)damage = 0;
    	else if (extradam<10000) damage = extradam/4;
    	 else damage = 2500 + extradam/2000;
    damage = ap*3 + random(ap*4) + damage/4 + 3*random(damage)/4;
 
    if(damage >me->query("max_kee")) damage = me->query("max_kee");
    
    ap=random(8*my_exp);
    if( ap>dp) {
	target->kill_ob(me);
	me->kill_ob(target);
	message_vision(msg, me, target);
        target->receive_wound("kee", damage/2, me);
        target->receive_damage("kee", damage/2, me);
        if( damage > 0 ) {
           target->set_temp("damaged_during_attack", 0);
           COMBAT_D->report_status(target);
           COMBAT_D->win_lose_check(me,target,1);
        }

    } else
    {
        msg += "但是被$n发现了！！\n";
        message_vision(msg, me, target);
		target->kill_ob(me);
		me->kill_ob(target);
    }
    me->start_busy(2) ;   //for a 2k damage sure hit, busy 2 is way too good
    return 1;
}

