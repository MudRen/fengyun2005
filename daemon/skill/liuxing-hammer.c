// liuxing-hammer.c
inherit SKILL;
void setup()
{
	set("name","反转流星锤法");
	set("skill_class","shaolin");
	set("type","hammer");
	set("effective_level",150);
	set("usage/hammer",1);
	set("usage/parry",1);
	set("practice_limit",100);
	set("difficulty",200);

	set("parry_msg", ({
			"$n后退一步，一招［不生不灭］手中的$v猛的砸向$N的$w。\n",
			"$n身形微顿，手中的$v一招［指引无生］反捣$N的必救之处。\n",
			"$n手中的$v从下往上急挥，一招［法归本性］磕开了$N手中的$w\n",
	}) );

	set("unarmed_parry_msg", ({
			"$n一招［阴阳轮转］，手中的$v从偏锋击向$N的太阳大穴。\n",
			"$n手中的$v从左划右，一招［万劫无移］封住了$N的攻势。\n",
			"$n凌空三连翻，一招［芥纳须弥］手中的$v反击$N的后脑，逼得$N中途撤招。\n",
	}) );	
	action = ({
		([      "action":               
				"$N手中$w抡动如飞，锤势连绵不断，一招［生生不息］，暴雨般向$n倾泻而去",
				"force":                70,
				"dodge":                100,
				"parry":                100,
				"post_action":  "bash_weapon",
				"damage_type":  "砸伤"
		]),
		([      "action":               
				"$N激进如飞，身影忽隐忽现，一招［明晦隐现］，手中的$w却早到$n的眼前",
				"damage":               70,
				"dodge":                20,
				"parry":                60,
				"post_action":  "bash_weapon",
				"damage_type":  "砸伤"
		]),
		([      "action":               
				"$N手中$w舞动，一招［雷动九天］挟着震天的撞击之声，猛砸$n的$l",
				"damage":               70,
				"force" :	            200,
				"dodge":                100,
				"parry":                200,
				"post_action":  "bash_weapon",
				"damage_type":  "砸伤"
		]),
		([      "action":               
				"$N手中的$w一转，一招［无中生有］从四面八方盖向$n的$l",
				"damage":               40,
				"force" :	            200,
				"dodge":                10,
				"parry":                40,
				"post_action":  "bash_weapon",
				"damage_type":  "砸伤"
		]),
		([      "action":
				"$N一抖手中的$w，一招［我法俱空］锤影漫天飞舞，虚虚实实的挥向$n的$l",
				"force":                100,
				"damage" :              50,
				"dodge":                100,
				"parry":                400,
				"post_action":  "bash_weapon",
				"damage_type":  "砸伤"
		]),
	});
}

int effective_level(object me)
{
	int skill, n;
	if( me ) {
		skill = me->query_skill("liuxing-hammer",1);
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
	if( ob=victim->query_temp("weapon") ) {
		if( ob->query("skill_type") == "sword" || ob->query("skill_type")=="spear" ) {
			return damage_bonus*15/100;
		}
	}
	return 0;
}

int skill_difficulty()
{
	object me = this_player();
	int skill, n;
	if( me && userp(me) ) {
		skill = me ->query_skill("liuxing-hammer",1);
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
流星锤法对所有剑法、枪法有额外１５％的伤害力。	
流星锤法的系数从150级开始逐步从150提高到200（L170）
但学习系数增加到400

『反背』（fanbei）
L50：单击，自我忙乱２轮
L80：两连击，自我忙乱２轮
L110：三连击，自我忙乱２轮
额外攻击力=流星锤等级*3/2

『玄机』（xuanji）
需要170级流星锤法和170级基本锤法，
60秒内自动反击敌人所有招式，每十分钟使用一次。
注：使用该特技后转换其他技能不受限制。

HELP
    );
    return 1;
}
