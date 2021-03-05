// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","迎风一刀斩");
	set("damage_level",300);
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",170);
	set("type","blade");
	set("difficulty",200);
	set("skill_class","npc");
	set("parry_msg", ({
		"$n慢慢地将手中的$v立于身前，强烈的刀风将$N逼得连退几步。\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n手中的$v慢慢地挥出，剧烈颤动的刀锋封向$N。\n",
	}) );	
	action = ({
		([	"action":		
		"$N手中的$w迎风一晃，刀锋带出裂锦般的声音，万马奔腾般地砍向$n的$l",
			"force":		400,
	                "damage":               200,
			"damage_type":	"割伤"
		]),
		([	"action":		
		"$N手中的$w迎风狂舞，象暴风中的滚沙，裹向$n的$l",
	                "damage":               200,
			"force":		300,
			"damage_type":	"割伤"
		]),
		([	"action":		
		"$N手中的$w象狂风中的流云，忽聚忽散地砍向$n的$l",
			"force":		100,
	                "damage":               200,
			"damage_type":	"割伤"
		]),
		([	"action":		
		"$N晃动手中的$w，刀光忽隐忽现，象秋风中的落叶，一刀连一刀地散向$n的$l",
			"force":		100,
	                "damage":               200,
			"damage_type":	"割伤"
		]),
		([	"action":		
		"$N聚起全身的功力，手中的$w象刺骨寒风般割向$n",
			"force":		200,
			"damage":		200,
			"damage_type":	"割伤"
		]),
	});
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 200 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "hammer")
    if(victim->query_skill_mapped("hammer") == "pangu-hammer" )
    if(me->query_skill("blade") > victim->query_skill("hammer")) {
    switch(random(3)) {
            case 0:
                    message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n因刀锤相克，$n逐渐施展不开了！" NOR,me,victim);
                    break;
                    }
    return random(me->query_skill("blade")) * 10;
    }
    return 0;
}

