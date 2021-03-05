#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
    	string msg;
    	int extra, mod, damage;

    	if(me->query("class")!="wudang" && userp(me))
		return notify_fail("太极『粘字诀』是武当镇殿之宝。\n");

    	extra = me->query_skill("taiji",1);
    	if (extra < 60)
        	return notify_fail("『粘字诀』需要60级太极拳！\n");

    	if (userp(me) && me->query_skill_mapped("force") != "taijiforce")
		return notify_fail("『粘字诀』需要太极心法配合！\n");

    	if( !target ) target = offensive_target(me);
    	if( !target
        	||!target->is_character()
        	||!me->is_fighting(target) )
        	return notify_fail("『粘字诀』只能对战斗中的对手使用。\n");

	mod = COMBAT_D->can_busy(me, target, "taiji");	
	if (!mod)
		return notify_fail(HIW"此人功力深湛，不会被此拳法迷惑的。\n"NOR);

    	if( target->is_busy() )
        	return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");

    	if (extra < 170) {
        	msg = CYN "\n$N使出太极拳法中的『粘字诀』，企图减缓$n的攻势，\n";
        	me->start_busy(1);
        	if (COMBAT_D->do_busy_attack( me, target, "taiji/nianzijue", "unarmed", 200, mod))
        	{
               		msg += "结果$p被$P攻了个措手不及！\n\n" NOR;
            		target->force_busy( me->query_skill("taiji",1) / 50 + random(2));
        	}  else {
            		msg += "可是$p看破了$P的企图，并没有上当。\n\n" NOR;
        	}
        	message_vision(msg, me, target);
        	return 1;
    	}
    	else {

	if (!target->query_temp("annie/wd_busy_test_2") || time() > target->query_temp("annie/wd_busy_test_2") +6 )
	{

        	msg = HIR "\n$N真气鼓动，双拳幻化为无数大大小小的圆圈向$n攻去，\n";
        	if (COMBAT_D->do_busy_attack( me, target, "taiji/nianzijue", "unarmed", 300, mod))
        	{
            		msg += "	结果$p头晕目眩，被$P的拳势围住不能脱身，频频中招！\n\n" NOR;
       
            		target->force_busy(3);
            		me->perform_busy(random(2));
               		damage = me->query("max_force")/6;
            		damage = COMBAT_D->magic_modifier(me, target,"kee",damage);
            		target->receive_damage("kee",damage,me);
       	    		message_vision(msg, me, target);
            		target->set_temp("damaged_during_attack", 1);
               		COMBAT_D->report_status(target, 0);
            		COMBAT_D->win_lose_check(me,target,1);
        	}	else {
            		msg += "	可是$p从容应招，将$P的攻势消于无形。\n\n" NOR;
            		me->perform_busy(random(2));
       	    		message_vision(msg, me, target);
        	}
	        return 1;
	}
	else
	{
        	msg = HIR "\n$N"HIR"抓住$n"HIR"破绽，真气鼓动，双拳幻化为无数大大小小的圆圈向$n"HIR"攻去，\n";
        	if (COMBAT_D->do_busy_attack( me, target, "taiji/nianzijue", "unarmed", 300, mod))
        	{
            		msg += "	结果$p头晕目眩，被$P的拳势围住不能脱身，频频中招！\n\n" NOR;
       
            		target->force_busy(3);
            		me->perform_busy(random(2));
               		damage = me->query("max_force")/6;
            		damage = COMBAT_D->magic_modifier(me, target,"kee",damage);
            		target->receive_damage("kee",damage,me);
       	    		message_vision(msg, me, target);
            		target->set_temp("damaged_during_attack", 1);
               		COMBAT_D->report_status(target, 0);
            		COMBAT_D->win_lose_check(me,target,1);

					target->set_temp("annie/wd_busy_test_3",time());
        	}	else {
            		msg += "	可是$p从容应招，将$P的攻势消于无形。\n\n" NOR;
            		me->perform_busy(random(2));
       	    		message_vision(msg, me, target);
        	}
	        return 1;

	}

    	}
}


