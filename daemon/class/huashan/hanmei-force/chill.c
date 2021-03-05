//	『寒霜凝梅』攻击multiple enemies, 

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target)
{
	object wp,weapon;
	int cost, extra, myexp,yourexp, i;
	int base;
	string msg, skill;
	object	*enemy;
	
	if (me->query("class") != "huashan") 
		return notify_fail("只有华山弟子可以使用『寒霜凝梅』。\n");
	
	extra = me->query_skill("hanmei-force", 1);
	if(extra < 50) 
		return notify_fail("『寒霜凝梅』需要50级寒梅心法。\n");
	if( !me->is_fighting() )
		return notify_fail("『寒霜凝梅』只能在战斗中使用。\n");
	
	if (ANNIE_D->checkbuff(me, "berserk"))
		return notify_fail("使用忍术时不能使用攻击性特殊技能。\n");
	
	if( me->query("force") < 200 )
		return notify_fail("『寒霜凝梅』至少需要200点的内力为基础。\n");
	
	if (userp(me)){ 
		if (me->query("force")>50)
			me->add("force", -50);
		else
			me->set("force",0);
	}

	wp = me->query_temp("weapon");
	
	if(!wp){
		msg=HIW"\n$N内力凝聚，手上似罩了一层寒霜，双掌泛白，轻飘飘拍出，似乎并没有什么目标，
身畔却劲力深藏，有若寒流泛涌。\n"NOR;
		
	} else {
		msg = HIW"\n$N"+HIW"内力凝聚，一层寒霜罩在了手中的"+ wp->name()+HIW"上，手腕一转，划出了数道弯曲的曲线，
竟似织成了一片光网，密密地向四周洒下。\n"NOR;
	}

	message_vision(msg, me);
	
	enemy =	me->query_enemy();
	
	me->add_temp("apply/attack",  extra);
		
	for (i = 0 ; i< sizeof(enemy); i++) {	
		if( enemy[i]&& enemy[i]->is_character()
        		&& me->is_fighting(enemy[i]) && !me->is_busy() )               
		{	
			target = enemy[i];   									       			
	   		COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");  
       	}
	}	        		
	
	me->add_temp("apply/attack", -extra);
    
	me->perform_busy(2);
	
	return 1;
}

