#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object *ob;
   	int i, skill, my_exp,his_exp, bonus, damage;
	
	if( !me->is_fighting() )
        	return notify_fail("『腐息』只能在战斗中使用。\n");

	// 180 + 200 + 100 = 480;
   	skill = me->query_skill("divineforce",1)*2;
	
	bonus = (me->query("combat_exp")-2000000)/5000 * skill/1000;
	if (bonus>skill) bonus= skill;
	if (bonus>0) skill= skill+bonus;
			
	me->perform_busy(2);
	message_vision(HIB "$N深深地吸几口气，突然吐出一团青紫色的毒雾！\n" NOR, me);
	
	my_exp=me->query("combat_exp");
	
	ob = all_inventory(environment(me));
    	for(i=0; i<sizeof(ob); i++)   {
        	if (!living(ob[i]) || ob[i]==me ) continue;
		if (!ob[i]->is_fighting(me)) continue;
		if (ob[i]->query_temp("divineforce/dot")) continue;
		his_exp=ob[i]->query("combat_exp");
		if (my_exp/2+ random(my_exp/80 * skill)>his_exp) {
			message_vision(HIC"$N"+HIC"觉得腥风扑面，一阵反胃，差点就吐了出来。\n"NOR,ob[i]);	

			ob[i]->set("force",ob[i]->query("force")/2);
			ob[i]->set("mana",ob[i]->query("mana")/2);
			ob[i]->set("atman",ob[i]->query("atman")/2);

			call_out("dot",6, me,ob[i],20,0, skill*2);  
			ob[i]->set_temp("divineforce/dot",1);
    		}
    	}
    	return 1;
}

void dot (object me, object enemy, int total, int count, int amount)
{
	int num;
	if (!objectp(enemy))	return;
	if (!enemy->is_fighting(me)) {
		message_vision(WHT"$N长吐一口浊气，周围的腐烂臭气终于慢慢散去了。\n"NOR,enemy);
		enemy->delete_temp("divineforce/dot");
		return;
	}

	message_vision(MAG"$N"+MAG"的脸憋得通红，忽感天旋地转，摇摇欲坠。\n"NOR,enemy);

	enemy->set("force",enemy->query("force")*2/3);
	enemy->set("mana",enemy->query("mana")*2/3);
	enemy->set("atman",enemy->query("atman")*2/3);

	enemy->set_temp("divineforce/dot",1);
	count= count + 1;
	if (count<total) call_out("dot",6,me, enemy,total,count, amount);
		else {
			message_vision(WHT"$N长吐一口浊气，周围的腐烂臭气终于慢慢散去了。\n"NOR,enemy);
			enemy->delete_temp("divineforce/dot");
		}
	return ;
}


