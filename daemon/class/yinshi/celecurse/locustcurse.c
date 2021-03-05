// Silencer@fengyun workgroup	June.2005
// 蛊降：召唤蛊虫，附加攻击对手一招（高成功率），杀伤力较高
//	但是有10%机会backfire，如果战斗中使用则40% chance to backfire。

#include <ansi.h>
inherit SSERVER;

int curse(object me, object target)
{
        int extra, skill, num;
        string msg;

		if(me->query("class")!="yinshi"&& userp(me))
			return notify_fail("只有帝王谷弟子才能使出『蛊降』\n");
 	
		skill = me->query_skill("celecurse",1);

		if (me->query_skill_mapped("force")!= "iceheart")
        	return notify_fail("施用蛊降需以冰心诀护体。\n");
        
        if (me->query_temp("pfm/locustcurse"))
        	return notify_fail("你已经下了蛊降了。\n");
        	
        if (me->query("force") < 50)
                return notify_fail("『蛊降』需要50点内力。\n");
        if (userp(me))	me->add("force", -50);
               
        msg = BMAG + HIR"
$N口中念念有词，左袖中飞出一团红光，红光时明时黯、时强时弱、时隐时显。
仔细看去，竟然是无数蠕动的红虫，如飞蛾扑火般吸附在$N手上。\n"NOR;	
	
		message_vision(msg, me);
	
		if (me->is_fighting())
			me->set_temp("pfm/locustcurse",40);
		else
			me->set_temp("pfm/locustcurse",10);	
	
		return 1;
}	