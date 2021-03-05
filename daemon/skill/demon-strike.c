// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;
void setup() {
	set("name","如意地魔连环八掌");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("effective_level",170);
	set("damage_level",100);
	set("type","unarmed");
	set("difficulty",200);
	set("skill_class","demon");
	set("parry_msg", ({
        	"$n使出「粘」字诀，双掌一划，引偏了$N的$w。\n",
	}) );
	set("unarmed_parry_msg", ({
        	"$n施展出如意地魔连环八掌，轻描淡写的化解了$N的攻势。\n",
	}) );
	action = ({
        ([      "action":               
"$N双掌一错，一招“魔火天焚”幻出漫天掌影拢向$n的$l",
                "dodge":                130,
                "parry":                110,
                "damage":                150,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N双掌纷飞，一招“魔王食飧”直取$n的$l",
                "dodge":                110,
                "parry":                130,
                "damage":                30,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N暴喝一声，双掌连环推出，一招“魔吼天地”强劲的掌风直扑$n的$l",
                "dodge":                130,
                "parry":                110,
                "damage":                150,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N使出如意地魔连环八掌中的“魔弑森森”，完全将$n的$l笼罩在双掌之下",
                "dodge":                110,
                "parry":                130,
                "damage":                160,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N化掌为刀，一招“乾坤尽魔”，左右掌分砍$n的两处要害",
                "dodge":                200,
                "parry":                300,
                "damage":                140,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N内气上提，全身拔起，一招“魔高和寡”，双掌凌空拍下",
                "dodge":                70,
                "parry":                210,
                "damage":                280,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N提气游走，一招“魔海漭漭”，森森掌风无孔不入般地击向$n的$l",
                "parry":                140,
                "force":                120,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":
"$N使出如意地魔连环八掌中的“璞宇浑魔”双掌携天地魔神之威击向$n的$l",
                "parry":                240,
                "force":                220,
		"damage" :		250,
                "damage_type":  "瘀伤"
        ]),
	});
}


int valid_learn(object me)
{
	if(!::valid_learn(me)) {
		return 0;
	}
    	if( (int)me->query_skill("demon-force", 1) < me->query_skill("demon-strike",1)) {
        return notify_fail("你的天地人魔心法火候不足，无法练如意地魔连环八掌。\n");
    	}
    	return 1;
}

