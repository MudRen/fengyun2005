// tigerstrike.c

inherit SKILL;
void setup(){
	set("name","虎掌");
	set("practice_limit",100);
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("effective_level",120);
	set("type","unarmed");
	set("difficulty",200);
	set("skill_class","task");
	
	set("parry_msg", ({
        "$n化掌为刀，一招「虎纵」急切$N拿着$w的手。\n",
        "$n双掌交错，使出一招「猛虎出山」，「啪」的一声将$N的$w夹在双掌之间。\n",
        "$n略一转身，一招「猛虎摆尾」拍向$N拿着$w的手。\n",
        "$n使出「啸」字诀，双掌一划，引偏了$N的$w。\n",
	}) );

	set("unarmed_parry_msg", ({
        "$n步走七星，一招「猛虎出山」虚空拍出十三掌，逼得$N撤招自保。\n",
        "$n化掌为指，一招「猛虎摆尾」反点$N的周身要穴。\n",
        "$n施展出「虎锤」，轻描淡写的化解了$N的攻势。\n",
	}) );	
	action = ({
        ([      "action":               
"$N使出一招「天虎扑式」，右掌穿出击向$n的$l",
                "dodge":                70,
                "parry":                110,
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出一招「天虎剪式」，左掌化虚为实击向$n的$l",
                "dodge":                100,
                "parry":                300,
                "force":                100,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出虎掌中「天虎扫式」，如猛虎般欺至$n身前，一掌拍向$n的$l",
                "dodge":                130,
                "parry":                90,
                "force":                70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双掌一错，使出「天虎擒式」，对准$n的$l连续拍出三掌",
                "dodge":                110,
                "parry":                130,
                "force":                130,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N左掌画了个圈圈，右掌推出，一招「天虎啜式」击向$n$l",
                "dodge":                120,
                "parry":                130,
                "force":                120,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出「天虎七式」，身形散作七处同时向$n的$l出掌攻击",
                "dodge":                170,
                "parry":                110,
                "force":                120,
                "damage_type":  "瘀伤"
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

