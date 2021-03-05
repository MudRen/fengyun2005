// Copyright (C) 2002, by Sinny Shi. All rights reserved.
// This skill is a skill to enable all kinds of "pen-like" weapons - neon

// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
#include <ansi.h>
void setup(){
	set("name","书法");
	set("type","unarmed");
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("effective_level",180);
	set("practice_limit",100);
	set("difficulty",200);
	set("skill_class","baiyun");
	
	set("unarmed_parry_msg", (
	
	 { "$n笔势如飞，瞬息之间『哀毒蓋深, 奈何奈何』八字令$N不知所措。 \n",
          "$n回腕轻灵，笔意圈转翔动，落落乎犹众星之列河汉，令$N眼花缭乱。 \n",
         }
        ) );

	action = ({
        ([      "action":               
"$N清啸一声，身形飘逸，笔势如刀割向$n，纵横之间『羲之顿首』四字写的清刚峭拔，卓尔不群",
                "dodge":                10,
                "parry":                10,
                "damage":               110,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N身形大开大阖，『先墓再离荼毒』一气呵成，一笔一划尽是悲愤，狂风暴雨般洒向$n",
                "dodge":                30,
                "parry":                30,
                "damage":               140,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N笔意抖变，出手迟缓凝重，似有千钧之力砸向$n的$l，写的正是『追惟酷甚』四字",
                "dodge":                50,
                "parry":                50,
                "damage":               160,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N挥洒之间在$n的$l刻下『号慕摧绝，痛贯心肝』八字，其缩也凝重，似尺蠖之屈，其
纵也险劲，如狡兔之脱 ",
                "dodge":                70,
                "parry":                70,
                "damage":               180,
                "damage_type":  "瘀伤"
        ]),
	});
}


int valid_learn(object me)
{
	if(!::valid_learn(me)){
		return 0;
	}
	 if((int)me->query_skill("chess", 1) <  (int)me->query_skill("calligraphy",1) ){
        	return notify_fail("你的弈道修为不够，心浮气躁不宜练习『书法』。\n");
    	}
    	return 1;
}


/*
mixed parry_ob(object victim, object me)
{	int busy_time;
	int skill;
	int my_exp, your_exp;
	
	my_exp=me->query("combat_exp");
	your_exp=victim->query("combat_exp");
	
	skill=me->query_skill("chess",1);
	
	if (random(skill) + skill/3 > 100 && me->is_busy()) {
		message_vision(HIG"$N提腕回手，进退井然，弈道的［得算篇］历历在目，身形骤然轻巧起来。\n"NOR, me);	
		me->stop_busy();
	}
	
	return 0;
}	
*/


