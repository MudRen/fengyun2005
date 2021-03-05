#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","太极剑法");
	set("practice_limit",100);
	set("type","sword");
	set("usage/sword",1);
	set("usage/parry",1);
	set("effective_level",170);
	set("skill_class","wudang");
	set("difficulty",200);
	set("unarmed_parry_msg",({
   	        "$n一招「右拦扫」，一招「左拦扫」，剑锋平指，一气呵成横扫$N的$l\n",
        	"$n一招「却步抽剑」，左脚跃步落地，$v回抽，反手勾向$N的$l\n",
		"$n使出「狮子摇头」，$v由右向左划出一个大８字，将$N圈在其中\n",
		"$n一招「迎风掸尘」，$v看似随意地一挥，$N却陡觉一股劲气迎面袭来。\n",
		"$n右腿半屈般蹲，一招「如封似闭」，便将$N的攻势化解了\n",        
	}) );		
	set("parry_msg",	({
		"$n一招「右拦扫」，一招「左拦扫」，剑锋平指，一气呵成横扫$N的$w\n",
        	"$n一招「却步抽剑」，左脚跃步落地，$v回抽，反手勾向$N的$w\n",
		"$n使出「狮子摇头」，$v由右向左划出一个大８字，将$N的$w圈在其中\n",
		"$n一招「迎风掸尘」，$v看似随意地一挥，$N却陡觉一股劲气迎面袭来。\n",
		"$n右腿半屈般蹲，一招「如封似闭」，便将$N的攻势化解了\n",			
	}) );
	
	
	
action = ({
([      "action" : "$N虚步提腰，一招「蜻蜓点水」，手中$w轻轻颤动，一剑剑点向$n的$l",
        "dodge" : 20,
        "parry" : 10,
        "damage" : 105,
        "lvl" : 0,
        "damage_type" : "刺伤"
]),
([      "action" : "$N向前跨上一步，左手剑诀，右手$w使出一式「指南针」直刺$n的$l",
        "dodge" : 15,
        "parry" : 10,
        "damage" : 120,
        "lvl" : 4,
        "damage_type" : "刺伤"
]),
([      "action" : "$N身形往右一挫，左手剑诀，右手$w使出一式「大魁星」刺向$n的$l",
        "dodge" : 15,
        "parry" : 10,
        "damage" : 130,
        "lvl" : 9,
        "damage_type" : "刺伤"
]),
([      "action" : "$N双膝下沉，右手$w使出一式「探海式」，由下而上疾刺$n的$l",
        "dodge" : 15,
        "parry" : 10,
        "damage" : 140,
        "lvl" : 14,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「燕子掠波」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
        "dodge" : 15,
        "parry" : 15,
        "damage" : 160,
        "lvl" : 19,
        "damage_type" : "刺伤"
]),
([      "action" : "$N上身往左侧一拧，一招「乌龙摆尾」，右手$w反手向$n的$l挥去",
        "dodge" : 15,
        "parry" : 15,
        "damage" : 170,
        "lvl" : 24,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左腿提膝，手中$w斜指，一招「宿鸟投林」刺向$n的$l",
        "dodge" : 15,
        "parry" : 15,
        "damage" : 200,
        "lvl" : 34,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「青龙出水」，$w自下而上划出一个大弧，平平地挥向$n的$l",
        "dodge" : 15,
        "parry" : 15,
        "damage" : 200,
        "lvl" : 39,
        "damage_type" : "刺伤"
]),
([      "action" : "$N使出「三环套月」，$w划出三个圆圈，剑锋直出，绵绵不断划向$n
的$l",
        "dodge" : 10,
        "parry" : 20,
        "damage" : 220,
        "lvl" : 44,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「风卷荷叶」，$w轻灵地划出几个圆弧，迅速地向$n的$l挥去",
        "dodge" : 15,
        "parry" : 20,
        "damage" : 205,
        "lvl" : 49,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「虎抱头」，$w划出一个左低右高的大弧，斜斜地斩向$n的$l",
        "dodge" : 15,
        "parry" : 20,
        "damage" : 240,
        "lvl" : 54,
        "damage_type" : "刺伤"
]),

([      "action" : "$N左脚踏实，右脚虚点，一招「仙人指路」，右手$w带着一团剑花，逼向$n的$l",
        "dodge" : 5,
        "parry" : 20,
        "damage" : 270,
        "lvl" : 64,
        "damage_type" : "刺伤"
]),
([      "action" : "$N轻轻跃起，一招「野马跳涧」，$w在半空中化为一圈银芒，落向$n的$l",
        "dodge" : 15,
        "parry" : 20,
        "damage" : 283,
        "lvl" : 69,
        "damage_type" : "刺伤"
]),
([      "action" : "$N两腿前箭后弓，一招「射雁式」，右手$w直刺$n的$l",
        "dodge" : 20,
        "parry" : 20,
        "damage" : 285,
        "lvl" : 74,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「小魁星」，身形往左一挫，左手剑诀，右手$w平平地向$n的$l挥去",
        "dodge" : 40,
        "parry" : 20,
        "damage" : 300,
        "lvl" : 79,
        "damage_type" : "刺伤"
]),
([      "action" : "$N猱身扑上，一招「白猿献果」，手中$w斜斜地向$n的$l挥去",
        "dodge" : 30,
        "parry" : 20,
        "damage" : 310,
        "lvl" : 84,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「顺水推舟」，$w自上而下划出一个大弧，平平地向$n的$l挥去。",
        "dodge" : 45,
        "parry" : 25,
        "damage" : 320,
        "lvl" : 94,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「流星赶月」，$w疾刺$n的$l",
        "dodge" : 35,
        "parry" : 25,
        "damage" : 370,
        "lvl" : 99,
        "damage_type" : "刺伤"
]),
([      "action" : "$N突然盘蹲下身来，一招「海底捞月」，$w自下而上地向$n的$l挥去",
        "dodge" : 25,
        "parry" : 25,
        "damage" : 350,
        "lvl" : 104,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「挑帘式」，$w自下而上徐徐划出一个大弧，平平地向$n的$l挥去",
        "dodge" : 35,
        "parry" : 25,
        "damage" : 190,
        "lvl" : 109,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「黄蜂入洞」，$w自上而下划出一个大弧，平平地向$n的$l挥去",
        "dodge" : 40,
        "parry" : 25,
        "damage" : 202,
        "lvl" : 114,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「大鹏展翅」，身形跃起，右手$w刺向$n的$l",
        "dodge" : 45,
        "parry" : 25,
        "damage" : 106,
        "lvl" : 119,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「车轮剑」，$w化作一片银盘，平平地向$n的$l卷去",
        "dodge" : 45,
        "parry" : 25,
        "damage" : 120,
        "lvl" : 124,
        "damage_type" : "刺伤"
]),
([      "action" : "$N左脚轻点地面，身形往前一扑，一招「天马行空」，$w向$n的$l挥去",
        "dodge" : 45,
        "parry" : 30,
        "damage" : 125,
        "lvl" : 129,
        "damage_type" : "刺伤"
]),
([      "action" : "$N一招「风扫梅花」，身体跃在半空，手中$w扫向$n的$l",
        "dodge" : 45,
        "parry" : 30,
        "damage" : 130,
        "lvl" : 90,
        "damage_type" : "刺伤"
]),

([  "action" : "$N回身拧腰，右手虚抱，一招「拨云瞻日」，$w中宫直进，刺向$n的$l",
        "dodge" : 35,
        "parry" : 30,
        "damage" : 160,
        "lvl" : 149,
        "damage_type" : "刺伤"
]),
});

}
int valid_learn(object me)
{
        object ob;

        if( (string)me->query_skill_mapped("force")!= "taijiforce")
                return notify_fail("太极剑法必须配合太极内功心法才能练。\n");

        return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
        int myexp,urexp;
	myexp=me->query("combat_exp");
	urexp=victim->query("combat_exp")*victim->query("cps")/20;
	if (!victim->is_busy())
		if (random(myexp+urexp)>urexp && me->query_skill("taiji-sword",1)>100)
		{
			victim->force_busy(2);
			return HIW "$n被$N的剑势所缠，速度不由得放慢下来。\n"NOR;
		}   
}

int eff_parry_level(object me) {
	if (me)
	if (me->query_temp("perform/taiji_shou"))
	{
		return 250;
	}
	return 170;
}