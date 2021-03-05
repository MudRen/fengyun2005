// stormdance.c
// annie 07.2003
// dancing_faery@hotmail.com


#include <combat.h>
#include <ansi.h>
inherit SKILL;

void setup(){
	set("name","天涯西风影");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",175);
	set("difficulty",200);
	set("skill_class","berserker");
	set("dodge_msg", ({
		"$n身子倒旋，一腿踢出，将$N迫退三丈！\n",
		"$n冷冷一笑，双腿一转，兜踢而出，$N大惊之下，连忙让过一边。\n",
		"可是$n背过身去，左脚在地上一点，反身踹向$N面门，$N连忙一闪避开！\n",
	}) );
}

mixed dodge_ob(object victim, object me,int attack_type)
{
	mapping buff;
	if (userp(me) && me->query("class")!="berserker")		return 0;
	if (me->query_skill("xifengying",1)<100)	return 0;

	if (ANNIE_D->check_buff(victim,"lockfield"))	return 0;

	buff =
		([
			"caster":me,
			"who":victim,
			"type":"lockfield",
			"att":"curse",
			"name":"天涯西风影·幻梦移胧",
			"time":30,
			"buff_msg":MAG"\n$n"NOR+MAG"嘴角挂着一丝若有若无的微笑，食、中两指屈并成眼睛般的弧形，$N"NOR+MAG"不
禁从那只眼睛中望了进去。\n"NOR,
		]);
	
	ANNIE_D->buffup(buff);
	tell_object(victim,CYN"眼前的景色笼上了一层淡淡的烟气，变得模模糊糊，又似水面镜影般扭曲不定。
你只觉微微晕眩，心下有些恍惚，仿佛陷进了梦境一般。\n"NOR);
	me->perform_busy(1);

	return 0;
}	

int help(object me)
{
	write(@HELP   
	
等级100以上的西风影在战斗中可能使对手迷乱无法逃脱。

HELP
    );
    return 1;
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
