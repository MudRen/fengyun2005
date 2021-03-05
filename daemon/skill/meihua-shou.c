// meihua-shou.c

inherit SKILL;
void setup() {
	set("name","一剪梅花手");
	set("practice_limit",100);
	set("usage/parry",1);
	set("type","unarmed");
	set("usage/unarmed",1);
	set("effective_level",150);
	set("difficulty",200);
	set("skill_class","legend");
	
	set("parry_msg", ({
	        "$n一招「红藕香残玉簟秋」，右手轻拂$N的面门，逼得$N中途撤回手中的$w。\n",
	        "$n右手虚幌，左手一招「云中谁寄锦书来」，逼得$N后退三步。\n",
	        "$n以守为攻，一招「花自飘零水自流」，轻拂$N握$w的手腕。\n",
	        "$n一招「此情无计可消除」，轻轻一托$N握$w的手，引偏了$N的$w。\n",
	}) );

	set("unarmed_parry_msg",  ({
	        "$n一招「薄雾浓云愁永昼」，逼得$N中途撤招。\n",
	        "$n脚走阴阳，一招「东篱把酒黄昏后」，攻$N之必救。\n",
	        "$n左手拂下，右手一招「花自飘零水自流」，将$N封于尺外。\n",
	        "$n双手齐出，使出一招「此情无计可消除」，$N的攻势入泥牛入海，消失得无影无踪。\n",
	}) );	
	action = ({
		([	"action":		"$N使一招「轻解罗裳」，对准$n的$l轻飘飘的扫去",
			"dodge":		120,
			"parry":		210,
			"damage_type":	"瘀伤"
		]),
		([	"action":		"$N扬起右手，一招「独上兰舟」便往$n的$l拍去",
			"dodge":		110,
			"parry":		100,
			"damage_type":	"瘀伤"
		]),
		([	"action":		"$N左手虚晃，右手「月满西楼」往$n的$l击出",
			"dodge":		220,
			"parry":		210,
			"damage_type":	"瘀伤"
		]),
	        ([      "action":               "$N左手微分，右手一长使出一招「雁字回时」，抓向$n的$l",
	                "dodge":                150,
	                "parry":                230,
	                "damage":                100,
	                "damage_type":  "抓伤"
	        ]),
	        ([      "action":               "$N倏地一个转身，双手一挑「一种相思」直掼$n$l",
	                "dodge":                110,
	                "parry":                160,
	                "damage":                110,
	                "damage_type":  "瘀伤"
	        ]),
	        ([      "action":               "$N左手虚晃，右掌飘飘，一招「两处闲愁」击向$n$l",
	                "dodge":                120,
	                "parry":                150,
	                "damage":                150,
	                "damage_type":  "挫伤"
	        ]),
	        ([      "action":               "$N右手在$n$l划过，随後一招「才下眉头」左爪又向同一方位抓到",
	                "parry":                150,
	                "damage":                60,
	                "damage_type":  "抓伤"
	        ]),
	        ([      "action":               "$N左手虚晃，右手握成拳，一招「却上心头」击向$n$l",
	                "dodge":                220,
	                "parry":                150,
	                "damage":                150,
	                "damage_type":  "挫伤"
	        ]),
		});
}

int accuracy_level(object me)
{
	int /*skill,*/n;
	if (me) {
		n = me->query_temp("pfm/legend_jushen")*200;
		return n;
	}
	return 0;
}


int help(object me)
{
	write(@HELP
『梅海』（meihai）
学会梅花手便可使用，令对手忙乱三招，若不成功则攻击对手一招，
无论成败自身忙乱两轮。此招是风云中最有效的忙乱技能之一，
但也会产生额外的仇恨。

『争春』（taunt）
需100级梅花手方能使用，此式非杀伤或忙乱，而是吸引敌人的仇恨，
若成功则立即产生与梅海相当的憎恨，同时在接下来的9回合里持续
产生憎恨，效果随使用者等级的提高而增加。对手在争春效果期间使
用特技的空门可能性提高+1%（空门对BOSS无效）
该特技无论成败都没有自我忙乱，但使用间隔不能少于10秒钟。

『五展梅』（wuzhanmei）
需150级梅花手和250级六灵暗识才能使用，
除非是指定无法ＢＵＳＹ的对手，五展梅必然成功。
对手忙乱三招，自身忙乱一轮。
每９０秒钟使用一次。

HELP
    );
    return 1;
}