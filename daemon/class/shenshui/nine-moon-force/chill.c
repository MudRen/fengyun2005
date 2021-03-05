// 	Silencer@fy4 workgroup
//	100 + random(100) damage shield and parry shield

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me,object target,int amount)
{
	int extra;
	mapping buff;
	string msg;

	if( me->query("class") != "shenshui"&& userp(me) ) {
		return notify_fail("只有神水宫弟子才能使出『九阴凝寒』的绝技。\n");
	}
	if( ANNIE_D->check_buff(me, "damageshield") || me->query_temp("damage_shield") ) {
		return notify_fail("你已经在使用类似的武功了。\n");
	}
	if( me->query_skill("nine-moon-force", 1) < 150 || me->query_skill("nine-moon-spirit", 1) < 135 ) {
		return notify_fail("『九阴凝寒』需要150级九阴心经和135级姹女神功。\n");
	}
	if( me->query("force") < 300 ) {
		return notify_fail("『九阴凝寒』需要300点内力。\n");
	}
	if( userp(me) ) {
		me->add("force", -300);
	}
	// L60 - L140
	extra = F_LEVEL->get_level(me->query("combat_exp"));
	extra=  extra/2;
	extra = COMBAT_D->magic_modifier(me, target, "kee", extra);
	// For claw and sword hit_ob, it's 30-70 extra wound
	// For claw and sword parry_ob, it's 15-35 extra damagee
	// For ob_hit shield, it's 15-35 extra damage.
	if( me->query_skill("qingpingforce",1) < 150 && userp(me) ) {
		msg = BMAG + HIM"$N瞑目屏息，运起九阴心经，一层淡淡的雾气在$N周围一闪即逝。\n"NOR;
		buff = ([
			"caster": me,
			"who": me,
			"type": "damageshield",
			"att": "bless",
			"name": "九阴心经·凝寒诀",
			"buff1": "nine-moon-force_poison",
			"buff1_c": extra,
			"time": 300,
			"buff_msg": msg,
			"disa_msg": MAG"$N周围的紫雾渐渐散去了。\n"NOR,
			"disa_type": 1,
		]);
	} else {
		msg = BMAG + HIM"$N瞑目屏息，运起九阴心经，一层淡淡的雾气弥漫开来，笼罩在$N周围。\n"NOR;	
		buff = ([
			"caster": me,
			"who": me,
			"type": "damageshield",
			"att": "bless",
			"name": "九阴心经·凝寒诀",
			"buff1": "nine-moon-force_poison",
			"buff1_c": extra,
			"time": 300,
			"buff_msg": msg,
			"disa_msg": MAG"$N周围的紫雾渐渐散去了。\n"NOR,
			"disa_type": 1,
			"shield_type": "kee",
			"shield_amount": extra/2,
			"shield_desc": MAG"$n似乎沾上了$N周围的毒雾，手脚开始不灵便起来。\n"NOR,
		]);
	}
	ANNIE_D->buffup(buff);
	return 1;
}