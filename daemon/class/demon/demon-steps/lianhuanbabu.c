// tie@fengyun
//	NPC only, no plan for players.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, mod;
	
	extra = me->query_skill("demon-steps",1);
	if ( userp(me) && extra < 200) 
		return notify_fail("［连环八步］需要200级［如意人魔连环八步］！\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［连环八步］只能对战斗中的对手使用。\n");
		
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
	
	mod = COMBAT_D->can_busy(me, target, "demon-steps");	
	if (!mod)
		return notify_fail(HIW"此人身法灵活，不会被此步法迷惑的。\n"NOR);
		
	message_vision(HIC"“九天十地，诸神诸鬼，俱入我门，唯命是从！！”
$N"HIC"脚踩八卦，口念魔咒，身子飞速旋动，如一道青烟般在$n"HIC"身边穿梭！\n"NOR,me,target);
	
	if (COMBAT_D->do_busy_attack(me, target, "demon-steps/lianhuanbabu", "step", 300, mod))
	{
		message_vision(HIB"$N被扰得心胆俱裂，魂飞魄散！\n"NOR,target);
		target->force_busy(3);
		target->set_temp("busy_timer/demon-steps",time());
	}
	else{
		message_vision(YEL"$n静气凝神，不为所动，$N自己反而转了个头晕眼花！\n"NOR,me,target);
		me->perform_busy(2);
	}
	return 1;
}
