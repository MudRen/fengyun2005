#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,bonus,a,b;
	extra = me->query_skill("dug",1);
	if ( extra < 200) return notify_fail("你对极光刺杀术的掌握程度不足以使出『七冥虚之剑』。\n");
	bonus = me->query_skill("dagger",1);
	if ( bonus < 200) return notify_fail("你对基本短兵刃的掌握程度不足以使出『七冥虚之剑』。\n");

	if (me->query("force") < 1200 && userp(me))
		return notify_fail("你的内力不足以使出『七冥虚之剑』。\n");

	if (NATURE_D->is_day_time() && userp(me))
			return notify_fail("『七冥虚之剑』只可在夜间使用。\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIR BLK"七冥虚之剑"NOR"只能对战斗中的对手使用。\n");

	if (me->query("age") - me->query("annie/dug") < 1 && userp(me))
		return notify_fail("你的精念还没有自上次施展『七冥虚之剑』的损耗中恢复过来，无法再次使用。\n");

	me->set("annie/dug",me->query("age"));
	if (userp(me))
		me->add("force",-1200);

	a=extra+random(bonus)+bonus;			// 200 + random(200) + 200 = 400-600
	b=bonus*2+random(extra*3)+extra*2;		// 200*2 + random(200*3) + 200*2 = 800 - 1600

	me->add_temp("apply/attack", a);	
	me->add_temp("apply/damage", b);

	msg = HIR BLK"一阵浓雾飘来，阻绝在$n"HIR BLK"眼前，$N"HIR BLK"身形一闪，迫到$n"HIR BLK"身边，借机发动了极光刺杀术的最终式：『"NOR BLU"七冥虚之剑"HIR BLK"』！"NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);

	me->add_temp("apply/attack", -a);	
	me->add_temp("apply/damage", -b);

	return 1;
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
