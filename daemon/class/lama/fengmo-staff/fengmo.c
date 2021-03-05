// Silencer@fengyun4

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	int skill, duration, stage;
	object weapon;
	mapping buff;

	if( me->query("class") != "lama" ) { 
		return notify_fail("只有大昭子弟才能使用『疯魔式』\n");
	}
	skill = me->query_skill("fengmo-staff", 1);		
	if( skill < 180 ) { 	
		return notify_fail("『疯魔式』需要180级的疯魔杖法和阅读卷轴！\n");
	}
	stage = me->query("scroll/fengmo-staff_fengmo");
	if( stage < 1 ) {
		return notify_fail("『疯魔式』只有从卷轴上才能领悟。\n");
	}
	if( me->query_temp("pfm/fengmo_2") || me->query_temp("pfm/fengmo_1") || me->query_temp("pfm/fengmo_3") ) {
		return notify_fail("你已经在使用类似的武功了。\n");
    }
	duration = me->query("timer/pfm/fengmo_3") - time() + 720 - F_ABILITY->check_ability(me, "3_fengmo_add", 3) * 36;
	if( duration > 0 ) {
		return notify_fail("你还需要等待"+(int)(duration/60+1)+"分钟左右才能再次使用『疯魔式』\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me ) { 
		return 	notify_fail("『疯魔式』只能用在自己身上。\n");
	}
	if( me->query("force") < 100 ) {
		return  notify_fail("『疯魔式』需要100点内力。\n");   	
	}
	if( userp(me) ) {
		me->add("force", -100);
	}
	weapon = me->query_temp("weapon");

	buff =
	([
		"caster":me,
		"who":me,
		"type":"pfm/fengmo",
		"att":"bless",
		"name":"疯魔杖法·降龙式",
		"buff1":"pfm/fengmo_3",
		"buff1_c":1,
		"buff2":"buff/berserk_attack",
		"buff2_c":2,
		"time":30,
		"buff_msg":HIR"
$N"HIR"手中"+weapon->name()+HIR"杖头指天，杖尾点地，招式未出，已激起满地黄叶，飞起漫空黄蝶。
正是疯魔杖法的最后一段起手式。。。。"HIR"疯魔！\n\n"NOR,
			"disa_msg":YEL"你一套『降龙式』演化完毕，稳住身形。\n"NOR,
			"special_func":0,
		]);

	ANNIE_D->buffup(buff);
	me->set_temp("buff/berserk_skill", "fengmo-staff");
	me->set_temp("buff/berserk_attack_msg", CYN"$N形似疯虎，杖声呼呼，劈头盖脸又向$n击到！\n"NOR);

	me->set("timer/pfm/fengmo_3", time());
	me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), 30);
	return 1;
}


int remove_effect(object me)
{
	if( !me ) {
		return 0;
	}
	me->delete_temp("buff/berserk_skill");
	me->delete_temp("buff/berserk_attack_msg");
	return 1;
}

