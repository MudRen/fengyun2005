// strategy.c
#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","兵法");
	set("skill_class","official");
	set("effective_level",160);
	set("type","knowledge");
	set("difficulty",200);
	
}

/*
void skill_improved(object me) {
	int s;
	
	s = me->query_skill("strategy", 1);
	if(s%10==9 && (int)me->query("cor") < s/5) {
		tell_object(me, HIW "由於你的兵法修炼有成，你的勇气增高了。\n" NOR);
//		me->add("cor", 2);
		me->set("cor",(s+1)/5);
	}
}
*/
