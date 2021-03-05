// Silencer@fengyun4

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	int skill, duration;
	object weapon;
	mapping buff;

	if( me->query("class") != "lama" ) {
		return notify_fail("只有大昭子弟才能使用『降龙式』\n");
	}
	skill = me->query_skill("fengmo-staff", 1);		
	if( skill < 120 ) {
		return notify_fail("『降龙式』需要120级的疯魔杖法！\n");
	}
	if( me->query_temp("pfm/fengmo_2") || me->query_temp("pfm/fengmo_1") || me->query_temp("pfm/fengmo_3") ) {
		return notify_fail("你已经在使用类似的武功了。\n");
	}    
	duration = me->query("timer/pfm/fengmo_2") - time() + 480 - F_ABILITY->check_ability(me, "xianglong_add") * 24;
	if( duration > 0 ) {
		return notify_fail("你还需要等待"+duration+"秒钟左右才能再次使用『降龙式』\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me ) {
		return 	notify_fail("『降龙式』只能用在自己身上。\n");
	}     
	if( me->query("force") < 100 ) {
		return  notify_fail("『降龙式』需要100点内力。\n");   	
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
		"buff1":"pfm/fengmo_2",
		"buff1_c":1,
		"buff2":"buff/berserk_attack",
		"buff2_c":1,
		"time":40,
		"buff_msg":HIY"
$N"HIY"一声暴喝，手中"+weapon->name()+HIY"一阵乱舞，竟似毫无章理，挥舞出数道杖影，
气势澎湃，力不可挡。跌出七八步，忽又冲出三五步，正是疯魔杖法的
第二段起手式。。。。"HIR"降龙！\n\n"NOR,
		"disa_msg":YEL"你一套『降龙式』演化完毕，稳住身形。\n"NOR,
		"special_func":0,
	]);
	ANNIE_D->buffup(buff);
    
	me->set_temp("buff/berserk_skill", "fengmo-staff");
	me->set_temp("buff/berserk_attack_msg", CYN"$N形似疯虎，杖声呼呼，劈头盖脸又向$n击到！\n"NOR);		
	me->set("timer/pfm/fengmo_2", time());
	me->start_call_out((: call_other, __FILE__, "remove_effect", me :), 40);
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

