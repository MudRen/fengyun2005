inherit SKILL;
void setup() {
	set("name","随缘无忧剑法");
	set("practice_limit",100);
	set("type","sword");
	set("difficulty",200);
	set("effective_level",150);
	set("usage/sword",1);
	set("usage/parry",1);
	set("skill_class","shaolin");
	set("parry_msg",			({
        "$n使出一招「潭水作天」，身形拔地而起，手中的$v荡开了$N的$w。\n",
        "$n使出「庭前菖蒲」，身形未动，手中$v将$N的$w封于丈外。\n",
        "$n使出一招「墙外余芳」，手中的$v光芒陡长，剑光自远而近，荡开了$N的$w。\n",
        "$n手中的$v一抖，一招「自有因缘」，向$N拿$w的手腕削去。\n",
		})
	);
	set("unarmed_parry_msg", 	({
        "$n用手中的$v带得$N脚步踉跄，一招「行人各自」封住了$N的攻势。\n",
        "$n微一侧身，一招「把手强牵」，整个人消失在一团剑光之中。\n",
        "$n使出一招「有情不识」，$v直刺$N的双手。\n",
        "$n将手中的$v一抖，一招「野渡无人」，迫得$N连连后退。\n",
		})
	);
	action = ({
        ([      "action":               
"$N内力自手中$w激荡而出，一招「遍放神光」，$n被笼罩在一片剑光之中",
		"force" :		50,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N使出随缘无忧剑法中的「几番欲逸」，手中$w势不可当，直取$n的$l",
                "force":               50,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N一招「一线孤牵」，腾空而起，身剑融为一体，化作一道寒光直刺$n的$l",
                "force":               50,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w连劈连挑，虚实相间，一式「迷云障雾」，层层叠叠向$n的$l刺出",
                "force":                90,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N的$w圆转，剑气萧森，一招「潭月影圆」刺向$n的$l",
                "force":               100,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N手中$w左削右砍，蓦地一招「铁干冰心」反手对准$n$l一剑刺去",
                "force":               50,
                "damage_type":  "刺伤"
        ]),
});

}
