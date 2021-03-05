//TIE@FY3
inherit SKILL;
void setup()
{
	set("name","断魂枪");
	set("skill_class","shaolin");
	set("type","spear");
	set("effective_level",150);
	set("usage/spear",1);
	set("usage/parry",1);
	set("practice_limit",100);
	set("difficulty",200);

	set("parry_msg", ({
			"$n使出一招「过眼烟云」，手中的$v荡开了$N的$w。\n",
			"$n使出「梦中说梦」，将$N的$w封于丈外。\n",
			"$n使出一招「踏遍天涯」，手中的$v化做漫天残照，荡开了$N的$w。\n",
			"$n手中的$v一抖，一招「久历歧途」，向$N拿$w的手腕刺去。\n",
	}) );

	set("unarmed_parry_msg", ({
			"$n将手中的$v舞得密不透风，一招「荆榛丛中」封住了$N的攻势。\n",
			"$n反手一招「云浮华相」，整个人消失在一团剑光之中。\n",
			"$n使出一招「光万境闲」，$v直刺$N的双手。\n",
			"$n将手中的$v一抖，一招「天涯空驰」，迫得$N连连后退。\n",
	}) );
	action = ({
		([      "action":               
			"$N使一招「周身皆梦」，手中$w一抖，化出无数枪头，直刺$n的$l",
			"dodge":                520,
			"parry":		300,
			"force" :		100,
			"damage_type":  "刺伤"
		]),
		([      "action":               
			"$N使出断魂枪中的「执梦为真」，手中$w晃动，虚点数枪，突然自影中发出一枪，刺向$n的$l",
			"dodge":                520,
			"parry":		300,
			"force":               200,
			"damage_type":  "刺伤"
		]),
		([      "action":               
			"$N一招「诸皆成梦」，向前猛窜，手中$w反背一枪，直扎$n的$l",
			"dodge":                530,
			"parry":		200,
			"force":               50,
			"damage_type":  "刺伤"
		]),
		([      "action":               
			"$N手中$w一式「梦中知梦」，手中$w枪头乱抖，铺天盖地杀来，枪枪不离$n的$l",
			"force":                90,
			"dodge":                230,
			"parry":                400,
			"damage_type":  "刺伤"
		]),
		([      "action":               
			"$N的$w虚点，蓦地进步跟身，一招「观物达观」刺向$n的$l",
			"dodge":                200,
			"parry":		300,
			"force":               300,
			"damage_type":  "刺伤"
		]),
		([      "action":               
			"$N手中$w一递，枪身竟如残月般弯转，，一招「一念回光」反手对准$n$l一枪刺去",
			"dodge":                260,
			"parry":		330,
			"force":               100,
			"damage_type":  "刺伤"
		]),
	});
}


int effective_level(object me)
{
	int skill, n;
	if( me ) {
		skill = me->query_skill("duanhun-spear", 1);
		if( skill <= 150 || (me->query("class") != "shaolin" && userp(me)) ) {
			return 150;
		}
		if( skill >= 170 ) {
			return 200;
		}
		n = (skill-150)/4*10+150;
		return n;
	}
	return 200;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	object ob;
	int ratio;
	ratio = F_ABILITY->check_ability(me, "3_weapon_add", 3) * 2;
	if( ob = victim->query_temp("weapon") ) {
		if( ob->query("skill_type") == "whip" || ob->query("skill_type") == "axe" ) {
			ratio += 15;
		}
	}
	return damage_bonus*ratio/100;
}

int skill_difficulty()
{
	object me = this_player();
	int skill, n;
	if( me && userp(me) ) {
		skill = me ->query_skill("duanhun-spear",1);
		if( skill < 150 ) {
			return 200;
		} else {
			return 400;
		}
	}
	return 200;
}

int help(object me)
{
	write(@HELP   
断魂枪对所有鞭法、斧法有额外１５％的伤害力。
断魂枪法的系数从150级开始逐步从150提高到200（L170）
但学习系数增加到400

（1）『锁梦缠魂』（suomengchanhun）
需要150级的断魂枪和150级的基本枪法，有一定几率击落敌人武器，
如果失败则攻击敌人一招。无论成功击落敌人武器与否，60秒内的
再次攻击同一对手不会再击落对手武器。自我忙乱2回合。
额外攻击力=断魂枪法等级
额外杀伤力=断魂枪法等级*2

（2）『七星夺魄』（qixingduopo）
需要170级的断魂枪法和170级的基本枪法
手中武器突击对手，攻击力杀伤力较大，60秒使用一次，
自我忙乱1回合，造成额外仇恨。
额外攻击力=断魂枪法等级*3
额外杀伤力=断魂枪法等级*6

HELP
    );
    return 1;
}
