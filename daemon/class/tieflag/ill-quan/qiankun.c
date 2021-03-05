#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
      	string msg;                                
        int extra;
	object target1, target2, *enemy;

	extra = me->query_skill("ill-quan",1);
	if ( extra < 150) 
		return notify_fail("「乾坤挪移」需要150级病维摩拳！\n");


	enemy=me->query_enemy();
        if (sizeof(enemy)<2) 
        	return notify_fail("你必须同时和两个或两个以上的敌手战斗才能使用乾坤挪移！\n");
        
        if( target) 
        	return notify_fail("「乾坤挪移」不需要指定对手。\n");
        
	target1=enemy[0];
        target2=enemy[1];
        
        if( !target1 || !target2
	||	!target1->is_character() || !target2->is_character()
	||	!me->is_fighting(target1) || !me->is_fighting(target2))
		return notify_fail("［乾坤挪移］只能对战斗中的对手使用。\n");
	
	if (me->query("force")<=100) 
		return notify_fail("你的内力不足，无法带动敌人攻势！\n");
		
        if (target1->query_busy() && target2->query_busy())
        	return notify_fail(WHT"两个对手正忙，无法对他们使用「乾坤挪移」\n"NOR);
        
        if (userp(me))	me->add("force",-100);
        
        message_vision(CYN"$N使出病维摩拳的不传之秘「乾坤挪移」\n"NOR,me);
        me->start_busy(2);
        
        if (random(me->query("combat_exp")*(extra/30+1))>target1->query("combat_exp"))
        {
          message_vision(HIY "$N伸手带动$n的攻势，使之攻向"+target2->name()+"！\n" NOR,me,target1);
          COMBAT_D->do_attack(target1,target2, TYPE_PERFORM, 0);  
          if(target2->query_temp("damaged_during_attack")) 
          		target2->receive_damage("kee",0,me);
          target1->force_busy(1);
        }
        else
        {
          message_vision(BLU"但$n看破$N的意图，趁势发动攻击！\n"NOR,me,target1);
          COMBAT_D->do_attack(target1,me,TYPE_PERFORM, 0);
        }
        
        if (random(me->query("combat_exp")*(extra/30+1))>target2->query("combat_exp"))
        {
          message_vision(HIY "$N伸手带动$n的攻势，使之攻向"+target1->name()+"！\n" NOR,me,target2);
          COMBAT_D->do_attack(target2,target1, TYPE_PERFORM, 0);  
          if(target1->query_temp("damaged_during_attack")) 
          		target1->receive_damage("kee",0,me);
          target2->force_busy(1);
        }
        else
        {
          message_vision(BLU"但$n看破$N的意图，趁势发动攻击！\n"NOR,me,target2);
          COMBAT_D->do_attack(target2,me,TYPE_PERFORM, 0);
        }
        
     	return 1;
}
