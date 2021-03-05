//TIE@FY3
// qiusheng-blade.c
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","秋声刀法");
	set("practice_limit",100);
	set("type","blade");
	set("difficulty",200);
	set("usage/blade",1);
	set("usage/parry",1);
	set("effective_level",150);
	set("skill_class","huangshan");
	set("parry_msg", ({
        "$n使出一招「风摇山竹寒声动」，手中的$v散出丝丝寒气格开了$N的$w。\n",
		"$n手中$v虚晃数刀，一招「淡烟疏雨间斜阳」，刀影中突然爆出一缕光芒从侧面划向$N之必救。\n",
		"$n身形微顿，手中的$v化作一道弧光，一招「雁点青天字一行」，反削$N的$w。\n",
	}) );

	set("unarmed_parry_msg", ({
		"$n使出一招「霜凋红叶正晚秋」，手中的$v内力激荡，$N的攻势随波而散。\n",
		"$n身形急退，手中$v上下飞舞，一招「雨过天连青壁润」，封住$N的招式。\n",
		"$n手中的$v挽出朵朵刀花，一招「金花玉萼影浮沉」，游刃有余。\n",
	}) );	
	action = ({
		([	"action":		"$N使一招「一叶浮萍归大海」，手中$w一摆，身形急进如飞，刀人合一，射向$n的$l！",
			"damage_type":	"割伤"
		]),
		([	"action":		"$N$w划出道道弧光，一招「人生何处不相逢」，刀刀不离$n的$l！",
			"damage_type":	"割伤"
		]),
		([	"action":		"$N手中$w刀光宛如流水，一招「衰草斜阳流曲浦」，斜斜削向$n的$l",
			"damage_type":	"割伤"
		]),
		([	"action":		"$N手中$w刀光激荡，一招「黄云影日暗长堤」，斩向$n！",
			"damage_type":	"割伤"
		]),
		([	"action":		"$N手中$w狂舞，刀光团团簇簇，一招「红萝花繁知景色」，飘飘荡荡向$n落去",
			"damage_type":	"割伤"
		]),
		([	"action":		"$N手中$w刀气森然，一招「白萍香远任依依」直劈$n$l",
			"damage_type":	"割伤"
		]),
		([	"action":		"$N使一招「缤纷天雨落花红」，手中$w摆动，刀光霍霍斩向$n的$l",
			"damage_type":	"割伤"
		]),
	});
}
int valid_learn(object me)
{
	if( (string)me->query("gender") != "男性" ){
	    return notify_fail("秋声刀法是只有男性才能练的武功。\n");
	}
	if(!::valid_learn(me)){
		return 0;
	}
	return 1;
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    object ob;
    if( random(damage_bonus) < 300 ) return 0;
    if(ob=victim->query_temp("weapon"))
    if(ob->query("skill_type") == "sword")
    if(victim->query_skill_mapped("sword") == "siqi-sword" )
    if(me->query_skill("blade") > victim->query_skill("sword")) {
		switch(random(3)) {
            case 0:
                    message_vision(HIR "\n因武功路数相克，$N占尽了上风！" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N轻而易举地抢入$n的空隙之间！" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n因刀剑相克，$n逐渐施展不开了！" NOR,me,victim);
                    break;
        }
    return random(me->query_skill("blade")) * 10;
    }
    return 0;
}

