#include <ansi.h>

int conjure(object me, object target)
{
	int lvl,i;
	mapping buff;
	string msg;

	lvl = (int) me->query_skill("essencemagic",1);	
    if ( lvl < 20)
         return notify_fail("『灵识』需要20级的八识神通！\n");
	
	if (target && target!=me && !target->team_member(me))
		return notify_fail("灵识只能用于自身或者队友。\n");
	
	if (!target || target == me )	{
		target = me;
		msg = WHT "$N微一凝神，闭著眼睛使出八识神通中的灵识．．．\n" NOR;
	} else
		msg = WHT "$n微一凝神，将八识神通中的灵识施用于$N．．\n" NOR;
	
	
	if (target->query_temp("apply/astral_vision"))
		return notify_fail("此人不需要灵识神通。\n");
	
	if( me->query("atman") < 30 )
		return notify_fail("需要30点的灵力！\n");            
	me->add("atman", -30);
	

	buff =
		([
			"caster":me,
			"who": target,
			"type":"soul_sense",
			"att":"bless",
			"name":"八识神通·灵识",
			"buff1":"apply/astral_vision",
			"buff1_c":1,
			"time": 900,
			"buff_msg": msg,
			"warn_msg":WHT"你的灵识很快就要失效了。\n"NOR,
			"disa_msg":YEL"你的灵识失效了！\n"NOR,
		]);
		
	ANNIE_D->buffup(buff);
	
    return 1;

}
