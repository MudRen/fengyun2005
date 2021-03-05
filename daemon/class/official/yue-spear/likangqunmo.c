#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        int extra, tmp, i, duration;
        string msg;
        object *enemy;
	
		if (me->query("family/master_id") != "master yue" || me->query("class")!="official")
			return notify_fail("『力抗群魔』是岳飞弟子的绝招。\n");
	
		extra = me->query_skill("yue-spear",1);
		tmp = me->query_skill("manjianghong",1);
    	    	
    	if (tmp < 140 || extra < 140 )
    		return notify_fail("『力抗群魔』需要140级的岳家中平枪法和140级满江红心法!\n");
    	
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
	        	return notify_fail("『力抗群魔』只能对战斗中的对手使用。\n");
	        
        duration = me->query_temp("timer/pfm/gf_qunmofuzhu")-time() + 10;
		if (duration>0)
        	return notify_fail("你需要等待片刻（"+ duration +"秒）才能再次使用『力抗群魔』\n");
            
        msg = HIW  "\n$N"HIW"使出一招『力抗群魔』，攒、刺、打、挑、拦、搠、架、闭，
枪尖银光闪闪，枪缨红光点点，分打众人要害！！\n" NOR;
	
		message_vision(msg, me);
	
		enemy = me->query_enemy();
		for (i=0;i<sizeof(enemy);i++)
		{
			if (!me->is_busy())
			{	
				me->add_temp("apply/attack",extra);
				COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM, "");
        		me->add_temp("apply/attack",-extra);
        	}
        }
        me->set_temp("timer/pfm/gf_qunmofuzhu",time());
        return 1;
}
