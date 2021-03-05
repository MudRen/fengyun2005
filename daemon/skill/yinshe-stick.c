// yinshe-stick.c
inherit SKILL;

void setup() {
	set("name","银蛇杖法");
	set("type","staff");
	set("difficulty",200);
	set("usage/staff",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("skill_class","npc");
 	set("parry_msg",		({
			"$n使出一招「庐山法蛤」手中$v摆开，格开了$N的$w。\n",
			"$n手中$v横摆，一招「蛇舌伸爪」，荡开了$N的$w。\n",
			})
	);
	set("unarmed_parry_msg",	({
			"$n身形徐徐后退，手中$v抡动，封住了$N的攻势。\n",
			"$n身形直挺挺扑倒在地，手中$v径自扫向$N。\n",
			})
	);
	action = ({
			([      "action":               "$N使出一招「银蛇长空」，身形腾空而起，手中$w挂定风声，向$n的$l狠狠砸去！",
			        "damage":               40,
			        "dodge":                40,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "挫伤"
			]), 
			([      "action":               "$N使出一招「银蛇三现」，手中$w挽出团团雪花，三隐三现，棍棍不离$n的$l！",
			        "damage":               40,
			        "dodge":                20,
			        "parry":                60,
			        "post_action":  "bash_weapon",
			        "damage_type":  "挫伤"
			]),
			([      "action":               "$N手中$w一振，一招「红德飞地」，立现满天$w，棍棍直指$n的$l！",
			        "damage":               80,
			        "dodge":                10,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "挫伤"
			]),
			([      "action":               "$N手中$w抡动，过处带起阵阵啸声，一招「虎啸龙吟」，直奔$n的$l打去！",
			        "damage":               200,
			        "dodge":                110,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "挫伤"
			]),
			([      "action":               "$N手中$w一晃，竟幻然为双，一招「二话双鸣」，分别袭向$n的两处要害！",
			        "damage":               10,
			        "dodge":                100,
			        "parry":                200,
			        "post_action":  "bash_weapon",
			        "damage_type":  "挫伤"
			]),
			([      "action":               "$N身形连转，手中$w一招「怪蟒翻身」，连连向$n的$l扫去！",
			        "damage":               20,
			        "dodge":                10,
			        "parry":                20,
			        "post_action":  "bash_weapon",
			        "damage_type":  "挫伤"
			]),
			([      "action":               "$N身形窜起，手中$w一招「毒害色丝」，直上直下地戳向$n的$l！",
			        "damage":               100,
			        "dodge":                10,
			        "parry":                20,
			        "post_action":  "bash_weapon",
			        "damage_type":  "挫伤"
			]),
			([      "action":               "$N身行一顿，手中$w斜出一招「白蛇出洞」，挑向$n的$l！",
			        "damage":               50,
			        "dodge":                10,
			        "parry":                20,
			        "post_action":  "bash_weapon",
			        "damage_type":  "挫伤"
			]),
			([      "action":               "$N手中$w舞动，化出满天棍影，一招「是乐道虾」竟从各个角度同时打向$n的$l！",
			        "damage":               50,
			        "dodge":                200,
			        "parry":                200,
			        "post_action":  "bash_weapon",
			        "damage_type":  "挫伤"
			]),
			([      "action":               "$N使出一招「猛龙下山」身形跃起，手中$w自上而下，呼地砸向$n的$l！",
			        "damage":               90,
			        "dodge":                30,
			        "parry":                50,
			        "post_action":  "bash_weapon",
			        "damage_type":  "挫伤"
			]),
	});
}
