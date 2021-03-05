
#include <ansi.h>

inherit SSERVER;
int disrupted (object me, object who, string how);

int cast(object me, object target)
{
	string msg;
	int damage, ap, lvl, cost;
	int dam,extradam;
	int flag ,type;

	function f = (: disrupted :);
	if( ANNIE_D->check_buff(me,"manatwist") > 0 ) {
		flag = 3;
	} else {
		flag = 1;
	}
	if( me->query("class") != "taoist" ) {
		return notify_fail("只有三清宫的弟子才能够使用三清道术。\n");
	}
	if( (int)me->query_skill("necromancy",1) < 135 ) {
		return notify_fail("『燃殇绝焰』需要135级的三清道术！\n");
	}
	if( me->query_skill_mapped("force") != "gouyee" ) {
		return notify_fail("三清道术需使用谷衣心法的运转法门。\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("这种法术只能对战斗中的对手使用。\n");
	}
	lvl = me->query_skill("necromancy", 1);
	cost = (20+lvl/2)*flag;
	if( me->query("mana") < cost || me->query("sen") < cost ) {
		return notify_fail("『燃殇绝焰』至少需要"+ cost + "点心神和法力。\n");
	}
	if( userp(me) ) {
		me->add("sen", -cost);
		me->add("mana", -cost);
	}
	msg = BLU "$N"NOR+BLU"口中喃喃地念著咒文，双手握焚灭印，淡蓝色的火焰在手心中轻摇．．．\n" NOR;
	message_vision(msg, me, target);
	type = me->query_temp("last_sqpfm_used");
	me->set_temp("last_sqpfm_used", 1111);
	me->set_temp("marks/pfm/sq_demonic", time());
	me->delete_temp("last_damage_from");
	me->start_busy(3, f);
	call_out("channeled", 6, me, target, flag, type);
	return 1;
}

int disrupted(object me, object who, string how)
{
	if( how == "hit" ) {
		if( ANNIE_D->check_buff(me,"feat") && random(100) < 55) {
			tell_object(me,WHT"你全神贯注未被影响。\n"NOR);
			me->delete_temp("last_damage_from");
			return 0;
		}
		tell_object(me,WHT"你的施咒被打断了。\n"NOR);
		me->delete_temp("marks/pfm/sq_demonic");
		return 1;
	}
	return 0;
}

void channeled(object me, object target, int flag, int type)
{
	string msg;
	int damage, ap, lvl, cost;
	int dam, extradam;
	int i;
	string typ;

	if( !me ) {
		return;
	}
	if( !me->query_temp("marks/pfm/sq_demonic") ) {
		return;
	}
	if( me->query_temp("marks/pfm/sq_demonic") + 5 > time() ) {
		return; // 这是上一个被打中但是没取消的channeled.
	}
	if( !target || !me->is_fighting(target) || environment(target) != environment(me) ) {
		return;
	}
	if( me->query_temp("last_damage_from") ) {
		return;
	}
	me->stop_busy();
	msg = HIB "\n$N"HIB"猛地一旋双手，一道火光在$n"HIB"身上迸裂而出，"NOR; 
	switch( type ) {
		case 2:
			typ = "gin";
			break;
		case 1:
			typ = "sen";
			break;
		case 3:
			typ = "kee";
			break;
		default: 
			typ = "kee";
	}
	lvl=me->query_skill("necromancy", 1);
	me->add_temp("apply/spells", lvl*2);
	if( COMBAT_D->do_magic_attack( me, target, "spells", typ, 0) ) {
		msg +=  HIR "一着衣物，顿时如附骨之蛆，四散延蔓。\n"NOR;
		message_vision(msg, me, target);
		// 900 damage * 2 = 1800 damage fixed.
		ap = me->query_skill("spells");
		damage = 60 + ap*ap/360;
		if( flag == 3 ) {
			damage *= 2;
		}
		// +20% chance double damage.
		if( random(100) < F_ABILITY->check_ability(me,"nether_add",1)*2 ) {
			damage = damage*2;
		}
		damage = COMBAT_D->magic_modifier(me, target, typ, damage*2);
		damage = damage*(100+F_ABILITY->check_ability(me,"3_bolt2_add",3)*2)/100;
		target->receive_damage(typ, damage, me);
		target->set_temp("damaged_during_attack", damage);
		COMBAT_D->report_status(target);
		COMBAT_D->win_lose_check(me,target,damage);
		
	} else {
		msg += YEL"然而旋即熄灭。\n"NOR;
		message_vision(msg, me, target);
	}
	me->add_temp("apply/spells", -lvl*2);
	return ;
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
