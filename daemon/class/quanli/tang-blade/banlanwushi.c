// tie@fengyun
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
    int extra;
    int tmp,chance;
    extra = me->query_skill("tang-blade",1);
    if ( userp(me) && extra < 150) 
    	return notify_fail("［瓣兰五式］需要150级的［五瓣兰刀法］！\n");
  	
    if( !target ) target = offensive_target(me);
    if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
        return notify_fail("［瓣兰五式］只能对战斗中的对手使用。\n");
        
    me->add_temp("apply/attack",extra);
    me->add_temp("apply/damage",extra*2);
    
    msg = HIG  "\n\n$N使出五瓣兰刀法中的［瓣兰五式］，一招连环五式，有若兰花绽放！！\n"NOR;
  	msg+=HIC"第一刀！兰花初现" NOR;
    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
   
    	msg = HIC"第二刀！兰花巍巍" NOR;
    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
  
      	msg = HIC "第三刀！花开花落" NOR;
    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
       
    	msg = HIC  "第四刀！日斜星河" NOR;
    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    
    	msg = HIC  "第五刀！兰花五瓣" NOR;
    	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
 
    me->start_busy(3);
    me->add_temp("apply/attack",-extra);
    me->add_temp("apply/damage",-extra*2);
    return 1;
}
