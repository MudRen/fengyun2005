// Silencer@fengyun workgroup	June.2005
// Paragon: 10 times +3*170=510 kee, with ability = 660 kee

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target, int amount)
{
	int level,i, skill, duration, amount1;
	object *enemy, *mem;
	
	if(me->query("class")!="wolfmount")
		return notify_fail("只有狼山弟子才能『天狼诀』！\n");

	level = me->query_skill("wolf-force",1);
	if (level<170 || me->query_skill("summonwolf",1)< 250) 
		return notify_fail("『天狼诀』需要170级天狼心法和250级唤狼术。\n");
	
	if(!target ) target=me;
	if (target != me)
		return notify_fail("『天狼诀』只能用于自身。\n");
		
	if (target->query_temp("pfm/wolf-force/paragon"))
		return notify_fail("你已经在使用『天狼诀』了。\n");
	
	// duration = 20mins.
	duration = me->query("timer/pfm/wm_paragon")+ 1200 -time();
	if (duration>0)
    	return notify_fail("『天狼诀』极耗元神，需要"+chinese_number(duration/60)+"分钟后才能再次运用。\n");
	
	if( (int)me->query("force") < 200 )
		return notify_fail("使用『天狼附体』需要２００点内力。\n");
	if (userp(me)) me->add("force", -200);
	
	message_vision(BRED+HIW"
$N目光突地全都变成了赤红颜色，手足颜面的皮肤，也突地变为紫红，全身
宛如已被火焰燃烧了起来。有如上古魔神，要择人而噬！\n"NOR, me);

	amount1 = level *3 * (100 + F_ABILITY->check_ability(me,"paragon_add")*3)/100;
	call_out("fillup",6,me,10,0,amount1);        
    
    me->set_temp("pfm/wolf-force/paragon", 1);
	me->set("timer/pfm/wm_paragon",time());
	return 1;

}


void fillup (object me, int total, int count, int amount)
{
	if (!me)	return;
		
	if(++count>=total)
	{
		tell_object(me,YEL"你的天狼心法·天狼诀运行完毕。\n"NOR);
		me->delete_temp("pfm/wolf-force/paragon");
		return;
	}
	else {
		me->receive_fulling("kee", amount,me);
		me->status_msg("kee");
		message_vision(WHT"$N汲草木万物之灵气，发出震人心肺的啸声。。。\n"NOR,me);
		call_out("fillup",6,me,total,count, amount);
	}
	return ;
}


