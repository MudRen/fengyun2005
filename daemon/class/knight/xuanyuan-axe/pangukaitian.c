#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,bonus,a,b;

	if (userp(me) //&& !wizardp(me) 
		&& me->query_temp("timer/pfm/longlife_pangu")+30 < time())
		return notify_fail("盘古开浑圆以辟天地，你开甚么？\n");
		
	extra = me->query_skill("xuanyuan-axe",1);
	if ( extra < 180) 
		return notify_fail("『盘古开天』需要180级轩辕斧法。\n");
	bonus = me->query_skill("axe",1);
//	if ( bonus < 300) return notify_fail("你对基本斧法的掌握程度不足以使出『盘古开天』。\n");

//	if (me->query("force") < 1200 && userp(me))
//		return notify_fail("你的内力不足以使出『盘古开天』。\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIB"盘古开天"NOR"只能对战斗中的对手使用。\n");

//	if (me->query("age") - me->query("annie/pangoaxe") < 1 && userp(me))
//		return notify_fail("你的精念还没有自上次施展『盘古开天』的损耗中恢复过来，无法再次使用。\n");

//	me->set("annie/pangoaxe",me->query("age"));

	
	me->delete_temp("timer/pfm/longlife_pangu");
	
	a=1000;
	b=3500;

	me->add_temp("apply/attack", a);	
	me->add_temp("apply/damage", b);

	msg = HIW"\n$N"HIW"长长吸气，一瞬间精气神俱达巅峰，手中"+me->query_temp("weapon")->query("name")+HIW"毫无花巧地向$n"HIW"当头劈落，

　　　　　　　　"HIW"－－－"HIY"这一式"HIW"『"HIB"盘古开天"HIW"』"HIY"已经没有任何变化，也已不需任何变化！！

"NOR;

	message_vision(msg, me, target);
	
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");

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
