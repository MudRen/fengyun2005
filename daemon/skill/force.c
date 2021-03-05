// force.c

#include <ansi.h>

inherit SKILL;

void setup() {
	set("name","内功心法");
	set("type","martial");
	set("skill_class","basic");
	set("difficulty",100);
	set("effective_level",50);
	set("eff_learn_level", 150);
	set("no_refund","attr");
}

void skill_improved(object me)
{
	string att = "con";
	string c_att = "体质";
	int s = me->query_skill("force", 1);
	
	if (s > 50 && s < 201 && !(s%10)) {
		if ( s/5 > 10 + me->query("improve/"+ att)) {
			tell_object(me, HIW "由於你的内功修炼有成，你的体质改善了。\n" NOR);
			me ->add(att, 2);
			me ->add("improve/"+att,2);
		}
		if (s == 200)
			tell_object(me,HIR"你的"+c_att+"已经不能再通过"+ name()+ "提高了。\n"NOR);
		
	}
	
}
