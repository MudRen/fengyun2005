// Silencer@fengyun	June.2005
// + 200 force for everyone, 

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    	int extra, bonus, cloud, num, i;
    	int duration;
    	string msg;
    	object *team, *team1;
    	mapping buff;
    	
    	if (me->query("class") != "huashan") 
    		return notify_fail("只有华山弟子可以使用『雪里春信』\n");
    
    	cloud = me->query_skill("cloud-dance",1);
    	
		if (F_LEVEL->get_level(me->query("combat_exp")) < 70)
    		return notify_fail("雪里春信需要经验等级70以上才能使用。\n");
    	
    	if (cloud < 200) 
    		return notify_fail("雪里春信至少需要200级的幻风飘云舞。\n");
    		    	
    	duration = me->query("timer/pfm/hs_chunxin")-time() + 10;
    	if (duration>0)
       		return notify_fail("你还需要等待"+(duration)+"秒钟左右才能再次使用『雪里春信』\n");
    	
    	if (cloud > 200) cloud = 200;
    	
    	if( !target ) target = offensive_target(me);
    	if( !target||!target->is_character()||!me->is_fighting(target) )
        	return notify_fail("雪里春信只能在战斗中使用。\n");
    	    	
    	if (ANNIE_D->check_buff(me,"pseudo-busy"))
    		return notify_fail("你现在的身法不适合舞蹈。\n");
    	
    	if (me->query("force")< 100)
    		return notify_fail("雪里春信至少需要100点内力。\n");
    	if (userp(me))	me->add("force",-100);
    		
    	me->set("timer/pfm/hs_chunxin", time());
		
		// + 200 force for everyone, self = +100
		me->add_temp("pfm/free_perform",1);
		   		
    	msg = HIG"
残雪斑驳，小草吐翠，柳絮轻扬，香山春信匆匆。$N纤指三扣，燕燕轻盈，莺莺
娇软，是耶非耶？是真是幻？曼妙的舞姿，伴着轻柔的歌声：笑江梅、雪里开迟。
香风轻度，翠叶柔枝。与玉郎摘，美人戴，总相宜。。。。\n"NOR;

		message_vision(msg, me);
		
		team1 = me->query_team();
		if (!team1 || sizeof(team1)<2)	team1 = ({ me });
		    		
		team = filter_array(team1,(: present($1,environment($2)) :),me);
		num = sizeof(team);	
		for (i=0; i<num; i++) {
			if (team[i]->query("force") < team[i]->query("max_force")*2) {	
				if (team[i]->query("force") + cloud < team[i]->query("max_force") *2)
					team[i]->add("force",cloud);			
	    	} else
	    		team[i]->set("force", team[i]->query("max_force")*2);
	    	team[i]->force_status_msg("force");
	    	tell_object( team[i],YEL"生机渐盎，如春临大地，一股氤氲之气，缓缓流过你奇经八脉。\n"NOR);
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
    	me->perform_busy(1);
    	return 1;
}


