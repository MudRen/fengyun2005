#include <ansi.h>
inherit SSERVER;

int main(object me, string arg)
{
	string roomname;
	object room;
	int skill,atman;
        int pts;
        if(strlen(arg)>1)
        	 return notify_fail("指令格式：usemark <导标编号数字[1-5]> \n");
        if( !arg || (arg!="none" && !sscanf(arg, "%d", pts)) ) 
                return notify_fail("指令格式：usemark  <导标编号数字[1-5]> \n");
        if(pts>5 || pts<1)
        	  return notify_fail("请输入<[1-5]之间的数字> \n");

	if( (skill=me->query_skill("incarnation",1)) < 160 )
       		return notify_fail("需要１６０级修仙术才能使用『逍遥游』！\n");
	if( me->is_fighting() )
		return notify_fail("战斗中无法使用仙法！\n");
	
	if (me->is_busy())
		return notify_fail("你现在正忙！\n");
	if( me->is_ghost())
		return notify_fail("鬼魂无法使用仙法！\n");
		
	if (stringp(me->query_temp("no_move")))
		return notify_fail(me->query_temp("no_move"));	
		 	
	if( !(roomname=me->query_temp("timespacemark"+pts)))
		return notify_fail("你没有设定道标。\n");
	if( time()>me->query_temp("timespacemark_time"+pts))
		return notify_fail("你设定的道标已经失效了。\n");
	if(environment(me)->query("no_death_penalty") || environment(me)->query("no_fly")
		|| environment(me)->query("no_magic") )
    		return notify_fail("此地不能使用『逍遥游』\n");
	
	if( (atman=me->query("atman")) < 200 )
		return notify_fail("你的灵力不够！\n");
	me->add("atman", -200);
	me->force_status_msg("atman");
	
	if( random(atman/5+(skill-90)/2+180) <100)	{
		 message_vision( HIY "$N手指掐诀，口中默念，但什么事也没发生。\n" NOR, me);
		 return notify_fail("你的『逍遥游』失败了。\n");	
		}
	message_vision( HIC "$N手指掐诀，口中默念，忽然化作一股青烟消失了 ....\n" NOR, me);
	TASK_D->flying_risk(me);
	room = load_object(roomname);
	me->move(room);
	message( "vision", HIC "\n忽然一股青烟从地上冒出，"+me->query("name")+"从烟雾中出现！\n\n" NOR,
		room, ({ me }) );
	return 1;
}


int help(object me)
{
write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 :		usemark
[0;1;37m────────────────────────────────[0m   

天地逍遥游：需要160级修仙术，可在一个地方设定道标（setmark），
	而后在一定时间内快速返回（usermark）
	每次耗费200点灵力。
			
[0;1;37m────────────────────────────────[0m   
HELP
    );
    return 1;
}
