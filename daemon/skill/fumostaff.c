// fumostaff.c

inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","韦陀伏魔杖法");
	set("skill_class","shaolin");
	set("effective_level",150);
	set("type","staff");
	set("usage/staff",1);
	set("usage/parry",1);
	set("difficulty",200);
	set("practice_limit",100);

	set("parry_msg", ({
        	"$n左手捏诀，右手持杖画个圈儿，正是一招「回头是岸」，格开了$N的$w。\n",
        	"$n大吼一声，手中$v由下往上，碰地一声击在$N的$w上。\n",
        	"$n双手持住$v，缓缓往外推出，$N只觉手中$w似有千钧，递不出招去。\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n左手捏诀，右手持杖画个圈儿，正是一招「回头是岸」，化去了$N的攻势。\n",
        	"$n大吼一声，手中$v由下往上，碰地一声击在$N的掌上。\n",
        	"$n双手持住$v，缓缓往外推出，$N只觉前面劲风震荡，递不进招去。\n",
	}) );
	action = ({
        ([      "action":               
"$N使一招「空王不语」，手中$w舞动如飞，扫向$n下盘！",
                "damage":               40,
                "dodge":                40,
                "parry":                40,
                "damage_type":  	"砸伤"
        ]),
        ([      "action":               
"$N挥起$w，一招「满目苍生」，手中$w只攻不守，攻向$n$l！",
                "damage":               40,
                "dodge":                20,
                "parry":                60,
                "damage_type":  	"砸伤"
        ]),
        ([      "action":               
"$N横过手中$w，使出「杖掠横空」，手中$w劈空而下，击向$n$l！",
                "damage":               40,
                "dodge":                10,
                "parry":                40,
                "damage_type":  	"砸伤"
        ]),
        ([      "action":               
"$N使出一招「苦海慈航」，$w大开大合，撞向$n$l！",
                "damage":               40,
                "dodge":                10,
                "parry":                40,
                "damage_type":  	"砸伤"
        ]),
	});
}

int valid_learn(object me) {
	
	if (	me->query_skill("fumostaff",1)>=150
		&& me->query_skill("fumostaff",1) >= me->query_skill("staff",1)
		)
		return notify_fail("150级以上的伏魔杖法需要有相同等级的基本杖法为基础。\n");
	return ::valid_learn(me);
}


void skill_improved(object me)
{
        int s;
        s = me->query_skill("fumostaff", 1);
		if (s == 170 && me->query("class") == "shaolin" ) 
        {
        	tell_object(me, WHT"由於你苦心修研韦陀伏魔杖法，你对『何去何从』的领悟加深了。\n" NOR);
        	me->set("pfm/fumo_improve",1);
        }
}

int effective_level(object me)
{
	int skill,n;
	if (me) {
		skill=me->query_skill("fumostaff",1);
		if (skill<=150 || (me->query("class")!="shaolin" && userp(me))) return 150;
		if (skill>=170) return 200;
		n= (skill-150) /4*10 + 150;
		return n;
	}
	return 200;
}


int skill_difficulty()
{
	object me = this_player();
	int skill,n;
	if (me && userp(me))
	{
		skill = me ->query_skill("fumostaff",1);
		if (skill < 150)
			return 200;
		else
			return 700;
	}
	return 200;
}


int help(object me)
{
	write(@HELP   
韦陀伏魔杖法的系数从150级开始逐步从150提高到200（L170）
但学习系数增加到700
150级以上的伏魔杖法需要有相同等级的基本杖法为基础

『何去何从Ｉ』（hequhecong）
需要150级的韦陀伏魔杖法和基本杖法
使敌手忙乱三招，如果失败自身忙乱两招，成功自身忙乱一招

『何去何从ＩＩ』（hequhecong）
需要170级的韦陀伏魔杖法和基本杖法
使敌手忙乱三招，如果失败自身忙乱两招，成功后无自身忙乱

HELP
    );
    return 1;
}
