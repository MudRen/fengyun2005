//silencer@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg, temp, temp1;
	int extra, num, num1, lvl;
	int gwxd_dmg;
	int myexp, yourexp, exp_bonus, duration;
	object weapon, shadow, hisweapon, newweapon;
	object *enemy;
	int cond;

	if( me->query("class") != "beggar" && userp(me) ) {
		return notify_fail("『引字诀』只传授给丐帮弟子！\n");
	}
	lvl = (int)me->query_skill("dagou-stick", 1);
	if( lvl < 110 ) {
		return notify_fail("『引字诀』需要110级的打狗棒法！\n");
	}
	if( me->query_skill_mapped("force") != "huntunforce" ) {
		return notify_fail("『引字诀』需要混沌心法的配合。\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『引字诀』只能对战斗中的对手使用。\n");
	}
	weapon = me->query_temp("weapon");
	myexp = me->query("combat_exp");
	yourexp = target->query("combat_exp");
	if( target->query_temp("annie/beggar/6") == "yin" && target->query_temp("annie/beggar/time")+8 >= time() ) {
		num = 4;  // +100%
		msg = YEL"$N"NOR+YEL"微微一笑，手中的棒儿倏然疾翻，忽然变了个花式，却是打狗棒法中的『引字诀』，	
顺势将$n"NOR+YEL"的劲力引向$n。\n" NOR;
		target->delete_temp("annie/beggar/time");
	} else {
		if( target->query("boss") || target->query("big_boss") ) {
			duration = me->query_temp("timer/pfm/gb_yzj") + 30 - time();
			if( duration > 0 ) {
				return notify_fail("你需要过"+ duration + "秒才能对此敌人再次使用引字诀。\n");
			}
		} else {
			duration = me->query_temp("timer/pfm/gb_yzj") + 10 - time();
			if( duration > 0 ) {
				return notify_fail("你需要过"+ duration + "秒才能再次使用引字诀。\n");
			}
		}
		msg = YEL+"\n\n$N"+NOR+YEL"棒法陡变，使出打狗棒法中的『引字诀』，三根手指捉住棒腰，将那棒儿舞
成个圆圈，倏然疾翻，顺势将$n"NOR+YEL"的劲力引向$n。\n" NOR;
		me->set_temp("timer/pfm/gb_yzj", time());
	}
	message_vision(msg, me, target);
	if( (myexp*3/4 + random(myexp)*(4+num) > yourexp || !userp(me)) && !target->query_temp("is_unconcious") ) {
		seteuid(getuid());
		if( !userp(target) ) {
			sscanf(file_name(target), "%s#%d", temp, num);
			shadow = new(temp);
			"/feature/annie"->annie_mimic(target, shadow);
		} else {
			shadow = new("/obj/npc/shadefigure");
			shadow->changeshape(target);
		}
		if( newweapon = shadow->query_temp("weapon") ) {
			// shadow 自己武器不用考虑
			newweapon->unequip();
		}
		if( hisweapon = target->query_temp("weapon") ) {
			// 给shadow 加新武器
			sscanf(file_name(hisweapon), "%s#%d", temp1, num1);
			newweapon = new(temp1);
			newweapon->move(shadow);
			newweapon->wield();
		}
		shadow->set("owner", me);
		shadow->set("possessed", me);
		shadow->move(environment(me));
		shadow->set("kee", target->query("kee"));
		shadow->set("sen", target->query("sen"));
		shadow->set("gin", target->query("gin"));
		shadow->set("eff_kee", target->query("eff_kee"));
		shadow->set("eff_gin", target->query("eff_gin"));
		shadow->set("eff_sen", target->query("eff_sen"));
		shadow->set("max_kee", target->query("max_kee"));
		shadow->set("max_sen", target->query("max_sen"));
		shadow->set("max_gin", target->query("max_gin"));
		shadow->set("name", target->query("name"));
		CHANNEL_D->do_sys_channel("sys", "shadow's exp is "+ shadow->query("combat_exp")+"\n");
		shadow->add_killer(target->query("id"));
		shadow->add_temp("apply/attack", lvl+num*lvl/2);
		shadow->add_temp("apply/damage", lvl*2);
		COMBAT_D->do_attack(shadow, target, msg);
		shadow->add_temp("apply/attack", -lvl-num*lvl/2);
		shadow->add_temp("apply/damage", -lvl*2);
		if( target->query_temp("damaged_during_attack") ) {
			target->set_temp("last_damage_from", me);
			target->dmg_msg("kee",me);
		}
		if( me->is_killing(target->query("id")) ) {
			cond = 1;
		}
		destruct(shadow);
	} else {
		message_vision(WHT"结果被$N将反击的劲力化开了。\n"NOR, target);
	}
	if( cond ) {
		me->add_killer(target->query("id"));
	}
	me->add_enemy(target);
	if( ANNIE_D->check_buff(me, "beggardoggie") > 0 ) {
		if( random(100) < F_ABILITY->check_ability(me,"doggie_tail",1)*2 + 20 ) {
			// 20% + 20%
			msg = YEL"$N"+YEL"舔舔嘴唇，只觉得意犹未尽，说道：再来一招！\n"NOR;
			message_vision(msg, me, target);
			gwxd_dmg = F_ABILITY->check_ability(me,"3_gwxd_add",3)*15;
			me->add_temp("apply/damage", gwxd_dmg);
			COMBAT_D->do_attack(me, target, TYPE_PERFORM, "");
			me->add_temp("apply/damage", -gwxd_dmg);
		}
	}
	me->perform_busy(1);
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
