// Silencer@fengyun	June.2005

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,extra,mod,duration;
	mapping buff;
	
	if(me) 
		return notify_fail("『见龙卸甲』停用。\n");
		
	if (me->query("class")!="fugui") 
		return notify_fail("『见龙卸甲』为富贵特技。\n");
		
	extra=me->query_skill("eagle-claw",1);
	if(extra<120)
		return notify_fail("『见龙卸甲』需要120级鹰爪功。\n");	
	
	duration = me->query("timer/pfm/fg_xiejia") - time() + 180;
    if( duration > 0 ) {
       	return notify_fail("你还需要等待"+(int)(duration+1)+"秒左右才能再次使用『见龙卸甲』。\n");
	}
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『见龙卸甲』只能对战斗中的对手使用。\n");
	
	if (ANNIE_D->check_buff(target,"irondown"))
		return notify_fail(target->name()+"硬气功已被瓦解。\n");
		
	mod = COMBAT_D->can_busy(me, target, "eagle-claw");	
	if (!mod)
		return notify_fail(HIW"此人功力深湛，无法得逞。\n"NOR);
	
	lvl = 200;					
	if (!userp(me)) 	lvl = 300;
		
	msg = BRED +HIW"
$N大喝一声『见龙卸甲』！掌风瞬间从$n身肩掠过。\n" NOR;
	message_vision(msg, me, target);
	
	if (COMBAT_D->do_busy_attack( me, target, "eagle-claw/jianlongxiejia","unarmed", lvl, mod))
	{
		msg = RED"$n惊讶，一时间感觉硬气功完全提不上来！\n"NOR;
		message_vision(msg, me, target);
		buff =
		([
			"caster":me,
			"who":	 target,
			"type": "irondown",
			"att":  "curse",
			"name": "鹰爪功·见龙卸甲",
			"time":  60,
			"buff1": "apply/iron-cloth",
			"buff1_c": -target->query_skill("iron-cloth")/10*7,
			"buff2": "apply/armor",
			"buff2_c": -target->query_temp("apply/armor")/10*7,
			"buff_msg": "",
			//"condition_type":  "<身法迟钝>",
			"warn_msg":"",
			"disa_type": 0, 
		]);
		ANNIE_D->buffup(buff);	
		me->set("timer/pfm/fg_xiejia", time());
	} else	{
			msg = CYN"$n早有防备，微挪身位，$N掌风擦身而过。\n"NOR;
			message_vision(msg,me,target);
			me->set("timer/pfm/fg_xiejia", time()-120);
	}
	me->perform_busy(1); 
	return 1;
}

