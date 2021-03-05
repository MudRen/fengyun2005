// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target, int amount)
{
	int level,ess_level,i,force_cost,delay;
	object *enemy, *mem;
	string color;
	
	level = 80;
	ess_level = 80;
	force_cost = 200;		
	color = YEL"";
	delay = 2;
	amount = 600;
	
	if(me->query("class")!="bonze")
		return notify_fail("只有兴国禅寺的弟子才能用此心法！\n");

	if( ANNIE_D->check_buff(me,"xg-cloudstaff-up") || ANNIE_D->check_buff(me,"xg-heal-down")) {
		return notify_fail("『战佛诵』期间无法使用佛门疗伤心法。\n");
	}
	
	if (ANNIE_D->check_buff(me,"xg-evil")>0)
		return notify_fail("使用诛仙诀时杀气太重，无法使用佛门疗伤心法。\n");
	
	if ( me->query_skill("lotusforce",1) <level || me->query_skill("essencemagic",1)< ess_level) 
		return notify_fail("需要"+level+"级的莲华心法和"+ess_level+"级的八识神通。\n");
		
	if(!target ) target=me;
	if(target!= me) {
		mem = me->query_team();
		if (!pointerp(mem) || member_array(target,mem) == -1)
			 return notify_fail("你只能给同一队伍中的人疗伤。\n");
	}
	
	if (!COMBAT_D->legitimate_heal(me,target))
		return notify_fail("你不能向此人使用此疗伤心诀。\n");

	if (me->query_temp("am_healing"))
		return notify_fail("你正在使用疗伤心法中。\n");
					
	if( (int)me->query("force") < force_cost && userp(me))
		return notify_fail("需要"+force_cost+"点的真气。\n");
	if (userp(me))  me->add("force", -force_cost);
	
	if (target!=me)
		message_vision(color+"$N运起内功，将手掌贴在$n背心，缓缓地将真气输入$n体内....\n\n"NOR,me,target);
	else
		message_vision(color+"$N运起内功，缓缓地将真气在体内流转....\n\n"NOR,me);
	call_out("heal_him",delay, me, target, amount);
	
	me->set_temp("am_healing",1);
	if(target->is_fighting()) {
		enemy = target->query_enemy();
		for (i=0;i<sizeof(enemy);i++) {
			if (!enemy[i]->is_fighting(me)) {
				enemy[i]->kill_ob(me);
				me->kill_ob(enemy[i]);
			}
		}	
	}
	
	me->perform_busy(1);	
	return 1;
}


int heal_him(object me, object target, int amount)
{
	int i;
	string msg;
	object *enemy;
	
	if (me)	me->delete_temp("am_healing");
	
	if (!me || !target )	return 1;
	if (environment(target) != environment(me)) {
		tell_object(me,"你要救治的人已经不在这里了。\n");
		return 1;
	}
	
	if (!COMBAT_D->legitimate_heal(me,target)) return 1;
		
	if (target!=me)
		msg = WHT"过了不久，$N额头上冒出豆大的汗珠，$n吐出口瘀血，脸色看起来红润多了。";
	else 
		msg = WHT"过了不久，$N吐出一口瘀血，脸色看起来红润多了。";
	
	amount = amount * (100 + F_ABILITY->check_ability(me,"heal1_add")*2)/100;
	if (F_ABILITY->check_ability(me,"heal2_add") > random(100)){
		amount = amount*2;
		msg = WHT"※※"+msg+"※※";
	}
	
	message_vision(msg + "（+"+amount + "）\n"NOR, me, target);
	target->receive_fulling("kee", amount,me);
	
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
