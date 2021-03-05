// Silencer@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int stone_done(object me, object caster);

int perform(object me, object target)
{
	int skill, timer, duration;
	int chance, num, time;
	mapping buff;

	if( me->query("class") != "fugui" ) {
		return notify_fail("只有富贵山庄弟子才能使出「二串炮」的绝技。\n");
	}
	skill = me->query_skill("henglian", 1);
	if( skill < 180 ) {
		return notify_fail("二串炮需要180级的横练功！\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me ) {
		return notify_fail("你只能将二串炮用在自己的身上。\n");
	}
	timer = 600;		
	duration = me->query("timer/pfm/hl_erchuan") + timer-time() - F_ABILITY->check_ability(me,"erchuan_add")*45;
	if( duration > 0 ) {
		return notify_fail("你真气已散，一时无法再次使用二串炮神功（需"+duration+"秒）。\n");
	}
	if( me->query_skill_mapped("force") != "skyforce" ) {
		return notify_fail("二串炮唯有使用碧空心法才有效。\n");
	}

	chance = F_ABILITY->check_ability(me, "3_erchuan_add", 3) * 10;
	if( random(100) < chance ) {
		num = 6;
		time = 60;
	} else {
		num = 3;
		time = 30;		
	}
	me->set_temp("pfm/fg_erchuan", num);
	me->set("timer/pfm/hl_erchuan", time());
	buff =
		([
			"caster": me,
			"who": me,
			"type": "stoneskin",
			"att": "bless",
			"name": "横练·二串炮",
			"time": time,	
			"buff_msg": YEL"$N全身每一个骨节忽然全都轰天般响起，隐隐有风雷之声！！\n"NOR,
			"warn_msg": WHT"你的横练·二串炮很快就要失效了。\n"NOR,
			"finish_function": (: stone_done :),
		]);
	ANNIE_D->buffup(buff);
	return 1;
}

int stone_done(object me, object caster)
{
	me->delete_temp("pfm/fg_erchuan");
	return 1;
}