// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit SKILL;

void setup(){
	set("name","摔跤");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("type","unarmed");
	set("difficulty",200);
	set("effective_level",180);
	set("skill_class","npc");
	set("parry_msg", ({
        	"$n就势一滚，双手一撑地，全身弹出$N的$w的攻击范围。\n",
	}) );
	set("unarmed_parry_msg", ({
        	"$n就势一滚，双手一撑地，全身弹出$N的攻击范围。\n",
	}) );
	action = ({
        ([      "action":    "$N双手前伸，似乎要抓住$n的$l",
                "dodge":                230,
                "parry":                110,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":    "$N双手搭向$n，身体向后倾斜，似乎要将$n摔倒",
                "dodge":                120,
                "parry":                320,
                "damage":                50,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":    "$N冷不丁伸出左脚，企图将$n绊倒在地下",
                "dodge":                30,
                "parry":                210,
                "damage":                80,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":     "$N右脚凌空，晃出一片腿影，霎那间向$n的$l一连踹出三脚",
                "dodge":                10,
                "parry":                330,
                "damage":                70,
                "damage_type":  "瘀伤"
        ]),
        ([      "action":     "$N抱住$n的$l，将$n举过头顶，往地下狠狠一摔",
                "dodge":                20,
                "parry":                230,
                "damage":                60,
                "damage_type":  "瘀伤"
        ]),
	});
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
        int myexp,urexp;
        
        if (userp(me) && me->query_skill("shuaijiao",1)<150)	return;
        if (victim->is_busy() || victim->query_busy()> 2)	return;
        
        myexp=me->query("combat_exp");
	urexp=victim->query("combat_exp")*victim->query("agi")/40;
	
	if (random(myexp+urexp)>urexp)
	{
		victim->force_busy(2);
		return HIW "$n被$N的双手所缠，一时难以脱身。\n"NOR;
	}   
}

