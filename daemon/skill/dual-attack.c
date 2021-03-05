//	by silencer@fy@, 9/10/02

inherit SKILL;

void setup() {
	set("name","连击之术");
	set("type","martial");
	set("skill_class","basic");
	set("difficulty",200);
	set("effective_level",200);
}


int valid_learn(object me)
{
	if( me->query_skill("combat_exp") <= 5000000 )
		return notify_fail("你的武功修为还不够高深，无法学习连击之术。\n");
	return 1;
}
