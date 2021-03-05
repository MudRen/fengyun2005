// silencer@fengyun4. workgroup

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, mod, duration;
	int damage;
	object ob;

	if( me->query("class") != "shenshui" ) {
		return notify_fail("只有神水宫弟子才能使出『追命』的绝技。\n");
	}
	extra = me->query_skill("nine-moon-steps", 1);
	if( extra < 180 || me->query_skill("nine-moon-claw", 1) < 200 || me->query_skill("nine-moon-spirit", 1) < 200 ) { 
		return notify_fail("『追命式』需要180级九阴身法、200级九阴神抓和200级姹女神功。\n");
	}
	if( me->query_skill_mapped("force") != "nine-moon-force" ) {
		return notify_fail("『追命式』需要九阴心经的配合。\n");
	}
	if( me->query_skill_mapped("unarmed") != "nine-moon-claw" ) {
		return notify_fail("『追命式』需要九阴神爪的配合。\n");
	}
	if( ob = me->query_temp("weapon") ) {
		if( ob->query("skill_type") != "unarmed" ) {
			return notify_fail("『追命式』是空手武功。\n");
		}
	}
	duration = me->query("timer/pfm/zhuimin") + 300 - time();
	if( duration > 0 ) {
		return notify_fail("你需要等待"+duration+"秒才能再次使用『追命式』。\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『追命式』只能对战斗中的对手使用。\n");
	}
	message_vision(HBRED+HIW"$N"HBRED+HIW"一声轻笑，身形展动，按着奇门八卦方位，绕圈飞进。\n"NOR,me,target);
	if( !target->is_busy() ) {
		if(COMBAT_D->do_busy_attack( me, target, "nine-moon-steps/lianhuanbu", "rev-unarmed", 100, 10) ) {
			message_vision(WHT"阴风迭起，$n"NOR+WHT"竟已捕捉不到$N的行踪，$n"NOR+WHT"大惊失色，慌乱无措!\n"NOR, me, target);
			target->force_busy(1);
		} else {
			message_vision(YEL"$n"NOR+YEL"脚踏生门，一圈，一带，竟似毫无破绽！\n\n"NOR, me, target);
		}
	}

	// 2.7M 900	
	// 6.4M 200*2 + 180 + 180 + 200*2 + 103 *3 = 1469
	// full 200*2  +180 + 180 + 200*2 + 140 *3 = 1580
	extra = me->query_skill("nine-moon-claw",1)*2 
		+ me->query_skill("nine-moon-steps",1)
		+ me->query_skill("nine-moon-force",1)
		+ me->query_skill("nine-moon-spirit",1)*2
		+ F_LEVEL->get_level(me->query("combat_exp"))*3;
			
	// + atk 240 -> 308, dmg 240 -> 308, a normal one-hit perform.	
	me->add_temp("apply/attack", extra/5);	
	me->add_temp("apply/damage", extra/4);
	msg = HIW"\n$N"HIW"身形闪动，如鬼魅般欺到$p"HIW"身边，这一下当真是兔起鹘落，迅捷无比。\n袖中探出纤纤素手，五根手指疾抓$n。\n"NOR ;
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, target, TYPE_PERFORM, "");
	me->add_temp("apply/attack", -extra/5);
	me->add_temp("apply/damage", -extra/4);		

	if( target->query_temp("damaged_during_attack")	) {
		me->set("timer/pfm/zhuimin", time());
		msg=MAG"$n"NOR MAG"只觉冷厉的阴风从$N的指尖如水银泻地般侵入自己的奇筋八脉。\n\n"NOR;
   		msg += RED"$n"NOR RED"心头一颤，脚步竟似不稳。。。\n\n"NOR;
		msg += HIW"$N"HIW"提气再起，指尖暴突，目露狰狞之色，挟劲风自空中飞扑而下！\n反掌间五根手指已向$n"+HIW"的头顶插了下去。\n\n"NOR ;
		message_vision(msg, me, target);
		if( target->query("kee") < 5000 && !target->query("boss") && !target->query("big_boss") && target->query("kee") < target->query("max_kee")/5 ) {
			message_vision(HIR"只听得一声惨嚎，$N五指已没入$n"HIR"头颅，$n"HIR"顶门血如泉涌，抽搐几下，倒在地上。\n"NOR, me, target);
    		// Most of times it's death sentence
    		target->receive_damage("kee", 6000, me);
    		message_vision(HIW"\n$N"HIW"回身收爪，舔了舔方自$n"HIW"顶门抽出的指尖，露出微微扭曲的笑容。\n\n"NOR, me, target);
    		COMBAT_D->win_lose_check(me, target, damage);
		} else {	// +atk 325, +dmg 1580, and full hit damage.
  			me->add_temp("apply/attack", extra/3);	
	  		me->add_temp("apply/damage", extra);
	  		target->add_temp("marks/full_hit_damage", 1);
  			msg = HIW"$n大惊失色，提气后掠，勉强避开了顶门要害。\n"NOR;
	  		COMBAT_D->do_attack(me, target, TYPE_PERFORM, msg);
  			target->add_temp("marks/full_hit_damage", -1);
  			me->add_temp("apply/attack", -extra/3);
  			me->add_temp("apply/damage", -extra); 	 
			if( !target->query_temp("damaged_during_attack") ) {
				message_vision(HIW"$n"HIW"临危不乱，堪堪避开了破脑之祸。$N一击不中，地面上生生被抓出五个孔洞。\n"NOR, me, target);
			}
		}
	}

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