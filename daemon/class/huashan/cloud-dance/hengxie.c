// Silencer@fengyun	June.2005
// + 100 dodge.100 parry.

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
    		return notify_fail("只有华山弟子可以使用『疏影横斜』\n");
    
    	cloud = me->query_skill("cloud-dance",1);
    	
    	if (F_LEVEL->get_level(me->query("combat_exp")) < 100)
    		return notify_fail("疏影横斜需要经验等级100以上才能使用。\n");
    	
    	if (cloud < 200) 
    		return notify_fail("疏影横斜至少需要200级的幻风飘云舞。\n");
    	    	
    	if( !target ) target = offensive_target(me);
    	if( !target||!target->is_character()||!me->is_fighting(target) )
        	return notify_fail("疏影横斜只能在战斗中使用。\n");
    	
    	if (cloud > 200) cloud = 200;
    	
    	if (ANNIE_D->check_buff(me,"pseudo-busy"))
    		return notify_fail("你现在的身法不适合舞蹈。\n");
    	
    	if (me->query("atman")< 50)
    		return notify_fail("至少需要50点魔力。\n");
    	if (userp(me))	me->add("atman",-50);
    	me->force_status_msg("atman");
    			
    	level = F_ABILITY->check_ability(me,"3_d_damage",3)*5;
    	    	
    	team1 = me->query_team();
    	if (!team1 || sizeof(team1)<2)	team1 = ({ me });
    	msg = WHT"
几分随意，几分凌乱，些须又有几分寂寥，$N顾影自怜，长裙舞动，但见人似
静似动，月忽明忽暗，$N莲步微挪，如风如歌，芳堂下月盈庭，踏碎横斜疏影。\n"NOR;

		message_vision(msg, me);
	
		// + 100 dodge.	100 parry
		team = filter_array(team1,(: present($1,environment($2)) :),me);
		num = sizeof(team);	
		for (i=0; i<num; i++) {
			if (ANNIE_D->check_buff(team[i],"hs_dodgeup")) continue;
			buff =
				([
					"caster":me,
					"who":	team[i],
					"type": "hs_dodgeup",
					"att": "bless",
					"name": "幻风飘云舞·疏影横斜",
					"time": 10 + F_ABILITY->check_ability(me,"3_d_duration",3)*2,
					"buff1": 	"apply/dodge",
					"buff1_c": 	cloud/2,
					"buff2":  "apply/damage",
					"buff2_c":  level,
					"buff_msg":"",
				]);
			ANNIE_D->buffup(buff);
			tell_object(team[i],YEL"但觉暗香流动，花笑语添，你的脚步轻快起来。\n"NOR);
			tell_object(team[i],YEL"（有效闪避增加"+(cloud/2)+"）\n"NOR);
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


