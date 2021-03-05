// pofeng-strike.c
inherit SKILL;

void setup() {
	set("name","泼风掌");
	set("practice_limit",100);
	set("usage/parry",1);
	set("damage_level",200);
	set("type","unarmed");
	set("usage/unarmed",1);
	set("effective_level",170);
	set("difficulty",150);
	
	set("skill_class","yinshi");
	
	set("parry_msg", ({
        	"$n化掌为刀，一招「晓风残月」急切$N拿着$w的手。\n",
        	"$n略一转身，一招「风动树梢」拍向$N拿着$w的手。\n",
        	"$n使出「粘」字诀，双掌一划，引偏了$N的$w。\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n化掌为指，一招「恶风怒啸」反点$N的周身要穴。\n",
        	"$n施展出「狂风怒吼」，轻描淡写的化解了$N的攻势。\n",
	}) );
	
	action = ({
        ([      "action":               
"$N使出一招「乱泼狂风」，右掌从肋下穿出击向$n的$l",
                "dodge":                30,
                "parry":                10,
                "force":                200,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出一招「狂风突袭」，左掌化虚为实击向$n的$l",
                "dodge":                10,
                "parry":                30,
                "force":                170,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出泼风掌法「风动天庭」，拔地而至$n身前，一掌拍向$n的$l",
                "dodge":                30,
                "parry":                10,
                "force":                150,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双掌一错，使出「风雨交加」，对准$n的$l拍出一排掌影",
                "dodge":                10,
                "parry":                30,
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N左掌画了个圈圈，右掌推出，一招「狂风扫叶」击向$n$l",
                "dodge":                20,
                "parry":                30,
                "force":                140,
                "damage_type":  "瘀伤"
        ]),
	});
}
