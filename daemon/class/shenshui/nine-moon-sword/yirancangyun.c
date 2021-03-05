// silencer@fengyun  「雁渡寒潭」

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int my_exp,your_exp, mod;
	object *weapon;
	int duration;
	int extra, bonus, attack_bonus, damage;
		
   	if(me->query("class")!="shenshui")
    	return notify_fail("只有神水宫弟子才能使出『意染苍云』的绝技。\n");

	if (userp(me))
	if (me->query_skill_mapped("force")!= "nine-moon-force")
		return notify_fail("若不借助九阴心法，此招无法克敌制胜。\n");
				
	if (me->query_skill("nine-moon-sword",1) < 200|| me->query_skill("qingpingsword",1)<200)
		return notify_fail("『意染苍云』需要200级的九阴剑法和200级清平剑法。\n");
		
	duration = 180 - F_ABILITY->check_ability(me,"yrcy_add")*6;
	duration = me->query("timer/pfm/cangyun") + duration - time();
	if (duration>0)
		return notify_fail("再剃，再剃就成秃驴啦！（须等待"+duration+"秒）\n");
		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『意染苍云』只能对战斗中的对手使用。\n");

		me->set("timer/pfm/cangyun",time());
		weapon = me->query_temp("weapon");
    	msg = HIR BLK+"\n$N"HIR BLK"脸上神色惨然，猛一咬牙，"+weapon->name()+HIR BLK"向自己身侧划去。冰冷的剑锋切进
$N"HIR BLK"飘飞的长发，喑哑的冷风呜咽划过，漫天的青丝在空中纷扬翻卷。\n"NOR;
		msg += CYN"散落的发梢拂过$n"NOR+CYN"，依稀还带着一缕清冽幽香。$n"NOR+CYN"心中一乱，
但觉得浑身发软，提不起一丝力道。\n\n"NOR;
		msg += WHT"踯躅之间，只见寒芒一闪，"+weapon->name()+WHT"已破出重网，斩断千结，抵近$n眉心。\n"NOR;
		message_vision(msg, me, target);
		
		// dmg = (500 + 139)*2 = 1268; atk = (200 + 139)*2 = 678;
				
		bonus = me->query_skill("nine-moon-sword",1) + F_LEVEL->get_level(me->query("combat_exp"));
		bonus *= 2;
		
		extra = me->query_skill("sword");
		extra += F_LEVEL->get_level(me->query("combat_exp"));
		extra *= 2;
		
		me->add_temp("apply/attack", bonus);	
		me->add_temp("apply/damage", extra);
		target->add_temp("cant_dodge",1);
		target->add_temp("cant_parry",1);
		target->add_temp("marks/full_hit_damage",1);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
		target->add_temp("marks/full_hit_damage",-1);
		target->add_temp("cant_dodge",-1);
		target->add_temp("cant_parry",-1);
		me->add_temp("apply/attack", -bonus);
		me->add_temp("apply/damage", -extra);
		
		if (me->query_skill("sword",1)<250)	me->perform_busy(2);
		else if (me->query_skill("sword",1)<300)	me->perform_busy(1);
		return 1;
}





/*

　　　     /＼              ／\      
　　　   ▕   ＼＿＿　　　／  ︱       
　　　   ▕ ／￣    ◥██◤╲︱       
　　　    ∕                  ﹨       
　　　    ︳   /￣\    /￣\   ▕      
　　　    ︳   ︳●    ●  ︳ ▕       
　　　   ┼    \ /    \　/    ┼      
　　　    ﹨　      ●      　∕         
　　　    ˉ╲　    　   　／ˉ         
　　　    ╭─◤ˉˉˉ￣◥◤﹨           
　　　   （   ︳           /﹀﹀\◢█    
　　　  （____︳  ▕ ／  ▕ .. █◤     
　　　        \︿︿/ ︺︺︺＼●／         
                       ˉ             
　　　　　　　　- FengYun - 　　　
 　　　　　　　annie 06.2005
 　　　　dancing_faery@hotmail.com

*/
