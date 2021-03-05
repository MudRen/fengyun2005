// Silencer@fengyun	June.2005
// L300：聚神：提高三刀三剑的命中率＋2０％，12秒，cdt20分

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me,object target,int amount)
{
        int level, fix, duration, add;
        mapping buff;
        string msg;

		if(me->query("class")!="legend" && userp(me))
		return notify_fail("只有铁雪山庄的弟子才能够使用聚神诀。\n");

	 	if (userp(me) && !REWARD_D->check_m_success(me,"力斗三佛"))
	 			return notify_fail("只有经过"WHT"考验"NOR"的铁雪弟子才能使用聚神诀。\n");
	 	
 		level = me->query_skill("six-sense",1);
 		if( level < 150 || me->query_skill("qidaoforce",1)<150)
			return notify_fail("『聚神诀』需要150级的六灵暗识和棋道心法。\n");
 	
 		if (ANNIE_D->check_buff(me,"legend_jushen") )
 			return notify_fail("你已经在施展类似的心诀了。\n");
              
        if (target && target!= me)
 		return notify_fail("此心法只能用在自己身上。\n");
        
        // ５mins, feat -２mins, eventually=３min
        fix = 300;
        add = F_ABILITY->check_ability(me,"jushen_add",2);
	    fix = fix - add *12;
                
        duration = me->query("timer/pfm/jushen")-time() + fix;
        if (duration>0)
        	return notify_fail("你还需要等待"+(duration)+"秒钟左右才能够再次使用聚神诀。\n");
        
        amount = 150;
        if (level >=250)	amount = 200;
                        
		me->set("timer/pfm/jushen",time());
	  
		msg = BRED + HIY"$N身法闪动，很美，美得叫人惊艳。很快，快得像流星，自长空划过，瞬间即逝!\n\n"NOR;
	
		buff =
			([
				"caster":me,
				"who": me,
				"type":"legend_jushen",
				"att":"bless",
				"name": "棋道·聚神",
				"buff1": "apply/attack",
				"buff1_c": amount,
				"time":  60,
				"buff_msg": msg,
			]);
		ANNIE_D->buffup(buff);
		return 1;       
}
