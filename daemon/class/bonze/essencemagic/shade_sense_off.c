#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	int lvl,i,duration;
	object env, *inv;
	string msg;
	mapping buff;
		
	if(me->query("class")!="bonze")
		return notify_fail("只有兴国禅寺的弟子才可以使用『隐识』\n");
	
	lvl = me->query_skill("essencemagic",1);
	if ( lvl < 60)
        return notify_fail("需要60级八识神通！\n");
	
	if(!ANNIE_D->check_buff(me, "invisible"))
   		return notify_fail("你现在并不在隐身。\n");
    
    if (me->query("timer/pfm/shade_off")+ 60 > time())
    	return notify_fail("主动停止『隐识』每分钟只能使用一次。\n");
        
	if(me->query("atman") < 100 )
		return notify_fail("需要100点的灵力！\n");
    me->add("atman", -100);
	me->set("timer/pfm/shade_off", time());
	
	ANNIE_D->debuff(me, "invisible");
	me->start_busy(2);
	return 1;
}
