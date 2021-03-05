// silencer@fengyun4. workgroup

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, mod,duration;
	int damage;

   	if(me->query("class")!="shenshui")
    	return notify_fail("只有神水宫弟子才能使出『追命』的绝技。\n");

	extra = me->query_skill("nine-moon-steps",1);
	
	if ( extra < 180 || me->query_skill("nine-moon-claw",1)< 170
		|| me->query_skill("nine-moon-spirit",1)< 170
		|| me->query_skill("chaos-steps",1) < 120 ) 
		return notify_fail("『追命式』需要180级九阴身法、120级倒乱七星步、170级九阴神抓和170级姹女神功。\n");

	if (me->query_skill_mapped("force") != "nine-moon-force")
		return notify_fail("『追命式』需要九阴心经的配合。\n");
	if (me->query_skill_mapped("unarmed") != "nine-moon-claw")
		return notify_fail("『追命式』需要九阴神爪的配合。\n");
	
	duration = me->query("timer/pfm/zhuimin") + 120 
			- time()- F_ABILITY->check_ability(me,"zhuiming_add")*5;
	if (duration>0)
		return notify_fail("你需要等待"+duration+"秒才能再次使用『追命式』。\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『追命式』只能对战斗中的对手使用。\n");

	mod = COMBAT_D->can_busy(me, target, "nine-moon-steps");	
	if (!mod)
		return notify_fail(HIW"此人身法灵活，不会被此步法迷惑的。\n"NOR);
		
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了，直接上破颅罢。\n");

	me->set("timer/pfm/zhuimin",time());
	message_vision(HBRED+HIW"$N"HBRED+HIW"深吸长气，按着奇门八卦方位，脚踩连环，绕圈飞进。\n"NOR,me,target);
	
	if (COMBAT_D->do_busy_attack( me, target, "nine-moon-steps/lianhuanbu", "rev-unarmed", 100, mod))
	{
		message_vision(WHT"微风飒然，$N"NOR+WHT"已到了$n"NOR+WHT"身后，$n"NOR+WHT"进退两难，无法可施!\n"NOR,me, target);
		target->force_busy(2);
		target->set_temp("busy_timer/nine-moon-steps",time());
	}
	else{
		message_vision(YEL"$n"NOR+YEL"施展绝顶轻功，俟的从干方绕到异位，轻松脱困！\n\n"NOR,me, target);
	}

	// 2.7M 900	
	// 6.4M 200*2 + 180 + 180 + 200*2 + 103 *3 = 1469
	// full 200*2  +180 + 180 + 200*2 + 140 *3 = 1580
	extra =   me->query_skill("nine-moon-claw",1)*2 
		+ me->query_skill("nine-moon-steps",1)
		+ me->query_skill("nine-moon-force",1)
		+ me->query_skill("nine-moon-spirit",1)*2
		+ F_LEVEL->get_level(me->query("combat_exp"))*3;
			
	// + atk 240 -> 308, dmg 240 -> 308, a normal one-hit perform.	
	me->add_temp("apply/attack", extra/7);	
	me->add_temp("apply/damage", extra/5);
	msg = HIW"$N"HIW"身形闪动，兔起鹘落，迅捷无比，如鬼魅般欺到$n"HIW"身边，
袖中伸出纤纤素手，五根手指疾抓$n"HIW"$l。\n"NOR ;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM, msg);
	me->add_temp("apply/attack", -extra/7);
	me->add_temp("apply/damage", -extra/5);
                                
	if (target->query_temp("damaged_during_attack")	)
	{
		message_vision(HIW"\n$N"+HIW"一招得手，更不稍停，反掌间五根手指已向$n"+HIW"的头顶插了下去。\n"NOR,me,target);
		if (COMBAT_D->do_busy_attack(me, target, "nine-moon-claw", "unarmed", 500, 10))
		{
			damage = extra;
			damage = COMBAT_D->magic_modifier(me, target, "kee", damage);
			target->receive_damage("kee",damage, me);

			extra=0;

			if (target->query("kee") < 0)
			{
				if ( time() - target->query("timer/lifesave") >= 3600 )
				{
					message_vision(MAG"只听得＂咯喇＂一声，$n"MAG"五指已插入$N"+MAG"顶门，一缕淡淡的紫雾升腾而起！\n"NOR,target,me);
					extra=1;
				}
			}
			else
				message_vision(MAG"$N"+MAG"惨叫一声，顶门已被$n"+MAG"的手掌罩住！\n"NOR,target,me);

			COMBAT_D->report_status(target);

			if (extra==1)
				message_vision(HIW"\n$N"HIW"回身收爪，舔了舔方自$n"HIW"顶门抽出的指尖，露出微微扭曲的笑容。\n\n"NOR,me,target);

		}
		else	
			message_vision(YEL"$N"NOR+YEL"不慌不忙，抢前半步，避开了脑门要害。\n"NOR,target);
	}

	if (target)	target->stop_busy();	// DOn't make it a 100% busy for teammate.
	me->perform_busy(2);
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
