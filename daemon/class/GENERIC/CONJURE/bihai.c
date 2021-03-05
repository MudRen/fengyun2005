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

int conjure(object me, object target)
{
	string msg;
	object * stuff;
	int skill, your_exp, my_exp, damage, qin, i;
	
	if (me->is_ghost())
		return notify_fail("你尚是鬼魂，还是想法先回阳间吧。\n");
	
	stuff = all_inventory(me);
	qin=0;
	for (i=0;i<sizeof(stuff) ;i++){
		if(qin < stuff[i]->query("timbre")){
		   qin = stuff[i]->query("timbre");
		}
	}  
	if(!qin && userp(me)) return notify_fail("你好像忘记带琴了。\n");
	
	skill = me->query_skill("music",1);	
	if (!skill)
		return notify_fail("你于音律一窍不通，瞎拨了几下，顿觉索然无味。\n");
		if (me->query("annie/music_choose") != 3 && userp(me))
		return notify_fail("这曲子你似乎没学会诶。\n");

	if (skill < 150)
		return notify_fail("你发现此谱过于高深，至少需要150级的琴道才能演奏。\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『碧海潮生曲』只能对战斗中的对手使用。\n");
        
	if( me->query("atman") < 200 )
		return notify_fail("『碧海潮生曲』需要200点灵力。\n");
	if (userp(me)) me->add("atman",-200);
		        
	message_vision(HIB"
$N暗运内力，手抚琴弦，琴声拟大海浩淼，万里无波，远处潮水缓缓推近，渐
近渐快，其后洪涛汹涌，白浪连山，而潮水中鱼跃鲸浮，海面上风啸鸥飞，水
妖海怪，群魔弄潮，忽而冰山飘至，忽而热海如沸，极尽变幻之能事。\n\n"NOR,me);
	me->start_busy(3);	

	// 60+300+139 => 499 + random(499)
	damage = qin + me->query_skill("magic")
			+ F_LEVEL->get_level(me->query("combat_exp"));
	damage = damage + random(damage);
	
	me->add_temp("apply/magic",skill);
	if (COMBAT_D->do_magic_attack(me, target, "magic","sen", 0)){
		message_vision(MAG"
$N听得片刻，心旌摇动，只感胸口怦怦而动，极不舒畅。再听少时，一颗
心几乎要跳出腔子来，却是无形中已受了内伤。\n"NOR,target);
		damage = COMBAT_D->magic_modifier(me, target, "sen", damage);
		target->receive_damage("sen",damage, me);
		COMBAT_D->win_lose_check(me,target,1);
		COMBAT_D->report_status(target);
	}
 	else {
 		message_vision(WHT"$N面露微笑，凝守心神，不为乐声所动。\n"NOR,target);
	}
	me->add_temp("apply/magic",-skill);

	return 1;
 		
}
