// Silencer@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill, agi_skill;
        mapping buff;
        
        if(me->query("class")!="bonze") 
		return notify_fail("只有兴国高僧才能使用『绝尘』\n");
	
		skill = me->query_skill("nodust-steps", 1);		
		if(skill < 150) 	
			return notify_fail("『绝尘』需要150级的无尘步法！\n");
	      
        if(!target) target = me;
        if( target != me ) 
        	return 	notify_fail("『绝尘』只能用在自己身上。\n");
        	
        if (ANNIE_D->check_buff(me,"agiup"))
        	return notify_fail("你已经在使用类似的武功了。\n");
        
        if( me->query("force") < 100 )     
        	return  notify_fail("『绝尘』需要100点内力。\n");   	
		me->add("force", -100);
	
		agi_skill = skill/20;	// 200/20 = 10
	
		buff =
		([
			"caster":me,
			"who": me,
			"type":"agiup",
			"att":"bless",
			"name":"无尘步·绝尘",
			"buff1": "apply/agility",
			"buff1_c":agi_skill,
			"buff2":"pfm/nodust_inquire",
			"buff2_c":1,
			"time":  900,
			"buff_msg":BGRN + WHT"$N提气纵身，足印如惊鸿踏雪泥，轻如鸟雀淡淡一触，无迹可循。\n"NOR,
		]);
		ANNIE_D->buffup(buff);
	
        return 1;
}