// Silencer@fengyun	June.2005
// 提高critical_strike 几率为原来的3倍，i.e.

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
    		return notify_fail("只有华山弟子可以使用『梅心惊破』\n");
    
    	cloud = me->query_skill("cloud-dance",1);
    	
    	if (F_LEVEL->get_level(me->query("combat_exp")) < 90)
    		return notify_fail("梅心惊破需要经验等级90以上才能使用。\n");
    	
    	if (cloud < 200) 
    		return notify_fail("梅心惊破至少需要200级的幻风飘云舞。\n");
    		
    	if( !target ) target = offensive_target(me);
    	if( !target||!target->is_character()||!me->is_fighting(target) )
        	return notify_fail("梅心惊破只能在战斗中使用。\n");
    	
    	if (ANNIE_D->check_buff(me,"pseudo-busy"))
    		return notify_fail("你现在的身法不适合舞蹈。\n");
    	
			if (me->query("atman")< 50)
    		return notify_fail("至少需要50点魔力。\n");
    	if (userp(me))	me->add("atman",-50);
    	me->force_status_msg("atman");
    		    	
    	cloud = 10;
    	cloud = cloud * ( 100 + F_ABILITY->check_ability(me,"jingpo_add")*5)/100;
    	level = F_ABILITY->check_ability(me,"3_d_damage",3)*5;
    		
    	team1 = me->query_team();
    	if (!team1 || sizeof(team1)<2)	team1 = ({ me });
    	msg = HIY"
空山静，鸟语惊，远方传来轻扬的笛声，似低似高地起承转合，$N一时心神惧醉，
伴着娓娓的笛声，翩翩起舞，笛声突起变化，萧萧煞煞，仿佛金戈铁马，$N
身影陡转，似癫似狂！萧杀的舞影之中，落叶秋花漫天飘扬。。。\n"NOR;

		message_vision(msg, me);
	
		team = filter_array(team1,(: present($1,environment($2)) :),me);
		num = sizeof(team);	
		for (i=0; i<num; i++) {
			if (ANNIE_D->check_buff(team[i],"hs_resistup")) continue;
			buff =
			([
				"caster":me,
				"who":	team[i],
				"type": "hs_resistup",
				"att": "bless",
				"name": "幻风飘云舞·梅心惊破",
				"time": 10 + F_ABILITY->check_ability(me,"3_d_duration",3)*2,
				"buff1": "resistance/kee",
				"buff1_c": cloud,
					"buff2":  "apply/damage",
					"buff2_c":  level,
				"buff_msg":"",
			]);
			ANNIE_D->buffup(buff);
			tell_object(team[i],YEL"笛声三弄，梅心惊破，你如坠梦中，身随舞动，无可觅迹。\n"NOR);
			tell_object(team[i],YEL"（对气血伤害抵抗力增加10%）\n"NOR);
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
