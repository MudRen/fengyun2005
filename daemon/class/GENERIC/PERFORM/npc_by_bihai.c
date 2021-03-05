// 琴 思路 by Sinny/Silencer@fy4.
// 清心普善曲： 
// 十面埋伏曲：
// 百鸟朝凤曲： 
// 碧海潮生曲:  
// 潇湘水云曲：
// 广陵散
#include <combat.h>
#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	object weapon, *inv, *instr;
	int skill, your_exp, my_exp, damage;
	
    	if(userp(me))
		return notify_fail("你所选用的武功中没有这种必杀技。。\n");
		
	inv = all_inventory(me);
	instr = filter_array(inv,(: $1->query("timbre") :));
	if (!instr || !sizeof(instr)) 
		return notify_fail("你身上没有携带乐器。\n");
	else 
		weapon = instr[0];
			
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『碧海潮生曲』只能对战斗中的对手使用。\n");
        
      	skill = me->query_skill("music",1);	
      
	message_vision(HIG"
$N暗运内力，手抚琴弦，琴声拟大海浩淼，万里无波，远处潮水缓缓推近，
渐近渐快，其后洪涛汹涌，白浪连山，而潮水中鱼跃鲸浮，海面上风啸鸥飞，水
妖海怪，群魔弄潮，忽而冰山飘至，忽而热海如沸，极尽变幻之能事。\n\n"NOR,me);
	me->start_busy(2);	

	my_exp = me->query("combat_exp");
	your_exp = target->query("combat_exp");
	damage = weapon->query("timbre") + me->query_skill("magic");
	damage = damage *2 + random(damage*2);
	// 500*2 + random(500*2)
	if ( my_exp/2 + random(my_exp)*3 > your_exp ) {
		message_vision(MAG"
$N听得片刻，心旌摇动，只感胸口怦怦而动，极不舒畅。再听少时，一颗
心几乎要跳出腔子来，却是无形中已受了内伤。\n"NOR,target);
		target->receive_damage("sen",damage, me);
		COMBAT_D->win_lose_check(me,target,1);
		COMBAT_D->report_status(target);
	}
 	else {
 		msg = WHT"$N面露微笑，凝守心神，不为乐声所动。\n"NOR;
		message_vision(msg,target);
	}
	return 1;
 		
}
