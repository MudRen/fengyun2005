// Pango-Axe
// annie 10.2003

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, myexp, hisexp,flag;
	object weapon;

	extra = me->query_skill("venusfinger",1) ;
	if (extra < 40) 
		return notify_fail("需要40级长庚指法才能使出『盘古斧』。\n");
	if (me->query("force") < 200)
		return notify_fail("你的内力不足以使出『盘古斧』。\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『盘古斧』只能对战斗中的对手使用！\n");
	
	weapon = target->query_temp("weapon");

	if (!weapon)
		return notify_fail("对手没有使用武器，无需使出『盘古斧』。\n");
	
	if (weapon->query("nodrop_weapon"))
		return notify_fail("这个武器看来你无法点断的。\n");

	if (userp(me))
		me->add("force",-200);
	
	message_vision(WHT"\n$N"WHT"突然将右手拇指食指相屈，眼神变得迷离而朦胧，身形也凝滞起来。\n\n"NOR,me,target);
	me->perform_busy(2);
	call_out("do_pangoaxe",1,me,target,weapon);
	return 1;
}

int do_pangoaxe(object me,object target,object weapon)
{
	string msg;
	int extra, myexp, hisexp,flag;
	if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me))
		return 0;
	if(!present(weapon,target)||weapon->query("equipped")!="wielded") {
		me->set("timer/pfm/venusfinger_fail",time());		// a mark used by NPCs. 
		return 0;
	}
	myexp  = me->query("combat_exp");
	hisexp = target->query("combat_exp");
	
	if( (userp(target) || random(hisexp) < random(myexp*2)) && weapon)	
	{
		message_vision(
		WHT "\n\n$N"WHT"眼中神光一闪，身影一晃，食指乍然弹出，如同穿越了千年的时间一般，点在"+ 
		weapon->name()+  WHT"之上。\n　　只听得一声混沌初破似的巨响炸开，"+weapon->name()+WHT"化作了无数碎片，如漫天花雨迸散而出。\n\n" NOR, me,target);

		weapon->unequip();
		if(weapon->query("owner"))
		{
			weapon->set("orig_name", weapon->query("name"));
			weapon->set("weapon_prop/damage",1);
		}
		else
			weapon->set("weapon_prop",0);
		target->reset_action();
		weapon->set("name","断掉的" + weapon->query("name"));
		weapon->set("item_damaged", 1);
		weapon->set("value",0);
		weapon->save();

	}
	else {
		message_vision(	WHT "\n$N左右寻不着机会，咬了咬牙，将二指缓缓松开。\n\n" NOR, me,target);
		me->set("timer/pfm/venusfinger_fail",time());		// a mark used by NPCs. 
	}
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
