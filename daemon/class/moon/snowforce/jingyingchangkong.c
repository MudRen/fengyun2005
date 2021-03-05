inherit SSERVER;
#include <ansi.h>

int exert(object me, object target, int amount)
{
		int force, lvl, duration;
		object obj, *mem;
		string msg;
		mapping buff;
		int skill,t,level;
	
		if (me->query("class") != "moon")
        	return notify_fail("只有皓月宫中人才能施展『静影长空』。\n");
        
        skill = me->query_skill("snowforce",1);
        if (skill < 90 && userp(me))
        	return notify_fail("『静影长空』需要至少170级的冷雪心经。\n");
        
		if(!objectp(obj = present(target, environment(me))))
			return notify_fail("这里没有这个人。\n");
		if (!obj->is_character() || obj->is_corpse() )
			return notify_fail("看清楚一点，那并不是活物。\n");
		
		if(!target) target=me;
		if(target!= me) {
			mem = me->query_team();
			if (!pointerp(mem) || member_array(target,mem) == -1)
				 return notify_fail("『静影长空』只能用于队友。\n");
		}
	
		if (ANNIE_D->check_buff(target, "fma"))
			return notify_fail("此人已经受到静影长空的影响了。\n");	
	
		if (me->query("force")< skill*5)
        	return notify_fail("『静影长空』至少需要"+ skill*5 + "点真气。\n");
        if (userp(me))	me->add("force",-skill*5);
        		
	// 100 - 1000, 50-500 for others.
	// duration = effect.
		
		if (skill< 170)
			amount =  500;
		else
			amount = 1000;
			
		duration = 900;
	
		if ( target == me) {
			msg = WHT"$N"NOR+WHT"整个人忽然静了，静若止水，波澜不惊，轻轻地吐气，气染霜寒。\n"NOR;
			msg += HIB"$N"HIB"清澈的眸中泛起一泓极幽极幽的靛蓝，像是十月行将破晓的天空，旷寂悠
远，深沉静谧，没有一缕白云。\n"NOR;
		} else {
			msg =  WHT"$n"NOR+WHT"整个人忽然静了，静若止水，波澜不惊，轻轻地一掌拍出，拍在$N"NOR+WHT"头顶。\n"NOR;
			msg += HIB"$N"HIB"清澈的眸中泛起一泓极幽极幽的靛蓝，像是十月行将破晓的天空，旷寂悠
远，深沉静谧，没有一染白云。\n"NOR;
			amount = amount /2 ;
		}

		buff =
			([
				"caster": me,
				"who":  target,
				"type": "fma",
				"att":	"bless",
				"name":	"冷雪心经·静影长空",
				"buff1":"force",
				"buff1_c":amount,
				"time":  duration ,
				"buff_msg": msg,
				"special_func":3,
			]);
	
		ANNIE_D->buffup(buff);	
		me->perform_busy(2);
		return 1;
}