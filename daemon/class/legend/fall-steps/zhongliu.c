// Silencer@fengyun June.2005
// L50： 『中流』Super defense stance

#include <ansi.h>
#include <combat.h>
#define S_TIME 480 // 最多使用8分钟，每次60秒
#define L_TIME 3600 // 一小时复原

inherit SSERVER;
int perform(object me, object target)
{
	string msg, type;
	int duration, extra, add, skill, num, amount;
	mapping buff;
	object weapon;

	extra = me->query_skill("fall-steps",1);
	skill = me->query_skill("six-sense",1);
	if( extra < 150 || skill < 150 || me->query_skill("dormancy",1) < 150 ) {
		return notify_fail("『中流』需要150级的秋风步、六灵暗识、息若纳气！\n");
	}
	if( me->query("class") != "legend" && userp(me) ) {
		return notify_fail("只有铁雪山庄的弟子才能够使用『中流』。\n");
	}
	if( !target ) {
		target = me;
	}
	if( target != me ) {
		return notify_fail("『中流』只能用在自己身上。\n");
	}
	if( ANNIE_D->check_buff(me,"afm-absshield") ) {
		return notify_fail("你已经在使用中流中了。\n");
	}
	// 初始化
	if( me->query("timer/tx-zhongliu") < 1 ) {
		me->set("timer/tx-zhongliu",time());
		me->set("timer/pfm/tx-zhongliu",S_TIME);
	}
	if( me->query("timer/tx-zhongliu") + L_TIME < time() ){
		me->set("timer/tx-zhongliu",time());
		me->set("timer/pfm/tx-zhongliu",S_TIME);
	}
	if( me->query("timer/pfm/tx-zhongliu") < 50 ) {
		duration = L_TIME + me->query("timer/tx-zhongliu") - time();
		return notify_fail("你还要等待"+ (duration/60)+"分钟才能再次使用中流。\n");
	}
	duration = 60;
	me->add("timer/pfm/tx-zhongliu",-60);
	if( weapon = me->query_temp("weapon") ) {
		if( weapon->query("skill_type") == "sword" ) {
			msg = "$N剑法一变，从极快而变为极慢，剑尖上坠了千斤重物似的，慢腾腾的东刺一剑，西\n刺一剑，身畔周围八尺之内，便似布起了一道铁壁铜墙一般。\n";
		} else if( weapon->query("skill_type") == "blade" ) {
			msg = "$N刀法一变，从极快而变为极慢，刀尖上坠了千斤重物似的，慢腾腾的东劈一刀，西\n劈一刀，身畔周围八尺之内，便似布起了一道铁壁铜墙一般。\n";
		}
	}
	if( !msg ) {
		msg = "$N招式瞬息万变，有如大海潮生，一渡末平，一波又起，周围八尺之内，便似布起了一道铁壁铜墙一般。\n";
	}
	add = me->query("timer/pfm/tx-zhongliu")/60;
	amount = 200 - F_ABILITY->check_ability(me,"3_zhongliu_add",3)*20;
	buff =
		([
			"caster": me,
			"who": me,
			"type": "afm-absshield",
			"type2": "tx-turtle-stance",
			"att": "bless",
			"name": "秋风步·中流",
			"buff1": "resistance/kee",
			"buff1_c": 50,
			"buff2": "apply/attack",
			"buff2_c": -amount,
			"shield_type": "force",
			"shield_amount": 50,
			"shield_msg": "",
			"time": 60,
			"buff_msg": BRED + HIY +msg+NOR,
		]);
	ANNIE_D->buffup(buff);
	write(WHT"（在接下来的"+ ((me->query("timer/tx-zhongliu") + L_TIME - time())/60) + "分钟里你还能使用"+ add + "次中流）\n"NOR); 
	return 1;
}
