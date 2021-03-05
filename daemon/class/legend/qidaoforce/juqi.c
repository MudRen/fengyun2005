#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me,object target,int amount)
{
    int juqi, skill, dorm;
	mapping buff;
	string name, msg;
	
	if(me->query("class")!="legend"&& userp(me))
		return notify_fail("只有铁雪山庄的弟子才能够使用聚气或蝶梦。\n");

 	if (ANNIE_D->check_buff( me, "juqi"))
 		return notify_fail("你已经在施展类似的武功了。\n");
        
    skill = me->query_skill("qidaoforce",1);
    dorm = me->query_skill("dormancy",1);
    
    if(skill < 100 )
    	return notify_fail("聚气或蝶梦至少需100级棋道心法。\n");
    
    if (me->query("force")<100)
    	return notify_fail("聚气或蝶梦至少需要100点内力。\n");
    	       
    if (userp(me))	me->add("force", -100);
               	
	if (skill >= 150 && dorm >=250)		juqi = 80;
	else if (skill >= 150 && dorm>=200)	juqi = 70;
	else	juqi = 60;
						
	if(me->query("family/master_id")=="master xuerui") {
		msg = HIG"$N双臂轻舒，如蝶翼般轻轻展开，晶莹的玉色光芒从身侧缓缓扩散而出。。。\n"NOR;
		name = "棋道·蝶梦";
	} else {
		msg = HIW"$N运劲将内力凝聚，全身上下升起了一团若有若无的白气。。。\n"NOR;
		name = "棋道·聚气";	
	}
		
	juqi = COMBAT_D->magic_modifier(me, me, "kee",juqi);
		
	buff =
		([
			"caster":me,
			"who": me,
			"type":"juqi",
			"att":"bless",
			"name": name,
			"buff1": "pfm/qidaoforce_juqi",
			"buff1_c":juqi,
			"time":  900,
			"buff_msg": msg,
		]);
	ANNIE_D->buffup(buff);
	
	return 1;
}
