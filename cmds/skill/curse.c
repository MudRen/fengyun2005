#include <ansi.h>
#include <skill.h>
#define LOWER_LIMIT 2000
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string curse, spl, trg;
	object target;
	int chance;
	
	seteuid(getuid());

	if( me->is_busy() )
		return notify_fail(" 你上一个动作还没有完成，不能下降头。\n");

	if( environment(me)->query("no_magic") )
		return notify_fail("这里不准下降头。\n");
		
	if( environment(me)->query("no_fight") )
		return notify_fail("这里不准下降头。\n");
		
	if( environment(me)->query("no_curse") )
		return notify_fail("这里不准下降头。\n");
		
//	if (me->query_temp("till_death/lockup")==1)
//    		return notify_fail(" （你血脉不畅，真气受滞，一时竟然下不了降头。）\n");  

	if( !arg ) return notify_fail("指令格式：curse <降头> [on <目标>]\n");
	if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
		target = present(trg, environment(me));
                if(!objectp(target)) 
	 		return notify_fail(" 你的降头要用在谁身上？\n");
		if( !target ) target = present(trg, me);
		if( !target ) return notify_fail("这里没有 " + trg + "。\n");
	} else {
		spl = arg;
		target = 0;
	}
	chance = 20 - me->query_temp("marks/kongmen_adjust")*10;
	spl = replace_string( spl, " ", "_");
	if( stringp(curse= me->query_skill_mapped("cursism")) ){
		if (me->is_fighting() && random(1000)<chance && !me->query("boss") && !me->query("big_boss")
        		&& me->query_temp("timer/pfm_fail")+ 30 < time())// 在战斗中　%2 chance of fail a perform
	        {
	        	message("vision", HIR"\n"+me->name()+HIR"心头一慌，露出了好大的一个破绽！！！\n"NOR,
	        		environment(me), me);
	        	tell_object(me, HIR"\n你心头一慌，没用出法术反而露出了空门！\n"NOR);
	        	me->set_temp("timer/pfm_fail",time());
	        	me->perform_busy(3);
	        	return 1;
	        }
		if ((int)SKILL_D(curse)->curse_curses(me, spl, target)) {
			if (userp(me) && ANNIE_D->check_buff(me,"forceshield")) {
        		if (me->query("force") > 300)
        			me->set("force", me->query("force") - 300);
        		else
        			me->set("force",0);
        	}
			me->force_status_msg("force");
			return 1;
		}
		return 0;
	}	
	return notify_fail("请先用 enable curse指令选择你要使用的降头术体系。\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	curse <降头> [on <施术对象>][0m
[0;1;37m────────────────────────────────[0m   

施降头必须要指定<降头名称>，<施术对象>则并不是所有的都需要。

风云中的武功可归为四大类：（分别对应的使用命令为）
（1）传统武技（如神机刀法、棋道心法）：（perform/exert）
（2）法术：（如兴国禅寺的八识神通）：(conjure)
（3) 咒术：（如三清的三清道术、大昭的观音六字明咒）：(cast)
（4）降头术：（如帝王谷的通天降，狼山的血狼咒）：（curse）

所谓降头，指的是cursism基础上的特殊降头术，如帝王谷的通天降。

在使用某一个降头之前，须先用 enable 指令来指定要使用的降头系。
比如你要使用帝王谷的通天降（celecurse）中的『血降』（bloodcurse）
就需要首先
enable cursism celecurse
cast bloodcurse on xxxx

相关指令: perform, exert , conjure, cast

[0;1;37m────────────────────────────────[0m     
HELP
        );
        return 1;
}
