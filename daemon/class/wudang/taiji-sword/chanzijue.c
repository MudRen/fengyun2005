

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, mod;
	object weapon;
	
	if ((string)me->query("class") != "wudang")
  		return notify_fail(WHT"太极『缠字诀』是武当不传之秘。\n"NOR);
	
	extra = me->query_skill("taiji-sword",1);
	if ( extra < 130) return notify_fail("『缠字诀』需要130级的太极剑法！\n");
	
	if (userp(me) && me->query_skill_mapped("force") != "taijiforce")
		return notify_fail("『缠字诀』需要太极心法的配合！\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『缠字诀』只能对战斗中的对手使用。\n");
	
	mod = COMBAT_D->can_busy(me, target, "taiji-sword");	
	if (!mod)
		return notify_fail(HIW"此人身法灵活，功力深湛，不会被此剑法迷惑的。\n"NOR);
	
	if(target->is_busy())
		return notify_fail("对方已经手忙脚乱了。\n");
		
//	降低3。5M后的成功率。
	if (!userp(target))
	if (target->query("combat_exp") > 3500000) mod = mod * 8/5;

	if (!target->query_temp("annie/wd_busy_test_1") || time() > target->query_temp("annie/wd_busy_test_1") +4 )
	{
		message_vision(HIY"$N"HIY"展开太极剑法『缠字诀』，剑势圆转如意，划出了一个又一个圈子。\n",me);
		
		if (COMBAT_D->do_busy_attack( me, target, "taiji-sword/chanzijue", "rev-unarmed", 120, mod))
		{ 
			target->force_busy( 2+ random(3) );
			message_vision(HIC "$N"HIC"被$n"HIC"的剑法所缠，动作慢了下来！\n"NOR,target,me);
		} else	{
			me->perform_busy(2);
			if (weapon = target->query_temp("weapon"))
				message_vision(HIW"$N"HIW"险中求胜，"+weapon->name()+HIW"从$n的剑光圈中攻了进去，金刃相交，剑圈立散！\n"NOR,target,me);	
			else 
				message_vision(HIW"$N"HIW"招术陡变，中宫疾进，从$n剑光圈中攻了进去，掌风到处，剑圈立散！\n"NOR,target,me);
		}
	}
	else
	{
		message_vision(HIY"$N"HIY"趁$n"HIY"动作迟滞，手腕一振，"+me->query_temp("weapon")->name()+HIY"幻出万道剑环，虚虚实实，相连无缝，正是太极剑法中缠字诀变招「紫府云封」！\n"NOR,me,target);
		me->perform_busy(1);
		
		if (COMBAT_D->do_busy_attack( me, target, "taiji-sword/chanzijue", "rev-unarmed", 120, mod))
		{ 
			target->force_busy(2);
			message_vision(HIC "$N"HIC"为$n"HIC"剑法所缠，封架不及，顿时破绽百出！\n"NOR,target,me);
			target->set_temp("annie/wd_busy_test_2",time());

		} else	{
			if (weapon = target->query_temp("weapon"))
				message_vision(HIW"$N"HIW"险中求胜，"+weapon->name()+HIW"从$n的剑光圈中攻了进去，金刃相交，剑圈立散！\n"NOR,target,me);	
			else 
				message_vision(HIW"$N"HIW"招术陡变，中宫疾进，从$n剑光圈中攻了进去，掌风到处，剑圈立散！\n"NOR,target,me);
		}
		
	}

	return 1;
}
