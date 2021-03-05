//『傲霜诀』（aoshuang）：与武当的第一个ｈｅａｌ类似，
 // L20:120内力 160heal 逐步提高到  L200 - 300内力，1600heal, 2 sec delay,self-busy 1.

#include <ansi.h>

int exert(object me, object target, int amount)
{
	int level,i, n,add, force;
	object *enemy, *mem;
	
	if(me->query("class")!="huashan")
		return notify_fail("只有华山弟子才能用此心法！\n");
	
	level=me->query_skill("hanmei-force",1);
	if (level<20) 
		return notify_fail("需要20级的寒梅心法。\n");
		
	if(!target ) target=me;
	if(target!= me) {
		mem = me->query_team();
		if (!pointerp(mem) || member_array(target,mem) == -1)
			 return notify_fail("你只能给同一队伍中的人疗伤。\n");
	}
	
	if (userp(me) && !COMBAT_D->legitimate_heal(me,target))
		return notify_fail("你不能向此人使用此疗伤心诀。\n");
	
	if (level < 50)			{ force = 100; amount = 250;}
	if (level < 100) 		{ force = 150; amount = 400;}
	else if (level < 150) 	{ force = 200; amount = 800;}
	else if (level < 200) 	{ force = 250; amount = 1200;}
	else					{ force = 300; amount = 1600;}

/*	XG's 	
	L20 heal:100内力，300heal,2 sec delay, self-busy 1
	L80 mheal: 200内力，600heal,2 sec delay, self-busy 1
	L120 gheal: 300内力，1500heal,3 sec dealy, self-busy 1
	L180 sheal:500 内力，4000heal,4 sec delay, self-busy 1	
	L190 fheal:500 内力  3000heal, 2 sec delay, self-busy 1
	L200 cheal:600 内力  8000heal, 6 sec delay,self-busy 1	*/

	if (me->query_temp("am_healing"))
		return notify_fail("你正在使用疗伤心法中。\n");
		
	if( (int)me->query("force") < force)
		return notify_fail("需要" + force + "点的真气。\n");

	if (target == me)
		write( WHT "你运起『傲霜诀』，开始运功疗伤。\n" NOR);
	else
		write( WHT "你运起『傲霜诀』，开始替"+ WHT+ target->name()+ WHT"运功疗伤。\n" NOR);
		
        message("vision", WHT + me->name() + NOR + WHT
"运起寒梅心法之『傲霜诀』，左掌上翻，右掌反腕相对，如绽开一朵寒梅。\n" NOR, 
		environment(me), me);

	if (userp(me))  {
		if (F_ABILITY->check_ability(me,"heal_add")> random(100))	
			tell_object(me,YEL"（你内息贯通，举重若轻地使出了这一招）\n"NOR);
		else
			me->add("force", -force);
	}
	
		call_out("heal_him", 3, me, target, amount);
		me->set_temp("am_healing",1);
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


int heal_him(object me, object target, int amount)
{
	if (!me || !target)	
		return 1;
		
	if (me)	me->delete_temp("am_healing");
		
	if (environment(target) != environment(me)) {
		tell_object(me,"你要救治的人已经不在这里了。\n");
		return 1;
	}
	amount = COMBAT_D->magic_modifier(me, target, "kee",amount);
		
	message_vision(WHT"一层淡淡的白气从指掌间透出，$N的外伤开始慢慢愈合。\n" NOR, target);
	target->receive_fulling("kee", amount,me);
	return 1;	
	
}