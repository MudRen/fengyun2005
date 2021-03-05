//	『寒霜凝梅』攻击multiple enemies, 

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target)
{
	object wp,weapon;
	int cost, extra, myexp,yourexp, i;
	int base,duration;
	string msg, msg2, skill;
	object	*enemy;
	mapping buff;
	
	if (me->query("class") != "legend") 
		return notify_fail("只有铁雪弟子可以使用『聚威』。\n");
	
	extra = me->query_skill("six-sense",1);
	if( extra < 230 || me->query_skill("qidaoforce",1)< 150)
		return notify_fail("『聚威』需要230级的六灵暗识和150级棋道心法。\n");
	
	wp = me->query_temp("weapon");
	
		
	duration = me->query("timer/pfm/tx_juwei")-time() + 180;
    
    if (extra>=300)	duration = duration -60;
    else if (extra>=270)	duration = duration-30;
    
    if (duration>0)
       	return notify_fail("你还需要等待"+(int)(duration)+"秒钟左右才能够再次使用聚威诀。\n");
    
    if(!wp)
    	return notify_fail("『聚威』必须配合短歌刀法或蝶恋花剑法使用。\n");
    
    if( !me->is_fighting() )
		return notify_fail("『聚威』只能在战斗中使用。\n");
			
	if(wp->query("skill_type") == "blade" && me->query_skill_mapped("blade")=="shortsong-blade"){
		msg=HIW"\n$N目光收缩，发出一声大吼，一刀由上而下垂直劈落！
这一刀声势非凡，刀至半途，又变成十二刀斜削，根本避无可避。\n\n"NOR;
		msg2 = WHT"$N沉肩，拧腰，"+wp->name()+NOR+WHT"御惊雷击下。\n"NOR;
	} else if (wp->query("skill_type") == "sword" && me->query_skill_mapped("sword") == "diesword") {
		msg = HIW"$N的剑法忽然变了，一柄平凡的"+wp->name()+NOR+HIW"，忽然化作了一道光华夺目的流星。
从天外飞来的流星，不可捉摸，不可抵御。\n\n"NOR;
		msg2 = WHT"$N脚步微错，青锋回旋，"+wp->name()+NOR+WHT"化电光击下。\n"NOR;
	} else
		return notify_fail("『聚威』必须配合短歌刀法或蝶恋花剑法使用。\n");
		
	message_vision(msg, me);
	
	me->set("timer/pfm/tx_juwei",time());
		
	enemy =	me->query_enemy();
	
	me->add_temp("apply/attack", extra*2);		
	me->add_temp("apply/damage", extra*2);
	for (i = 0 ; i< sizeof(enemy); i++) {	
		if( enemy[i]&& enemy[i]->is_character()
        		&& me->is_fighting(enemy[i]) && !me->is_busy() )               
		{	
			target = enemy[i];
			target->add_temp("cant_parry",1);  
			target->add_temp("cant_dodge",1); 									       			
	   		message_vision(msg2,me,target);
	   		COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");
	   		target->add_temp("cant_parry",-1);
	   		target->add_temp("cant_dodge",-1);
	   		if (!userp(target))
	   			target->add_hate(me, extra*5);
	   		
	   		if (target->query_temp("damaged_during_attack")
	   			&& ANNIE_D->check_buff(target,"fight_stop")<1) {
		  		buff =
				([
					"caster":me,
					"who":target,
					"type":"fight_stop",
					"att":	"curse",
					"name": "棋道心法·聚威",
					"time":  10,
					"buff1": "marks/fight_stop",
					"buff1_c":	1,	
					"buff_msg":"",
					"disa_type": 1,
				]);
				ANNIE_D->buffup(buff);	 				
	   		  }
       	}
	}	        		
	
	me->add_temp("apply/attack", -extra*2);
	me->add_temp("apply/damage", -extra*2);    
	me->perform_busy(1);
	
	return 1;
}

