//silencer@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, myexp, enemyexp, lvl;
	int gwxd_dmg;
	object weapon,hisweapon;

	if( me->query("class") != "beggar" && userp(me) ) {
		return notify_fail("『戳字诀』只传授给丐帮弟子！\n");
	}
	lvl = (int)me->query_skill("dagou-stick", 1);
	if( lvl < 20 ) {
		return notify_fail("『戳字诀』需要20级的打狗棒法。\n");
	}
	if( me->query_skill_mapped("force") != "huntunforce" ) {
		return notify_fail("『戳字诀』需要混沌心法的配合。\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『戳字诀』只能对战斗中的对手使用。\n");
	}
	weapon = me->query_temp("weapon");
	msg = YEL"\n$N"NOR+YEL"迎面一棒刺去，似神龙夭矫，又似灵蛇盘舞，
棒身晃动，似是刺向上盘，却又似向$n"NOR+YEL"下三路缠打！\n"NOR;

	if( target->query_temp("annie/beggar/6") == "cuo" && target->query_temp("annie/beggar/time")+8 >= time() ) {
		msg += HIY"重重棒影中忽然飞出一招，正点向$n"HIY"的破绽之中！\n"NOR;
		lvl *= 2;
		target->delete_temp("annie/beggar/time");
	}

	//	atk, 180	marks/pfm_dagou
	message_vision(msg, me, target);
	me->add_temp("apply/attack", lvl);
	me->add_temp("apply/damage", lvl*2);
	me->add_temp("marks/pfm_dagou", 1);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM, "");
	me->add_temp("marks/pfm_dagou", -1);
	me->add_temp("apply/attack", -lvl);
	me->add_temp("apply/damage", -lvl*2);
	
	if( ANNIE_D->check_buff(me, "beggardoggie") > 0 && !me->is_busy() ) {
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
	if( ANNIE_D->check_buff(me, "fastcast") > 0 ) {
		me->perform_busy(1);
	} else {
		me->perform_busy(2);
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
