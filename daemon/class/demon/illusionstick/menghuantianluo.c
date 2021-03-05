#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int do_pfr(object me, object target,int loc);

int do_pfm(object me, object target,int idx,int loc)
{
	string msg;
	int l;

	string *style = ({
"火龙吞野－－$N抡动手中$w，棍风呼啸，打向$n的$l！",
"凤羽翩跹－－$N手中$w化做棍影重重，将$n团团围住！",
"虎止咆野－－$N向前一纵，手中$w狂舞，向$n猛扑过去！",
"豹影风行－－$N欺身急进，手中$w头尾齐出，分打$n的两处要害！",
"断鹤续凫－－$N手中$w一顿，暗蓄内力，点向$n的$l！",
"望月仙猿－－$N身形连纵连跃，手中$w威势陡增，连连向$n打去！",
"盘蛇吐信－－$N身影绕着$n连续晃动，手中$w连发，扫向$n的$l！",
"飞鹰搏兔－－$N身形纵起，手中$w自上而下，迅猛无比，砸向$n的$l！"});

	if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me))
		return 0;

	msg = HIY+style[idx]+NOR;

	me->stop_busy();
	l = target->query("kee");
    me->add_temp("apply/attack", idx * me->query_skill("illusionstick",1)/3);
    COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
    me->add_temp("apply/attack", -idx * me->query_skill("illusionstick",1)/3);
	if (me->is_busy())
	{
		loc += 1;
		if (loc < 3)
		{
			message_vision(HIG"$N凝定心神，劲力暗送，迫开$n，转眼间重夺先机。\n"NOR,me,target);
			me->stop_busy();
		}
	}
	else if (!target->query_temp("damaged_during_attack"))
		loc += 1;
	me->perform_busy(3);	
	if (target->query("kee") < 1)
	{
		message_vision(HIY"\n$N挥汗如雨，力难以继，身形渐渐稳定下来。\n"NOR,me,target);
		return 1;		// Unconcious/Dead
	}
	if (loc >= 3)
	{
		message_vision(HIY"\n$N连连失手，顿无凭倚，身形渐渐稳定下来。\n"NOR,me,target);
		return 1;		// no enough force
	}
	if (me->query("force") < 50)
	{
		message_vision(HIY"\n$N挥汗如雨，力难以继，身形渐渐稳定下来。\n"NOR,me,target);
		return 1;		// no enough force
	}
	me->add("force",-50);
	
	if (idx == 7)
	{
		message_vision(HIG"\n$N独自使过一轮「万类霜天竟自由」，身形渐渐稳定下来。\n\n"NOR,me,target);
		call_out("do_pfr",1,me,target,loc);
		return 1;
	}

	do_pfm(me,target,idx+1,loc);
}


int do_pfr(object me, object target,int loc)
{
	if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me))
		return 0;
	message_vision(HIG"$N深吸了一口长气，身形一拢即分，再次化作一片人影环在$n身侧，"NOR,me,target);
	if(random(target->query("combat_exp")) < random(me->query("combat_exp")))
	{
		message_vision(HIG"\n$n但觉眼花缭乱，依然没有看出任何破绽。\n\n"NOR,me,target);
		me->perform_busy(2);
		target->perform_busy(1);
		call_out("do_pfm",1,me,target,loc);
	}
	else
		message_vision(HIG"\n$n一声冷笑，向无人处虚虚一击，$N幻象登时破去。\n\n"NOR,me,target);
	me->perform_busy(2);
	return 1;
}

int do_pfx(object me, object target)
{
	if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me))
		return 0;
	message_vision(HIY"$N陡然一声大喝，独自发动形意六合棍阵，使出了似是而非的一式「万类霜天竟自由」！\n"NOR,me,target);
	do_pfm(me,target,0,0);
	return 1;
}


int perform(object me, object target)
{
 	string msg;
 	int extra;
	
 	extra = me->query_skill("unarmed");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「梦幻天罗」只能对战斗中的对手使用。\n");

	message_vision(HIG"$N手中"+me->query_temp("weapon")->name()+HIG"在地上连连点击，身形渐散作七八个人影绕着$n，"NOR,me,target);

	if(random(target->query("combat_exp")) < (int)me->query("combat_exp"))
	{
		message_vision(HIG"\n看得$n只觉如处梦幻，目瞪口呆，难以置信。\n\n"NOR,me,target);
		target->perform_busy(1);
		me->perform_busy(2);
		call_out("do_pfx",1,me,target);
	}
	else
		message_vision(HIG"\n$n一声冷笑，向无人处虚虚一击，$N幻象登时破去。\n\n"NOR,me,target);
	me->perform_busy(2);
	return 1;
}

