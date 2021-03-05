// daimonsword.c	; annie 6.29.03
// demon - npc only.
// 破灵犀指，克天岚凝舞、风雨飘香步、碧空步、暗香浮影、幻风飘云舞、飞仙步。
// desc: ESII小步玄剑.改,星野变秋风式.改

#include <ansi.h>
inherit SKILL;
int check_skill(object victim) ;

void setup(){
	set("name","三叹剑法");
	set("usage/sword",1);
	// cant parry
	set("type","sword");
	set("practice_damage",100);
	set("effective_level",200);
	set("difficulty",250);
	set("skill_class","demon");

	action = ({
        ([      "action":               
"$N手执$w回转，一招「叶舞秋风」，几点剑光夹杂在寒风中落向$n",
                "parry":                50,
                "damage":               230,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N抬眉远望，意兴萧然，$w一式「孤峰远指」，斜斜向上推出",
                "parry":                120,
                "damage":               330,
                "damage_type":  "刺伤"
        ]),
([      "action":               
"$N使出「四时江雨」一振$w，几个光环如水面涟漪般散开，环环相扣向$n笼去",
                "parry":                155,
                "damage":               450,
                "damage_type":  "割伤"
        ]),
        ([      "action":               
"$N手中$w轻轻一抖，只见寒光点点，飘浮不定，好似「天河寥落」，映着脸色苍白的$n",
                "parry":                300,
                "damage":		320,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N凝气敛心，手中$w一宛一转，施出「古式·断恨」，一道寒光如秋水般划向$n",
                "parry":                150,
                "damage":		600,
                "damage_type":  "刺伤"
        ]),
        ([      "action":               
"$N两指夹住$w，不偏不倚的缓缓推向$n，看似平凡无奇，实则大巧不工，正是三叹剑法「古式·湮尘」",
                "parry":                150,
                "damage":		600,
                "damage_type":  "刺伤"
        ]),
	});
}
/*
int valid_learn(object me)
{
	object ob;
	seteuid(getuid());
	if(!::valid_learn(me))
		return 0;
	if (!me->query("marry") || me->query("divorced"))	// married,never divorce,and ... *grin
		return notify_fail("无论你怎样用心，总是无法把握住三叹剑法的神之所在。\n");
	ob = FINGER_D->acquire_login_ob(me->query("marry"));
	if (ob)
		return notify_fail("无论你怎样用心，总是无法把握住三叹剑法的神之所在。\n");
	return 1;
}*/


int practice_skill(object me)
{
	return notify_fail("三叹剑法只能用学的。\n");
}

mapping query_action(object me, object weapon) 
{
	int act;
	act=random(sizeof(action));
	return action[act];

}


mixed hit_ob(object me, object victim, int damage_bonus)
{
	int badint=0;
    	if( damage_bonus < 500 ) return 0; 
	if (victim->query_skill_mapped("dodge") == "stormdance"
		||victim->query_skill_mapped("dodge") == "fengyu-piaoxiang"
		||victim->query_skill_mapped("dodge") == "sky-steps"
		||victim->query_skill_mapped("dodge") == "cloud-dance"
		||victim->query_skill_mapped("dodge") == "anxiang-steps"
		||victim->query_skill_mapped("dodge") == "feixian-steps"
		)
		{
		badint=victim->query_skill("dodge");
		if(badint) {
			victim->receive_wound("kee",badint*2,me);
			switch(random(2)) {
        			case 0: return "$N料敌机先，轻而易举地抢入$n的空隙之间！\n";
               			case 1: return "$N熟知$n步法去向，$n逐渐施展不开了！\n";
           			}
		}
	}
}


int help(object me)
{
	write(@HELP   
该剑法对天岚凝舞、风雨飘香步、碧空步、暗香浮影、幻风飘云舞、
飞仙步有额外伤害

『愁思烈杀式』（chousi）
必中的一招，破去对手所有祝福，伤害气血=祝福数*1000

『愁思烈杀式』(chousix)
过时的，没用

『断肠绝灭式』（duanchang）
『断肠绝灭式』（duanchangx）
『离别亢怒式』（libie）
『离别亢怒式』（libie2）
『梦幻空花』（menghuankonghua）
以上五个。。。总之是超级变态的特技了

HELP
    );
    return 1;
}
