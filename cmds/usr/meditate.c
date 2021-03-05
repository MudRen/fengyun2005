#include <ansi.h>
inherit F_CLEAN_UP;
int do_recover(object me,object target);

int main(object me, string arg)
{
		object target;
			
		if (!arg)
        	return notify_fail("了悟必须指定对象。\n");
        
       	if(!objectp(target = present(arg, environment(me))))
				return notify_fail("这里没有这个东西。\n");
        	
    	if( !target->is_corpse())
			return notify_fail("了悟必须指定有效对象（遗体）。\n");
	
		if (!target->query("victim_player"))
			return notify_fail("了悟只能使用在自己的遗体上。\n");
	
		if ( target->query("victim_id")!= me->query("id"))	
			return notify_fail("了悟只能在自己的尸体上使用。\n");

		if (!mapp(me->query("death")) || me->query("death/half_quest")>=0)
			return notify_fail("你现在无须使用了悟。\n");
		
		if (me->query("score") < 10)
			return notify_fail("了悟消耗十点评价，你的评价不足。\n");
	
		if (me->is_fighting() || me->is_busy())
			return notify_fail("你现在正忙着，如何能静下心来了悟？\n");
		
		if (target->query_temp("in_reviving"))
			return notify_fail("你现在不能了悟这具尸体。\n");
		
		if (target->query("already_revived")|| !target->query("real_death")
			|| me->query("death/revived"))
			return notify_fail("你已经无法从这次转世经历中领悟什么了。\n");
		
		me->start_busy(10);
		target->set_temp("in_reviving",1);
		
		message_vision(HIW"$N缓缓坐定，左手翻转指定$n，右手虚托于腹前，垂首不语。
脸上忽青忽红，忽而身子微颤，如堕寒冰；忽而额头汗如雨下，如履烈焰。\n"NOR,me,target);
		call_out("do_recover",20,me,target);
    	return 1;
}

int do_recover(object me,object target){
	
		mapping buff;
		
		if (!me )	return	1;
		
		me->stop_busy();
		
		if (!target) {
			tell_object(me,"你的尸体消失了，无法了悟。\n");
			return 1;
		}
		target->delete_temp("in_reviving");
		
		if (environment(target)!= environment(me)) {
			tell_object(me,"你的了悟被打断了。\n");
			return 1;
		}
		
		if (me->query("score") < 10) {
			tell_object(me,"了悟需消耗十点评价，你的评价不足。\n");
			return 1;
		}
		
		if (me->is_fighting() || me->is_busy()){
			tell_object(me,"你现在正忙着，如何能静下心来了悟？\n");
			return 1;
		}
		
		if (target->query("already_revived")) {
			tell_object(me,"你已经无法从这次转世经历中领悟什么了。\n");
			return 1;
		}
		
		message_vision(WHT"$N长吐一口气，慢慢站起身来，似有所得。\n"NOR, me);
		tell_object(me,"（你悟出了一些生死之道，你的死亡损失降低了）\n");
						
		
		me->add("score",-10);
		target->set("already_revived",1);

		me->add("death/half_quest",me->query("death/exp_lost")*50/100);
		
		if (me->query("death/half_quest")>=0) {
			me->delete("death/half_quest");		// 罕见情况
			me->delete("death/exp_lost");
		}	

/*		me->set("force",0);
		me->set("atman",0);
		me->set("mana",0);
		me->set("death_revive",time());
		me->force_status_msg("all");
		
		// THis just serves as a timer, all checks use query(death_time), so even relogin can't bypass
		buff =
		([
			"caster":me,
			"who":me,
			"type":"revive-sickness",
			"att":"curse",
			"name":"还魂·虚弱不堪",
			"buff1":"revive-sickness",
			"buff1_c": 1,
			"time":180,
			"buff_msg":"$N身子虚弱到了极点，连站都站不稳了。\n"NOR,
		]);
		ANNIE_D->buffup(buff);*/
				
		
		me->set("death/revived",1);
		me->add("marks/self_revive",1);
		me->add("marks/revived",1);
		
		
		log_file("REVIVE_LOG",
	  			sprintf("%s,%s(%s) 使用meditate恢复了自身 %d 的损失。\n",
	    		ctime(time()),me->name(1), geteuid(me),
	    		me->query("death/exp_lost")/2));
	    		
		return 1;
}		
			


int help(object me)
{
    write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 了悟	meditate [0m
[0;1;37m────────────────────────────────[0m 

风云里危机重重，死亡偶有发生，不过，只要你能够从挫折中悟出点
什么来，便能够降低死亡的损失。该命令的具体功效请参看
ｈｅｌｐ　ｇａｍｅ中的死亡设定篇。

此命令不能在战斗中使用，自我忙乱１０轮。

[0;1;37m────────────────────────────────[0m
HELP
        );
    return 1;
}
