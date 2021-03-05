inherit SKILL;

void setup() {
	set("name","高级纵跃闪躲之术");
	set("practice_limit",100);
	set("skill_class","basic");
	set("difficulty",400);
	set("effective_level",200);
	set("type","martial");
}


int valid_learn(object me)
{
	if( me->query("combat_exp") <= 5000000 )
		return notify_fail("你的武功修为还不够高深，无法学习高级纵跃闪躲之术。\n");
	return 1;
}
