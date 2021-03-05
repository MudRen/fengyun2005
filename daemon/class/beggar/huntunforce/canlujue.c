#include <ansi.h>

int exert(object me, object target, int amount)
{
        int ammount;
		object *team, *team1;
		int lvl, num, i,teampf;

		if(me->query("class")!="beggar")
    		return notify_fail("只有丐帮弟子才能领悟风餐露宿的奥妙。\n");

        if( target && target!=me )
            return notify_fail("『餐露诀』只能用在自己身上。\n");

        if( (int)me->query("force") < 300 )
                return notify_fail("餐露诀需要300点内力。\n");
        me->add("force", -300);
        
        message_vision(BGRN + HIW "$N闭目凝神，鼓漱舌津，将混沌心法中的餐露诀运转一周。\n"NOR,me);

	
		team1 = me->query_team();
		if (team1 && me->query_skill("huntunforce",1)>=150)
		{
			team = filter_array(team1,(: present($1,environment($2)) :),me);
			num = sizeof(team);	
			for (i=0; i<num; i++)
			{
				if (team[i]->query("food")<100) team[i]->set("food",100);
		        if (team[i]->query("water")<100) team[i]->set("water",100);
		        tell_object( team[i], "你腹中空空的感觉消失了。\n" NOR,team[i]);
				tell_object( team[i], "你口干舌燥的感觉也消失了。\n" NOR,team[i]);
			}
			        me->perform_busy(1);
		}

		if ( (int)me->query_skill("huntunforce",1)<100) 
		{
			if (me->query("food")<100) me->set("food",100);
			tell_object( me, "你腹中空空的感觉消失了。\n" NOR,me);
		}	else {
				if (me->query("food")<100) me->set("food",100);
        		if (me->query("water")<100) me->set("water",100);
             	tell_object( me, "你腹中空空的感觉消失了。\n" NOR,me);
				tell_object( me, "你口干舌燥的感觉也消失了。\n" NOR,me);
             }	
        me->perform_busy(1);
        return 1;
}
