// annie 6.27.03
// DISORDER - NPC ONLY

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i,j;
	object *tar;

	tar = me->query_enemy();
	if (sizeof(tar) > 1)
	{
		message_vision(HIY"\n$N使出武当派失传的借力打力功夫，左掌虚虚画了个半弧，右掌回圈，\n陡然沉气开声，发出扭曲圆转的劲力，震得所有人东倒西歪。\n"NOR,me);
		for (i=0;i<sizeof(tar) ; i++)
		{
			if (i != sizeof(tar)-1)
				target = tar[i+1];
			else
				target = tar[0];

			if (tar[i]->is_unconcious())	continue;

// 为了让parry busy生效(爆,太恶毒了),这里不使用mimic function....
			target->add_temp("no_check_pfm_win",1);
			j = tar[i]->query_busy();
			tar[i]->stop_busy();
			tar[i]->add("force_factor",me->query("force_factor")/2);
	        COMBAT_D->do_attack(tar[i],target,TYPE_QUICK,HIY"$N"HIY"只觉得一道大力推来，身不由己的向$n"HIY"攻去！"NOR);
			tar[i]->add("force_factor",-me->query("force_factor")/2);
			tar[i]->perform_busy(j+random(2));	// busy 0~1.
			target->add_temp("no_check_pfm_win",-1);
			target->receive_damage("kee",1,me);
		}
		me->perform_busy(2);
		return 1;
	}
	else
		return notify_fail("借力打力现在无法使用。\n");
	return 1;
}

