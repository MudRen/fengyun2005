//neon@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
void get_up(object me,object target);

int perform(object me, object target)
{
	string msg;
	int extra, enhance, lvl, mod, damage, flag;
	int gwxd_dmg;
	object weapon;

	if( me->query("class") != "beggar" && userp(me) ) {
		return notify_fail("『绊字诀』只传授给丐帮弟子！\n");
	}
	lvl = me->query_skill("dagou-stick",1);
	if( lvl < 60 ) {
		return notify_fail("『绊字诀』需要60级的打狗棒法！\n");
	}
	if( me->query_skill_mapped("force") != "huntunforce" ) {
		return notify_fail("『绊字诀』需要混沌心法的配合。\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『绊字诀』只能对战斗中的对手使用。\n");
	}
	if( target->query_temp("is_unconcious") || target->is_busy() || target->query_temp("marks/pfm/dagou_fallen") ) { 
		return notify_fail("对方已经不能动弹了，还不乘机进攻？\n");
	}
	if( me->query("force") < 50 ) {	
		return notify_fail("你的内力不够。\n");
	}
	if( userp(me) ) {
		me->add("force", -50);
	}
	mod = COMBAT_D->can_busy(me, target, "dagou-stick");	
	if( !mod ) {
		return notify_fail(HIW"此人身法灵活，不会被『绊字诀』迷惑的。\n"NOR);
	}
	weapon = me->query_temp("weapon");

	//	extra = 180*2.1 + 150 = 528
	//	enhance == 200 + 45	
	extra = me->query_skill("staff");
	enhance = 200 + me->query_skill("dagou-stick",1)/4;
	if( target->query_temp("annie/beggar/6") == "ban" && target->query_temp("annie/beggar/time")+8 >= time() ) {
		enhance *= 2;
		flag = 1;
		target->delete_temp("busy_timer/dagou-stick");
		mod = COMBAT_D->can_busy(me, target, "dagou-stick");	
		msg = YEL"\n$N手中"+ weapon->name() + YEL"忽然往下一拐，如蜻蜓点水般连续击向$n"YEL"下盘。\n" NOR;
	} else {
		msg = YEL"\n$N"YEL"看准$n"YEL"步法的破绽，手中"+ weapon->name() + YEL"如蜻蜓点水般连续击向$n"YEL"下盘。\n" NOR;
	}
	message_vision(msg, me, target); 
	if( COMBAT_D->do_busy_attack(me, target, "dagou-stick/banzijue", "step", enhance, mod) ) {
		msg = HIG"\n只见"+ weapon->name() + HIG"点在地下，轻轻弹起，$n"HIG"似乎是一步赶来凑上去一样。\n"
			HIR+ weapon->name()+HIR"“啪”的一声，狠狠敲在$n"HIR"胫骨上！"NOR"\n\n"
			WHT"随着长声惨叫，$n扑通一下倒在地上！\n\n"NOR;
		if( me->query("cps") < random(target->query("cps")*3) && !flag ) {
			msg +=CYN"$N看着$n疼得在地上打滚，笑得腰都直不起来，\n上气不接下气地说：“怪不得狗腿需要比人腿多两条！”\n"NOR;
			if( ANNIE_D->check_buff(me, "fastcast") > 0) {
				me->perform_busy(2);
			} else {
				me->perform_busy(3);
			}
		} else {
			if( ANNIE_D->check_buff(me, "fastcast") > 0 ) {
				me->perform_busy(1);
			} else {
				me->perform_busy(2);
			}
		}
		//Beat down enemy
		target->force_busy(3);
		// 	180 + random(180) + My_LEvel -- 320+ random(180);
		damage = F_LEVEL->get_level(me->query("combat_exp")) + lvl + random(lvl);  
		damage = COMBAT_D->magic_modifier(me, target, "kee", damage);
		target->receive_damage("kee", damage, me);
		target->set_temp("busy_timer/dagou-stick", time());
		target->set_temp("marks/pfm/dagou_fallen", 1);
		call_out("get_up",5, me, target);
		message_vision(msg, me, target);
		COMBAT_D->report_status(target);
		COMBAT_D->win_lose_check(me, target, 1);
	} else {
		me->add_temp("apply/attack", lvl);
		me->add_temp("apply/damage", extra/2);
		me->add_temp("marks/pfm_dagou", 1);
		msg = HIR"\n眼见$n迅速变换步法，$N只好招式突换，一棍随手挥出！\n"NOR;
		message_vision(msg, me, target);
		COMBAT_D->do_attack(me, target, TYPE_PERFORM, "");
		me->add_temp("marks/pfm_dagou", -1);
		me->add_temp("apply/attack", -lvl);
		me->add_temp("apply/damage", -extra/2);
		
		if( ANNIE_D->check_buff(me, "fastcast") > 0 ) {
			me->perform_busy(1);
		} else {
			me->perform_busy(2);
		}
	}
	if( ANNIE_D->check_buff(me, "beggardoggie") > 0 ) {
		damage = me->query_busy();
		if( random(100) < F_ABILITY->check_ability(me, "doggie_tail", 1)*2 + 20) {
			// 20% + 20%
			me->stop_busy();
			msg = YEL"$N"+YEL"舔舔嘴唇，只觉得意犹未尽，说道：再来一招！\n"NOR;
			message_vision(msg, me, target);
			gwxd_dmg = F_ABILITY->check_ability(me,"3_gwxd_add",3)*15;
			me->add_temp("apply/damage", gwxd_dmg);
			COMBAT_D->do_attack(me, target, TYPE_PERFORM, "");
			me->add_temp("apply/damage", -gwxd_dmg);
		}
		me->perform_busy(damage);
	}
	return 1;
}

void get_up(object me, object target)
{
	if( !target ) {
		return;
	}
	target->delete_temp("marks/pfm/dagou_fallen");
	if( !living(target) ) {
		return;
	}
	message_vision(YEL "\n\n$N在地上打了几个滚，忍着疼痛狼狈不堪地爬了起来！！\n\n" NOR, target);	
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
