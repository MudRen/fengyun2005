// yawn pfm
// *bored,#10 *yawn,*bored annie
// 少林专用pfm? doubt

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra, busy,busy2,pp=0,pd=0;
	object * pros,weapon;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『梦幻空花』只能对战斗中的对手使用。\n");

	if (me->query("marry"))
		return notify_fail("你心头有所挂念，无法施展『梦幻空花』。\n");
	
	if (me->query("quest"))
		return notify_fail("你心头尚有挂念，无法施展『梦幻空花』。\n");

	if (me->query_skill("zen",1) < 51)
		return notify_fail("你禅机未悟，无法施展『梦幻空花』。\n");
	
	if (me->query_skill("zen",1) < 51)
		return notify_fail("你禅机未悟，无法施展『梦幻空花』。\n");
	
	extra = me->query_skill("sword");
	extra /= 4;
	
	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",me->query_skill("zen",1));	

	msg =  CYN"$N双眼微合，只觉万事空无，意兴阑珊，将$w倚禅机随手挥舞，胡乱击向$n。\n" NOR;

	pros = target->query_temp("protectors");
	target->delete_temp("protectors");
	busy = target->query_busy();
	busy2 = target->query("no_busy");

    msg +=  YEL"梦…"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	if (target->query_temp("damaged_during_attack"))
	{
		message_vision(HIB"$N只觉得世事宛如春梦一场，人生几无意味，目光渐渐迷离。\n",target);
		target->delete("no_busy");
	}
    msg =  NOR YEL  "幻…"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	if (target->query_temp("damaged_during_attack") && !target->query("boss") && !target->query("big_boss"))
	{
		message_vision(HIB"种种往时幻像如走马灯般流过$N眼前，$N心神无主，动作迟缓。\n",target);
		target->force_busy(1);
	}
    msg =  NOR YEL  "空…"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	if (target->query_temp("damaged_during_attack"))
	{
		message_vision(HIB"回首旧时光阴，竟是韶光虚掷，一事无成，$N不由觉得心头一片茫然。\n",target);
		pp = extra * 2;
		pd = me->query_skill("zen",1);
		target->add_temp("apply/parry",-pp);
		target->add_temp("apply/dodge",-pd);	
	}
    msg =  NOR YEL  "花…"NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	if (target->query_temp("damaged_during_attack") && !target->query("no_drop") && !target->query("boss") && !target->query("big_boss") && (weapon=target->query_temp("weapon")))
	{
		if (random(me->query("combat_exp") + target->query("combat_exp")) > target->query("combat_exp") / 2 * 3)
		{
			if (weapon->query("skill_type") != "throwing" && weapon->query("skill_type") != "ring" && weapon->query("skill_type") != "unarmed")
			{
				message_vision(HIB"$N但觉万念俱灰，大千世界里再无自己容身之处，长长叹息一声，将手中"+weapon->name()+HIB"折断。\n"NOR,target);
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
		}
	}

	target->set_temp("protectors",pros);
    me->add_temp("apply/attack",-extra);
	me->add_temp("apply/damage",-extra);	
	me->perform_busy(3);
	target->perform_busy(busy);
	target->set("no_busy",busy2);
    target->add_temp("apply/parry",pp);
	target->add_temp("apply/dodge",pd);	
	
	return 1;
}


/*

　　　　　　　╔╕
　　　　　　　║╰╮
　　　　　　　║│╰╮
　　　　　　　║││╰╮
　　　　　　　║││││
　　　　　　　╚╧╧╧╛

　　　　　　　- FengYun - 　　　
　　　　　　annie 08.2003
　　　dancing_faery@hotmail.com
*/

