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
	int qin, skill, your_exp, my_exp, damage, mod, i;

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

	if (me->query("annie/music_choose") != 1 && userp(me))
		return notify_fail("这曲子你似乎没学会诶。\n");
	
	if (skill < 150)
		return notify_fail("你发现此谱过于高深，至少需要150级的琴道才能演奏。\n");

	if( !target ) target = offensive_target(me);        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『十面埋伏曲』只能对战斗中的对手使用。\n");
        
    if (target->is_busy())
       	return notify_fail("对方手忙脚乱，心烦意乱，无暇顾及你的琴声。\n");
        	
    if( me->query("atman") < 200 )
		return notify_fail("『十面埋伏曲』需要２００点灵力。\n");
	if (userp(me))me->add("atman",-200);
		        
	message_vision(HIB"
$N暗运内力，手抚琴弦，琴声初似夜幕低沉，伏兵重重，瞬间声动天地，瓦屋
若飞坠。徐而察之，有金声、鼓声、剑弩声、人马辟易声，俄而无声，久之有
怨而难明者，为楚歌声；凄而壮者，为项王悲歌慷慨之声、别姬声。或铁骑纵
横，马蹄声碎，或刀兵相见，呐喊喧嚣。。。。。\n\n"NOR,me);
	me->perform_busy(1);	

	mod = COMBAT_D->can_busy(me, target, "music");	
	if (!mod)
		return notify_fail(HIW"此人深谙乐理，不会被此琴声困扰的。\n"NOR);

	if (COMBAT_D->do_busy_attack(me, target, "music/shimian", "step", 200+qin/2, mod)){
		message_vision(MAG"$N似陷于十面埋伏之中，左冲右突，不得以脱。\n"NOR,target);
		target->set_temp("busy_timer/music",time());
		target->force_busy(2);
	}
 	else {
 		message_vision(WHT"$N面露微笑，凝守心神，不为乐声所动。\n"NOR,target);
	}
	return 1;
 		
}
