// Silencer@fengyun	June.2005
// L300：聚力：damage不作random,永远是最大值，12秒，cdt20分

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me,object target,int amount)
{
        int level, fix, duration, add;
        mapping buff;
        string msg;

		if(me->query("class")!="legend" && userp(me))
			return notify_fail("只有铁雪山庄的弟子才能够使用聚力诀。\n");

		if (userp(me) && !REWARD_D->check_m_success(me,"力斗三佛"))
 			return notify_fail("只有经过"WHT"考验"NOR"的铁雪弟子才能使用聚力诀。\n");

	 	level = me->query_skill("dormancy",1);
	 	if( level < 300)
			return notify_fail("『聚力诀』需要300级的息若纳气。\n");
	 	
 		if (ANNIE_D->check_buff(me, "damagecurse"))
 			return notify_fail("你已经在施展类似的心诀了。\n");
              
        if (target && target!= me)
 			return notify_fail("此心法只能用在自己身上。\n");
        
        // ５mins, feat -２mins, eventually=３min
        fix = 300;
        add = F_ABILITY->check_ability(me,"juli_add",2);
        fix = fix - add *12;
        
        duration = me->query("timer/pfm/juli")-time() + fix;
        if (duration>0)
        	return notify_fail("你还需要等待"+(int)(duration)+"秒钟左右才能够再次使用聚力诀。\n");
                
		me->set("timer/pfm/juli",time());
	  
	msg = BRED + HIY"$N凝立不动。一掌向天，天颤。一手指地，地动。指尖发出啸啸劲气，从红转赭，由赭变紫!\n\n"NOR;
	
	buff =
		([
			"caster":me,
			"who": me,
			"type":"damagecurse",
			"att":"bless",
			"name": "棋道·聚力",
			"time":  60,
			"buff_msg": msg,
		]);
	ANNIE_D->buffup(buff);
	return 1;       
}
