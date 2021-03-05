// conjure.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string spells, spl, trg;
	object target;
	int chance;
	
	seteuid(getuid());

	if( me->is_busy() )
		return notify_fail("( 你上一个动作还没有完成，不能施展神通。)\n");

	if( environment(me)->query("no_magic")||environment(me)->query("no_fight") )
		return notify_fail("这里无法使用神通。\n");
	
//	if (me->query_temp("till_death/lockup")==1)
//    		return notify_fail(" （你血脉不畅，真气受滞，一时竟然不能施展神通。）\n");  

	if( !arg ) return notify_fail("指令格式：conjure <神通> [on <目标>]\n");
	if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
		target = present(trg, environment(me));
		if( !target ) target = present(trg, me);
		if( !target ) return notify_fail("这里没有 " + trg + "。\n");
	} else {
		spl = arg;
		target = 0;
	}

	spl = replace_string( spl, " ", "_");
	chance = 20 - me->query_temp("marks/kongmen_adjust")*10;
	if( stringp(spells = me->query_skill_mapped("magic")) ){
		if (me->is_fighting() && random(1000) < chance && !me->query("boss") && !me->query("big_boss")
        		&& me->query_temp("timer/pfm_fail")+ 30 < time())// 在战斗中　%2 chance of fail a perform
	        {
	        	message("vision", HIR"\n"+me->name()+HIR"心头一慌，露出了好大的一个破绽！！！\n"NOR,
	        		environment(me), me);
	        	tell_object(me, HIR"\n你心头一慌，没用出法术反而露出了空门！\n"NOR);
	        	me->set_temp("timer/pfm_fail",time());
	        	me->perform_busy(3);
	        	return 1;
	        }
		if ((int)SKILL_D(spells)->conjure_magic(me, spl, target)) {
			if (userp(me) && ANNIE_D->check_buff(me,"forceshield")) {
        		if (me->query("force") > 300)
        			me->set("force", me->query("force") - 300);
        		else
        			me->set("force",0);
        		me->force_status_msg("force");
        	}
			me->force_status_msg("atman");
			return 1;
		}
		return 0;
	}	
	return notify_fail("你请先用 enable 指令选择你要使用的神通系。\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	conjure <法术名称> [on <施术对象>][0m
[0;1;37m────────────────────────────────[0m   

施法必须要指定<法术名称>，<施术对象>则并不是所有的都需要。

风云中的武功可归为四大类：（分别对应的使用命令为）
（1）传统武技（如神机刀法、棋道心法）：（perform/exert）
（2）法术：（如兴国禅寺的八识神通）：(conjure)
（3) 咒术：（如三清的三清道术、大昭的观音六字明咒）：(cast)
（4）降头术：（如帝王谷的通天降，狼山的血狼咒）：（curse）

所谓法术，指的是Magic基础上的特殊法术，如兴国禅寺的八识神通。

在使用某一个法术之前，须先用 enable 指令来指定要使用的法术系。
比如你要使用如兴国禅寺的八识神通（essencemagic）中的『神识』
(mind_sense) ，就需要首先
enable magic essencemagic
conjure mind_sense on xxxx

在战斗中使用特殊技能有2%的可能会失败，造成自己忙乱，修习某些
特定的武功可以降低此概率。

注：不同的法术系灵力种类不同，你可以随时转换自己的法术系，
	但蓄积的灵力会暂时清零。

相关指令: perform, exert , curse, cast

[0;1;37m────────────────────────────────[0m    
 
HELP
        );
        return 1;
}
