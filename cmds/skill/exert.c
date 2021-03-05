// exert.c

#include <skill.h>
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	string force;
    	int result, amount, pass,chance;
    	string arg1;
    	
    	seteuid(getuid());
    
    	if( environment(me)->query("no_magic")||environment(me)->query("no_fight") )
        	return notify_fail("你不可以在这里用内功。\n");
    	if( me->is_busy() )
        	return notify_fail("你上一个动作还没有完成，不能施用内功。\n"); 
    	if( !arg ) return notify_fail("你要用内功做什麽？\n");
    
    	if( stringp(force = me->query_skill_mapped("force")) )
    	{
        	notify_fail("你所学的内功中没有这种功能。\n");
        	
        	if (sscanf(arg,"%s %d", arg1, amount)== 2) {
        		if (arg1 == "qi" || arg1 == "shen" || arg1 == "jing")
        			pass = 1;
        	} else if (sscanf(arg,"%s",arg1)==1) {
        		if (arg1 == "qi" || arg1 == "shen" || arg1 == "jing")
        			pass = 1;
        	}
        	chance = 20 - me->query_temp("marks/kongmen_adjust")*10;        	
        	if (me->is_fighting() && random(1000) < chance && !me->query("boss") && !me->query("big_boss")
        		&& me->query_temp("timer/pfm_fail")+ 30 < time()
        		&& !pass )// 在战斗中　%2 chance of fail a perform, and let ppl exert recover
	        {
	        	message("vision", HIR"\n"+me->name()+HIR"真气一岔，露出了好大的一个破绽！！！\n"NOR,
	        		environment(me), me);
	        	tell_object(me, HIR"\n你真气一岔，没用出绝招反而露出了空门！\n"NOR);
	        	me->set_temp("timer/pfm_fail",time());
	        	me->perform_busy(3);
	        	return 1;
	        }
        	if( SKILL_D(force)->exert_function(me, arg) )        {
            	if (!me->is_fighting() && me->query_busy()<1)
            		me->start_busy(1);
            	me->force_status_msg("force");
            	return 1;
        	}
        	return 0;
    	}
    	return notify_fail("你请先用 enable 指令选择你要使用的内功。\n");
}


int help (object me)
{
    write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式：exert|yun <功能名称> [<施用对象>] [<内力点数>] [0m
[0;1;37m────────────────────────────────[0m
用内力进行一些特异功能，你必须要指定<功能名称>，<施用对象>则可有
可无。在你使用某一种内功的特异功能之前，你必须先用 enable 指令来
指定你要使用的内功。（如果你改变自己的内功，你原本蓄积的内力并不
能直接转换过去，必须从0开始。）

内功的特殊功用可见各门派的具体介绍。

所有门派内功都具有的功能：
	恢复体力：	ｅｘｅｒｔ ｑｉ
	恢复心神：	ｅｘｅｒｔ ｓｈｅｎ
	恢复精力：	ｅｘｅｒｔ ｊｉｎｇ
	治疗外伤：	ｅｘｅｒｔ ｈｅａｌ (有一部分内功无此功能）
体力／心神／精力平均恢复值＝ （１０＋有效内功等级／１０）＊耗费内力＊／２０

在战斗中使用特殊技能有2%的可能会失败，造成自己忙乱，修习某些
特定的武功可以降低此概率。

相关指令：
	恢复内力：	ｅｘｅｒｃｉｓｅ　ｑｉ
	恢复法力：	ｅｘｅｒｃｉｓｅ　ｓｈｅｎ
	恢复灵力：	ｅｘｅｒｃｉｓｅ　ｊｉｎｇ
	
[0;1;37m────────────────────────────────[0m
HELP
        );
    return 1;
}
