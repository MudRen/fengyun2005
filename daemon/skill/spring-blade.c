// spring-blade.c

inherit SKILL;
void setup(){
	set("name","春风快意刀法");
	set("type","blade");
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("difficulty",200);
	set("skill_class","berserker");
              
        set("parry_msg", ({
        "$n使出一招「快意图恩仇」，用手中的$v急削$N的五指。\n",
                "$n左脚踏前一步，一招「春风吹斜柳」，手中的$v从侧面飘向$N之必救。\n",
                "$n手中的$v一抖，挽出一片刀花，一招「晚春怜夕阳」，撒向$N的全身。\n",
                "$n微退一步，手中的$v划出一条圆弧，一招「春眠不知哓」，将$N的全身围住。\n",
        }) );

        set("unarmed_parry_msg", ({
                "$n使出一招「快意图恩仇」，用手中的$v急削$N的五指。\n",
                "$n左脚踏前一步，一招「春风吹斜柳」，手中的$v从侧面飘向$N之必救。\n",
                "$n手中的$v一抖，挽出一片刀花，一招「晚春怜夕阳」，撒向$N的全身。\n",
                "$n微退一步，手中的$v划出一条圆弧，一招「春眠不知哓」，将$N的全身围住。\n",
        }) );
        
        action = ({
                ([      "action":               "$N使一招「清风拂人醉」，手中$w轻飘飘地向$n的$l斩去！",
                        "damage":               100,
                        "dodge":                70,
                        "damage_type":  "割伤"
                ]),
                ([      "action":               "$N金刃劈风，$w随著一招「远山伴人痴」由下而上撩往$n的$l",
                        "damage":               40,
                        "damage_type":  "割伤"
                ]),
                ([      "action":               "$N身形一转，一招「飞花逐人香」$w刀光不定，斩向$n的$l",
                        "damage":               20,
                        "damage_type":  "割伤"
                ]),
                ([      "action":               "$N舞动$w，一招「柳叶随人笑」迅捷无伦地劈向$n的$l",
                        "damage_type":  "割伤"
                ]),
                ([      "action":               "$N手中$w一晃，一招「倩影惹人怜」往$n的$l斜斜砍出一刀",
                        "damage":               40,
                        "damage_type":  "割伤"
                ]),
                ([      "action":               "$N提刀过肩，蓄劲发力，一招「芦雪碎人影」直劈$n$l",
                        "damage":               40,
                        "damage_type":  "割伤"
                ]),
                ([      "action":               "$N移步侧身，使一招「彩蝶灼人衣」刀光霍霍斩向$n的$l",
                        "damage":               40,
                        "damage_type":  "割伤"
                ]),
        });
}


int help(object me)
{
	write(@HELP   
『风逝云栖』(fengsiyunqi)
攻击技，自我忙乱2轮，如果击中产生额外心神伤害


HELP
    );
    return 1;
}
