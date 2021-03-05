// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target, object friend)
{
	string msg;
	int extra,i,j,k,extra_y;
	string *style = ({
BBLU+HIR "$N"BBLU+HIR"手中$w"BBLU+HIR"突发红光，急劈$n"BBLU+HIR"的$l！" NOR,
BBLU+HIY "$N"BBLU+HIY"手中$w"BBLU+HIY"突发黄光，直取$n"BBLU+HIY"的$l！" NOR,
BBLU+HIW "$N"BBLU+HIW"手中$w"BBLU+HIW"突发白光，径砍$n"BBLU+HIW"的$l！" NOR,
BBLU+HIG "$N"BBLU+HIG"手中$w"BBLU+HIG"突发绿光，平削$n"BBLU+HIG"的$l！" NOR,
BBLU+HIB "$A"BBLU+HIB"手中$W"BBLU+HIB"和$B"BBLU+HIB"手中的$V"BBLU+HIB"交织错合，泛出层层黑气，网向$n！" NOR,
});
	object ob;
	object you, *myteam;
	
	if (!friend || friend == me)
		return notify_fail ("一片莲心需要与同伴一起使用。\n");
	
	you = friend;
	if ( you->team_member(me) 
			|| (!userp(me) && you->query("npc_team")==me->query("npc_team")))
		k = 1;
		
	if (!k)
		return notify_fail("同伴必须是与你在同一个队伍中。\n");  
    
    // 对同伴进行判断           
	if( !you->query_skill("lianxin-blade",1) 
		|| you->query_skill_mapped("blade") != "lianxin-blade") 
        	return notify_fail("同伴没有配合的武功。\n");  
    if(!objectp(ob=you->query_temp("weapon"))) 
        	return notify_fail("同伴没有执刀。\n");
	if(ob->query("skill_type") != "blade")
        	return notify_fail("同伴没有执刀。\n");
	if (you->is_busy())
		return notify_fail("同伴正忙着呢。\n");
	if (you->query_temp("till_death/lockup") || you->query_temp("is_unconcious"))
		return notify_fail("同伴现在无法使用特技。\n");
				
	if (!target)	target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『一片莲心』只能对战斗中的对手使用。\n");
	
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
        
	message_vision( BBLU + HIC "\n$N"BBLU+HIC"和$n"BBLU+HIC"的身形突然交织在一起，越转越快！\n" NOR,me,you);

	target->set_temp("no_check_pfm_win",1);
	
	msg = style[0];
	
	extra = me->query_skill("lianxin-blade",1);
	extra_y = you->query_skill("lianxin-blade",1);
	
    me->add_temp("apply/attack", extra);
    me->add_temp("apply/damage", extra);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	target->set_temp("skip_damage_record",1);
		
	msg = style[1];
    
    you->add_temp("apply/attack", extra_y);
    you->add_temp("apply/damage", extra_y);
		COMBAT_D->do_attack(you,target, TYPE_PERFORM,msg);
	you->add_temp("apply/attack", -extra_y);
	you->add_temp("apply/damage", -extra_y);
	
	msg = style[2];
    me->add_temp("apply/attack", extra);
    me->add_temp("apply/damage", extra);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	
	msg = style[3];
	extra = you->query_skill("lianxin-blade",1);
    you->add_temp("apply/attack", extra_y);
    you->add_temp("apply/damage", extra_y);
		COMBAT_D->do_attack(you,target, TYPE_PERFORM,msg);
	you->add_temp("apply/attack", -extra_y);
	you->add_temp("apply/damage", -extra_y);

		style[4] = replace_string(style[4],"$A", me->name());
        style[4] = replace_string(style[4],"$B", you->name());
        style[4] = replace_string(style[4],"$W", (me->query_temp("weapon"))->name());
        style[4] = replace_string(style[4],"$V", (you->query_temp("weapon"))->name());
	
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,style[4]);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
	
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

	
	me->perform_busy(3);
	you->perform_busy(3);
	return 1;
}

	