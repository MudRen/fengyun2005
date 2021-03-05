#include <ansi.h>
inherit SKILL;
void setup() {
	set("name","小重山掌");
	set("type","unarmed");
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("effective_level",230);
	set("difficulty",230);
	set("skill_class","task");
	set("parry_msg", ({
        	"$n一招「旧山松竹老，阻归程」，双掌齐出，$N只得撤回手中的$w。\n",
        	"$n两手不住弹拨，使出一招「欲将心事付瑶琴」，$N握$w的手腕一麻，竟已使不出力道。\n",
        	"$n一招「起来独自绕阶行」，已将$N的$w夹在手中。\n",
	}) );
	set("unarmed_parry_msg", ({
        	"$n一招「旧山松竹老，阻归程」，双掌齐出，逼得$N连连后退。\n",
        	"$n两手不住弹拨，使出一招「欲将心事付瑶琴」，$N的手腕一麻，竟已使不出力道。\n",
        	"$n一招「起来独自绕阶行」，与$N硬碰硬的拼了一招，两人都只觉全身一震。\n", 
	}) );
	action = ({
        ([      "action":               "$N使一招「昨夜寒蛩不住鸣」，双掌暗运功力，对准$n的$l扫去",
                "dodge":                80,
                "parry":                20,
		"damage":		100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N扬起左手，一招「惊回千里梦，已三更」便向$n的$l挥去",
                "dodge":                40,
                "parry":                90,
		"damage":		80,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N双手交错，直取$n的$l，却是一招「白首为功名」",
                "dodge":                120,
                "parry":                20,
		"damage":		120,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N左掌虚晃，右手忽长，使出一招「人悄悄，窗外月胧明」，击向$n的$l",
                "dodge":                60,
                "parry":                80,
                "damage":               100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               "$N轻轻退后，左手却蕴涵内力，一招「知音少，弦断有谁听」直掼$n$l",
                "dodge":                70,
                "parry":                60,
                "force":                130,
                "damage_type":  "瘀伤"
        ]),
	});
}



mixed parry_ob(object victim, object me)
{	int busy_time,alr_busy_time;
	int skill;
	int my_exp, your_exp;
	
	if (victim->query("race")=="野兽") return 0;
	
	my_exp=me->query("combat_exp");
	your_exp=victim->query("combat_exp");
	skill=me->query_skill("yue-strike",1);
	
	if ( 
		(userp(me) && !random(4-skill/60) && 4*random(my_exp)>your_exp) ||
		me->query_temp("pfm/yue-strike/shts")
		|| !userp(me) ) {
		me->set_temp("counter_action",1);
		me->set_temp("counter_msg",HIY"$N双拳齐出，硬碰硬就往$n身上招呼了过去。\n"NOR);
	}
	
	return 0;

/*		if(busy_time>alr_busy_time)
			victim->start_busy(busy_time);
		switch(random(3)){
			case 0:
				message_vision(HIY"$N只觉的面前掌影纷飞难辨真幻。\n"NOR, victim);
				break;
			case 1:
				message_vision(HIY"$N一掌徐徐攻向$n，半途中突然加快，$n一时间不知如何是好。\n"NOR, me, victim);
				break;
			case 2:
				message_vision(HIY"$N掌法似断似续笼罩在$n身旁四周，$n身形越来越慢逐渐施展不开。\n"NOR, me, victim);
				break;
		}
	}
	return 0;
*/
}	


