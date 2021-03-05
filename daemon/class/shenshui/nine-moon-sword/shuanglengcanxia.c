// neon@fengyun  「霜冷残霞」

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, bonus, attack_bonus, damage;
	object weapon;

	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("『霜冷残霞』只能对战斗中的对手使用。\n");
	}
		
	weapon = me->query_temp("weapon");
	bonus = me->query_skill("nine-moon-sword",1) + F_LEVEL->get_level(me->query("combat_exp"));
	extra = me->query_skill("sword");

	msg = WHT"$N"NOR+WHT"手中"+weapon->name()+WHT"贴身斜指向上，纤腰一摆，"+weapon->name()+WHT"从鬓侧斜挥而出，闪动的剑光如凝地的清霜。 \n"NOR;
	me->add_temp("apply/attack", bonus);	
	me->add_temp("apply/damage", extra);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM, msg);
	me->add_temp("apply/attack", -bonus);
	me->add_temp("apply/damage", -extra);
	
	if( random(100) < F_ABILITY->check_ability(me,"3_slcx_add",3)*3 ) {
		msg = RED"$N"NOR+RED"手中"+weapon->name()+RED"剑气回转，锋芒暴长，"+weapon->name()+RED"映出红影一片，层层向外涌出，好似漫天的的残霞。 \n"NOR;
		me->add_temp("apply/attack", bonus);	
		me->add_temp("apply/damage", extra);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM, msg);
		me->add_temp("apply/attack", -bonus);
		me->add_temp("apply/damage", -extra);
	}

	if( target->query_temp("damaged_during_attack") && random(me->query_skill("nine-moon-force",1)/90) ) {
		msg = MAG"\n在森森剑影间玫瑰色的薄雾冉冉升起，说不尽的凄迷幽艳，$n"NOR+MAG"忽感天旋地转，摇摇欲坠。\n"NOR ;
		damage = COMBAT_D->magic_modifier(me, target, "sen", random(extra)/2);
		target->receive_damage("sen", damage, me);
    	target->set_temp("marks/pfm/polu_chance", time());
    	message_vision(msg, me, target);
	}

	me->perform_busy(2);
	return 1;
}
