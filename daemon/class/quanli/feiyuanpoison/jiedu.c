// recover.c

inherit SSERVER;

int curse(object me, object target, int amount)
{
	int force, lvl;
        if( target != me ) return 
	notify_fail("你只能用真气将自己体内毒素逼出。\n");
        force =(int) me->query("force") - (int) me->query("max_force");
	if( force <=100) return notify_fail("你的真气不足。\n");
	lvl = me->query_skill("herb",1);
	if (random(lvl) < 20)
	{
	me->add("force", -100  );
	message_vision("$N运功抗毒，准备把毒逼出体外．．．\n", me);
		return notify_fail("你失败了。\n");
	}
	else
	{
	me->clear_condition();	
		write("你成功地逼出体内的巨毒！\n");
        return 1;
	}
}
 
