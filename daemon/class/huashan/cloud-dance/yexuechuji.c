//	Busy : ENchance = 380*100/130 = 292

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, bonus, mod, total, enhance;
	
	if (me->query("class")!="huashan") 
		return notify_fail("幻风飘云舞的『夜雪初积』是华山派绝技。\n");
		
	extra = me->query_skill("anxiang-steps",1);
	bonus = me->query_skill("cloud-dance",1);
	
	if ( userp(me) && extra < 100) return notify_fail("『夜雪初积』需要100级的暗香浮影。\n");
	if ( bonus < 100) return notify_fail("『夜雪初积』需要100级的幻风飘云舞。\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
        return notify_fail("『夜雪初积』只能对战斗中的对手使用。\n");
		
	if(target->is_busy())
		return notify_fail(target->name()+"已经手忙脚乱了！\n");
	
	mod = COMBAT_D->can_busy(me, target, "cloud-dance");	
	if (!mod)
		return notify_fail(HIW"此人身法灵活，不会被此步法迷惑的。\n"NOR);
		
	message_vision(WHT"\n$N"+WHT"的身影忽然变得朦胧不定，似乎化作了如梦如幻的飘云。\n"NOR, me); 
	message_vision(WHT"如夜雪在寒梅间飘落，雪花舞动之间，有冷冷的幽香浮动。\n"NOR, me); 
	
	total = bonus + extra;
	if (total > 380 ) total = 380; 
	enhance = total *100/130;
	
	if (COMBAT_D->do_busy_attack( me, target, "cloud-dance/yexuechuji", "step", enhance, mod))
	{
		message_vision(WHT"\n$N"+WHT"觉得身法越来越滞塞，好似陷入迷茫的雾雪里。\n"NOR, target); 
 		message_vision(HIG"在缕缕暗香中，$N"+HIG"不禁有些痴迷起来。\n\n"NOR, target); 
		target->set_temp("busy_timer/cloud-dance",time());
		target->force_busy(3);
	}
	else{
		message_vision(YEL"\n$N"+YEL"守心归一，不为$n"+YEL"身法所惑。一步踏出，正是$n"+YEL"的空门！\n\n"NOR, target, me); 
		me->perform_busy(2);
	}
	return 1;
}
