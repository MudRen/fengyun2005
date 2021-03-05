// annie 07.2003
// dancing_faery@hotmail.com
// desc： 星野变洹白式.改

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
inherit F_ANNIE;

int perform(object me, object target)
{
	string msg,temp1;
	object weapon,*pros,shadow,newweapon;
	int attack_points, dodge_points,skill,count,i,j,k,level,num1,duration;
	int mm;
	
	if (me->query("class")!="moon" && userp(me))
		return notify_fail("唯有皓月宫弟子才能使用『风漏飞烟』\n");
	
	skill = me->query_skill("starrain",1);
	if (skill < 150)
		return notify_fail("『风漏飞烟』需要至少150级的寒星雨觞。\n");

	if (me->query_skill_mapped("force") != "snowforce")
       	return notify_fail("『风漏飞烟』需以冷雪心经发动。\n");	// limit enforce

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『风漏飞烟』只能对战斗中的对手使用。\n");

/*	风漏飞烟?上卷	starrrain_fengloufeiyan_1	L100	1M
	风漏飞烟?上卷	starrrain_fengloufeiyan_2	L150	4M
	风漏飞烟?上卷	starrrain_fengloufeiyan_3	L200	6.4M

*/
	level = me->query("annie/starrain_liulongbingjia");
	if (!userp(me))
		level = 5;
	
	weapon = me->query_temp("weapon");
	count = weapon->query_amount();
	if (count < 6)
		return notify_fail("『风漏飞烟』至少需要6枚暗器。\n");

	duration = me->query("timer/pfm/fengloufeiyan")+ 20 - time();
	if (duration>0)
		return notify_fail("风漏飞烟需"+duration+"秒后才能再次使用。\n");
	
	me->set("timer/pfm/fengloufeiyan",time());

	if (!target->is_busy())	// target不在busy状态时获得extra attack bonus.
		me->add_temp("apply/throwing",me->query_skill("throwing"));
		
	attack_points = COMBAT_D->skill_power(me, SKILL_USAGE_ATTACK);
	dodge_points = COMBAT_D->skill_power(target, SKILL_USAGE_DODGE);	// 计算中对方相当于不在busy中	
		
	if (!target->is_busy())
		me->add_temp("apply/throwing",-me->query_skill("throwing"));

	k=0;
	for (i=0; i<6; i++)
		if (random(attack_points+dodge_points) > dodge_points)	// pass
			k++;

	if(wizardp(me) && (string)me->query("env/combat1")=="verbose" ) {
		write(WHT"atk = "+ attack_points + ", dp = " + dodge_points + "\n"NOR);
		mm = dodge_points*100/(attack_points+dodge_points);
		write(WHT" missing chance = " + mm + "%\n"NOR);
		write(WHT" all miss chance = " + mm*mm*mm*mm/10000*mm*mm/10000+ "/100 %\n");
	}
	
//	message_vision("K:"+k+"\n",me,target);

	j=0;
	if ( F_ABILITY->check_ability(me,"flfy_add")< random(10))
	{
		for (i=0; i<k; i++)
			if (random(attack_points+dodge_points) > dodge_points)	// pass
				j++;
	}					
	else
		j=k;

	if (wizardp(me))
		message_vision("AP:"+attack_points+"  DP:"+dodge_points+"\n",me,target);
	
	msg = HIY"只听$N"HIY"一声清喝，向后疾退三尺，双袖乍然抖开，袖中银芒闪动，数点寒光疾驰$n！\n"NOR;
	message_vision(msg,me,target);

	switch (j)
	{
	case 0:
		msg = HIY"$n"HIY"冷笑一声，哼道：萤火之光，也与皓月争辉！
$n"HIY"一折一拍，也不见用什么手法，寒光就向$N"HIY"倒卷而回。"NOR;
		break;
	case 1:
		msg = HIY"$n"HIY"催动真气，挥手间将五枚暗器击落，正在暗自得意，不防却为最后一道寒光所伤！"NOR;
		break;
	case 2:
		msg = HIY"$n"HIY"提气纵起，堪堪避过正面来袭的三点寒星，又在空中一转，避过身后疾
风，身形优雅的落向地面，却没料到还有两枚暗器正在落脚之处等着$n！"NOR;
		break;
	case 3:
	case 4:
	case 5:
		msg = HIY"$n"HIY"冷哼一声，斜斜在身前划了一个圆弧，三点寒光应声而落。
另三枚暗器却似有灵性一般，越到$n"HIY"身后又转折飞回，射入$n"HIY"背心！"NOR;
		j = 3;
		break;
	case 6:
		msg = HIY"$n"HIY"大惊失色，斜走横飞，纵横腾挪，但总闪不过暗器的追击。"NOR;
		break;
	}
	
	if (level >= 2 && j == 0 )
		msg = HIY"$n"HIY"挑挑眉毛，扬手拍出一道劲风，将暗器尽数击落。\n"NOR;
	
	message_vision(msg+"\n",me,target);

	me->set_temp("annie/perform_starrain",1);
	target->set("timer/liulongbingjia",time());
	
	if (j > 0)
	{
		me->add_temp("apply/damage",-skill/3);		// -150

		pros = target->query_temp("protectors");
		target->delete_temp("protectors");
		target->add_temp("cant_parry",1);
		target->add_temp("cant_dodge",1);
		target->add_temp("cant_counter",1);
		
		for (i=0; i<j ;i++ )
			COMBAT_D->do_attack(me,target, TYPE_PERFORM, " ");
		
		if (target)
		{
			target->add_temp("cant_parry",-1);
			target->add_temp("cant_dodge",-1);
			target->add_temp("cant_counter",-1);
			target->set_temp("protectors",pros);
		}
		me->add_temp("apply/damage",skill/3);
	}
	else
	{
		// j == 0
		if (level < 2 || !target->is_busy())
		{
			// 修准工作方式：
			
			seteuid(getuid());
			shadow=new("/obj/npc/shadefigure");
			shadow->changeshape(me);		
			annie_mimic(me,shadow);
			sscanf(file_name(weapon),"%s#%d",temp1,num1);
			newweapon=new(temp1);
			newweapon->move(shadow);
			newweapon->wield();

			shadow->move(environment(me));
			shadow->set_temp("fight_to_death",1);

			me->add_temp("cant_parry",1);
			me->add_temp("cant_dodge",1);
			me->add_temp("cant_counter",1);
			
			pros = me->query_temp("protectors");
			me->delete_temp("protectors");
			
			for (i=0; i<6 ;i++)
				COMBAT_D->do_attack(shadow,me, TYPE_REGULAR, " ", "刺伤！");	 //  not TYPE_PERFORM.

			me->receive_damage("kee",1,target);

		   	if (shadow)
		   		destruct(shadow);
			if (me){
				me->add_temp("cant_parry",-1);
				me->add_temp("cant_dodge",-1);
				me->add_temp("cant_counter",-1);
				me->set_temp("protectors",pros);
			}			
		}
	}

	
	if (userp(me))	weapon->add_amount(j-6);	// 6 

	me->delete_temp("annie/perform_starrain");
	me->perform_busy(2);
	return 1;
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/

