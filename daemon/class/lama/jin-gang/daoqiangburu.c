/*jin-gang 200x1.5 + 200x0.5 = 400, 
200/2 + 300 /2 + 100 = 350*/

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	int skill, duration,stage, rate;
	string msg;
	mapping buff;

	target = me;
	if( me->query("class") != "lama" ) {
		return notify_fail("只有大昭寺的弟子才能使用『刀枪不入』。\n");
	}
	skill = me->query_skill("jin-gang", 1);
	if( skill < 150 ) {
		return notify_fail("『刀枪不入』需要150级金刚不坏功！\n");
	}
	if( ANNIE_D->check_buff(me, "damageshield") || me->query_temp("damage_shield") ) {
		return notify_fail("你已经在使用类似的武功了。\n");
	}
	if( me->query("force") < 200 ) {
		return notify_fail("『刀枪不入』需要200点内力。\n");
	}
	if( userp(me) ) {
		me->add("force", -200);
	}
	msg = HIR"$N拍了拍胸脯，高叫着：“刀枪不入！刀枪不入！刀枪不入！．．．”\n"NOR;

	// SCROLL ADVANCE PERFORM, 
/*
	stage = me->query("scroll/jin-gang_daoqiangburu");
	switch( stage ) {
		case 0:
		case 1:
			rate = 50;
			break;
		case 2:
			rate = 60;
			break;
		case 3:
			rate = 70;
			break;
	 }
*/

	buff = ([
		"caster": me,
		"who": me,
		"type": "damageshield",
		"att": "bless",
		"name": "金刚不坏·刀枪不入",
		"buff1": "resistance/kee",
		"buff1_c": 20,
		"buffup_name": "backfire",
		"buffup_type": "kee",
		"buffup_ratio": 10,
		"buffup_msg": "", //WHT"$n"NOR WHT"受到$N"NOR WHT"金刚不坏功反震，气血翻涌。\n"NOR,
		"time": 900,
		"buff_msg": msg,
	]);
	ANNIE_D->buffup(buff);
	return 1;
}