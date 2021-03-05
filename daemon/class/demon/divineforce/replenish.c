// 这个技能将补充玩家身上排在第一顺位的暗器数目。

inherit SSERVER;
#include <ansi.h>

int exert(object me, object target, int amount)
{
	int lvl,duration,i;
	object obj,*inv;
	object drug1,drug2;

	amount = 150;	// 1k.
	duration = 1800;// 30 min

	lvl = me->query_skill("divineforce",1);	
	if( lvl < 1)
	return notify_fail("『灵华仙迹』需要1级的破邪心经。\n");

	inv = all_inventory(me);

	for (i=0; i<sizeof(inv); i++)
		if (inv[i]->query("skill_type") == "throwing")
		{
			obj = inv[i];
			break;
		}
	if (!obj)
	 	return notify_fail("你现在无法使用『灵华仙迹』。\n");
	if (obj->query("base_value") >= 10000)
	 	return notify_fail("你无法对"+obj->name(1)+"使用『灵华仙迹』。\n");
	if (obj->query("no_replenish"))
	 	return notify_fail("你无法对"+obj->name(1)+"使用『灵华仙迹』。\n");
	if (!	obj->query("volumn"))
	 	return notify_fail("你无法对"+obj->name(1)+"使用『灵华仙迹』。\n");

	if (me->query("timer/replenish") + 3600 > time())
	 	return notify_fail("『灵华仙迹』无法连续使用。\n");

	if (me->query("force") < 400)
	 	return notify_fail("『灵华仙迹』需要至少４００点内力。\n");

	i = me->query("force");
	if (i>lvl*15)
		i=lvl*15;
	if (i>obj->query("volumn") * (lvl/2))
		i=obj->query("volumn") * (lvl/2);
	me->add("force",-i);
	i=i/10;
	obj->add_amount(i);
	obj->set("base_value",1);
	obj->set("no_sell",1);
	obj->set("no_pawn",1);
	obj->set("no_stack",1);

	message_vision( HIB
"\n$N"HIB"双目微合，两手交叠虚按在"+obj->name(1)+HIB"之上，身侧笼起一层幽蓝的亮芒。\n\n	 "NOR HIW+obj->name(1)+HIW"上渐渐泛起淡白的柔光，变得越来越明亮．．．\n" NOR, me);

	me->set("timer/replenish",time());

	me->perform_busy(3);

	return 1;
}
