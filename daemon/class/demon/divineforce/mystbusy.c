// annie 6.27.03
// MYSTBUSY - NPC ONLY

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	int i,j;
	object *tar;

	tar = me->query_enemy();
	if (sizeof(tar))
	{
		message_vision(BLK"\n$N身侧散出无数细小的蛛丝，刹时间漫满了周围的整个空间。\n"NOR,me);
		for (i=0;i<sizeof(tar) ; i++)
		{
			j = tar[i]->query_busy();
			tar[i]->perform_busy(j+1);	// busy +1.
			tar[i]->apply_condition("mystbusy",10);
		}
		me->perform_busy(1);
		return 1;
	}
	else
		return notify_fail("现在无法施展千结缠缚。\n");
	return 1;
}

