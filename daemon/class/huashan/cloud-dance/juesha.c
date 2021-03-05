// Silencer@fengyun	June.2005
// 提高+100 attack

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    	int extra, bonus, cloud, num, i, level;
    	string msg;
    	object *team, *team1;
    	mapping buff;
    	
		if (me->query("class") != "huashan") 
    		return notify_fail("只有华山弟子可以使用『九遁绝杀』\n");
    
    	cloud = me->query_skill("cloud-dance",1);
    	
		if (F_LEVEL->get_level(me->query("combat_exp")) < 110)
    		return notify_fail("九遁绝杀需要经验等级110以上才能使用。\n");
    	
    	if (cloud < 200) 
    		return notify_fail("九遁绝杀至少需要200级的幻风飘云舞。\n");

    	if( !target ) target = offensive_target(me);
    	if( !target||!target->is_character()||!me->is_fighting(target) )
        	return notify_fail("九遁绝杀只能在战斗中使用。\n");
    	
    	if (ANNIE_D->check_buff(me,"pseudo-busy"))
    		return notify_fail("你现在的身法不适合舞蹈。\n");
    	
			if (me->query("atman")< 50)
    		return notify_fail("至少需要50点魔力。\n");
    	if (userp(me))	me->add("atman",-50);
    	me->force_status_msg("atman");
    		    	
    	if (cloud > 200) cloud = 200;
    	level = F_ABILITY->check_ability(me,"3_d_damage",3)*5;
    	
    	team1 = me->query_team();
    	if (!team1 || sizeof(team1)<2)	team1 = ({ me });
    	msg = HIR"
$N仰首望天，静立半晌，陡然放歌起舞，舞姿愈转愈快，无半点乐声，但竟
仿佛两军决战时，声动天地，屋瓦若飞坠，徐而察之，有金鼓声，剑弩声，人马
辟易声、金骑蹂践争项王声！\n"NOR;

		message_vision(msg, me);
		
		team = filter_array(team1,(: present($1,environment($2)) :),me);
		num = sizeof(team);	
		for (i=0; i<num; i++) {
			if (ANNIE_D->check_buff(team[i],"hs_atkup"))continue;
			buff =
				([
					"caster":me,
					"who":	team[i],
					"type": "hs_atkup",
					"att": "bless",
					"name": "幻风飘云舞·九遁绝杀",
					"time": 10 + F_ABILITY->check_ability(me,"3_d_duration",3)*2,
					"buff1": "apply/attack",
					"buff1_c": cloud/2,
					"buff2":  "apply/damage",
					"buff2_c":  level,
					"buff_msg":"",
				]);
			ANNIE_D->buffup(buff);
			tell_object(team[i],YEL"始而奋，继而恐，涕泣之无从也，浩然之气充盈心中！。\n"NOR);
			tell_object(team[i],YEL"（有效攻击增加"+(cloud/2)+"）\n"NOR);
			if (level)	tell_object(team[i],YEL"（伤害力增加"+(level)+"）\n"NOR);
	    	}
	    	
	        	buff =
			([
				"caster":me,
				"who":	 me,
				"type": "pseudo-busy",
				"att":  "curse",
				"name": "舞蹈中",
				"time":  6,
				"buff1": "pseudo-busy",
				"buff1_c": 1,
				"buff_msg": "",
				"condition_type":  "<身法迟钝>",
				"warn_msg":"",
				"disa_type": 0, 
			]);
	    	ANNIE_D->buffup(buff);	
	    	
	    	return 1;
	}
