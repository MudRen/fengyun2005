#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target, object friend)
{
	string msg;
	int k;
	object you,weapon,ob;
	int skl_me, extra_me, skl_you,extra_you,extra, skill;
		
	if (me->query_skill("chillblade",1) < 20)
		return notify_fail("『雨后初虹』需要至少20级的冰镜七诀。\n");
	
	if (me->query("gender") == "男性")
		return notify_fail("男子不适合施展轻盈灵动的『雨后初虹』。\n");

	target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『雨后初虹』只能对战斗中的对手使用。\n");
	
	weapon = me->query_temp("weapon");
	
	skl_me= me->query_skill("chillblade",1);
	extra_me= me->query_skill("blade");
		
	if (!friend || friend == me) {
		msg = HIG"\n$N"HIG"手中的"+weapon->name()+HIG+"突然泛起一片光幕，幕覆如雨，密密潇潇，向$n"HIG"落去。\n"NOR;
        msg+= HIC"刀锋骤然一转，从光幕中破出一道弯弧劈去，宛如雨后初现的彩虹。\n"NOR;
        message_vision(msg, me, target);
        me->add_temp("apply/attack",skl_me);
        me->add_temp("apply/damage",extra_me);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
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
	if(!you->query_skill("chillblade",1) || you->query_skill_mapped("blade") != "chillblade" ) 
        return notify_fail("同伴没有配合的武功。\n");  
    if (you->query_skill("chillblade",1)< 20)
    	return notify_fail("同伴的冰镜七诀等级太低。\n");
    if(!objectp(ob=you->query_temp("weapon")) || ob->query("skill_type") != "blade") 
        return notify_fail("同伴没有持刀。\n");
	if (you->query("gender")=="女性")
		return notify_fail("此套合击技只能男女使用。\n");
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
        
	skl_you= you->query_skill("chillblade",1);
	extra_you= you ->query_skill("blade");
	skill = skl_me + skl_you;
		
	msg = HIG"\n$N"HIG"手中的"+weapon->name()+HIG+"突然泛起一片光幕，幕覆如雨，密密潇潇。\n"NOR;
	message_vision(msg,you,target);
	
	msg = HIY"\n$N手中"+weapon->name()+HIY+"慢慢地挥出，剧烈颤动的刀锋封向$n，形如一片黑沉的刀云。\n"NOR;
	message_vision(msg,me,target);
	
	message_vision(HIW"\n光幕与刀云相错而过，刹时间合二为一，迅如夏夜雷电，轻若雨后初虹，直直向"+target->name()+"劈出！\n"NOR,me);
	
	me->add_temp("apply/attack", skill);
	me->add_temp("apply/damage", extra_me);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
	me->add_temp("apply/damage", -extra_me);
	me->add_temp("apply/attack", -skill);
	
	you->add_temp("apply/attack", skill);
	you->add_temp("apply/damage", extra_you);
	COMBAT_D->do_attack(you,target, TYPE_PERFORM,"");
	you->add_temp("apply/attack", -skill);
	you->add_temp("apply/damage", -extra_you);
	
	me->perform_busy(2);
	you->perform_busy(2);
		
	return 1;
}

