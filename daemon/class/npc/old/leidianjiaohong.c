// annie 07.2003
// 冰镜七诀 
// 有些特别的team perform *snicker
// 初心者用．．．

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, bonus;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『雷电交轰』只能对战斗中的对手使用。\n");

	if (me->query_skill("chillblade",1) < 20)
		return notify_fail("『雷电交轰』需要至少20级的冰镜七诀。\n");
	
	if (me->query("gender") == "女性")
		return notify_fail("女子不适合施展刚猛无铸的『雷电交轰』。\n");

	weapon = me->query_temp("weapon");
	extra = me->query_skill("blade");

	msg = HIY"\n$N手中"+weapon->name()+HIY+"慢慢地挥出，剧烈颤动的刀锋封向$n，形如一片黑沉的刀云。\n"NOR;
	me->set_temp("annie/perform_ldjh",1);
	message_vision(msg,me,target);
    call_out("do_ldjh", 2, me,target,0,weapon,extra);
	me->perform_busy(2);

	return 1;
}

//  This is a no-busy extra hit
int do_team_perform(object me,object mate,object target,object weapon,object w2,int extra,int extra2)
{
	int a,b,ex;
	a = me->query_busy();
	b = mate->query_busy();
	me->stop_busy();
	mate->stop_busy();

	ex = extra + extra2;
	ex = ex/4;

	me->add_temp("apply/attack", ex);
	me->add_temp("apply/damage", ex);
	mate->add_temp("apply/attack", ex);
	mate->add_temp("apply/damage", ex);

	message_vision(HIW"\n光幕与刀云相错而过，刹时间合二为一，迅如夏夜雷电，轻若雨后初虹，直直向"+target->name()+"劈出！\n"NOR,me,mate);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM," ");
	COMBAT_D->do_attack(mate,target, TYPE_PERFORM," ");

	mate->add_temp("apply/attack", -ex);
	mate->add_temp("apply/damage", -ex);
	me->add_temp("apply/damage", -ex);
	me->add_temp("apply/attack", -ex);

	me->perform_busy(a);
	mate->perform_busy(b);

	return 1;
}

int do_ldjh(object me,object target,int count,object weapon,int extra)
{
	int i,extra2;
	object *team;
	object teammate,tweapon;
	if (me)
		me->set_temp("annie/perform_ldjh",0);
	if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me))
		return 0;
	if(!present(weapon,me)||weapon->query("equipped")!="wielded")
		return 0;

	if (me->query("class") != "moon")
		extra /= 2;

	if( pointerp(team = me->query_team()) )
		for (i=0; i<sizeof(team); i++)
		{
			if (!team[i]) continue;
			if (team[i] == me) continue;
			if (team[i]->query_temp("annie/perform_yhch_ldjh"))
			{
				teammate=team[i];
				if(teammate->is_fighting(target) && environment(target)==environment(teammate) && (tweapon = teammate->query_temp("annie/perform_yhch_ldjh_param1")) && present(tweapon,teammate) && weapon->query("equipped")=="wielded" && target == teammate->query_temp("annie/perform_yhch_ldjh_param2"))
				{
					extra2=team[i]->query_temp("annie/perform_yhch_ldjh");
					do_team_perform(me,teammate,target,weapon,tweapon,extra,extra2);
					return 1;
				}
			}
			if (team[i]->query_temp("annie/perform_yhch"))
			{
				me->set_temp("annie/perform_yhch_ldjh",extra);
				me->set_temp("annie/perform_yhch_ldjh_param1",weapon);
				me->set_temp("annie/perform_yhch_ldjh_param2",target);
				return 1;
			}
		}

/*
		while ( remove_call_out( "data_write_callback" ) != -1 ) {
			  TP( "Killing callout.\n" );
		}
*/
	//	+atk 225*3/4 = 169, +dmg = 150.
	i = me->query_busy();
	me->stop_busy();
	me->add_temp("apply/attack", extra*3/4);
	me->add_temp("apply/damage", extra*2/3);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,HIR"刀云中突发裂帛之声，一道寒光闪过，"+weapon->name()+HIR"已然雷霆霹雳般向$n破去！\n"NOR);
	me->add_temp("apply/damage", -extra*2/3);
	me->add_temp("apply/attack", -extra*3/4);
	me->perform_busy(i);
	return 1;
}
