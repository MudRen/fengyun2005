#include <ansi.h>
inherit SSERVER;
int curse(object me, object target)
{
	string msg;
	int damage,level,perp;
	object ob, room;

	if(me->query("class")!="wolfmount")
    	return notify_fail("只有狼山弟子才能使出『蹑杀咒』\n");
	level=(int)me->query_skill("wolf-curse",1);
        
    if( (level < 100 || me->query_skill("cursism", 1) < 100)
    		|| me->query_skill("summonwolf",1)<200)
    		return notify_fail("『蹑杀咒』需要100级天狼血咒和降头术，200级唤狼术！\n");
    	
	if(!target) return notify_fail("你想向谁下这个降头？\n");
	room=environment(target);
	if(room!=environment(me)) 
		return notify_fail("你想向谁下蹑杀咒？\n");
	
	if ( environment(me)->query("no_fly") || environment(target)->query("no_fly"))
		return notify_fail("此地不能使用蹑杀咒。\n");

    if (userp(target))
       	return notify_fail("蹑杀咒不能用在玩家身上。\n");
	
	if(!target->is_character() || target->is_corpse())
		return notify_fail("你只能向活物下蹑杀咒。\n");
	
	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, target)) {
		if (stringp(target->query("NO_KILL")))
			return notify_fail(target->query("NO_KILL"));
		if (stringp(target->query("NO_PK")))
			return notify_fail(target->query("NO_PK"));	
		else 
			return notify_fail("你不能向此人下蹑杀咒。\n");	
	}
	
	if (domain_file(file_name(environment(target)))=="eren2")
		return notify_fail("此人警觉太高，无法下蹑杀咒。\n");
	
	if((int)me->query("kee") < 100 )
		return notify_fail("你的气血不够！\n");
	me->receive_damage("kee",100);
	
	me->start_busy(2);
	if(random(me->query("combat_exp"))>target->query("combat_exp")/4)
	{
		me->set_temp("chase_target",target);
		target->set_temp("chaser",me);
		tell_object(me,WHT"你已经成功的对"+target->name()+"下了蹑杀之咒。\n"NOR);
		return 1;
	}
	else return notify_fail(WHT"你由于不够熟练而失败了。\n"NOR);
}
		
		