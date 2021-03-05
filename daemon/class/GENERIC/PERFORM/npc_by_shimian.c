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
	int skill, your_exp, my_exp, damage, mod;
	 	
    	if(userp(me))
		return notify_fail("你所选用的武功中没有这种必杀技。。\n");
	
	inv = all_inventory(me);
	instr = filter_array(inv,(: $1->query("timbre") :));
	if (!instr || !sizeof(instr)) 
		return notify_fail("你身上没有携带乐器。\n");
		
	skill = me->query_skill("music",1);	
	
	if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『十面埋伏曲』只能对战斗中的对手使用。\n");
        
        if (target->is_busy())
        	return notify_fail("对方手忙脚乱，心烦意乱，无暇顾及你的琴声。\n");
        	
               
	message_vision(HIB"
$N暗运内力，手抚琴弦，琴声初似夜幕低沉，伏兵重重，瞬间声动天地，瓦屋
若飞坠。徐而察之，有金声、鼓声、剑弩声、人马辟易声，俄而无声，久之有怨
而难明者，为楚歌声；凄而壮者，为项王悲歌慷慨之声、别姬声。或铁骑纵横，
马蹄声碎，或刀兵相见，呐喊喧嚣。。。。。\n\n"NOR,me);
	me->start_busy(1);	

	mod = COMBAT_D->can_busy(me, target, "music");	
	if (!mod)
		return notify_fail(HIW"此人深谙乐理，不会被此琴声困扰的。\n"NOR);
	
	my_exp = me->query("combat_exp");
	your_exp = target->query("combat_exp")*mod;
		
	if ( my_exp/2 + random(my_exp)*3 > your_exp ) {
		message_vision(MAG"$N似陷于十面埋伏之中，左冲右突，不得以脱。\n"NOR,target);
		target->force_busy(2);
	}
 	else {
 		message_vision(WHT"$N面露微笑，凝守心神，不为乐声所动，反借琴韵猝然反击。\n"NOR,target);
 		COMBAT_D->do_attack(target,me,TYPE_PERFORM,msg);
	}
	return 1;
 		
}
