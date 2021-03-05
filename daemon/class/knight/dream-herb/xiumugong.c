// Silencer@fengyun


#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	int skill, resist, resist_gin_sen;
	mapping buff;
	string buff_msg;

	if( me->query("class") != "knight" ) {
		return notify_fail("只有快活林弟子才能使用朽木功。\n");
	}
	skill = me->query_skill("dream-herb", 1);
	if( skill < 100 ) {
		return notify_fail("朽木功至少需要100级的云梦五花锦！\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me ) {
		return notify_fail("朽木功只能用在自己身上。\n");
	}
	if( ANNIE_D->check_buff(me,"resistup") ) {
		return notify_fail("你已经在使用类似的武功了。\n");
	}
	switch( skill/50 ) {
		case 2:
			resist = 5;
			buff_msg = YEL"$N"NOR+YEL"双目紧闭，长吸一口气，又缓缓地吐了出来。\n"NOR;
			break;
		case 3:
			resist = 10;
			buff_msg = YEL"$N"NOR+YEL"反掌击在自己百汇穴上，气血逆转，身如朽木。\n"NOR;
			break;
		default:
			resist = 15;
			buff_msg = YEL"$N"NOR+YEL"功随意发，脸色忽变，左青右白，瞬息数次。\n"NOR;
			break;
	}
	resist += F_ABILITY->check_ability(me, "3_xiumu_add", 3);
	resist_gin_sen = F_ABILITY->check_ability(me, "resist_gin");
	buff =
	([
		"caster":me,
		"who": me,
		"type":"resistup",
		"att":"bless",
		"name":"云梦五花锦·朽木功",
		"buff1": "resistance/kee",
		"buff1_c":resist,
		"buff2": "resistance/gin",
		"buff2_c":resist_gin_sen,
		"buff3": "resistance/sen",
		"buff3_c":resist_gin_sen,
		"time": 900,
		"buff_msg":buff_msg,
	]);
	ANNIE_D->buffup(buff);
	if( userp(me) && skill < 200 ) {
		me->perform_busy(1);
	}
	return 1;
}