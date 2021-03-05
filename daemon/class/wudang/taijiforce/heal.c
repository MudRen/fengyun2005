// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target, int amount)
{
	int level,i, n,add;
	object *enemy, *mem;
	
	if(me->query("class")!="wudang")
		return notify_fail("只有武当弟子才能用此心法！\n");
	
	level=me->query_skill("taijiforce",1);
	if (level<20) 
		return notify_fail("需要20级的太极心法。\n");
		
	if(!target ) target=me;
	if(target!= me) {
		mem = me->query_team();
		if (!pointerp(mem) || member_array(target,mem) == -1)
			 return notify_fail("你只能给同一队伍中的人疗伤。\n");
	}
	
	if (!COMBAT_D->legitimate_heal(me,target))
		return notify_fail("你不能向此人使用此疗伤心诀。\n");
	
	// L20 -- 120/160
	// L150 - 250/1200	
	if( (int)me->query("force") < 100+ level && userp(me))
		return notify_fail("需要" + stringp(level+100) + "点的真气。\n");
	if (userp(me))  me->add("force", -level-100);
	
	if (target!=me)
		message_vision(WHT "$N运起太极两仪功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"NOR,me,target);
	else
		message_vision(WHT "$N运起太极两仪功，缓缓地将真气在体内流转....\n\n"NOR,me);
	call_out("heal_him", 2, me, target, level);
	me->start_busy(1);
	
	if(target->is_fighting()) {
		enemy = target->query_enemy();
		for (i=0;i<sizeof(enemy);i++) {
			if (!enemy[i]->is_fighting(me)) {
				enemy[i]->kill_ob(me);
				me->kill_ob(enemy[i]);
			}
		}	
	}
		
	return 1;
}


int heal_him(object me, object target, int level)
{
	int amount;
	if (environment(target) != environment(me)) {
		tell_object(me,"你要救治的人已经不在这里了。\n");
		return 1;
		}
	
	if (target!=me)
		message_vision(WHT"过了不久，$n吐出一口瘀血，脸色看起来红润多了。\n"NOR,me,target);
	else 
		message_vision(WHT"过了不久，$N吐出一口瘀血，脸色看起来红润多了。\n"NOR,me);
	
	amount = level * 8;
	target->receive_fulling("kee", amount,me);
	return 1;	
	
}