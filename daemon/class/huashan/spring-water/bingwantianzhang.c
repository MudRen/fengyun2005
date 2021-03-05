// -by foxgirl@fengyun.com

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
    	int skill;
    	mapping buff;
		string msg;
	    
    	if (me->query("class") != "huashan") 
    		return notify_fail("只有华山弟子可以使用「冰纨天障」。\n");
    	
    	if( userp(me) && me->query("gender") != "女性" )
        	return notify_fail("你一个大男人居然学来了这样扭扭捏捏的功夫，也好意思用？\n");
    
    	skill = me->query_skill("spring-water",1);
    	if(skill < 50) 
    		return notify_fail("冰纨天障需要50级的春水罗衫！\n");
    	
    	if(!target) target=me;
    	else if( target != me )
        	return notify_fail("你只能将冰纨天障用在自己的身上。\n");
    
    	if( ANNIE_D->check_buff(me, "ironup"))
        	return notify_fail("你已经在施展类似的护体神功了。\n");
        	
    	if( (int)me->query("force") < 100 )
        	return notify_fail("使用冰纨天障需100点的内力。\n");
    	if (userp(me))	me->add("force", -100);    	
    	
    	msg = HIY
"$N凝眉低首，运起『冰纨天障』，身上衣衫如春水涟波，无风自动。\n"NOR;
    	msg += HIG
"似乎有一层离合的微光淡淡笼上$N周围．．．\n" NOR;

    	buff =
		([
			"caster":me,
			"who":	me,
			"type": "ironup",
			"att": "bless",
			"name": "春水罗衫·冰纨天障",
			"buff1":"apply/iron-cloth",
			"buff1_c":skill/2,
			"time":  600,
			"buff_msg":msg,
		]);
		ANNIE_D->buffup(buff);
    	if( me->is_fighting() ) me->perform_busy(2);
    	return 1;
}
