// Silencer@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
int stone_done(object me, object caster);
int perform(object me, object target)
{
        int skill;
		mapping buff;	
	
        if (userp(me))
        	return notify_fail("此技已绝迹江湖。\n");
        	
        if(me->query("class")!="fugui")
    		return notify_fail("只有富贵山庄弟子才能使出「三串炸山轰」的绝技。\n");

       skill = me->query_skill("henglian",1);
		if(skill < 160) 
		return notify_fail("三串炸山轰需要160级的横练功！\n");
        
        if(!target) target = me;
        if( target != me ) 
        	return notify_fail("你只能将三串炸山轰用在自己的身上。\n");
        
        if( ANNIE_D->check_buff(me,"ironup"))
        	return notify_fail("你已经在施展类似的护体神功了。\n");
        
        if (me->is_fighting())
		return notify_fail("三串炸山轰无法在战斗中使用。\n");	
		
        if (me->query_skill_mapped("force")!="skyforce")
        	return notify_fail("二串炮唯有碧空心法才有效。\n");
        	
        if( me->query("force") < 300 )     
        	return	notify_fail("三串炸山轰需要300点的内力。\n");
		if (userp(me))	me->add("force", -300);
	       
	me->set_temp("pfm/fg_sanchuan",5);
	
	buff =
		([
			"caster":me,
			"who":	me,
			"type": "ironup",
			"att": "bless",
			"name": "横练·三串炸山轰",
			"buff1":"apply/iron-cloth",
			"buff1_c":skill/2,
			"time":  300,
			"buff_msg":WHT"$N全身衣襟忽然无风自动，却完全没有一丝声响！！\n" NOR,
			"warn_msg":"",
			"finish_function": (: stone_done :),
		]);
	ANNIE_D->buffup(buff);
    	if(me->is_fighting() ) me->perform_busy(3);
    	return 1;
}


int stone_done(object me, object caster){
	me->delete_temp("pfm/fg_sanchuan");
	return 1;
}