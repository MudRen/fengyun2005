// fy-sword.c
#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","大旗风云剑");
	set("type","sword");
	set("usage/sword",1);
	set("usage/parry",1);
	set("skill_class","tieflag");
	set("effective_level",210);
	set("difficulty",200);
	set("parry_msg", ({
	        "$n以攻代守，$v直向$N刺去。$N吓的连退数步，撤回了攻势。\n",
	        "$n使出一招「山高林密」，将全身躲在了$v形成的剑幕中。\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n将手中的$v连续刺出，挡住$N的全部攻势。\n",
	}) );	
	action = ({
        ([      "action":
"$N使出一招「风满长空」，手中的$w画了一道圆弧，向$n的$l刺来",
                "dodge":                30,
                "damage":               50,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N左手轻轻拍出一掌，右手中的$w使出一招「烈火腾云」，斩向$n的$l",
                "dodge":                10,
                "damage":               70,
                "damage_type":  "割伤"
        ]),
        ([      "action":
"$N使出一招「水到渠成」，身形宛如流水，手中$w从天而降，斩向$n的$l",
                "dodge":                50,
                "damage":               10,
                "damage_type":  "割伤"
        ]),
        ([      "action":
"$N使出一式的「雷震四方」对准$n的$l刺出一剑",
                "dodge":                20,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N将手中$w连晃几个虚招，一招「草深雾泽」向$n刺去",
                "dodge":                60,
                "damage_type":  "刺伤"
        ]),
        ([      "action":
"$N双手握剑，使出一招「天目昭辉」劈向$n的$l",
                "dodge":                100,
                "damage":               40,
                "damage_type":  "割伤"
        ]),
        ([      "action":
"$N手中剑轻轻一晃，$w化为一道电光，使出「地老天荒」刺向$n的$l",
                "dodge":                100,
                "damage":               100,
                "damage_type":  "刺伤"
        ]),
	});
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 250 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "sword")
    if(victim->query_skill_mapped("sword") == "softsword")
    if(me->query_skill("sword") > victim->query_skill("sword")) {
	    switch(random(3)) {
	        case 0:
	            message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
	            break;
			case 1:
	            message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
	            break;
	        case 2:
	            message_vision(HIR "\n因剑法相克，$n逐渐施展不开了！" NOR,me,victim);
	            break;
		}
    return random(me->query_skill("sword")) * 5;
    }
    return 0;
}

