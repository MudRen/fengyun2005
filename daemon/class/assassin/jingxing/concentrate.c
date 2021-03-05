#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount); 
int exert(object me, object target, int amount)
{
        int skill,cl;
        skill = me->query_skill("jingxing",1); 
        if (me->query("class")!="assassin")
                return notify_fail ("聚神诀只有金钱帮弟子能使用。\n"); 
        if(skill < 150) 
                return notify_fail("你的静行心法太差了！\n");
        if (me->query("combat_exp")<6400000)
                return notify_fail("你的战斗经验不足，还不能领会聚神诀。\n");
        	cl=F_ABILITY->check_ability(me,"jjj_add") ; 
        	
        	if(!cl)
        	  return notify_fail("你的能力尚不足以使用聚神诀。\n"); 
                
        if( target != me ) 
                return notify_fail("聚神诀只能施用于自身。\n");
          
          	
        if( (int)me->query("force") < 200 )   
                return  notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("jingxing/concentrate") ) 
                return  notify_fail("你已经在运功中了。\n");
        
        me->add("force", -200);
        message_vision(HIR "$N藏眼神，凝耳韵、调鼻息、缄舌气，整个人似化成了一把利器。\n" NOR, me);
        me->set_temp("jingxing/concentrate", 1);
        me->add_temp("apply/attack",skill/5);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me,skill :), skill);
        me->start_busy(1);
        return 1;
}   
void remove_effect(object me, int skill)
{
        me->delete_temp("jingxing/concentrate");
        me->add_temp("apply/attack",-skill/5);
        tell_object(me, "你的聚神诀运行完毕，将内力收回丹田。\n");
}
       
