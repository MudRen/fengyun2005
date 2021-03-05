#include <ansi.h>
inherit SKILL;

void setup(){
	set("name","三才剑法");
	set("practice_limit",100);
	set("type","sword");
	set("usage/sword",1);
	set("usage/parry",1);
	set("effective_level",170);
	set("skill_class","npc");
	set("difficulty",200);
	
	
	set("parry_msg", ({
	        "$n使出「天」字诀，以攻为守、身随剑动，将$N迫得连连后退。\n",
	        "$n使出一招地字决中的「地动天摇」，手中的$v含着内力震开了$N的$w。\n",
	        "$n不顾$N的$w，一招人字决中的「人非人、我非我」，向$N的头上砍去。\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n将手中的$v化作三道剑气，迫得$N连连后退。\n",
	}) );
	
	action = ({
        ([      "action":               
"$N使出天字诀中的「日月互转」，$w交于左手，向$n的$l刺来",
                "dodge":                120,
                "parry":                90,
                "damage":               100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N左手握成天字诀，右手中的$w使出一招「风云突起」，斩向$n的$l",
                "dodge":                120,
                "parry":                80,
                "damage":               130,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N使出一招地字诀中的「山水相连」，身形宛如流水，手中$w有如泰山地斩向$n的$l",
                "dodge":                140,
                "parry":                60,
                "damage":               140,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一式地字诀中的「水火无情」对准$n的$l刺出一剑",
                "dodge":                140,
                "parry":                80,
                "damage":               100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w一招人字诀中的「众生平等」，化出无数剑尖向$n刺出",
                "dodge":                200,
                "parry":                60,
                "damage":               120,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N双手握剑，一招人字诀中的「生老病死」刺向$n的$l",
                "dodge":                420,
                "parry":                120,
                "damage":               160,
                "damage_type":  "刺伤"
        ]),
	});
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
	    object ob;
	    if( random(damage_bonus) < 300 ) return 0;
	    if(ob=victim->query_temp("weapon"))
	    if(ob->query("skill_type") == "blade")
	    if(victim->query_skill_mapped("blade") == "qiusheng-blade" )
	    if(me->query_skill("sword") > victim->query_skill("blade")) {
	    switch(random(3)) {
	            case 0:
	                    message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
	                    break;
	            case 1:
	                    message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
	                    break;
	            case 2:
	                    message_vision(HIR "\n因刀剑相克，$n逐渐施展不开了！" NOR,me,victim);
	                    break;
	                    }
	    return random(me->query_skill("sword")) * 4;
	    }
	    return 0;
}

