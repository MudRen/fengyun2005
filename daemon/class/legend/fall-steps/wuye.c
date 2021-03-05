// Silencer@fengyun	June.2005
// L100：『舞叶』持续3分钟，armor 50-150, 定力增加５－１０－１５，气血增加 (dormancy -150)*10

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg, type;
	int extra, add, skill, cps, armor, kee, amount, duration;
	mapping buff, buff2;
	
	extra = me->query_skill("fall-steps", 1);
	skill = me->query_skill("dormancy", 1);
	if( extra < 150 ) {
		return notify_fail("『舞叶』需要150级的秋风步！\n");
	}
	if( me->query("class") != "legend" && userp(me) ) {
		return notify_fail("只有铁雪山庄的弟子才能够使用『舞叶』。\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me ) {
		return notify_fail("『舞叶』只能用在自己身上。\n");
	}
	if( ANNIE_D->check_buff(me,"tx-df-stance") > 0 ) {
		return notify_fail("你已经在使用『舞叶』了。\n");
	}
	duration = me->query_temp("timer/tx-stance") + 30 - time();
	if( duration > 0 ) {
		return notify_fail("铁雪步法每30秒钟最多转换一次（"+duration+"）\n");
	}
	if( ANNIE_D->check_buff(me,"cpsup") ) {
		return notify_fail("你已经在用提高定力的特技了。\n");
	}
	if( ANNIE_D->check_buff(me, "tx-atk-stance") > 0 ) {
		ANNIE_D->debuff(me,"tx-atk-stance");
	}
	me->set_temp("timer/tx-stance",time());
	armor = 50;
	cps = 5;
	if( extra >= 150 ) {
		if( skill >= 300 ) {
			armor = 120;
			cps = 15;
			amount = 2000;
		} else if( skill >= 250 ) {
			armor = 120;
			cps = 15;
			amount = 1500;
		} else if( skill >= 200 ) {
			armor = 80;
			cps = 10;
			amount = 1000;
		} else if( skill >= 150 ) {
			amount = 500;
		}
	}
	armor += F_ABILITY->check_ability(me,"3_wuye_add",3)*5;
	buff =
		([
			"caster":	me,
			"who": 		me,
			"type":		"tx-df-stance",
			"type2":	"cpsup",
			"att":		"bless",
			"name":		"秋风步·舞叶",
			"buff1": 	"apply/armor",
			"buff1_c":	armor,
			"buff2":	"apply/composure",
			"buff2_c":	cps,
			"time":  	600,
			"buff_msg":	YEL"满地秋叶忽然飞起，如风般旋转上升护住$N周身。\n"NOR,
		]);
	ANNIE_D->buffup(buff);
	// 2000 + 1500
	amount = amount + F_ABILITY->check_ability(me,"wuye_add",2)*150;
	if( amount <= 100 ) {
		return 1;
	}
	buff2 =
		([
			"caster":	me,
			"who": 		me,
			"type":		"kee1",		// Cumulative with DWG's buffup gks
			"att":		"bless",
			"name":		"秋风步·舞叶·气",
			"buff1": 	"kee",
			"buff1_c":	amount,
			"time":  	600,
			"buff_msg":	"",
			"disa_msg":	" ",
			"warn_msg":	" ",
			"special_func":	1,
		]);
	ANNIE_D->buffup(buff2);
	return 1;
}