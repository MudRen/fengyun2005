// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// kongshoudao.c
inherit SKILL;
void setup() {
	set("name","空手道");
	set("damage_level",400);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("type","unarmed");
	set("effective_level",100);
	set("difficulty",200);
	set("skill_class","npc");
	set("parry_msg", ({
        "$n就势一滚，双手一撑地，全身弹出$N的$w的攻击范围。\n",
	}) );

	set("unarmed_parry_msg", ({
        "$n就势一滚，双手一撑地，全身弹出$N的攻击范围。\n",
	}) );	
	action = ({
        ([      "action":               
"$N左腿在前，右腿在后，双掌用力向$n的$l挥来",
                "dodge":                30,
                "parry":                10,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N左脚点地，身体向后旋转，右腿像疾风扫落叶般扫向$n的$l",
                "dodge":                10,
                "parry":                30,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N右手虚晃，左肘从意想不到的角度撞向$n的$l",
                "dodge":                30,
                "parry":                10,
                "damage":                80,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N右脚凌空，晃出一片腿影，霎那间向$n的$l一连踢出三脚",
                "dodge":                10,
                "parry":                30,
                "damage":                70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":               
"$N凌空跃起，身体向后急转，双脚从下往上一前一后地撩向$n的$l",
                "dodge":                20,
                "parry":                30,
                "damage":                60,
                "damage_type":  "瘀伤"
        ]),
	});
}
