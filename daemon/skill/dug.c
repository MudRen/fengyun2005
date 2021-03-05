inherit SKILL;
#include <ansi.h>

void setup(){
	set("name","极光刺杀术");
	set("type","dagger");
	set("usage/dagger",1);
	set("effective_level",250);
	set("difficulty",200);
	set("skill_class","berserker");
	
	action = ({
        ([  "action":       "$N身形一闪，出现在$n身边，手起刀落",
			"dodge":		100,
			"damage":		200,
			"damage_type":	"割伤"
		]),
        ([  "action":       "$N一晃即隐，$w骤然出现在$n眼前",
			"dodge":		150,
			"damage":		180,
			"damage_type":	"割伤"
		]),
        ([  "action":       "$n眼前失去$N踪影，一怔之下，$w已自$n背后戳到",
			"dodge":		200,
			"damage":		220,
			"damage_type":	"割伤"
		]),
        ([  "action":       "$N一扬手，$w飞电似的射向$n，又反穿而回",
			"dodge":		220,
			"damage":		300,
			"damage_type":	"割伤"
		]),
	});
}

int help(object me)
{
	write(@HELP   
『七冥虚之剑』（deathtouch）
需要200级短兵刃（a）和200级的极光刺杀术（b）
至少需要120点的内力
单击攻击，自我忙乱两轮
额外攻击力= a + b + random(b)
额外伤害力= (a+b)*2 + random(a*3)

HELP
    );
    return 1;
}


/*
╔[ 　- FengYun -　 ]┄┄┄┄╗
┊[dancing_faery@hotmail.com]├──╗
┊[ 　annie 09.2003　 ]┄┄┄╝    │
┊[ 离离漫惹三秋露，脉脉时凝九月霜 │
╚————————————————-╝
*/
