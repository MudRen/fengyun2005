// 『心有千结』（xinyouqianjie）：An attack that do 1/2 damage to self 

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,i,bonus,count,amount;
	int num, damage;
	object weapon, *enemy;
	
	extra = me->query_skill("tanzhi-shentong",1);
	if(extra < 160 || me->query_skill("cloud-dance",1)<200)
		return notify_fail("『心有千结』至少需要160级的弹指神通和200级的幻风飘云舞！\n");
	
	if( !target ) target = offensive_target(me);
	if(!objectp(target) || !target->is_character() || !me->is_fighting(target)) {
		return notify_fail("『心有千结』只能对战斗中的对手使用。\n");
	}
	
	weapon = me->query_temp("weapon");
	count = weapon->query_amount();
	if (count < 12)
		return notify_fail("『心有千结』至少需要12枚暗器。\n");
		
	enemy=me->query_enemy();
	if(!sizeof(enemy))
		return notify_fail("『心有千结』只能对战斗中的对手使用。\n");

	msg = RED"
$N"RED"面色惨白、低声吟道：高山峨峨，河水泱泱，我心千结，与君同殇。"HIG"

$N飞身一掠，双袖连扬，手腕上翻，猛地抖手打去，十二枚"+ weapon->name()+ NOR+HIG"
连翩飞出，有如流星乱舞，惊雹骤落。

"NOR+YEL"$n身形展开，俨如燕子掠波，蜻蜓点水，"HIG"

那十二枚"+ weapon->name()+ NOR+HIG"却忽然竟在空中转折回朔，三枚向左，
三枚向右，另有六枚掉转了头，将$n上下的去路封死。"NOR+WHT"

陡然间，但见银光一闪，已到面前，却是$N以真气击出的指镖！\n"NOR;

	if (userp(me))	weapon->set_amount(count-1);
	message_vision(msg, me, target);
	
	me->add_temp("apply/attack", extra*3);
	me->add_temp("apply/damage", extra*3);
	target->add_temp("buff/no_abs",1);
	
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");		
	
	me->add_temp("apply/attack",-extra*3);
	me->add_temp("apply/damage", -extra*3);
	if (target) {
		target->add_temp("buff/no_abs",-1);
		if (!target->query_temp("buff/no_abs"))
			target->delete_temp("buff/no_abs");
	}
	
	if (target->query_temp("damaged_during_attack")){
		// 160*3 = 480	// Roughly 1/2 damage at least
		message_vision(RED"\n$N面色更显苍白，抚胸又咳出一口鲜血。\n"NOR, me);
		amount = extra*3* (100 - F_ABILITY->check_ability(me,"xyqj_add")*3)/100;
		amount = COMBAT_D->magic_modifier(me, target, "sen", amount);
		me->receive_damage("kee",amount,target);
		COMBAT_D->report_status(me);
	}
	
	me->perform_busy(2);
	return 1;
}


