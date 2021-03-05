//博浪一击// Silencer @ FY4 workgroup. Oct.2004

#include <ansi.h>
#include <combat.h>

int tobe(object me,object target,object weapon, object room);

int perform(object me, object target)
{
	string msg;
	int extra,i;
	object weapon;
	
    if(userp(me))
		return notify_fail("你所选用的武功中没有这种必杀技。。\n");  
		
	extra = me->query_skill("assassin-hammer",1);
	if(me->query("class")!="wolfmount")
		return notify_fail("只有狼山弟子才能使用『博浪一击』\n");
	if ( extra < 100) 
		return notify_fail("『博浪一击』需要100级的博浪锤法。\n");
	
	if (me->query_skill_mapped("force")!="wolf-force")
		return notify_fail("搏浪锤法需要天狼心法为基础。\n");
		
	if( !target || !target->is_character()) 
		return notify_fail(HIR"你要暗算谁？\n"NOR);
	
	if( target==me) return notify_fail(HIR"你不想活了？\n"NOR);
	
	if (!target->is_fighting(me))
		return notify_fail("战斗外的刺杀请使用『荆轲刺秦』\n");
	
	weapon = me->query_temp("weapon");
	tell_object(me, HBBLU HIC"\n你趁其不备，飞速转到" + target->query("name") + HBBLU HIC"身后，『博浪一击』蓄势待发！\n"NOR);	
	call_out("tobe", 7, me, target, weapon, environment(me));	
	me->start_busy(3);
	return 1;
}

        	
int tobe(object me,object target,object weapon, object room)
{
	string msg;
	int hit_damage, damage,crit,rate,stage;
	
	if(!me || !target || environment(target)!=environment(me)
		|| !target->is_fighting(me) || room!=environment(me)) 
	{
		if (me)
			tell_object(me, WHT"真可惜，你要刺杀的目标溜走了。\n"NOR);	
		return 0;
	}
		
	if(!present(weapon,me) || weapon->query("equipped")!="wielded"){
		tell_object(me, WHT"手软了？你怎么把武器收起来了？ \n"NOR);
		return 0;
	}
		
	msg = YEL "\n$N跃起，手中"+weapon->query("name")+YEL"一转，带起阵阵风雷之声。\n$N手一抖，" + weapon->query("name") + YEL"脱手飞出，如风卷黄沙呼啸着击向$n。 \n"NOR;
	message_vision(msg, me, target);
	
	rate = 80;
	
    stage = F_LEVEL->get_level(me->query("combat_exp"));	 
    if (stage >= 105 )   		rate = 100;				// 6.6 M
	else if (stage >=95)		rate = 90;				// 5.6 M
	
//	write ("rate is " + rate + "\n");	
	// 150*3 + 100 = 550, 485*3 + 100 = 1555
	// Players can reach skill cap @4.6M, so we use hard code to limit it
	//  @4.6M 左右, 1088*1.5 = 1632
	//	1321* 1.5 = 1982 dmg @ 5.6M+
	//  1555* 1.5 = 2332 dmg @ 6.6M + 
	
	hit_damage = 100 + me->query_skill("hammer")*3 *rate/100;
		
	hit_damage = hit_damage * (F_ABILITY->check_ability(me,"bolang2_add")*2 + 100)/100;
	if (F_ABILITY->check_ability(me,"bolang1_add") > random(100))
		hit_damage = hit_damage *2;
	
	// inherently 2% critical chance
	if (F_ABILITY->check_ability(me,"bolang1_add")+2 > random(100)) {
		hit_damage = hit_damage *2;
		crit = 1;
	}
		
	if (COMBAT_D->do_busy_attack(me, target, "assassin-hammer/bolangyiji","unarmed", 500, 10)
		|| ANNIE_D->check_buff(me,"assassinate"))
	{
		damage = hit_damage + random(hit_damage);
			
		if (ANNIE_D->check_buff(me,"assassinate"))
			damage = hit_damage *2;
		
		damage = COMBAT_D->magic_modifier(me, target, "kee", damage);
		if (damage >= hit_damage *3/2)
			msg = HIR"只见" +weapon->query("name")+ HIR"带着一阵低啸和猛烈的劲风“轰”地击中了$n"HIR"的头部！\n"NOR;
		else
			msg = HIR"只见" +weapon->query("name")+ HIR"带着一阵低啸和猛烈的劲风“轰”地击中了$n"HIR"的胸口！\n"NOR;
		
		if (crit)
			msg = HBRED+HIW"只见" +weapon->query("name")
			+ HBRED+HIW"带着一阵低啸和猛烈的劲风“轰”地击中了$n"HBRED+HIW"的眉心！\n"NOR;	
		
		message_vision(msg, me, target);
		target->receive_damage("kee",damage, me);
		target->set("eff_kee",target->query("kee"));
		COMBAT_D->report_status(target);		
	}else 
	{
		msg = HIR"只见" +weapon->query("name")+ HIR"带着一阵劲风贴着$n"HIR"的脑袋飞过，只差几寸没有击中！\n"NOR;
		message_vision(msg, me, target);
	}
	
	return 1;
}