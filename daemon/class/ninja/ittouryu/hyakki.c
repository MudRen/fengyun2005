// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,adjust;
        int count;
        object weapon,targetweapon;
        extra = me->query_skill("ittouryu",1);
        
        if ( extra < 150) return notify_fail("『百鬼夜狂』需要150级的一刀流剑术！\n");

        if( !target ) target = offensive_target(me);    
        if( !target	
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("『百鬼夜狂』只能对战斗中的对手使用。\n");
 	
 		if(userp(me) && me->query("bellicosity")<1 
 			&& me->query_temp("pfm/hyakki")+ 120 > time())
 			return notify_fail("你的杀气已尽，无法内再出这一招。\n");
 		
 		if (userp(me))
 			me->set("bellicosity",0);
 		
 		me->set_temp("pfm/hyakki",time());
 		
        msg = HIR  "\n
$N突然仰天长嚎，头发如钢针般根根直竖，依稀看到$N的瞳仁正在变成红色。
$N猛地扑向$n，发动了一刀流的最强招『百鬼夜狂』，将$n笼罩在一片刀光中。

" NOR;
		message_vision(msg, me, target);
		
	count=0;
	
	adjust = 440-me->query_skill("blade")>0?0:440-me->query_skill("blade");
//	message_vision("adjust is "+(string)adjust+"\n",me);	
//	me->set_temp("timer/hyakki",time());
	
	target->set_temp("no_check_pfm_win",1);
	me->add_temp("apply/damage",extra);
	me->add_temp("apply/attack", adjust);
	
        msg = HIC  "百鬼袭！！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if(target->query_temp("damaged_during_attack")) count++;
        msg = HIG  "百鬼冲！！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if(target->query_temp("damaged_during_attack")) count++;
        msg = HIB  "百鬼碎！！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if(target->query_temp("damaged_during_attack")) count++;
        msg = HIY  "百鬼突！！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if(target->query_temp("damaged_during_attack")) count++;
        msg = HIM  "百鬼坠！！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if(target->query_temp("damaged_during_attack")) count++;
        msg = HIW  "百鬼斩！！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if(target->query_temp("damaged_during_attack")) count++;
        msg = HIR  "灭！！！！" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        if(target->query_temp("damaged_during_attack")) count++;
 	
 	msg="\n\n";
 	
 	me->add_temp("apply/damage",-extra);
 	me->add_temp("apply/attack", -adjust);
 	
 	if(!count)
 		msg+=HIB"$n好整以暇地闪过$N所有的攻击，冷冷地说：“该轮到我了！”。\n"NOR;
 	else if(count<4)
 		msg+=HIY"突然，一蓬鲜血激射，随之$n破出刀光，捂着殷红的衣襟，退向一侧。\n"NOR;
 	else if(count<7)
 		msg+=HIM"突然，一蓬鲜血激射，随之$n破出刀光，捂着殷红的衣襟，口中撕吼着：“魑魅魍魉...”,
$N接道：“百鬼夜狂”。\n"NOR;
	else
		msg+=HIR"突然，一蓬鲜血激射，随之$N破出刀光，背对着血泊中的$n傲慢地说道：“笑止千万！”\n"NOR;
	message_vision(msg,me,target);
	
	 if (objectp(target))	{
	 	 target->delete_temp("no_check_pfm_win");
        	COMBAT_D->win_lose_check(me,target,1);
	}
	
	if (objectp(target))	{
		if (count>3) target->force_busy(3);
			else target->force_busy(count);
	}
	
	if (count>5) me->perform_busy(3);
		else me->perform_busy(8-count);
	
        return 1;
}


