// silencer@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object friend)
{
		string msg;
		int skl_me, skl_you, extra_me, extra_you,i,j,k;
		object you,ob,target,*myteam;
	
		if (userp(me) && me->query_skill("yizhichan",1)< 100)
			return notify_fail("参合指需要１００级一指禅法。\n");
			
		target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
			return notify_fail("参合指只能对战斗中的对手使用。\n");
        
    	skl_me= me->query_skill("yizhichan",1);
		extra_me= me->query_skill("unarmed");
                           
	        msg = BBLU + HIY"
$N"NOR+ BBLU + HIY"眼中带着淡淡的倦意，宛若远山含笑迷蒙，以食指代天，中指代人，
无名指代地，击出一指参合，无空、无活、无生、无命！\n\n" + NOR;

        me->add_temp("apply/attack",skl_me);
        me->add_temp("apply/damage",extra_me);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-skl_me);
        me->add_temp("apply/damage",-extra_me);
		me->perform_busy(2);
		return 1;

}


