// astral_vision.c 

#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
	mapping buff, *mem;
	if( me->query("class") != "taoist" ) {
		return notify_fail("只有三清宫的弟子才能够使用三清道术。\n");
	}
	if( (int)me->query_skill("necromancy",1) < 10 ) {
		return notify_fail("『阴阳眼』需要10级的三清道术！\n");
	}
	if( !target ) {
		target = me;
	} else {
		mem = me->query_team();
		if( !pointerp(mem) || member_array(target,mem) == -1 ) {
			return notify_fail("你只能给同一队伍中的人施展阴阳眼。\n");
		}
	}
	if( ANNIE_D->check_buff(target, "astral_vision") ) {
		return notify_fail("此人已经施展过阴阳眼的法术了。\n");
	}
	if( (int)me->query("mana") < 30 || me->query("sen") < 5 ) {
		return notify_fail("需要30点法力和5点心神。\n");
	}
	if( userp(me) ) {
		me->add("mana", -30);
		me->receive_damage("sen", 5);
	}
	buff =
		([
			"caster":me,
			"who": target,
			"type":"astral_vision",
			"att":"bless",
			"name":"三清道术·阴阳眼",
			"buff1":"apply/astral_vision",
			"buff1_c":1,
			"time":  900,
			"buff_msg":BBLU + HIB "$N微一凝神，施展「阴阳眼」法术，闭著眼睛念了几句咒语。\n" NOR,
		]);
	ANNIE_D->buffup(buff);
	return 1;
}
