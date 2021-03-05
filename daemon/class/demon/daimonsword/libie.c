// 别方不定，别理千名，有别必怨，有怨必盈。——　三叹剑法·离别亢怒式,annie 6.29.03


#include <ansi.h>
inherit SSERVER;

int perform(object me, object target) 
{
	int i, skill ;
	object weapon,ob;
	string obn;

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIC"『离别亢怒式』"NOR"只能对战斗中的对手使用。\n");

	skill = me->query_skill("daimonsword",1);
	if (skill < 200)
		return notify_fail(HIC"『离别亢怒式』"NOR"至少需要200级三叹剑法。\n");
	
	if (!me->is_fighting())
		return notify_fail(HIC"『离别亢怒式』"NOR"只能在战斗中使用。\n");
	
	if (userp(me))
	{
		if (me->query("class")!= "demon")
			return notify_fail("只有魔教弟子才能施展"HIC"『离别亢怒式』"NOR"。\n");

		if (!me->query("marry") || me->query("divorced"))
			return notify_fail("无论你怎样用心，总是无法把握住三叹剑法的神之所在。\n");

		ob = FINGER_D->acquire_login_ob(me->query("marry"));

		if (ob)
			return notify_fail("无论你怎样用心，总是无法把握住三叹剑法的神之所在。\n");

		if (me->query("bellicosity") < 1000)
 			return notify_fail("你现在毫无怨气杀机，如何使得出"HIC"『离别亢怒式』"NOR"？\n");

		me->add("bellicosity",-1000);
	}
	
	weapon = me->query_temp("weapon");
	message_vision(HIW"\n$N敛神聚气，后避三步，手中"+weapon->name()+HIW"斜斜下指，神态凝重。\n" NOR, me);
	me->perform_busy(2);
    call_out("do_bash", 1, me,target,weapon);
	return 1;
}


int do_bash(object me,object target,object weapon)
{
	object tw;
	int i;
	int ax,bx,cx,dx;	// 晕....cindy的这个forumla真..
	if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me))
		return 0;
	if(!present(weapon,me))
		return 0;
	if (weapon->query("equipped")!="wielded" && userp(me))
		return 0;
	
	tw = target->query_temp("weapon");
	ax = me->query_skill("sword");
	bx = target->query_skill(tw?tw->query("skill_type"):"unarmed");
	cx = me->query("combat_exp");
	dx = target->query("combat_exp");
	ax = ax - bx;		// 200sword/200daimonsword为500,这个数字应该在600以下,对于exp相近者为0.
	if (ax<0)
		ax = 0;
	cx = cx * 10 / dx * 20;	// 相同经验200, 1.5倍300, 0.5倍100.
	ax += cx;			// 对于相同经验的人而言,应为200左右
	ax = (ax>0?random(ax)*10:1);	// 1000
//	cx = random(ax)/10+1;			// 50
	cx = random(ax)/5+1;			// 100

//	message_vision(HIY "\n$N暴喝一声长身而起，手中"+weapon->name()+HIY"色转赤红，在空中带出一溜飞溅火星划向$n！\n" NOR, me,target);
	message_vision(HIC "\n$N一声暴喝，错步上前，手中"+weapon->name()+HIC"一划，剑气宛若惊虹，切破长空，飞泻而下！\n" NOR, me,target);

	if (tw && tw->query("skill_type") != "throwing")	// 暗器不能挡..
	{
		message_vision(HIR "慌乱之中，$N连忙高抬"+tw->name()+HIR"，向"+weapon->name()+HIR"横挡而去。\n" NOR, target);
//		message_vision(HIR "debug:"+tw->query("weapon_prop/damage")+HIR"，"+cx+HIR"。\n" NOR, target);
		if (tw->query("weapon_prop/damage") <= cx)
		{
			message_vision(HIR"只听＂铛＂一声巨响，$N手中的"+tw->name()+HIR"应声而折。\n" NOR, target);
			tw->unequip();
			if(tw->query("owner"))
			{
				tw->set("orig_name", tw->query("name"));
				tw->set("weapon_prop/damage",1);
			}
			else
				tw->set("weapon_prop",0);
			target->reset_action();
			tw->set("name","断掉的" + tw->query("name"));
			tw->set("item_damaged", 1);
			tw->set("value",0);
			tw->save();

			target->receive_damage("kee",(ax+random(ax)));
			target->receive_wound("kee",ax);
			COMBAT_D->report_status(target);
		
		}
		else
		{
			message_vision(HIR"只听＂铛＂一声巨响，"+tw->name()+HIR"上密密麻麻的出现了一片蛛网般的裂痕。\n\n" NOR, target);
			tw->add("weapon_prop/damage",-cx);
			target->add_temp("apply/damage",-cx);
//			target->reset_action();
			tw->save();
		}
	}
	else
	{
		message_vision(HIR"$N无以招架，一个闪身躲避不及，被怨别剑气切出一道深深的血口。\n" NOR, target);
		target->receive_damage("kee",(ax+random(ax))*2);
		target->receive_wound("kee",ax*2);
	    COMBAT_D->report_status(target);
	}
	return 1;
}
