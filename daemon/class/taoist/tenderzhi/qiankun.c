// silencer@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target, object friend)
{
	string msg;
	int k;
	object you;
	int skl_me, extra_me, skl_you,extra_you,ob;
		
	target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『乾坤』只能对战斗中的对手使用。\n");
	
	skl_me= me->query_skill("tenderzhi",1);
	extra_me= me->query_skill("unarmed");
		
	if (!friend || friend == me) {
		msg = BBLU+ HIG+"$N施展出阴柔的柔虹指，无数指影夹杂着阴冷的指风，点向$n的全身！\n" + NOR;
        me->add_temp("apply/attack",skl_me);
        me->add_temp("apply/damage",extra_me);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-skl_me);
        me->add_temp("apply/damage",-extra_me);
		me->perform_busy(2);
		return 1;		
	}
		
	you = friend;
	if ( you->team_member(me) 
			|| (!userp(me) && you->query("npc_team")==me->query("npc_team")))
		k = 1;
		
	if (!k)
		return notify_fail("同伴必须是与你在同一个队伍中。\n");  
    
    // 对同伴进行判断           
	if(!you->query_skill("yiyangzhi",1) || you->query_skill_mapped("unarmed") != "yiyangzhi" ) 
        return notify_fail("同伴没有配合的武功。\n");  
    if(objectp(ob=you->query_temp("weapon")) && ob->query("skill_type") != "unarmed") 
        return notify_fail("同伴不是空手。\n");
	if (you->is_busy())
		return notify_fail("同伴正忙着呢。\n");
	if (you->query_temp("till_death/lockup") || you->query_temp("is_unconcious"))
		return notify_fail("同伴现在无法使用特技。\n");
				
	if (you == target)
		return notify_fail("想窝里反啊？\n");
	if (userp(you) && !you->is_fighting(target))
		return notify_fail("同伴与对方并不在战斗中。\n");

	if (userp(me))
	if (!COMBAT_D->legitimate_kill(you, target)) {
		if (stringp(target->query("NO_KILL")))
			return notify_fail(target->query("NO_KILL"));
		if (stringp(target->query("NO_PK")))
			return notify_fail(target->query("NO_PK"));	
		else 
			return notify_fail("想用这办法把同伴扯进江湖争斗来？不成！\n");
	}
	
	// this is to prevent those annoying checking, 2 vs 1 == kill
	 	if (!me->is_killing(target->get_id())){
 			me->kill_ob(target);
 			target->kill_ob(me);
 		}
 		
 		if (!you->is_killing(target->get_id())){
        	you->kill_ob(target);
        	target->kill_ob(you);
        }
        
	skl_you= you->query_skill("yiyangzhi",1);
	extra_you= you ->query_skill("unarmed");
		
	msg = BBLU+ HIG+"$N施展出阴柔的柔虹指，"+ HIR + you->name()+"施展出刚阳的一阳指，\n"+ HIY +
		"无数指影夹杂着阴冷炽热的指风，点向$n的全身！\n\n" + NOR;
		
		me->add_temp("apply/attack",skl_you+skl_me*2);
		me->add_temp("apply/damage",extra_you*2+extra_me*2);
	    COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		me->add_temp("apply/attack",-skl_you-skl_me*2);
	    me->add_temp("apply/damage",-extra_you*2-extra_me*2);
		
		me->perform_busy(2);
		you->perform_busy(2);
		
	return 1;
}
