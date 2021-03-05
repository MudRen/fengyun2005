// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra=0,extra2=0,i;
	object ob,*obs;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("［四爪天龙］只能对战斗中的对手使用。\n");
	if(!pointerp(obs=me->query_team()) || !me->is_team_leader())
		return notify_fail("只有队伍领袖才可以发动此式！\n");
// this loop just checking, make sure everyone use  tianlongwhip
	for(i=0;i<sizeof(obs);i++)
	{
	if(!obs[i]) return notify_fail("你需要从新组合队伍。\n");
	if(environment(obs[i]) != environment(me)) return notify_fail("你队伍成员不全在你身边。\n");
	if(!obs[i]->query_skill("tianlongwhip")) return notify_fail("你队伍中有人不会梵音天龙鞭法。\n");
	if(!objectp(ob=obs[i]->query_temp("weapon"))) return notify_fail("你的队伍中有人没有兵器！\n");
	if(ob->query("skill_type") != "whip") return notify_fail("你的队伍中有人没有用鞭法！\n");
	if(obs[i]->query_skill_mapped("whip") != "tianlongwhip") return notify_fail("你的队伍中有人没有用梵音天龙鞭法！\n");
	}	
	if(sizeof(obs) !=4) return notify_fail("［四爪天龙］只能四个人的队伍才可以发动！\n");

 	msg = HIR "\n\n"+
	obs[0]->name()+"手中的"+(obs[0]->query_temp("weapon"))->name()+"大力从上往下抽出，\n"+
        obs[1]->name()+"手中的"+(obs[1]->query_temp("weapon"))->name()+"展开，拦腰横扫，\n"+
        obs[2]->name()+"手中的"+(obs[2]->query_temp("weapon"))->name()+"鞭随身起，撩向下盘，\n"+
        obs[3]->name()+"手中的"+(obs[3]->query_temp("weapon"))->name()+"贯力直刺，\n"+
"同时使用梵音天龙鞭法，高喝道：四－－爪－－天－－龙！！\n手中的家伙同时击到！！" NOR;
	for(i=0;i<sizeof(obs);i++)
        {
	extra += (int)obs[i]->query_skill("whip");
	extra2 += (int)obs[i]->query_temp("apply/damage") + ((int)obs[i]->query_str())*((int)obs[i]->query_str()) / 10;
	}
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra2);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra2);
	for(i=0;i<sizeof(obs);i++)
	{
	obs[i]->start_busy(2);
	target->kill_ob(obs[i]);
	}
	return 1;
}
