#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int disrupted (object me, object who, string how);
void channeled(object me,object target,int lvl, int flag);

int perform(object me, object target)
{
	string msg;
	int lvl;
	function f = (: disrupted :);

	if( me->query("class") != "beggar" && userp(me) ) {
		return notify_fail("『震惊百里』是丐帮弟子不传之秘。\n");
	}
	lvl = me->query_skill("dragonstrike",1);
	if( lvl < 100 ) {
		return notify_fail("『震惊百里』需100级的降龙十八掌。\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『震惊百里』只能对战斗中的对手使用。\n");
	}
	if( me->query_skill_mapped("force") != "huntunforce" && userp(me) ) {
		return notify_fail("『震惊百里』需要混沌心法的配合。\n");
	}
	if( target->query_temp("annie/beggar/6") == "zjbl" && target->query_temp("annie/beggar/time")+8 >= time() ) {
		msg = HIY"
$N"HIY"看准$n"HIY"空隙，大喝一声打出一掌，只听得滚雷之声骤然而起，
$N"HIY"须发尽赤，浑身无俦真气竟皆含在这一掌中攻去！\n\n" NOR;
		message_vision(msg, me, target);
		me->delete_temp("last_damage_from");
		target->delete_temp("annie/beggar/time");
		me->set_temp("marks/pfm/gb_zjbl", time()-6);
		channeled(me, target, lvl, 1);
		return 1;
	} else {
		msg = HIY"
$N"HIY"看准$n"HIY"空隙，慢慢地一掌打出，只听得滚雷之声骤然而起，
$N"HIY"须发尽赤，浑身无俦真气竟皆含在这一掌中攻去！\n\n" NOR;
		message_vision(msg, me, target);
		me->delete_temp("last_damage_from");
		me->set_temp("marks/pfm/gb_zjbl", time());
		me->start_busy(4,f);
		call_out("channeled", 6, me, target, lvl, 0);
		return 1;
	}
}

int disrupted(object me, object who, string how)
{
	if( how == "hit" ) {
		if( F_ABILITY->check_ability(me, "3_zjbl_brk", 3)*5 > random(100) ) {
			tell_object(me,WHT"你的体内真气澎湃，硬受一击。\n"NOR);
			me->set_temp("marks/zjbl_pass",1);
			return 0;
		}
		tell_object(me, WHT"你的真气被打乱了，使不出震惊百里。\n"NOR);
		me->delete_temp("marks/pfm/gb_zjbl");
		me->delete_temp("marks/zjbl_pass");
		return 1;
	}
	return 0;
}

void channeled(object me, object target, int lvl, int flag)
{
	string msg;
	int level, extra_hate, kee1, amount, scroll, pass;
	object weapon;

	//	CHANNEL_D->do_sys_channel("sys","in channeled.");
	if( !me ) {
		return;
	}
	if( me->query_temp("marks/zjbl_pass") ) {
		pass = 1;
	}
	me->delete_temp("marks/zjbl_pass");
	if( !me->query_temp("marks/pfm/gb_zjbl") ) {
		return;
	}
	if( me->query_temp("marks/pfm/gb_zjbl")+5 > time() ) {
		return; // 这是上一个被打中但是没取消的zjbl.	
	}
	if( !target || !me->is_fighting(target) || environment(target) != environment(me) ) {
		return;
	}
	if( me->query_temp("is_unconcious") ) {
		return;
	}
	if( me->query_temp("last_damage_from") && !pass ) {
		return;
	}
	me->stop_busy();
	weapon = me->query_temp("weapon");
	if( weapon && weapon->query("skill_type") != "unarmed" ) {	
		tell_object(me, WHT"你使用的武功不对，无法发出震惊百里。\n"NOR);
		return;
	}
	if( me->query_skill_mapped("unarmed")!= "dragonstrike" ) {
		tell_object(me, WHT"你使用的武功不对，无法发出震惊百里。\n"NOR);
		return;
	}
	level = me->query_skill("begging", 1);
	scroll = me->query("scroll/begging_baili");
	if( level >= 200 && scroll >= 4 ) {
		amount = 1800;
	} else if( level >= 170 && scroll >= 3 ) {
		amount = 1500;
	} else if( level >= 140 && scroll >= 2 ) {
		amount = 900;
	} else {
		amount = 500;
	}
//	write("lvl="+level+" scroll="+scroll+" amount="+amount+"\n");
	if( !userp(me) ) {
		if( me->query("combat_exp") >= 6000000) {
			amount = 1800;
		} else if( me->query("combat_exp") >= 4500000 ) {
			amount = 1500;
		} else if( me->query("combat_exp") >= 3500000) {
			amount = 900;
		} else {
			amount = 500;
		}
	}
//	write ("amount = " + amount + "\n");
	amount = amount * (100 + F_ABILITY->check_ability(me,"3_zjbl_dmg",3)*3)/100;
//	write ("amount = " + amount + "\n");
	msg = HIY"$N将要触到$n身子，突施劲力，－－－－－－－－－"BOLD"震　惊　百　里！\n"NOR;		
	kee1 = target->query("kee");
	me->add_temp("apply/attack", lvl);
	me->add_temp("apply/damage", amount);
	target->add_temp("cant_dodge", 1);
	me->add_temp("marks/full_hit_damage", 1);
	message_vision(msg, me, target);
	COMBAT_D->do_attack(me, target, TYPE_PERFORM, "");
	me->add_temp("marks/full_hit_damage", -1);
	target->add_temp("cant_dodge", -1);
	me->add_temp("apply/damage", -amount);
	me->add_temp("apply/attack", -lvl);
	if( flag ) {
		me->perform_busy(flag);
	}
	return ;
}

