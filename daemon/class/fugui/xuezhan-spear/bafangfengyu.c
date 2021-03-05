#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	int tmp, timer, duration, i;
	object *team, *team1;
	mapping buff;
	
	extra = me->query_skill("xuezhan-spear",1);
	tmp = me->query_skill("hawk-steps",1);
	
	if(me->query("class")!="fugui")
    		return notify_fail("只有富贵山庄弟子才能使出『八方风雨会中州』\n");
	
	dodskill = (string) me->query_skill_mapped("dodge");
	if ( dodskill != "hawk-steps")
		return notify_fail("『八方风雨会中州』需要鲲鹏步法的配合！\n");
	if ( userp(me) && me->query_skill_mapped("force") != "skyforce")
		return notify_fail("『八方风雨会中州』需要碧空心法的配合！\n");
	
	if ( extra < 190 || tmp < 160 || me->query_skill("skyforce",1) < 160) 	
		return notify_fail("需要190级的血战枪法、160级的鲲鹏步法和160级的碧空心法！\n");
			
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("『八方风雨会中州』只能对战斗中的对手使用。\n");
	
	if (extra>=250) timer = 20;
	else if (extra >=210)	timer = 30; 
	else	timer = 40;
				
	duration = me->query("timer/pfm/bafang")+timer-time();
	if (duration>0)
    		return notify_fail("『八方风雨会中州』需要"+chinese_number(duration)+"秒后才能再次使用。\n");

	tmp=tmp/2;	

	if (ANNIE_D->check_buff(me,"fg-afo")>0) {
		ANNIE_D->debuff(me,"fg-afo");		
		team1 = me->query_team();
		if (pointerp(team1) && sizeof(team1)>1) {
			team = filter_array(team1,(: present($1,environment($2)) :),me);
			if (pointerp(team) && sizeof(team)>1) {
				for (i=0;i<sizeof(team);i++){
					if (team[i]==me)	continue;
					if (ANNIE_D->check_buff(team[i],"fg-afo-bffy"))	continue;
					if (team[i]->query("class")=="fugui")	continue;
					buff =
						([
							"caster":me,
							"who": team[i],
							"type":"fg-afo-bffy",
							"att":"bless",
							"name":"碧空心法·傲天诀",
							"buff1":"pfm/fg-afo-bffy",
							"buff1_c":me->query_skill("xuezhan-spear",1),
							"time":  30,
							"buff_msg": "",
						]);
					tell_object(team[i],BGRN + HIW+me->name(1)+BGRN + HIW"向你笑了笑，你的心中忽然又充满了信心。\n"NOR);
					ANNIE_D->buffup(buff);
				}
			}
		}
	}	

	target->set_temp("no_check_pfm_win",1);
	
//	me->add_temp("apply/attack",tmp);
    msg = HIR "\n\n$N大喝一声，漫天矛影中赫然使出『血战枪法』中的雷霆一击『--八方--风雨--会中州--』\n"NOR;
    message_vision(msg, me, target);
    
    msg=HIR"★休门★\n$N手中$w"+HIR"由缓至快向$n"+HIR"刺来！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);
	
    msg = HIR  "★伤门★\n$N挥舞$w"NOR+HIR",化作漫天矛影,当空刺向$n！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "★杜门★\n$N将$w"NOR+HIR"灌满真力,硬生生便朝$n"NOR+HIR"砸了过来！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "★景门★\n但见$N手中$w"NOR+HIR"幻化出千万条银蛇,漫天攒动,扑向$n！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "★惊门★\n$N将$w"NOR+HIR"舞得虎虎生风,卷起一波又一波滔天巨浪，飞向$n！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);	
    msg = HIR  "★开门★\n$N奋起神威,手中$w"NOR+HIR"大开大阖,旋风般朝$n"+HIR"袭了过来！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "★生门★\n$N断喝一声,手中$w"NOR+HIR"迅如奔雷快如电掣,当胸捅向$n！" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIW  "★死门★\n$w"NOR+HIW"划出一道超出任何世俗之美的弧线,宛如刀刃般划过$n"NOR+HIW"的面门！" NOR;
	me->add_temp("apply/attack",tmp*2);
	me->add_temp("apply/damage",extra);	
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-tmp*2);
        me->add_temp("apply/damage",-extra);
        me->set("timer/pfm/bafang",time()); 
     
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

        
        
        
        me->perform_busy(4);
	return 1;
}
