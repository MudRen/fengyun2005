#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int extra,i,bonus;
        object *inv,skin;

        if (!me->query("fy41/luori_changrijiangjin") && userp(me))
                return notify_fail("你所选用的武功中没有这种必杀技．\n");

        if (userp(me) && me->query_skill("luoriquan") < 220)
                return notify_fail("「长日将尽」需要220级落日神拳。\n");

        extra = me->query_skill("unarmed");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「长日将尽」只能对战斗中的对手使用。\n");
        
        if (!me->query_condition("drunk") && userp(me))
                return notify_fail("你一丝醉意也没有，怎样施展「长日将尽」？\n");

        if (userp(me))
        {
                inv = all_inventory(me);
                for (i=0; i<sizeof(inv);i++ )
                {
                        if (!inv[i]->query("liquid/name"))      continue;
                        if (inv[i]->query("liquid/type") != "alcohol")  continue;
                        skin=inv[i];
                }
                if (!skin)
                        return notify_fail("身上没有酒器，如何能够尽兴施展「长日将尽」？\n");
                msg = HIG "\n$N"HIG"仰天灌下一口"+skin->query("liquid/name")+HIG"，一把将"+skin->name()+HIG"抛开，借着酒兴攻向"HIG"$n，纵声长歌：\n" NOR;
                destruct(skin);
        }
        else
                msg = HIG "\n$N仰天灌下一口明驼瀚海，一把将青葫芦抛开，借着酒兴攻向"HIG"$n，纵声长歌：\n" NOR;

        if (userp(me))
                bonus = me->query_condition("drunk");
        else
                bonus = me->query_skill("luoriquan",1);

        bonus *= 2;

        me->add_temp("apply/attack",bonus);
        me->add_temp("apply/damage",extra/3);
		target->set_temp("no_check_pfm_win",1);
		
        message_vision(msg,me,target);
        msg = HIM    "　　　　　　　　一身托天地，\n　　　　　　　　　　　　　　　　醒醉寄浮舟。\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        target->set_temp("skip_damage_record",1);
        
        msg = HIC  "　　　　　忽然酹中流，\n　　　　　　　　　　　　　扣舷发狂歌。\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "　　　　　　　　歌尽续长笑，\n　　　　　　　　　　　　　　　　浪子意如何？\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIW   "　　　　　回首来时路，\n　　　　　　　　　　　　　灼灼日已没！\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIR   "\n　　　　－－－长－－－日－－－将－－－尽－－－　\n\n" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);

        me->add_temp("apply/attack",-bonus);
        me->add_temp("apply/damage",-extra/3);

		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

        me->perform_busy(3);
        return 1;
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/

