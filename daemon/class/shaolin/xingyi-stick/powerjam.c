// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i;
	string *style = ({
"龙形－－$N抡动手中$w，棍风呼啸，打向$n的$l！",
"凤形－－$N手中$w化做棍影重重，将$n团团围住！",
"虎形－－$N向前一纵，手中$w狂舞，向$n猛扑过去！",
"豹形－－$N欺身急进，手中$w头尾齐出，分打$n的两处要害！",
"鹤形－－$N手中$w一顿，暗蓄内力，点向$n的$l！",
"猿形－－$N身形连纵连跃，手中$w威势陡增，连连向$n打去！",
"蛇形－－$N身影绕着$n连续晃动，手中$w连发，扫向$n的$l！",
"鹰形－－$N身形纵起，手中$w自上而下，迅猛无比，砸向$n的$l！"});
	object ob,*obs;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［万类霜天竞自由］只能对战斗中的对手使用。\n");
	if(!pointerp(obs=me->query_team()) || !me->is_team_leader())
		return notify_fail("只有队伍领袖才可以发动此式！\n");
// this loop just checking, make sure everyone use 形意六合棍
	if(sizeof(obs) > 8 )
		return notify_fail("队伍最多八个人！！\n");
	
	for(i=0;i<sizeof(obs);i++)
	{
		if(!obs[i]) return notify_fail("你需要重新组合队伍。\n");
		if(environment(obs[i]) != environment(me)) return notify_fail("你队伍成员不全在你身边。\n");
		if(!obs[i]->query_skill("xingyi-stick")) return notify_fail("你队伍中有人不会形意六合棍法。\n");
		if(!objectp(ob=obs[i]->query_temp("weapon"))) return notify_fail("你的队伍中有人没有兵器！\n");
		if(ob->query("skill_type") != "staff") return notify_fail("你的队伍中有人没有用棍法！\n");
		if(obs[i]->query_skill_mapped("staff") != "xingyi-stick") return notify_fail("你的队伍中有人没有用形意六合棍法！\n");
	}	
	
	message_vision(HIY+"\n\n$N高喝一声：万－－类－－霜－－天－－竞－－自由！！\n立时发动了形意六合棍阵！\n\n",me);
	
	for(i=0;i<sizeof(obs);i++)
    {
		if (!obs[i]->is_fighting(target))	
			obs[i]->kill_ob(target);	
		
		msg = HIR +  style[i] + NOR;
		extra = obs[i]->query_skill("staff");
		extra *= (i+1);	
        obs[i]->add_temp("apply/attack", extra);
        obs[i]->add_temp("apply/damage", extra);
		
		COMBAT_D->do_attack(obs[i],target, TYPE_PERFORM,msg);
	
		obs[i]->add_temp("apply/attack", -extra);
		obs[i]->add_temp("apply/damage", -extra);
		obs[i]->start_busy(2);
	}
	
	return 1;
}
