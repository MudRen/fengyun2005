// bloodystrike.c
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit SKILL;

void setup() {
	set("name","密宗大手印");
	set("type","unarmed");
	set("effective_level",110);
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","lama");
	set("parry_msg", 			({
			"$n双掌微合，使出一招「千里迎刹佛」，「啪」的一声将$N的$w夹在双掌之间。\n",
			"$n略一转身，一招「撒手离红尘」拍向$N拿着$w的手。\n",
			"$n使出「粘」字诀，双掌一划，引偏了$N的$w。\n",
			})
	);
	set("unarmed_parry_msg",	({
			"$n步走阴阳，一招「我佛慈悲怀」虚空拍出三掌，逼得$N撤招自保。\n",
			"$n施展出「万象皆归空」，轻描淡写的化解了$N的攻势。\n",
			})
	);

	action = ({
			([      "action":               
			"$N使出一招「苦海端无涯」，左掌虚幌，右掌穿出击向$n的$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                100,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
			"$N使出一招「地狱似有门」，左掌化虚为实击向$n的$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                 70,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
			"$N使出密宗大手印中的「天堂却无路」，一掌拍向$n的$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                50,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
			"$N双掌一错，使出「密宗为独尊」，对准$n的$l连续拍出",
			        "dodge":                100,
			        "parry":                100,
			        "force":                150,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
			"$N左掌立于胸前，右掌推出，一招「万念皆是空」击向$n$l",
			        "dodge":                100,
			        "parry":                100,
			        "force":                140,
			        "damage_type":  "瘀伤"
			]),
			([      "action":               
			"$N使出「佛云以杀止杀」，身形凌空飞起，从空中当头向$n的$l出掌攻击",
			        "dodge":                200,
			        "parry":                200,
			        "force":                150,
			        "damage_type":  "瘀伤"
			]),
	});
}

int help(object me)
{
	write(@HELP   
『佛法无边』（fofawubian）
需要２０级密宗大手印。
忙乱对手，如果成功后对手忙乱三招，如果失败则攻击对方一招，无论
成败自身都有两轮忙乱，此招对敌人产生额外的仇恨。

『舍身饲虎』（sheshensihu）
需要１００级密宗大手印和１００级的密宗佛法。
如果成功提高自身护甲等级＝金刚不坏功等级。
对敌人产生额外＝『佛法无边』仇恨的5倍。
维持120秒，CDT8分钟。

『印契』（yinqi）
需要１００级密宗大手印和１００级的密宗佛法。
三连击，第一招中后对手无法闪避、第二招中后对手无法招架，自身忙
乱三回合
额外攻击力＝密宗大手印等级。
额外伤害力＝密宗大手印等级。
最后一击的额外攻击力和额外伤害力还随着密宗佛法等级和自身经验等
级的提高而提升。
HELP
    );
    return 1;
}
