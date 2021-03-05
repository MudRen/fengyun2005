// yoga.c
#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","瑜珈");
	set("type","knowledge");
	set("skill_class","basic");
	set("difficulty",100);
	set("effective_level",50);
}
	
void skill_improved(object me) {
	int s;
	
	s = me->query_skill("yoga", 1);
	if( s%10==9 && (int)me->query("dur") < s/5) {
		tell_object(me, HIW "由於你勤练瑜珈，你的耐力提高了。\n" NOR);
//		me->add("dur", 2);
		me->set("dur",(s+1)/5);
	}
}

