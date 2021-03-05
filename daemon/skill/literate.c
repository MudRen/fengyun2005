// literate.c

#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","读书识字");
	set("skill_class","basic");
	set("difficulty",100);
	set("type","knowledge");
	set("no_refund","attr");
	set("effective_level",50);
	set("eff_learn_level", 150);
}



void skill_improved(object me)
{
	string att = "int";
	string c_att = "才智";
	int s = me->query_skill("literate", 1);
	
	if (s > 50 && s < 151 && !(s%10)) {
		if ( s/5 > 10 + me->query("improve/"+ att)) {
			tell_object(me, HIW "由於你的勤学苦读，你的"+c_att+"提高了。\n" NOR);
			me ->add(att, 2);
			me ->add("improve/"+att,2);
		}
		if (s == 150)
			tell_object(me,HIR"你的"+c_att+"已经不能再通过"+ name()+ "提高了。\n"NOR);
		
	}
	
}

