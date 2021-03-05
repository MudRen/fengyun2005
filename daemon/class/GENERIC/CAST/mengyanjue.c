#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int cast(object me, object target)
{
		string msg,p_name;
		mapping perform;
		object soldier;
		
		p_name = "mengyanjue";
		
		if (!F_ABILITY->check_pfm_r1(me,p_name))	return notify_fail("");
		perform = F_ABILITY->reward_perform_1(p_name);
		if (!mapp(perform))
			return notify_fail("ERROR 99000, Please inform wizard.\n");
								
		if( !me->is_fighting() )
		return notify_fail("只有战斗中才能召唤护驾！\n");

		message_vision(HIB"$N"HIB"喃喃地念了几句咒语，双手一挥，一团烟雾自地底升起！\n\n"NOR, me);
		message_vision("		"BMAG YEL"★梦魇召唤★\n\n"NOR,me);
	
		seteuid(getuid());
		soldier = new("/obj/npc/mengyan_guard");
		soldier->move(environment(me));
		soldier->invocation(me, 400);
		soldier->set("possessed", me);
		soldier->set("combat_exp", me->query("combat_exp"));
		"/feature/nada"->reset_npc(soldier);
		soldier->full_me();
				
		me->perform_busy(perform["self_busy"]);
		me->set("timer/pfm/pfm_r1",time());
		me->set("timer/pfm/"+p_name,time());
		
		F_ABILITY->add_pfm_r1_expertise(me, p_name,1);
		F_ABILITY->add_pfm_r1_memorized(me, p_name, -1);
		
		return 1;
}

