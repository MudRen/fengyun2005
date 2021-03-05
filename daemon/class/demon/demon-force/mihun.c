#include <ansi.h>
inherit SSERVER;

int exert(object me, object target, int amount)
{
	object *ob;
	int i, skill, damage;

	if (userp(me) && me->query_skill("demon-force",1)<100)
		return notify_fail("『迷魂大法』需要100级天地人魔心法。\n");
		
	if( !me->is_fighting() )
		return notify_fail("『迷魂大法』只能在战斗中使用。\n");

	if( (int)me->query("force") < 50 )
		return notify_fail("『迷魂大法』至少需要50点的内力。\n");

	if( !target || target==me ) {
		target = offensive_target(me);
		if( !target) return notify_fail("你要对谁施展『迷魂大法』？\n");
	}

	if (target->is_busy())
		return notify_fail("对方已经魂不附体了。\n");
		
	skill = me->query_skill("force");
	if (userp(me))	me->add("force", -50);

	message_vision(	HIB "\n$N面上神情诡异，双眼变得异常朦胧！\n" NOR, me, target);
	
	if( random(skill) < (int)target->query("cps") * 2 ){
		message_vision("$N很快地转过头去，避开了$n的目光。\n", target, me);
		me->perform_busy(2);
		return 1;
	}

	damage = (int)me->query("force_factor");
	target->receive_damage("gin", damage, me);
	message_vision(HIM"$N被$n的诡异神情所惑，不自禁地慢了下来。\n"NOR, target, me);
	target->force_busy(3);
	me->perform_busy(1);
	return 1;
}

