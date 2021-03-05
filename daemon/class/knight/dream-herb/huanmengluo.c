// Silencer@fengyun

#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill, stage, rate,duration;
        mapping buff;
        string buff_msg;
        
        if(me->query("class")!="knight") 
		return notify_fail("只有快活林弟子才能使用幻梦落。\n");
	
		skill = me->query_skill("dream-herb", 1);		
		if(skill < 140) 	
			return notify_fail("幻梦落至少需要140级的云梦五花锦！\n");
		     
        if(!target) target = me;
        if( target != me ) 
        	return 	notify_fail("幻梦落只能用在自己身上。\n");
        
        if (!me->query_temp("weapon"))
        	return notify_fail("幻梦落只有配合轩辕斧法才有作用。\n");
        	
        duration = me->query("timer/pfm/huanmengluo")+ 900 - time();
        if (duration >0)
        	return notify_fail("还需要等待"+ (duration/60) + "分钟左右才能再次使用幻梦落。\n");
        
        if (ANNIE_D->check_buff(me,"poison_spirit"))
        	return notify_fail("你已经在使用类似的武功了。\n");
        
        	// SCROLL ADVANCE PERFORM, 
	    stage = me->query("scroll/dream-herb_huanmengluo");
	    rate = 2;
	    
	    switch (stage) {
	    	case 2:		rate   	= 3; break;	// L150  c-d
	    	case 3:		rate	= 4; break;	// L170 c-d
	    }
        
        me->set("timer/pfm/huanmengluo",time());
        
		buff =
			([
				"caster":me,
				"who": me,
				"type":"poison_spirit",
				"att":"bless",
				"name":"云梦五花锦·幻梦落",
				"buff1": "poison_spirit",
				"buff1_c":rate,
				"time":  90,
				"buff_msg":MAG"$N"NOR+MAG"的眼神忽然迷蒙，慢慢吟道：世事一场大梦，人生几度秋凉。\n"NOR,
			]);
		ANNIE_D->buffup(buff);
	        
        return 1;
}


