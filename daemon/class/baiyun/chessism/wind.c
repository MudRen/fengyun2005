//	Remove lockup.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target)
{
	int extra;
	if (me->query("class") != "baiyun") 
		return notify_fail("只有白云岛弟子可以使用『云开雾散』\n");
		
	extra = me->query_skill("chessism", 1);
	if(extra < 50) 
		return notify_fail("『云开雾散』需要50级的弈道心法。\n");
      
	if( !target ) target = me;
  	if (target!= me)
  		return notify_fail("『云开雾散』只能用于自身。\n");
        
	if( (int)me->query("force") < 200 )
		return notify_fail("你的内力不够。\n");

	if( me->query_temp("apply/painting") ) 
		return notify_fail("你已经在使用『云开雾散』了。\n");
		
	message_vision(HIG"$N衣带飘飘，似当风而动，周围空气霎时如云开雾散般清新舒畅。\n"NOR,me);
	me->add("force", -50);
	me->delete_temp("till_death/lockup");
	return 1;
}

