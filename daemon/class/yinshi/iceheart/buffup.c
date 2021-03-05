// Silencer @ FY4 workgroup. Aug.2004

inherit SSERVER;
#include <ansi.h>

int exert(object me, object target, int amount)
{
	int stage, force, lvl, duration, ability;
	object obj, *mem, target2;
	int extra_amount;
	string msg;
	mapping buff;

	if( me->query("class") != "yinshi" ) {
		return notify_fail("『寒心诀』是帝王谷的不传之谜。\n");
	}
	lvl = me->query_skill("iceheart",1);
	if( lvl < 50 || me->query_skill("celecurse",1) < 50 ) {
		return notify_fail("『寒心诀』需要50级的冰心诀和通天降。\n");
	}
	if( me->is_fighting() ) {
		return notify_fail("战斗中无法使用『寒心诀』\n");
	}
	if( !objectp(obj = present(target, environment(me))) ) {
		return notify_fail("这里没有这个人。\n");
	}
	if( !obj->is_character() || obj->is_corpse() ) {
		return notify_fail("看清楚一点，那并不是活物。\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me) {
		target2 = target;
		if( objectp(target->query("possessed")) ) { // Spirit
			if( !userp(target->query("possessed")) ) {
				return notify_fail("『寒心诀』只能用于队友。\n");
			} else {
				target2 = target->query("possessed");
			}
		}
		mem = me->query_team();
		if( (!pointerp(mem) || member_array(target2,mem) == -1 ) && target2 != me ) {
			return notify_fail("『寒心诀』只能用于队友。\n");
		}
	}
	
	if( ANNIE_D->check_buff(target, "gks") ) {
		return notify_fail("此人已经在使用类似的心法了。\n");
	}
	if( me->query("force") < 400 ) {
		return notify_fail("『寒心诀』至少需要400点真气。\n");
	}
	if( userp(me) ) {
		me->add("force", -400);
	}
	// SCROLL ADVANCE PERFORM, 
	stage = me->query("scroll/celecurse_buffup") > 0 ? me->query("scroll/celecurse_buffup") : 1;
	if( stage >= 4 && me->query_skill("celecurse", 1) >= 200 && lvl >= 150) {
		amount = 2500;
	} else if( stage >= 3 && lvl >= 150) {
		amount = 1500;
	} else if( stage >= 2 && lvl >= 110 ) {
		amount = 900;
	} else {
		amount = 300;
	}

	// 1-10, add 5%-50%
	ability = F_ABILITY->check_ability(me,"buffup_add",2);
	amount = amount * (100 + ability*5)/100;
	duration = 600;
	if( target == me ) {
		extra_amount = F_ABILITY->check_ability(me,"3_buffup_add",3)*100;
		msg = HIW"$N呼翕参阳，抱一含元，深深吸了口气，运起冰心诀中『寒心诀』。\n"NOR;
	} else {
		extra_amount = F_ABILITY->check_ability(me,"3_buffup_add",3)*50;
		msg =  HIW"$n呼翕参阳，抱一含元，深深吸了口气，运起冰心诀中『寒心诀』，\n"NOR;
		msg += WHT"$n两掌抵在$N背心，内力源源不绝地从掌心传出．．．\n"NOR;
	}
	buff =
		([
			"caster": me,
			"who":  target,
			"type": "kee",
			"att":	"bless",
			"name":	"冰心诀·寒心诀",
			"buff1":"gin",
			"buff1_c":extra_amount,
			"buff2":"kee",
			"buff2_c":amount+extra_amount,
			"buff3":"sen",
			"buff3_c":extra_amount,
			"time":  900 ,
			"buff_msg": msg,
			"special_func":1,
		]);
		
	ANNIE_D->buffup(buff);
	me->perform_busy(1);
	return 1;
}