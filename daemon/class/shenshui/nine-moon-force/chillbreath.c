#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
	object *ob;
    	int i, skill, my_exp,his_exp, bonus, damage;

    if(me->query("class")!="shenshui")
    	return notify_fail("只有神水宫弟子才能使出『九阴毒雾』的绝技。\n");

	if (me->query_skill("nine-moon-force",1)<180 
		|| me->query_skill("nine-moon-spirit",1)<180)
		return notify_fail("『九阴毒雾』需要180级九阴心经和姹女神功。\n");
		
	if(!me->is_fighting() )
        return notify_fail("『九阴毒雾』只能在战斗中使用。\n");

   	if( me->query("force") < 150 )
        return notify_fail("『九阴毒雾』需要150点的内力。\n");
	me->add("force", -150);
	
	// 180 + 200 + 100 = 480/2; + 150 = 390
    skill = me->query_skill("nine-moon-force",1)+me->query_skill("nine-moon-spirit",1)
    		+ me->query_skill("qingpingforce",1)/2;
	
	bonus = F_LEVEL->get_level(me->query("combat_exp"));
	
	skill = skill/2 + bonus;		// 195+ 150 = 345
				
   	message_vision(BMAG + HIM"$N深深地吸几口气，突然吐出一团血红色的阴雾！\n" NOR, me);
	
	my_exp=me->query("combat_exp");
	
	ob = all_inventory(environment(me));
    for(i=0; i<sizeof(ob); i++)   {
        if (!living(ob[i]) || ob[i]==me ) continue;
		if (!ob[i]->is_fighting(me)) continue;
		if (ob[i]->query_temp("nine-moon-force/dot")) continue;
		if (COMBAT_D->do_busy_attack(me, ob[i], "nine-moon-force/chillbreath", "step", 500, 10)){
			message_vision(MAG"$N"+MAG"觉得阴风扑面，差点儿晕了过去。\n"NOR,ob[i]);	
			damage = COMBAT_D->magic_modifier(me, ob[i],"kee", skill);
			ob[i]->receive_wound("kee", damage ,me);
			call_out("dot",6, me,ob[i],20,0, skill);  
			ob[i]->set_temp("nine-moon-force/dot",1);
    	}
    }
    return 1;
}

void dot (object me, object enemy, int total, int count, int amount)
{
	int num, level,freq, n;
	
	if (!me)	return;
	if (!objectp(enemy))	return;
	
	if (!enemy->is_fighting(me)) {
		message_vision(WHT"$N长吐一口浊气，中的『九阴毒雾』终于失效了。\n"NOR,enemy);
		enemy->delete_temp("nine-moon-force/dot");
		return;
	}

	// 120sec 20 chances, L65 (3> random(20), 3times, 40 sec once) - L140(5 times, 24sec once) 
	level = F_LEVEL->get_level(me->query("combat_exp"));
	freq = 3 + (level - 60)/40;  
	n = random(20);
	
	if(wizardp(me) && (string)me->query("env/combat1")=="verbose" ) {
		tell_object(me,"n = " + n + "\n");
	}
	
	if (freq > n) {
		message_vision(RED"$N"+RED"的脸憋得通红，忽感天旋地转，摇摇欲坠。\n"NOR,enemy);
		num = COMBAT_D->magic_modifier(me, enemy,"kee", amount/10);
		enemy->receive_wound("kee",num,me);
//		message_vision("$N says: freq = " + freq + " . count " + count + " . SPLASH \n", enemy);
		enemy->set_temp("marks/pfm/polu_chance",time());
	} 
	
	enemy->set_temp("nine-moon-force/dot",1);
	count = count + 1;
	if (count<total) call_out("dot",6,me, enemy,total,count, amount);
		else {
			message_vision(WHT"$N长吐一口浊气，中的『九阴毒雾』终于失效了。\n"NOR,enemy);
			enemy->delete_temp("nine-moon-force/dot");
		}
	return ;
}


