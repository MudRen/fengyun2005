//mimicat@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra,i;
	string *perform_msg=({
	YEL"$N单手在地上一撑，身体不可思议地再次弹起，双脚蹬向$n的膝关节。\n"NOR,
	YEL"$N借着下落之势，再次转身，脚以迅雷不及掩耳之势，扫向$n的颈部。\n"NOR,
	YEL"$N高高跃起，空中一个拧腰，居然以脚作刀猛地自$n的头顶斩了下来。\n"NOR,
	YEL"$N猛地从侧面跃向$n，趁着$n不知所措之时，一个高踢踹向$n的面门。\n"NOR,
	});

        extra = me->query_skill("enmeiryu",1);
        if(extra<100) 
        	return notify_fail("『紫电四连脚』需要100级的陆奥圆明流拳术\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『紫电四连脚』只能对战斗中的对手使用。\n");

	
	message_vision(HIY"$N突然一笑，右手在$n的眼前一晃，跃向另一侧。$n一时无法看清$N的身影。 
		紫	电	四	连	脚 \n"NOR,me,target);
	
	extra = me->query_skill("enmeiryu",1) / 2;
	
	me->add_temp("apply/attack", extra);    
    me->add_temp("apply/damage", extra);		
	
	for(i=0;i<4;i++){
		msg = perform_msg[i];	
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	}
	
	me->add_temp("apply/attack", -extra);
    me->add_temp("apply/damage", -extra);
	
	me->perform_busy(3);        	

        return 1;
        
}     
