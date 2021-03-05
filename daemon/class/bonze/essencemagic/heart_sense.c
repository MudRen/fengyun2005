// heart_sense.c
// silencer@fy4 -------- this is the revive skill ------------
// 	Heart_sense can be used at corpse

#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
		int skill, extra, exp_recovered,rate,t;
		string victim_id;
		object victim,room;
		mapping buff;
	
		if(me->query("class")!="bonze")
			return notify_fail("只有兴国禅寺的弟子才可以使用八识神通！\n");
	
		skill = me->query_skill("essencemagic",1);
		if( skill < 100)
        	return notify_fail("心识神通需要100级八识神通！");
                
		if( !target || !target->is_corpse())
			return notify_fail("心识神通必须指定遗体（conjure heart_sense on corpse）。\n");
	
		if (!target->query("victim_player"))
			return notify_fail("心识神通只能使用在玩家的遗体上。\n");
	
		if (!(victim_id = target->query("victim_id")))	
			return notify_fail("心识神通不能使用在此无主身上。\n");

		if (target->query("already_revived")|| !target->query("real_death"))
			return notify_fail("这具尸体已经不能再重复使用心识神通类的特技了。\n");
			
		victim = find_player(victim_id);
	
		if (!victim || !userp(victim))
			return notify_fail(victim_id+"不在风云世界内。\n");
				
		if( !victim ->is_ghost())
			return notify_fail("此人已经不在冥界了。\n");
	
		if (!mapp(victim->query("death")) || victim->query("death/half_quest")>=0
			|| victim->query("death/revived"))
			return notify_fail("此人无须使用回复的特技。\n");
			
		if (!victim->query("env/revive"))
        	return notify_fail("此人不愿意被人施心识神通（需要对方Set revive 1）\n"); 
        	
       	if (victim->query_busy() || environment(victim)->query("no_revive"))
				return notify_fail("现在不能对此人施心识神通。\n");
	
		if (victim->query("score") < 5)
			return notify_fail("心识神通至少须消耗对方5点评价。\n");
		
		if( me->query("atman") < 500 ) 
			return notify_fail("心识神通需要５００点灵力！\n");
    	me->add("atman", -500);
		victim->add("score",-5);
		target->set("already_revived",1);
		
		message_vision(WHT "$N一手直竖于胸前，一手向前微屈虚指，合目缓缓低吟往生之咒，
南無阿彌多婆夜　哆他伽多夜　哆地夜他　阿彌利都婆毗
阿彌利哆　悉耽婆毗　阿彌利哆　毗迦蘭帝
阿彌利哆　毗迦蘭多　
伽彌膩　伽伽那　枳多迦利　娑婆訶\n\n" NOR, me);	

		tell_object(victim, WHT"冥冥中忽然传来一阵低沉的佛号，
南無阿彌多婆夜　哆他伽多夜　哆地夜他　阿彌利都婆毗
阿彌利哆　悉耽婆毗　阿彌利哆　毗迦蘭帝
阿彌利哆　毗迦蘭多　
伽彌膩　伽伽那　枳多迦利　娑婆訶\n\n" NOR);	
	
	   	message_vision( HIW"$N浑身剧烈地颤抖着，忽然，一道光芒注入$N的顶门。\n",victim);
		message_vision( HIW "光芒越来越强烈，$N身不由己地升了起来。"NOR,victim);
	
		message_vision(HIW"忽然一道白光闪过，眼前似乎多了个人影。\n"NOR, me);
		tell_object (victim, "\n\n\n");
		tell_object(victim, HIR "你复活了！！\n"NOR);
		
		skill = me->query_skill("essencemagic",1);
		
		if (skill >= 200)		rate = 90;
		else if (skill>= 180)	rate = 80;
		else if (skill>= 140) 	rate = 70;	
		else if (skill>= 100) 	rate = 60;	
		
		t = victim->query("death/exp_lost")*rate/100;
				
		log_file("REVIVE_LOG",
	  			sprintf("%s,%s(%s) 使用heart_sense恢复了 %s(%s) %d 的损失。\n",
	    		ctime(time()),me->name(1), geteuid(me), victim->name(1),geteuid(victim), t ));

		t = victim->query("death/half_quest")+ t;
		victim->set("death/half_quest",t);
		if (t>=0)	{
			t = 0;
			victim->delete("death/half_quest");
			victim->delete("death/exp_lost");
		}
		   				
//		write ("recover to "+ victim->query("death/half_quest") + "\n");    	
	
		// Remove mengpo things.
		ANNIE_D->debuff(victim,"mengpo-soup");
		victim->delete_temp("marks/ready_incar");
    	victim->set("startroom", AREA_FY"church");

		victim->reincarnate();
		victim->set("env/revive",0);
		victim->add("marks/revived",1);

		me->add("annie/11_revive_others_heart",1);
		
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
