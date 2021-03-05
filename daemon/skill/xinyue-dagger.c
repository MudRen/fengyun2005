// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
#include <ansi.h>

void setup(){
	set("name","新月斩");
	set("type","dagger");
	set("usage/dagger",1);
	set("usage/parry",1);
	set("effective_level",300);
	set("difficulty",300);
	
	set("skill_class","npc");
	set("parry_msg", ({
		"$n慢慢地将手中的$v立于身前，强烈的刀风将$N逼得连退几步。\n",
	}) );

	set("unarmed_parry_msg", ({
		  "$n手中的$v慢慢地挥出，剧烈颤动的刀锋封向$N。\n",
	}) );	
	
	
	action = ({
        ([  "action":       "$N右手一挥$w，扬起漫天刀光。挥挥洒洒尽在$n左右，$n彷佛笼罩在凄迷月色之中，刀
意竟是无穷无尽，绵绵不去",
			"dodge":		100,
			"damage":		200,
			"damage_type":	"割伤"
		]),
        ([  "action":       "$N刀锋突转，带着奇异的弧度呼啸而来，淡淡的刀光仿佛天上那一抹新月",
			"dodge":		150,
			"damage":		180,
			"damage_type":	"割伤"
		]),
        ([  "action":       "$N手中的$w突然重若千斤，挥洒之间，无不沉滞已极。竟似泰山压顶一般，让$n喘不
过气来",
			"dodge":		200,
			"damage":		220,
			"damage_type":	"割伤"
		]),
        ([  "action":       "$N刀意一转，复又变的轻柔万分，有如春风化雨，又如白雪轻舞，姿态妙曼已极",
			"dodge":		220,
			"damage":		300,
			"damage_type":	"割伤"
		]),
        ([  "action":       "$N双手紧握$w，双脚一弹，一飞冲天。人随刀势，刀随人形，向$n$l劈落",
			"dodge":		300,
			"damage":		500,
			"damage_type":	"割伤"
	        ]),
	});
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object my_weapon;
    	int badint;
    	my_weapon=me->query_temp("weapon");
    	if(damage_bonus < 300 ) return 0;
        if(victim->query_skill_mapped("iron-cloth") == "yijinjing") {
        	badint = victim->query_skill("iron-cloth")*2+random(victim->query_skill("iron-cloth"));
		if(badint) {
			victim->receive_wound("kee",badint,me);
			switch(random(2)) {
        			case 0: return HIW"$N手中"+my_weapon->query("name")+"透出一丝丝寒气,竟击破了$n的护体神功！\n"NOR;
               			case 1: return HIW"$n只觉心头一凉,$N的"+my_weapon->query("name")+"竟透体而入 ．．．\n"NOR;
           		}
		}
	}
	return 0;
}
