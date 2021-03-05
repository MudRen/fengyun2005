// dugu-jiujian.c 独孤九剑

inherit SKILL;
void setup() {
	set("name","独孤九剑");
	set("type","sword");
	set("usage/sword",1);
	set("usage/parry",1);
	set("effective_level",130);
	set("difficulty",200);
	set("skill_class","npc");
	set("unarmed_parry_msg", ({
	        "却见$n踏前一步，剑式斜指$N的右臂，想要使$N闪身而退。\n",
	        "$n脸上突现笑容，似乎已看破$N的武功招式，胸有成竹地一剑刺向$N！\n",
	        "$n随手一剑指向$N，落点正是$N的破绽所在，端的是神妙无伦，不可思议！\n",
	}) );

	action = ({
		([	"action" : "$N目若朗星，身如秋月，$w斜斜刺向$n的$l",
			"force" : 100,
			"dodge" : 5,
			"damage": 50,
			"damage_type" : "刺伤"
		]),
		([	"action" : "$N身行飘拂，如烟似云，手中$w无声无息已然刺至$n的$l",
			"force" : 80,
			"dodge" : 0,
			"damage": 30,
			"damage_type" : "刺伤"
		]),
		([	"action" : "$N身行突转凝滞，手中$w如有千斤向$n慢慢推去，但重剑无锋、大巧不工之意尽在其中",
			"force" : 200,
			"dodge" : 15,
			"damage": 100,
			"damage_type" : "刺伤"
		]),
		([	"action" : "$N剑意突焕气象森严，便似千军万马奔驰而来，长枪大戟，黄沙千里，剑势击向$n的$l",
			"force" : 110,
			"dodge" : 10,
			"damage": 60,
			"damage_type" : "刺伤"
		]),
		([	"action" : "$N抱剑旋身，转到$n身后，杂乱无章地向$n刺出一剑，不知使的是什么剑法",
			"force" : 180,
			"dodge" : 5,
			"damage": 80,
			"damage_type" : "刺伤"
		]),
		([	"action" : "$N剑挟刀势，大开大阖地乱砍一通，但招招皆击在$n攻势的破绽，迫得$n不得不守",
			"force" : 220,
			"dodge" : -10,
			"damage": 100,
			"damage_type" : "刺伤"
		]),
		([	"action" : "$N反手横剑刺向$n的$l，这似有招似无招的一剑，威力竟然奇大，$n难以看清\n剑招来势",
			"force" : 240,
			"dodge" : -15,
			"damage": 120,
			"damage_type" : "刺伤"
		]),
		([	"action" : "$N举剑狂挥，迅速无比地点向$n的$l，却令人看不出其所用是什么招式",
			"force" : 260,
			"dodge" : 0,
			"damage": 100,
			"damage_type" : "刺伤"
		]),
	});

}

int valid_learn(object me)
{
	object ob;
	
	if(!::valid_learn(me)) {
		return 0;
	}
	if ((string)me->query("class") != "npc") {
		return notify_fail("「独孤九剑」是只能传给华山派弟子的。\n");
	}
	if ((int)me->query("max_force") < 1000) {
		return notify_fail("你的内力不够。\n");
	}
	if ((int)me->query_skill("dugu-sword",1) > 90) {
		return notify_fail("这套剑法到这儿后就要靠自己练了。\n");
	}
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("独孤九剑只能通过「总诀式」来演练。\n");
}

