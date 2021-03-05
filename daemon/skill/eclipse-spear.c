/*
annie. 10.2003
------------------
朔望长枪
Eclipse Spear
------------------

「神机落水空堕泪」
「望断楚天暮鼓钟」
「严霜染醉千山树」
「黄石骑陷万里尘」
「万里夕烽长寥寂」
「荒烟血火已无痕」
「钟声敲碎空庭月」
「一怀乡恨几晨昏」

*/
#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","朔望长枪");
	set("type","spear");
	set("usage/spear",1);
	set("usage/parry",1);
	set("skill_class","berserker");
	set("effective_level",200);
	set("difficulty",200);
	set("parry_msg", ({
	        "$n枪尖一转，一招「钟声敲碎空庭月」已将$N封在门外。\n",
	        "可$n一封枪势，疏疏密密的「一怀乡恨几晨昏」顿让$N有无从下手之感。\n",
	}) );

	set("unarmed_parry_msg", ({
	        "$n枪尖一转，一招「钟声敲碎空庭月」已将$N封在门外。\n",
	        "可$n一封枪势，疏疏密密的「一怀乡恨几晨昏」顿让$N有无从下手之感。\n",
	}) );
	action = ({
		([      "action":               
			"$N使一招「神机落水空堕泪」，手中$w迅若疾风，急如骤雨，直刺$n",
			"dodge":                520,
			"parry":		300,
			"force" :		100,
			"damage_type":  "刺伤"
		]),
		([      "action":               
			"$N长转$w，一式「望断楚天暮鼓钟」在空中划出半弧，划向$n",
			"dodge":                520,
			"parry":		300,
			"force":               200,
			"damage_type":  "割伤"
		]),
		([      "action":               
			"$N一振$w，使出「严霜染醉千山树」，无数点枪光向$n迸去",
			"dodge":                530,
			"parry":		200,
			"force":               50,
			"damage_type":  "割伤"
		]),
		([      "action":               
			"$N手中$w一个圈转，一招「黄石骑陷万里尘」卷挟真力向$n点去",
			"force":                90,
			"dodge":                230,
			"parry":                400,
			"damage_type":  "刺伤"
		]),
		([      "action":               
			"$N低眉垂枪，忽一反手，「万里夕烽长寥寂」已然使出",
			"dodge":                200,
			"parry":		300,
			"force":               300,
			"damage_type":  "刺伤"
		]),
		([      "action":               
			"$N手中$w一递，枪身竟如残月般弯转，一招「荒烟血火已无痕」反手对准$n一枪刺去",
			"dodge":                260,
			"parry":		330,
			"force":               100,
			"damage_type":  "刺伤"
        ]),
	});
}


mixed hit_ob(object me,object victim)
{
	if(me->query_temp("annie/eclipse"))
	return BLU "$n心头一撞，只觉七魂六魄仿佛要随着那弯淡紫的残月飞离．．．\n"NOR;

}

int help(object me)
{
	write(@HELP   
L150『日月同天』（riyuetongtian）
有连续攻击三次的可能，若击中则停止，自我忙乱三轮
攻击一：额外伤害力=额外攻击力=朔望枪法等级
攻击二：额外伤害力=额外攻击力=朔望枪法等级*3
攻击三：额外伤害力=额外攻击力=朔望枪法等级*8
第三次攻击为两败俱伤之举，同时攻击敌人和自身，必中

L200『蚀魂』（eclipse）
单击攻击，自我忙乱两轮
额外攻击力=朔望枪法等级*3/2
如果击中将在10-20秒内持续产生九次伤害，
伤害数值=111*n，也就是说为111,222,333....999

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
