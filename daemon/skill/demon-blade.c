// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","如意天魔连环八式");
	set("type","blade");
	set("difficulty",200);
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("skill_class","demon");
	set("parry_msg", ({
		"$n使出天魔连环八式中的“魔障无边”，手中的$v化成九重刀幕护住全身。\n",
		})
	);
	set("unarmed_parry_msg", ({
        	"$n使出天魔连环八式中的“魔障无边”，手中的$v化成九重刀幕护住全身。\n",
		})
	);
	action = ({
	([	"action":	"$N使出天魔八式中的起手式“万魔初醒”，手中的$w划出一溜光芒斩向$n的$l",
		"force":	500,
		"damage_type":	"割伤"
	]),
	([	"action":	"$N手一抖，一招“魔焰万丈”手中的$w幻成一片刀花，散向$n的$l",
		"force":	300,
		"damage_type":	"割伤"
	]),
	([	"action":	"$N刀锋忽转，手中的$w一招“魔光乍现”，闪电般劈向$n的$l",
		"force":	200,
		"damage_type":	"割伤"
	]),
	([	"action":	"$N身影晃动，刀锋忽左忽右，一招“天魔独尊”，手中的$w，从中路突然砍至$n的$l",
		"force":	300,
		"damage_type":	"割伤"
	]),
	([	"action":	"$N的双脚点地，刀背贴身，一招“万刃天魔”全身转出一团刀光滚向$n",
		"force":	200,
		"damage_type":	"割伤"
	]),
	([	"action":	"$N刀刃向上，一招“天魔回天”，从一个$n意想不到的角度撩向$n的$l",
		"force":	200,
		"damage_type":	"割伤"
	]),
	([	"action":	"$N手中的$w左右横划，一招“天魔七现”，来来回回地狂扫向$n的$l",
		"force":	100,
		"damage_type":	"割伤"
	]),
    	([	"action":       "$N使出如意天魔连环八式中的收手式“万魔归宗”，手中的$w迅捷无比地砍向$n的$l",
        	"force":        500,
        	"damage_type":  "割伤"
     ]),
	});
}

int valid_learn(object me)
{
        if(!::valid_learn(me)) {
        	return 0;
        }
        if( (int)me->query_skill("demon-force", 1) < me->query_skill("demon-blade",1)) {
            return notify_fail("你的天地人魔心法火候不足，无法练如意天魔连环八式。\n");
		}
	return 1;
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        object ob;
        if( random(damage_bonus) < 300 ) return 0;
        if(ob=victim->query_temp("weapon"))
        if(ob->query("skill_type") == "throwing")
        if(victim->query_skill_mapped("throwing") == "tanzhi-shentong" )
        if(me->query_skill("demon-blade",1) > victim->query_skill("tanzhi-shentong",1)) {
        switch(random(3)) {
                case 0:
                        message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                        break;
                case 1:
                        message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                        break;
                case 2:
                        message_vision(HIR "\n$N手中钢刀来回横扫，$n的暗器无从施展！" NOR,me,victim);
                        break;
                        }
        return random(me->query_skill("blade")) * 4;
        }
        return 0;
}
