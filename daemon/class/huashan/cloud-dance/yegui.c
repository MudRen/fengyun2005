// silencer@fy4 -------- this is the revive skill ------------
//	L150:『离人夜归』：(dodge.yegui):	在有尸体处ｒｅｖｉｖｅ，70％(L150)－90％(L200)

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{

		int cloud, extra, t, rate,stage;
		object victim, room;
		string victim_id;
		mapping buff;
	
    	if (me->query("class") != "huashan") 
    		return notify_fail("只有华山弟子可以使用『离人夜归』\n");
    
    	cloud = me->query_skill("cloud-dance",1);
    	extra = me->query_skill("hanmei-force",1);
    	
    	if (cloud < 150) 
    		return notify_fail("离人夜归至少需要150级的幻风飘云舞。\n");
    	    	
    	if (extra<150) 
    		return notify_fail("离人夜归至少需要150级的寒梅心法。\n");
    	    	
		if (userp(me) && !me->query("scroll/cloud-dance_yegui"))
			return notify_fail("你还没有悟出离人夜归的真谛，需要找到其密籍才行。\n");
			
    	if (me->query_skill_mapped("force") != "hanmei-force")
			return notify_fail("幻风飘云舞的舞技需要寒梅心法配合。\n");
	
		if( !target || !target->is_corpse())
			return notify_fail("离人夜归必须指定有效对象（遗体）。\n");
	
		if (!target->query("victim_player"))
			return notify_fail("离人夜归只能使用在玩家的遗体上。\n");
	
		if (!(victim_id = target->query("victim_id")))	
			return notify_fail("离人夜归不能使用在此无主身上。\n");

		if (target->query("already_revived")|| !target->query("real_death"))
			return notify_fail("这具尸体已经不能再重复使用离人夜归类的特技了。\n");
			
		victim = find_player(victim_id);
	
		if (!victim || !userp(victim))
			return notify_fail(victim_id+"不在风云世界内。\n");
				
		if( !victim ->is_ghost())
			return notify_fail("此人已经不在冥界了。\n");
	
		if (!mapp(victim->query("death")) || victim->query("death/half_quest")>=0
			|| victim->query("death/revived"))
			return notify_fail("此人无须使用回复的特技。\n");
			
		if (!victim->query("env/revive"))
        	return notify_fail("此人不愿意被人施离人夜归。（需要对方Set revive 1）\n"); 
        	
       	if (victim->query_busy() || environment(victim)->query("no_revive"))
				return notify_fail("现在不能对此人施离人夜归。\n");
	
		if (victim->query("score") < 5)
			return notify_fail("离人夜归至少须消耗对方5点评价。\n");
		
		if( me->query("atman") < 500 ) 
			return notify_fail("离人夜归需要５００点灵力！\n");
    	me->add("atman", -500);
    	me->force_status_msg("atman");
    	
		victim->add("score",-5);
		target->set("already_revived",1);
		
		message_vision( WHT "
新月东出，鸿雁南飞，$N柔夷轻摆，纤指微颤，哀声而舞，悠悠扬扬，似乎
漫天飘着落花，细看来，不是杨花，点点是，离人泪。淡淡的忧伤之舞中，
$N轻轻吟唱：回头万水千山，一枝重见处，离肠千结，离肠千结。。。。。\n" NOR, me);
	
		message_vision(WHT"
如水的月光下，$n悠悠起舞，一滴清泪缓缓滴到$N紧闭的双眸之中，
$N眉心一颤，但问心有所伤，怎忍离去？$N缓缓地站起身来。\n"NOR,victim,me);
	
	// SCROLL ADVANCE PERFORM, 
    	stage = me->query("scroll/cloud-dance_yegui");
        switch (stage) {
	    	case 1:		rate   	= 60; break;	// L150  c-d
	    	case 2:		rate	= 70; break;	// L170 c-d
	    	case 3:		rate	= 90; break;	// L200	c-d
	    }
	
		t = victim->query("death/half_quest") + victim->query("death/exp_lost")* rate/100;
				
		victim->set("death/half_quest",t);

		log_file("REVIVE_LOG",
	  			sprintf("%s,%s(%s) 使用cloudy-dance恢复了 %s(%s) %d 的损失。\n",
	    		ctime(time()),me->name(1), geteuid(me), victim->name(1),geteuid(victim),
	    		victim->query("death/exp_lost")* rate/100));

		if (t>=0)	{
			t = 0;
			victim->delete("death/half_quest");
			victim->delete("death/exp_lost");
		}
		victim->set("death/revived",1);
					    					
//		write ("recover to "+ victim->query("death/half_quest") + "\n");    	
	
		// Remove mengpo things.
		ANNIE_D->debuff(victim,"mengpo-soup");
		victim->delete_temp("marks/ready_incar");
    	victim->set("startroom", AREA_FY"church");

		victim->reincarnate();
		victim->set("env/revive",0);
		
		me->add("annie/11_revive_others_yegui",1);
		victim->add("marks/revived",1);
		
		room = environment(me);
		if (room->query("no_fly"))
		{
			room = find_object(AREA_FY"hiretem");
			if (!room) room = load_object(AREA_FY"hiretem");
		}
		victim->move(room);
		victim->perform_busy(1);
		
		victim->set("death_revive",time());
		victim->set("force",0);
		victim->set("mana",0);
		victim->set("atman",0);
		victim->force_status_msg("all");
		victim->status_msg("all");
		
		// THis just serves as a timer, all checks use query(death/time), so even relogin can't bypass
		buff =
		([
			"caster":victim,
			"who":victim,
			"type":"revive-sickness",
			"att":"curse",
			"name":"还魂·虚弱不堪",
			"buff1":"revive-sickness",
			"buff1_c": 1,
			"time":180,
			"buff_msg":"$N身子虚弱到了极点，连站都站不稳了。\n"NOR,
		]);
		ANNIE_D->buffup(buff);
		
		me->perform_busy(3);
		return 1;
}


