// po.c 「总诀式」
 
#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
 string msg;
 object weapon;
 int skill, gin_cost;
 mapping my_fam  = me->query("family");
 skill = me->query_skill("dugu-sword",1);
 gin_cost = (int)me->query_int() + 45;
 if ((string)me->query("class") != "huashan")
  return notify_fail("你不是华山派的弟子，不能学习「独孤九剑」。\n");

 if( me->is_fighting() )
		return notify_fail("「总诀式」不能在战斗中演练。\n");

 if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你必须先去找一把剑。\n");

 if( !skill || (skill < 50))
  return notify_fail("你的独孤九剑等级不够, 不能演练「总诀式」！\n");

 if( me->query("force") < 50 )
  return notify_fail("你的内力不够，没有力气演练「总诀式」！\n");
 
 if( me->query("gin") < gin_cost )
  return notify_fail("你现在太累了，无法集中精神演练「总诀式」！\n");

 msg = HIC "$N使出独孤九剑之「总诀式」，将手中" + weapon->name() + "随意挥舞击刺。\n" NOR;
 me->add("force", -50);
 me->add("gin", -gin_cost);
 me->improve_skill("dugu-sword",  random((int)me->query_int()) + 1);
	me->start_busy(random(3));
	message_vision(msg, me);
	return 1;
}
