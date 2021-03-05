//hanshan-strike.c

inherit SKILL;
void setup() {
	set("name","寒山掌法");
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("type","unarmed");
	set("effective_level",100);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","knight");
	set("parry_msg", ({
	        "$n一招「孤松一线」，猛击$N的面门，逼得$N中途撤回手中的$w。\n",
	        "$n右拳虚幌，左拳一招「反客为主」，逼得$N后退三步。\n",
	        "$n以守为攻，一招「狮吼辉煌」，猛击$N握$w的手腕。\n",
	        "$n一招「听涛」，轻轻一托$N握$w的手，引偏了$N的$w。\n",
	}) );

	set("unarmed_parry_msg", ({
	        "$n一招「瞒天过海」，逼得$N中途撤招。\n",
	        "$n脚走阴阳，一招「釜底抽薪」，攻$N之必救。\n",
	        "$n左拳击下，右拳自保，一招「过桥抽板」，将$N封于尺外。\n",
	        "$n双拳齐出，使出一招「一箭双雕」，$N的攻势如泥牛入海，消失得无影无踪。\n",
	}) );	
	action = ({
		([	"action":		"$N使一招「杳杳寒山道」，对准$n的$l「呼」地一拳",
			"dodge":		60,
			"parry":		40,
			"damage_type":	"瘀伤"
		]),
		([	"action":		"$N扬起拳头，一招「落落冷涧滨」便往$n的$l招呼过去",
			"dodge":		70,
			"parry":		30,
			"damage_type":	"瘀伤"
		]),
		([	"action":		"$N左手虚晃，右拳「白云抱幽石」往$n的$l击出",
			"dodge":		80,
			"parry":		30,
			"damage_type":	"瘀伤"
		]),
		([	"action":		"$N步履一沉，左拳拉开，右拳使出「沓嶂恒凝雪」击向$n$l",
			"dodge":		90,
			"parry":		30,
			"damage_type":	"瘀伤"
		]),
	});
}


int help(object me)
{
	write(@HELP   
『掌剑』（zhangjian）攻击技能
额外杀伤力 = 掌剑等级/4 + 自身经验等级
额外攻击力 = 掌剑等级/4 + 自身经验等级
L100：三连击，自我忙乱2轮
L130：四连击，自我忙乱3轮，第四击额外伤害、攻击力加倍

HELP
    );
    return 1;
}
