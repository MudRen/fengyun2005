// buddhism.c
inherit SKILL;

void setup() {
	set("name","大乘佛法");
	set("skill_class","bonze");
	set("type","knowledge");
	set("difficulty",250);
	set("effective_level",200);
	set("usage/literate",1);
	set("no_refund",({"essencemagic","lotusforce"}));
}


int valid_learn(object me) {
	if(!::valid_learn(me)) {
		return 0;
	}
	if( (int)me->query("bellicosity") > 100 )
		return notify_fail("修炼大乘佛法时杀气需低于100点。\n");
	return 1;
}



