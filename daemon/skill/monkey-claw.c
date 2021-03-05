#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","猴爪");
	set("type","unarmed");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("usage/theorem",1);
	set("practice_limit",1);
	set("effective_level",170);
	set("difficulty",100);
	set("skill_class","npc");

	set("parry_msg", ({
        "$n双爪一叉，架住了$N的攻击。\n",
	}) );

	set("unarmed_parry_msg", ({
        "$n双爪一叉，架住了$N的攻击。\n",
	}) );	

	action = ({
        ([      "action":               
"$N单腿微曲，忽的向前扑出，二爪直出，「"HIR"仙猴摘桃"NOR"」般抓向$n的双眼。 ",
                "dodge":                10,
                "parry":                10,
                "damage":                70,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N左手虚晃，如「"HIG"灵猴攀枝"NOR"」右手直击，反扣$n的肩井大穴。 ",
                "dodge":                30,
                "parry":                30,
                "damage":                90,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N一臂前伸，一臂后指，一招「"WHT"猿臂轻舒"NOR"」，攻向$n的两肋 ",
                "dodge":                50,
                "parry":                50,
                "damage":                100,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N忽然缩成一团，使一式「"MAG"八方幻影"NOR"」，双爪无形无定，一爪抓向$n的胸口。 ",
                "dodge":                70,
                "parry":                70,
                "damage":                140,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N猛吸一口气，一弯腰，使出「"CYN"水中揽月"NOR"」，双爪疾扣向$n的小腹。 ",
                "dodge":                30,
                "parry":                25,
                "damage":                77,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N猛的向上高高跃起，一招「"HIC"落地摘"HIY"星"NOR"」，居高临下，一爪罩向$n的头骨。 ",
                "dodge":                50,
                "parry":                90,
                "damage":                30,
                "damage_type":  "抓伤"
        ]),
	});
}


void skill_improved(object me)
{
    	int s;
    	s = me->query_skill("monkey-claw", 1);
	    	if (s == 50 || s == 100 || s == 150 || s == 200) 
	    		tell_object(me,WHT"由于勤练猴爪，你於更换武器之际的破绽减小了。\n"NOR);
    	return;
}


int valid_learn(object me)
{

	if (me->query_skill("monkey-claw",1) >= me->query_skill("theorem",1)*2)
		return notify_fail("你的无有之术火候不够。\n");

	return ::valid_learn(me);
}


int help(object me)
{
	write(@HELP   
需至少/2等级的无有之术，学成后可降低战斗中变换武器所引起的防
守力下降，在司空摘星处学得。此技能为消极技能，无需Enable便能
自动生效。
注：战斗中变换武器后2回合内自身招架（parry）能力将会暂时下降
L0： 招架力为原来的20%
L50：招架力为原来的30%
L100：招架力为原来的50%
L150：招架力为原来的70%
L200：招架力为原来的90%
HELP
);
    return 1;
}
