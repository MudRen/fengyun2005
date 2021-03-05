// cast.c

#include <ansi.h>
#include <skill.h>
#define LOWER_LIMIT 2000
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	string spells, spl, trg;
    	object target;
 		int chance;
 		   
    	seteuid(getuid());
    
    	if( me->is_busy() )
        	return notify_fail("( 你上一个动作还没有完成，不能念咒文。)\n");
    
    	if( environment(me)->query("no_magic") || environment(me)->query("no_fight"))
        	return notify_fail("这里不准念咒文。\n");
    	
    	if( !arg ) return notify_fail("指令格式：cast <法术> [on <目标>]\n");
    	if( sscanf(arg, "%s on %s", spl, trg)==2 ) {
        	target = present(trg, environment(me));
        	if(!objectp(target)) 
            		return notify_fail(" 你的咒文要用在谁身上？\n");
		if( !target ) target = present(trg, me);
        	if( !target ) 
        		return notify_fail("这里没有 " + trg + "。\n");
    	} else {
        	spl = arg;
        	target = 0;
    	}

    	spl = replace_string( spl, " ", "_");
		chance = 20 - me->query_temp("marks/kongmen_adjust")*10;
    	if( stringp(spells = me->query_skill_mapped("spells")) ){
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
//        	return (int)SKILL_D(spells)->cast_spell(me, spl, target);
			if ((int)SKILL_D(spells)->cast_spell(me, spl, target)) {
				
				if (userp(me) && ANNIE_D->check_buff(me,"forceshield")) {
	        		if (me->query("force") > 300)
	        			me->set("force", me->query("force") - 300);
	        		else
	        			me->set("force",0);
	        		me->force_status_msg("force");
	        	} 
	        					
				me->force_status_msg("mana");
				return 1;
			}
			return 0;
    	}
    	return notify_fail("你请先用 enable spells 指令选择你要使用的咒文系。\n");
}

int help (object me)
{
    write(@HELP
[0;1;37m────────────────────────────────[0m
[0;1;36m指令格式 : 	cast <咒术名称> [on <施咒对象>][0m
[0;1;37m────────────────────────────────[0m   

施法必须要指定<咒术名称>，<施咒对象>则并不是所有的都需要。

风云中的武功可归为四大类：（分别对应的使用命令为）
（1）传统武技（如神机刀法、棋道心法）：（perform/exert）
（2）法术：（如兴国禅寺的八识神通）：(conjure)
（3) 咒术：（如三清的三清道术、大昭的观音六字明咒）：(cast)
（4）降头术：（如帝王谷的通天降，狼山的血狼咒）：（curse）

所谓咒术，指的是Spells基础上的特殊咒术，比如三清的三清道术 
(necromancy) 和大昭的观音六字明咒（kwan-yin-spells）。

在使用某一个咒术之前，须先用 enable 指令来指定要使用的法术系。
比如你要使用三清的『紫幽之箭』〔drainerbolt〕，就需要首先
enable spells necromancy，然后在战斗中使用
cast drainerbolt on xxxx

在战斗中使用特殊技能有2%的可能会失败，造成自己忙乱，修习某些
特定的武功可以降低此概率。

注：不同的咒术系法力种类不同，你可以随时转换自己的咒术系，
	但蓄积的法力会暂时清零。

相关指令: perform, exert , curse, conjure

[0;1;37m────────────────────────────────[0m    
HELP
        );
    return 1;
}
