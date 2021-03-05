#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","宫九的武功");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("type","unarmed");
	set("effective_level",70);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","npc");
	
 	set("unarmed_parry_msg", 		({
        "$n指尖发出丝丝寒气抓向$N手腕，$N急忙沉腕避开。\n",
        "然而$n轮指虚点，锐利的指风将$N逼退。\n",
        "$n化出无数身影，一招「镜花水月」身身皆出一指，一齐点向$N。\n",
        "$n双拳交叉挥出，劲风刚烈，迫得$N连连后退。 \n",
        "$n飞身急抓$N双目，酸冷的阴风迫得$N一跃退开。 \n",
        "$n步走七星，一招「猛虎出山」虚空拍出十三掌，逼得$N撤招自保。\n",
        "$n并起二指，凌空虚点，指风直奔$N的周身大穴。\n",
        "$n一招「如封似闭」，双掌不断圆转，引得$N不由自主地转了一圈。\n",
        "$n化掌为指，一招「恶风怒啸」反点$N的周身要穴。\n",
        "$n中指微弹，一招「无孔不入」，一股阴森森的指风直刺$N的面门。\n",

        
							})
	);

					   
 	action = ({
        ([      "action":               
"$N左手指甲暴突，奋力推出，一招「九阴腐万象」，抓向$n$l",
                "dodge":                250,
                "parry":                350,
                "force":                470,
                "damage_type":  "抓伤"
        ]),

        ([      "action":               
"$N左掌画了个圈圈，右掌推出，一招「狂风扫叶」击向$n$l",
                "dodge":                20,
                "parry":                30,
                "force":                140,
                "damage_type":  "瘀伤"
        ]),

         ([ "action":
"$N左掌阳、右掌阴，使出一招「手挥琵琶」，双掌慢慢向$n的$l合拢",
             "dodge":20,
             "parry":120,
             "force":300,
             "damage_type":"瘀伤"
                ]),
 		
         ([      "action":               
"$N身法稍顿，左手一扬使出「柳亭簪花」往$n的$l点去",
                "dodge":                30,
                "parry":                30,
                "force":                140,
                "damage_type":  "刺伤",
                "weapon":               "左手食指",
        ]),

        ([      "action":               
"$N回步斜身，右手成爪反挥一个圆弧，一式“鹞子翻身”击向$n$l",
                "dodge":                310,
                "parry":                200,
                "force":                290,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N伸指向前一捺，一股凌厉的指力射将过去，点向$n$l ",
                "dodge":                380,
                "parry":                360,
                "force":                390,
                "damage_type":  "刺伤",
                "weapon":               "气劲",
        ]),
        ([      "action":          	
"$N一招「明心见性」，急出数指，指风破空，往$n的$l点去",
                "dodge":                30,
                "parry":                180,
                "force":                140,
                "damage_type":  "刺伤",
                "weapon":               "一缕指风",
        ]),
        ([      "action":               
"$N斜身一转，右掌成爪虚晃$n面门，左掌蓄力斜劈$n的$l。 ",
                "dodge":                170,
                "parry":                170,
                "damage":                70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N缓缓出爪，虚罩$n的全身，身形闪动，忽如一缕幽风欺近身来猛下杀手！ ",
                "dodge":                70,
                "parry":                70,
                "damage":                140,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N吐气扬声，一招「九重天虎」双掌并力推出",
                "dodge":                170,
                "parry":                240,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),

	});
}

mixed hit_ob(object me, object victim, int damage_bonus) {
	if(random(damage_bonus) < 350) {
		return 0;
	}
	if(!victim->query_temp("weapon") 
			&& victim->query_skill_mapped("unarmed") == "ill-quan"
			&& me->query_skill("unarmed") > victim->query_skill("unarmed")) {
		switch(random(3)) {
			case 0:
				message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
				break;
			case 1:
				message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
				break;
			case 2:
				message_vision(HIR "\n因拳法相克，$n逐渐施展不开了！" NOR,me,victim);
				break;
		}
		return random(me->query_skill("unarmed")) * 10;
	}
	return 0;
}

