//mimicat@fy4

#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{	
	int lvl, cost, damage;

	if( me->query("class") != "lama" ) {
		return notify_fail("只有大昭寺的弟子才能使用观音六字明咒。\n");
	}
	lvl = me->query_skill("kwan-yin-spells", 1);
	if( lvl < 120 ) { 
		return notify_fail("『唵』需要120级的观音六字明咒。\n");
	}
	if( me == target ) {
		return notify_fail("『唵』不能用在自己身上。\n");
	}
	if( !target ) {
		target = offensive_target(me);
	}
	if( !target || !target->is_character() || !me->is_fighting(target) ) {
		return notify_fail("这种真言只能对战斗中的对手使用。\n");
	}

	cost = 50 + (lvl/10)*10;
	if( me->query("mana") < cost ) {
		return notify_fail("需要" + cost + "点法力。\n");
	}
	if( userp(me) ) {
		me->add("mana", -cost);
	}
	message_vision(HIR "\n$N"HIR"身、口、意与佛成为一体，面色庄重，沉声念道『唵』！ \n"NOR, me, target );
	if( COMBAT_D->do_magic_attack(me, target, "spells", "sen", 300) ) {
		message_vision(RED"$n"NOR+RED"只觉得心头好象被重锤一击，灵魂似乎要离窍而去。 \n\n"NOR,me,target);
		//	500 + random(500) = 500 + random (500) = avg 750
		//  *30% -- 975 avg
		// 3an = 1500 -3000 damage with 6 turn self-busy
		// 2an = 1000- 2000 damage with 4 turn self-busy
		damage = me->query_skill("spells") + random(me->query_skill("spells"));
		damage = damage * (100 + F_ABILITY->check_ability(me, "an_add") * 3) /100;
		if( !me->query("possessed") ) {
			if( random(100) < F_ABILITY->check_ability(me, "3_an_add", 3)*2 ) {
				damage = damage*2;
			}
		}
		damage = COMBAT_D->magic_modifier(me, target, "sen", damage);
		target->receive_damage("sen", damage ,me);
		target->receive_wound("sen", random(damage), me);
		COMBAT_D->report_status(target);
		COMBAT_D->win_lose_check(me,target,1);
	} else {
		message_vision(WHT"$n"NOR+WHT"只觉得心头一紧，急忙凝气护心。 \n"NOR,me,target);
	}
	me->start_busy(3);
	return 1;
}