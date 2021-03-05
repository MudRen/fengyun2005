//TIE@FY3
inherit SKILL;
void setup(){
	set("name","神机刀法");
	set("type","blade");
	set("difficulty",200);
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",150);
	set("skill_class","npc");
	
	set("parry_msg", ({
		"$n使出一招「偷梁换柱」，手中$v虚点一招，突然回招换式，护住$n的全身。\n",
		"$n手中$v虚刺，半途突然翻转，一招「指桑骂槐」，护住全身要害。\n",
		"$n一招「借尸还魂」，身影闪过，又飘回原地，手中$v＂铛＂的一声磕开了$N的$w。\n",
		"$n一招「调虎离山」，身形虚晃，将$N的招式引开，$v却直袭$N之必救。\n",
	}) );

	set("unarmed_parry_msg", ({
		"$n一招「反客为主」，用手中的$v荡开了$N的招式。\n",
		"$n故意丢个破绽，一招「抛砖引玉」，手中单刀反挥向$N之必救。\n",
		"$n手中$v舞得风雨不透，一招「瞒天过海」，逼得$N回手撤招。\n",
		"$n一招「围魏救赵」，全然不顾$N的攻击，$v直向$N砍去，逼得$N回招自保。\n",
	}) );	
	action = ({
		([	"action":		"$N脸上浮现出一丝诡异的笑容，突然使出一招「笑里藏刀」，手中$w直劈$n的$l！",
			"damage":		70,
			"dodge":		200,
			"parry":		200,	
			"damage_type":	"割伤"
		]),
		([	"action":		"$N使出一招「趁火打劫」掌中$w泛出闪闪刀光，映得$n眼花缭乱，趁机平削$n的$l！",
			"damage":		80,
			"dodge" :		100,
			"parry" : 		100,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N单掌虚晃，$w反手一招「声东击西」狠狠砍向$n的$l",
	                "damage":               80,
	                "dodge" :               100,
	                "parry" :               100,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N身形一矮，一招「釜底抽薪」，$w往$n的$l斜斜撩出一刀",
	                "damage":               40,
	                "dodge" :               10,
	                "parry" :               10,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N手中$w幻出满天刀光，一招「混水摸鱼」，身行如飞，无声无息地转到$n的背后，猛剁$n的$l",
	                "damage":               90,
	                "dodge" :               200,
	                "parry" :               100,
			"damage_type":	"割伤"
		]),
		([	"action":		"$N的$w走弧形，一招「关门打狗」，封住$n的退路，刀尖直刺$n的$l",
			"damage":		30,
	                "dodge" :               200,
	                "parry" :               100,
			"damage_type":	"刺伤"
		]),
		([	"action":		"$N一招「擒贼擒王」，$w挂风，自上而下，电闪般砍向$n的$l",
			"damage":		50,
	                "dodge" :               200,
	                "parry" :               100,
			"damage_type":	"割伤"
		]),
        ([      "action":               "$N一招「打草惊蛇」，$w发疯般狂砍，攻得$n心惊胆战！",
                "damage":               200,
                "dodge" :               200,
                "parry" :               100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N使出一招「顺手牵羊」，$w布满内力，将$n向旁一带，斜刺里顺手一刀",
                "damage":               50,
                "dodge" :               100,
                "parry" :               100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N身行一长，手中$w大开大合，一招「远交近攻」，方圆丈许布满刀风，将$n团团围住",
                "damage":               80,
                "dodge" :               80,
                "parry" :               80,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N手中$w一招「假途灭虢」，刀人合一，冲杀过去，突然回手一刀，劈向$n的$l",
                "damage":               100,
                "dodge" :               200,
                "parry" :               100,
                "damage_type":  "割伤"
        ]),
        ([      "action":               "$N一招「借刀杀人」，欺身而进，一刀攻向$n的$l",
                "damage":               10,
                "dodge" :               200,
                "parry" :               100,
                "damage_type":  "割伤"
        ]),

	});
}
