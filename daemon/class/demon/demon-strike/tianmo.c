// silencer@fengyun
//	三个穿着墨绿绣花长袍，头戴白玉黄金高冠的老人
//	“九天十地，诸神之子，遇难遭劫，神魔惧泣。”
// 	九天十地，诸神诸魔，俱来护驾，同登极乐
//	九天十地，诸神诸鬼，俱入我门，唯命是从
//	丁香姨：“黑虎堂下，又分白鸽、灰狼、黄犬，三个分党。。。”
//    “黄犬”负责追踪：“灰狼”负责搏杀：“白鸽”的任务，就是负责刺探传递各路
//	的消息。


#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, damage;
	
	extra = me->query_skill("demon-strike",1) ;
	if(userp(me) && extra < 150 ) 
		return notify_fail("『天魔式』需要180级如意地魔连环八掌！\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『天魔式』只能对战斗中的对手使用。\n");
	
	damage = me->query_skill("demon-strike",1)*3;
	
	msg = HIR "\n$N喝道：『九天十地，诸神诸鬼，俱入我门，唯命是从』，
倏然间双臂暴长，一招『天魔式』，双手拢向$n！" NOR;
	
	if(random(me->query("combat_exp")*3) >= (int)target->query("combat_exp"))	{
		message_vision(msg+"\n",me,target);
		message_vision( HIC "$N躲闪不及，全身正被掌影罩住！ 一股青气从顶门喷涌而出！\n" NOR,target);
		damage = COMBAT_D->magic_modifier(me, target, "sen", damage);
		target->receive_damage("sen",damage,me);
		me->receive_fulling("sen", damage/2,me);
		COMBAT_D->report_status(target);
	        COMBAT_D->win_lose_check(me,target,damage);
	}	
	else{
        	me->add_temp("apply/attack",extra);
        	me->add_temp("apply/damage",extra);
        	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        	me->add_temp("apply/attack",-extra);
        	me->add_temp("apply/damage",-extra);
	}
	me->perform_busy(2);
	return 1;
}
