#include <ansi.h>
inherit SSERVER;

int main(object me, string arg)
{
	object room;
	int marktime;
        int pts;
        if(strlen(arg)>1)
        	 return notify_fail("指令格式：setmark <导标编号数字[1-5]> \n");
        if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) ) 
                return notify_fail("指令格式：setmark <导标编号数字[1-5]> \n");
        if(pts>5 || pts<1)
        	  return notify_fail("请输入 <[1-5]之间的数字> \n");

	if((int) me->query_skill("incarnation",1) < 160)
    	return notify_fail("需要１６０级修仙术才能使用『逍遥游』！\n");
	if( me->is_fighting() )
		return notify_fail("战斗中无法使用仙法！\n");

	if( me->query("atman") < 200 )
		return notify_fail("你的灵力不够！\n");

	if (me->is_busy())
		return notify_fail("你现在正忙！\n");
	if( me->is_ghost())
		return notify_fail("鬼魂无法使用仙法！\n"); 	
        if (environment(me))
        if (environment(me)->query("no_fly_in"))
    		return notify_fail("此地不能使用『逍遥游』。。\n");
    	if(environment(me)->query("no_fly")||environment(me)->query("no_death_penalty")
    		|| environment(me)->query("no_fly"))
    		return notify_fail("此地不能使用『逍遥游』。\n");

	me->add("atman", -200);
	me->force_status_msg("atman");
	
	me->start_busy(1);
	message_vision( HIM "$N环顾四方，双手一挥，闪出一点紫色火花落入地上消失了 。。。。\n" NOR, me);
	room = environment(me);
	marktime=90000+random((me->query_skill("incarnation",1)-80)*100);
	me->set_temp("timespacemark"+pts,base_name(room));
    	me->set_temp("timespacemark_time"+pts,time()+marktime);
	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 :		setmark
[0;1;37m────────────────────────────────[0m   

天地逍遥游：需要160级修仙术，可在一个地方设定道标（setmark），
	而后在一定时间内快速返回（usermark）
	每次耗费200点灵力。

[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}
