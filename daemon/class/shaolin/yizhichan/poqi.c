// hippo@fengyun	2010.3.11

#include <ansi.h>
#include <combat.h>

void enforce_refresh(object ob,int off);
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,extra,mod,duration,old_force_factor;
	mapping buff;
	
	if (me->query("class")!="shaolin") 
		return notify_fail("『破气』为少林特技。\n");
		
	extra=me->query_skill("yizhichan",1);
	if(extra<150)
		return notify_fail("『破气』需要150级一指禅。\n");	

	duration = me->query("timer/pfm/sl_poqi") - time() + 600;
    if( duration > 0 ) {
       	return notify_fail("你还需要等待"+(int)(duration+1)+"秒左右才能再次使用『破气』。\n");
	}

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『破气』只能对战斗中的对手使用。\n");
	
	if (ANNIE_D->check_buff(target,"enforcedown"))
		return notify_fail(target->name()+"气势已经被破解。\n");
		
	mod = COMBAT_D->can_busy(me, target, "yizhichan");	
	if (!mod)
		return notify_fail(HIW"此人功力深湛，无法得逞。\n"NOR);
	
	//lvl = 250;					
	lvl = (int) me->query_skill("unarmed") /40 + 1;
	if (!userp(me)) 	lvl = 300;
		
	msg = BRED +HIY"
$N使出一招『破气』！一指快速的经过$n身上各处穴道。\n" NOR;
	message_vision(msg, me, target);
	if (COMBAT_D->do_busy_attack( me, target, "yizhichan/poqijue","unarmed", lvl*100, mod))
	{
		old_force_factor=target->query("force_factor");
		target->set("force_factor",0);
		msg = RED"$n察觉到的时候已经晚了，全身上下根本使不上劲！\n"NOR;
		message_vision(msg, me, target);
		buff =
		([
			"caster":me,
			"who":	 target,
			"type": "enforcedown",
			"att":  "curse",
			"name": "一指禅·破气",
			"time":  60,
//			"buff0": "force_factor",
//			"buff0_c": target->query("force_factor"),
			"buff_msg": "",
			"disa_msg": "",
			//"condition_type":  "<身法迟钝>",
			"warn_msg":"",
			"disa_type": 0, 
		]);
		ANNIE_D->buffup(buff);	
		call_out("enforce_refresh",60,target,old_force_factor);
		me->set("timer/pfm/sl_poqi", time());
	} else	{
			msg = WHT"$n看破$N的手势，不慌不忙的躲开。\n"NOR;
			message_vision(msg,me,target);
			me->set("timer/pfm/sl_poqi", time());
	}
	me->perform_busy(1); 
	return 1;
}

void enforce_refresh (object ob,int off) {
	if (ob)
		ob->set("force_factor",off);
}