// alchemy.c

inherit SKILL;

void setup() {
	set("name","炼丹术");
	set("type","magic");
	set("difficulty",200);
	set("effective_level",150);
	set("usage/magic",1);
	set("skill_class","taoist");
	set("practice_limit",1);
}

int valid_learn(object me)
{
	if( (int)me->query_skill("taoism",1) < 200)
		return notify_fail("学习炼丹术需要高深的天师正道（200级）\n");
	return 1;
}
