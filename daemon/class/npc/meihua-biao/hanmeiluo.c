// silencer@fengyun
// 雪里已知春信至，
// 寒梅点缀琼枝腻，
// 香脸半开娇旖旎，
// 当庭际，
// 玉人浴出新妆洗。



#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
    	string msg;
    	int extra, count, i;
    	int tmp,chance;
    	object weapon;
    	
    	extra = me->query_skill("meihua-biao",1);
    	if ( userp(me) && extra < 150) 
    		return notify_fail("［寒梅落］需要150级的［梅花镖法］！\n");
  	
    	if( !target ) target = offensive_target(me);
    	if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
        	return notify_fail("［寒梅落］只能对战斗中的对手使用。\n");
        
        weapon = me->query_temp("weapon");
	count = weapon->query_amount();
	if (count < 10)
		return notify_fail("你的暗器数量太少。\n");
        
    	me->add_temp("apply/attack",extra);
    	me->add_temp("apply/damage",extra*2);
    
    	msg = HIG  "\n\n$N使出梅花镖法中的［寒梅落］，一招连环五式，有若寒梅绽放！！\n\n"NOR;
/*	  msg += HIR"
		玉      当     	香      寒  	雪
						  	
		人      庭     	脸      梅  	里
						  
		浴      际     	半     	点  	已
					 
		出      	开     	缀  	知
		        	  	
		新      	娇     	琼  	春
			          	
		妆      	旖     	枝  	信
			          	
		洗      	旎     	腻    	至
	  	
	  	\n"NOR;			
	  message_vision(msg,me,target);
	  
	  i = 5; 
	  while (i--) 
	  	  COMBAT_D->do_attack(me,target, TYPE_REGULAR,0); */
	  	msg+=HIM"    雪里已知春信至，寒梅点缀琼枝腻，" NOR;
	    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	   
	    	msg = HIM"    香脸半开娇旖旎，" NOR;
	    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	       
	    	msg = HIM "    当庭际，玉人浴出新妆洗！！" NOR;
	    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
 
    	me->start_busy(3);
    	me->add_temp("apply/attack",-extra);
    	me->add_temp("apply/damage",-extra*2);
    	return 1;
}
