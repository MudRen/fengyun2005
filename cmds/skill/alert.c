// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
inherit F_CLEAN_UP;
#define MAX_GUARD 1


int main(object me, string arg)
{
	object soldier,*enemy;
	string where;
	int strategy,leadership, exp, title , cost, sen, yue,hate;
	int duration, i,timer;
	
	if ((string)me->query("class") != "official")
		return notify_fail("你不是朝廷命官，还是自己照顾自己吧！\n");
	
	 if (userp(me))
     if (REWARD_D->check_m_success(me,"纵横天下") || me->query("family/master_id")=="master yue")
        	return notify_fail("驰骋疆场的哪儿还有大内高手保护啊。\n");
	
	if (ANNIE_D->check_buff(me,"lockfield") >= 1)
	{
		tell_object(me,YEL"你张口欲啸，却突然发现发不出一点声音。\n"NOR);
		return 0;
	}

	timer  = 6;
		
	strategy = (int)me->query_skill("strategy",1);
	leadership = (int)me->query_skill("leadership",1);
	if(strategy < 25 || leadership < 25)
		return notify_fail("啸警至少需要25级兵法和25级用人之技!\n");	
	
	if( !me->is_fighting() )
    	return notify_fail("好象没有人要杀你！\n");
		
	duration = me->query("timer/pfm/alert")-time() + timer;
    if (duration >0)
		return notify_fail("你还需要等待"+(int)(duration)+"秒钟左右才能再次啸警。\n");
	        	
	if( me->query_temp("max_guard") > MAX_GUARD )
                return notify_fail("以你现在的官位，你已经受到足够的保护！\n");
		
	//	high cost for alert.	
	cost = me->query("max_sen")/5;
	cost = (cost> 800)? 800 : cost;
	if ( me->query("sen") < cost)
		return notify_fail("需要" + cost + "点心神！\n");
	me->receive_damage("sen",cost);
   
    me -> set("timer/pfm/alert",time());
    
    if (random(leadership+strategy)< 13 && leadership + strategy <=260) {
       	message_vision(HIB "\n$N发出一声长啸求援！但是什麽也没有发生！\n" NOR, me);   
		return 1;
	}  	
    	
	if (leadership + strategy >260 && random(100)<5)  
		message_vision(HIB "\n$N发出一声长啸求援！但是什麽也没有发生！\n" NOR, me); 
	else {
		seteuid(getuid());
		soldier= new("/obj/npc/danei_guard");
		message_vision(HIB "\n$N发出一声长啸求援！\n" NOR, me);   
        soldier->set("possessed", me);
        soldier->set_leader(me);
      	    
        title = leadership+ strategy;
        	
        if (title < 200)
			soldier->set_name("大内高手",({ "bodyguard" }));
		else if (title < 300)
			soldier->set_name(HIY"御前侍卫"NOR,({ "bodyguard" }));
		else 
			soldier->set_name(HIR"锦衣卫"NOR,({ "bodyguard" }));

        me->add_temp("max_guard",1);			
		soldier->move(environment(me));	
		soldier->invocation(me, (leadership+strategy));

		if (soldier) {
	       	message_vision(HIB "\n$N应声而来！\n" NOR, soldier);
	       	message_vision("$N喝道：大胆！竟敢和朝廷命官过不去！\n" NOR,soldier);
	       	enemy = me->query_enemy();
		    if (enemy)
	    	for (i=0;i<sizeof(enemy);i++)
	    	{
	       		hate = enemy[i]->query_hate(me);
	       		enemy[i]->add_hate(soldier, hate);     	
	    	}
	       	me->remove_all_killer();
	       	
	    }
	}
		
	return 1;
}


int help(object me)
{
	write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式：alert[0m
[0;1;37m────────────────────────────────[0m
官府特有指令：这个指令让官员呼唤高手来保护自己。
能否招呼出高手，呼出高手水平的高低取决于官员用人之技和兵法的等级高低。

官府弟子啸警条件：25级兵法和25级用人之技。
召唤出来的高手分别为：
兵法 + 用人之技《 200：	大内高手
兵法 + 用人之技《 300：	御前侍卫
兵法 + 用人之技《 450：	锦衣卫	

注意：风云乱世，朝廷人才凋零，啸警/求援能够召到的高手亦有一定限制。
	官府弟子每6秒才能啸警一次，最多只能同时有两个高手。
	拜岳飞后不能再啸警。

[0;1;37m────────────────────────────────[0m 
HELP
    );
    return 1;
}
