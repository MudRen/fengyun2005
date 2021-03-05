// silencer@fengyun  「雁渡寒潭」

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int my_exp,your_exp, mod;
	object *weapon;
	int enhance;
	
	if (userp(me) && me->query("class")!="shenshui")
		return notify_fail("只有神水弟子才能使用此特级。\n");
	
	if (me->query_skill("nine-moon-sword",1) < 150 || me->query_skill("qingpingsword",1) < 100)
		return notify_fail("『雁渡寒潭』需要150级的九阴剑法和100级清平剑法。\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『雁渡寒潭』只能对战斗中的对手使用。\n");

	mod = COMBAT_D->can_busy(me, target, "nine-moon-sword");	
	if (!mod)
		return notify_fail(HIW"此人功力深湛，不会被此剑法迷惑的。\n"NOR);
	
	if( target->is_busy() )
		return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧！\n");
	
	weapon = me->query_temp("weapon");
	msg = WHT"\n$N"NOR+WHT"平空拔起，一招雁渡寒潭，"+weapon->name()+WHT"在空中一划，登时似天空中洒下了千百点寒星。\n\n"NOR;
	
	me->perform_busy(1);
	
	enhance=325;

	if (COMBAT_D->do_busy_attack( me, target, "nine-moon-sword/yanduhantan", "unarmed", enhance, mod))
	{
		msg += MAG"$n"NOR+MAG"急忙护住上盘，不料$N"NOR+MAG"虚虚实实，无声无息间欺近，在$n"NOR+MAG"的肘上轻轻一划。\n"NOR,
		message_vision(msg, me, target);
		tell_object(target,MAG"你觉得半边身子又酥又麻，似是中了九阴毒气。\n\n"NOR);
		target->force_busy(3);
		target->set_temp("busy_timer/nine-moon-sword",time());
		
	} else {
		msg += YEL"$n"NOR+YEL"识破$N"NOR+YEL"的虚招，纵身往后跃开。\n\n"NOR;
		message_vision(msg, me, target);
	}
		return 1;
}



/*

　　　     /＼              ／\      
　　　   ▕   ＼＿＿　　　／  ︱       
　　　   ▕ ／￣    ◥██◤╲︱       
　　　    ∕                  ﹨       
　　　    ︳   /￣\    /￣\   ▕      
　　　    ︳   ︳●    ●  ︳ ▕       
　　　   ┼    \ /    \　/    ┼      
　　　    ﹨　      ●      　∕         
　　　    ˉ╲　    　   　／ˉ         
　　　    ╭─◤ˉˉˉ￣◥◤﹨           
　　　   （   ︳           /﹀﹀\◢█    
　　　  （____︳  ▕ ／  ▕ .. █◤     
　　　        \︿︿/ ︺︺︺＼●／         
                       ˉ             
　　　　　　　　- FengYun - 　　　
 　　　　　　　annie 06.2005
 　　　　dancing_faery@hotmail.com

*/
