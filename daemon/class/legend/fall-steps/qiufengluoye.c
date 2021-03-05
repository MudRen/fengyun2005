#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	
	string msg, type;
	int extra;
	int mod, i, n, t, skill, rate;	
	object *enemy, *enemy_all;
	
	if (me->query("class")!="legend")
		return notify_fail("秋风落叶为铁雪特技。\n");
		
	if(me->query_temp("pfm/luoyeqiufeng")+ 2 > time())
		return notify_fail("你刚刚施展过秋风步的特技，还没喘过气来。\n");
	
	extra = me->query_skill("fall-steps",1);
	
	skill = me->query_skill("six-sense",1);
	
	if (skill < 200 || extra <150) 
		return notify_fail("『秋风落叶』需要200级的六灵暗识和150级的秋风步！\n");
	
	if (ANNIE_D->check_buff(me,"tx-turtle-stance"))
		return notify_fail("你现在的身法纯属守势，无法使用灵活多变的秋风落叶。\n");
		
	if (!me->is_fighting())
		return notify_fail("『秋风落叶』只能对战斗中的对手使用。\n");
	
	enemy_all = me->query_enemy();
	
	enemy = filter_array(enemy_all, (: !$1->is_busy():));
	
	if (!(n = sizeof(enemy)))
		return notify_fail("敌人都已经在忙乱中了，快抓紧时间攻击吧。\n");
	else
		n = ( skill>= 230) ? 5: ((skill-190)/10+1) ;
	
	rate = 250; 
	if (me->query_temp("pfm/legend_berserk")) rate = 200;
	
	message_vision(HIY"$N"+HIY"脚踏八方，身形如秋风中的落叶，飘渺不定！\n"NOR,me,target);
		
	for (i=0; i<n ; i++)
	{
		if (i>sizeof(enemy)-1)	continue;
		if(enemy[i]->is_busy()) continue;
		
		mod = COMBAT_D->can_busy(me, enemy[i], "fall-steps");	
		if (!mod)	mod = 10000;
		
		if (COMBAT_D->do_busy_attack(me, enemy[i], "fall-steps/luoyeqiufeng", "step", rate, mod))
		{
			message_vision(YEL"结果$N被扰得眼花潦乱，应接不暇！\n"NOR,enemy[i]);
			enemy[i]->force_busy(3);
			enemy[i]->set_temp("busy_timer/fall-steps",time());
		} else
		{
			msg = HIR"可惜$N"+HIR"看出了$n"+HIR"的身法，向$p"+HIR"倏然攻击！"NOR;
			me->add_temp("cant_dodge",1);
			me->add_temp("cant_parry",1);
			COMBAT_D->do_attack(enemy[i],me,TYPE_PERFORM,msg); 
			me->add_temp("cant_dodge",-1);
			me->add_temp("cant_parry",-1);
		}
	}	
	me->set_temp("pfm/luoyeqiufeng",time());
		
	return 1;
}
