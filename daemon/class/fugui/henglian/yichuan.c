// Silencer@fengyun
#include <ansi.h>
#include <combat.h>

int perform(object me, object target)
{
        int skill;
		mapping buff;	
	
        if(me->query("class")!="fugui")
    		return notify_fail("只有富贵山庄弟子才能使出「一串鞭」的绝技。\n");

        skill = me->query_skill("henglian",1);
		if(skill < 100) return notify_fail("一串鞭需要100级的横练功！\n");
        
        if(!target) target = me;
        if( target != me ) 
        	return notify_fail("你只能将一串鞭用在自己的身上。\n");
        
        if( ANNIE_D->check_buff(me,"ironup")) {
        	ANNIE_D->debuff(me, "ironup");
        	return 1;
        }
//        	return notify_fail("你已经在施展类似的护体神功了。\n");
        
        if( me->query("force") < 150 )     
        	return	notify_fail("一串鞭需要150点的内力。\n");
		if (userp(me))	me->add("force", -150);
		
		buff =
			([
				"caster":me,
				"who":	me,
				"type": "ironup",
				"att": "bless",
				"name": "横练·一串鞭",
				"buff1":"apply/iron-cloth",
				"buff1_c":50,
				"time":  900,
				"buff_msg":HIY"$N全身每一个骨节忽然全都爆竹般响起，一连串响个不停！！\n" NOR,
			]);
		ANNIE_D->buffup(buff);
    	return 1;
}
